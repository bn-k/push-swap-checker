package number

import (
	"engo.io/ecs"
	"engo.io/engo"
	"engo.io/engo/common"
	"image/color"
	"fmt"
	"bufio"
	"os"

)

type Line struct {
	ecs.BasicEntity
	common.RenderComponent
	common.SpaceComponent
}

type LineBuilding struct {
	w *ecs.World
}

func (cb *LineBuilding) New(world *ecs.World) {
	entry := bufio.NewReader(os.Stdin)
	str ,_ :=  entry.ReadString('\n')
	fmt.Printf("%s", str)
	fmt.Println("LineBuilding was added to the scene")
	cb.w = world
}

func (cb *LineBuilding) Update(dt float32) {
	rectangle := Line{BasicEntity: ecs.NewBasic()}
	rectangle.SpaceComponent = common.SpaceComponent{Position: engo.Point{100, 100},
	Width: 100, Height: 100}
	rectangle.RenderComponent = common.RenderComponent{
		Drawable: common.Rectangle{},
		Color: color.Black, Scale: engo.Point{0.5, 0.5}}
		//fmt.Printf("%p\n", cb.w)
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

func (cb *LineBuilding) Remove(ecs.BasicEntity) {
}

func Test (){
	fmt.Println("Test call")
}
