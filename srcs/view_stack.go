package main

import (
	"log"
	"image/color"
	"engo.io/engo"
	"engo.io/ecs"
	"engo.io/engo/common"
	"./systems"
	"./number"
)

type myScene struct {}


func (*myScene) Preload() {
	engo.Files.SetRoot("/Users/abbenham/home/push_swap/srcs/")
	engo.Files.Load("assets/textures/city.png")
}

func (*myScene) Type() string { return "Viewer" }

func (*myScene) Setup(up engo.Updater) {
	w, _ := up.(*ecs.World)
	w.AddSystem(&common.RenderSystem{})
	w.AddSystem(&common.MouseSystem{})
	w.AddSystem(&systems.CityBuildingSystem{})
	w.AddSystem(&number.LineBuilding{})
	number.Test()
	common.SetBackground(color.White)
	engo.Input.RegisterButton("AddCity", engo.KeyF)
}

func main() {
	//entry := bufio.NewReader(os.Stdin)
	//str ,_ :=  entry.ReadString('\n')
	//fmt.Printf("%s", str)
	log.Println("Jusqu'ici tout va bien")
	opts := engo.RunOptions{
		Title: "View Stack",
		Width:  1400,
		Height: 1400,
	}
	engo.Run(opts, &myScene{})
}
