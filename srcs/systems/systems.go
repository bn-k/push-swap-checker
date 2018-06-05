package systems

import (
	"engo.io/ecs"
	"engo.io/engo"
	"engo.io/engo/common"
	"fmt"
)

const cityTextureLocation = "assets/textures/city.png"

type CityMouseTracker struct {
	ecs.BasicEntity
	common.MouseComponent
}

type City struct {
	ecs.BasicEntity
	common.RenderComponent
	common.SpaceComponent
}

type CityBuildingSystem struct {
	world *ecs.World

	mouseTracker CityMouseTracker
}

func (cb *CityBuildingSystem) New(w *ecs.World) {
	cb.world = w
	fmt.Println("CityBuildingSystem was added to the scene")

	cb.mouseTracker.BasicEntity = ecs.NewBasic()
	cb.mouseTracker.MouseComponent = common.MouseComponent{Track : true}

	engo.Input.RegisterButton("Addcity", engo.KeyF)

	for _, system := range w.Systems() {
		switch sys := system.(type) {
		case *common.MouseSystem:
			sys.Add(&cb.mouseTracker.BasicEntity, &cb.mouseTracker.MouseComponent, nil, nil)
		}
	}

}

func (cb *CityBuildingSystem) Update(dt float32) {
	if engo.Input.Button("AddCity").JustPressed() {
		fmt.Println("F pressed")
	}
	city := City{BasicEntity: ecs.NewBasic()}

	city.SpaceComponent = common.SpaceComponent{
		Position:engo.Point{cb.mouseTracker.MouseComponent.MouseX, cb.mouseTracker.MouseComponent.MouseY},
		Width: 30,
		Height: 60,
	}
	texture, err := common.LoadedSprite(cityTextureLocation)
	if err != nil {
		panic(err)
	}
	city.RenderComponent = common.RenderComponent{
		Drawable: texture,
		Scale: engo.Point{0.5, 0.5},
	}
	for _, system := range cb.world.Systems() {
		switch sys := system.(type) {
		case *common.RenderSystem:
			sys.Add(&city.BasicEntity, &city.RenderComponent, &city.SpaceComponent)
		}
	}
}

func (cb *CityBuildingSystem) Remove(ecs.BasicEntity) {
}

func Test () {
	engo.Files.SetRoot("/Users/abbenham/home/push_swap/srcs/")
}
