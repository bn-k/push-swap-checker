package number

import (
	"engo.io/ecs"
	"engo.io/engo"
	"engo.io/engo/common"
	"image/color"
	"fmt"
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
	fmt.Println("LineBuilding was added to the scene")
	cb.w = world
}

func (cb *LineBuilding) Update(dt float32) {
	rectangle := Line{BasicEntity: ecs.NewBasic()}
	rectangle.SpaceComponent = common.SpaceComponent{Position: engo.Point{100, 100},
	Width: 100, Height: 100}
	rectangle.RenderComponent = common.RenderComponent{Drawable: common.Rectangle{},
	Color: color.Black,
	Scale: engo.Point{0.5, 0.5}}
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

func Add (w *ecs.World) {
	rectangle1 := Line{BasicEntity: ecs.NewBasic()}
	rectangle1.SpaceComponent = common.SpaceComponent{Position: engo.Point{100, 100}, Width: 100, Height: 100}
	rectangle1.RenderComponent = common.RenderComponent{Drawable: common.Rectangle{}, Color: color.RGBA{0, 255, 0, 255}}

	for _, system := range w.Systems() {
		switch sys := system.(type) {
		case *common.RenderSystem:
			sys.Add(&rectangle1.BasicEntity, &rectangle1.RenderComponent, &rectangle1.SpaceComponent)
		}
	}

}
