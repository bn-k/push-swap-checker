package number

import (
	"engo.io/ecs"
	"engo.io/engo"
	"engo.io/engo/common"
	"image/color"
	"./parser"
	"./ps"
	"fmt"
	"time"
)

const SCREEN_Y = 800
const SCREEN_X = 1000
const MARGIN = ((SCREEN_Y + SCREEN_X) / 20)
const WIND_Y = SCREEN_Y - (MARGIN * 2)
const WIND_X = (SCREEN_X - (MARGIN * 3)) / 2

type Line struct {
	ecs.BasicEntity
	common.RenderComponent
	common.SpaceComponent
}

type Geo struct {
	pad	float32
	thick	float32
	n	int
	slice	float32
	max	int
	K	float32
}

type LineBuilding struct {
	w	*ecs.World
	A	[]int
	B	[]int
	Ope	[]string
	Done	int
	g	*Geo
}

type rect struct {
	s	[]int
	col	uint8
	r	uint8
	g	uint8
	b	uint8
	y	int
	side	int
}

func (cb *LineBuilding) New(world *ecs.World) {
	cb.w = world
	cb.A, cb.Ope = parser.Parser()
	cb.initMath()
	fmt.Println(cb)
	fmt.Println(SCREEN_Y)
	fmt.Println(cb.g)
	for y := 0; y < len(cb.A) ; y++ {
		addLine(cb, rect{s: cb.A, col: 0, r: 255, g:255, b:255, y: y, side: 0})
	}
	for y := 0; y < len(cb.B) ; y++ {
		addLine(cb, rect{s: cb.B, col: 0, r: 255, g:255, b:255, y: y, side: 1})
	}
}

func (cb *LineBuilding) initMath () {
	var g Geo
	g.n = len(cb.A)
	g.slice = WIND_Y / float32(g.n)
	g.thick = ((g.slice / 8) * 6)
	g.pad = (g.slice - g.thick) / 2
	cb.g = &g
	for i := 0 ; i < len(cb.A) ; i++ {
		if cb.g.max < cb.A[i] {
			cb.g.max = cb.A[i]
		}
	}
	cb.g.K = float32(WIND_X / cb.g.max)
}

func (cb *LineBuilding) Update(dt float32) {
	time.Sleep(100 * time.Millisecond)
	select {
	case <-time.After(30 * time.Millisecond):
		fmt.Println("Operate")
		cb.A, cb.B, cb.Ope, cb.Done = ps.Operate(cb.A, cb.B, cb.Ope, cb.Done)
		fmt.Println(cb)
	}
}

func (cb *LineBuilding) xPointLen (y int, s []int) (x, l float32) {
	l = float32(s[y]) * cb.g.K
	x = (float32(WIND_X) - l) / 2
	return x, l
}

func (cb *LineBuilding) Remove(ecs.BasicEntity) {
}

func addLine (cb *LineBuilding, r rect){
	x, l := cb.xPointLen(r.y, r.s)
	rectangle := Line{BasicEntity: ecs.NewBasic()}
	rectangle.SpaceComponent = common.SpaceComponent{Position: engo.Point{float32((MARGIN * (r.side + 1))) + x + float32(WIND_X * r.side), (cb.g.slice*float32(r.y)) + cb.g.pad + MARGIN},
	Width: l + 6,
	Height: cb.g.thick}
	rectangle.RenderComponent = common.RenderComponent{Drawable: common.Rectangle{}, Color: color.RGBA{r.col, r.r, r.g, r.b}}

	addToSystem(cb, rectangle)
}

func addToSystem (cb *LineBuilding, rectangle Line) {
	for _, system := range cb.w.Systems() {
		switch sys := system.(type) {
		case *common.RenderSystem:
			sys.Add(&rectangle.BasicEntity, &rectangle.RenderComponent,
			&rectangle.SpaceComponent)
		}
	}
}
