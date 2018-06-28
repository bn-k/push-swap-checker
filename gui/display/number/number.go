package number

import (
	"engo.io/ecs"
	//"engo.io/engo"
	"engo.io/engo/common"
	//"image/color"
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

type DoubleStackSystem struct {
	ecsWorld	*ecs.World
	eds		*DoubleStackEntity
}

type DoubleStackEntity struct {
	A	[]int
	B	[]int
	Ope	[]string
	Done	int
	pad	float32
	thick	float32
	n	int
	slice	float32
	max	int
	K	float32
}

type line struct {
	s	[]int
	col	uint8
	r	uint8
	g	uint8
	b	uint8
	y	int
	side	int
}

func (sys *DoubleStackSystem) New(world *ecs.World) {
	sys.ecsWorld = world
	var ds DoubleStackEntity
	sys.eds = &ds
	ds.A, ds.Ope = parser.Parser()
	sys.initMath()
	for y := 0; y < len(ds.A) ; y++ {
		//addLine(ds, line{s: ds.A, col: 0, r: 255, g:255, b:255, y: y, side: 0})
	}
	for y := 0; y < len(ds.B) ; y++ {
		//addLine(ds, line{s: ds.B, col: 0, r: 255, g:255, b:255, y: y, side: 1})
	}
}

func (sys *DoubleStackSystem) initMath () {
	sys.eds.n = len(sys.eds.A)
	sys.eds.slice = WIND_Y / float32(sys.eds.n)
	sys.eds.thick = ((sys.eds.slice / 8) * 6)
	sys.eds.pad = (sys.eds.slice - sys.eds.thick) / 2
	for i := 0 ; i < len(sys.eds.A) ; i++ {
		if sys.eds.max < sys.eds.A[i] {
			sys.eds.max = sys.eds.A[i]
		}
	}
	sys.eds.K = float32(WIND_X / sys.eds.max)
}

func (sys *DoubleStackSystem) Update(dt float32) {
	time.Sleep(100 * time.Millisecond)
	select {
	case <-time.After(30 * time.Millisecond):
		fmt.Println("Operate")
		sys.eds.A, sys.eds.B, sys.eds.Ope, sys.eds.Done = ps.Operate(sys.eds.A, sys.eds.B, sys.eds.Ope, sys.eds.Done)
	}
}

func (sys *DoubleStackSystem) Remove(ecs.BasicEntity) {
}

func addToSystem (sys *DoubleStackSystem, rectangle Line) {
	for _, system := range sys.ecsWorld.Systems() {
		switch sys := system.(type) {
		case *common.RenderSystem:
			sys.Add(&rectangle.BasicEntity, &rectangle.RenderComponent,
			&rectangle.SpaceComponent)
		}
	}
}
