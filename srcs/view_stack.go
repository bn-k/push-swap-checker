package main

import (
	"fmt"
	"bufio"
	"os"
	"log"
	"image/color"
	"engo.io/engo"
	"engo.io/ecs"
	"engo.io/engo/common"
	"./systems"
)

type myScene struct {}


func (*myScene) Preload() {
	engo.Files.SetRoot("/Users/abbenham/home/push_swap/srcs/")
	engo.Files.Load("assets/textures/city.png")
}

func (*myScene) Type() string { return "Viewer" }

func (*myScene) Setup(u engo.Updater) {
	world, _ := u.(*ecs.World)
	world.AddSystem(&common.RenderSystem{})
	world.AddSystem(&common.MouseSystem{})
	//world.AddSystem(&systems.CityBuildingSystem{})
	common.SetBackground(color.White)
	engo.Input.RegisterButton("AddCity", engo.KeyF)
	systems.Test()
}

func main() {
	entry := bufio.NewReader(os.Stdin)
	str ,_ :=  entry.ReadString('\n')
	fmt.Printf("%s", str)
	log.Println("Jusqu'ici tout va bien")
	opts := engo.RunOptions{
		Title: "View Stack",
		Width:  1400,
		Height: 1400,
	}
	engo.Run(opts, &myScene{})
}
