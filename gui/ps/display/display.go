package display

import (
	"fmt"
	"log"
	"os"
	"image/color"
	"engo.io/engo"
	"engo.io/ecs"
	"engo.io/engo/common"
	"path/filepath"
	"./number"
	"./systems"
)

type myScene struct {}

func (*myScene) Preload() {
	dir, err := filepath.Abs(filepath.Dir(os.Args[0]))
	if err != nil {
		log.Fatal(err)
	}
	engo.Files.SetRoot(dir + "/")
	engo.Files.Load("gui/assets/textures/city.png")
}

func (*myScene) Type() string { return "Viewer" }

func (*myScene) Setup(up engo.Updater) {
	w, _ := up.(*ecs.World)
	w.AddSystem(&common.RenderSystem{})
	w.AddSystem(&common.MouseSystem{})
	common.SetBackground(color.White)
	log.Println("Jusqu'ici tout va bien")
	w.AddSystem(&systems.CityBuildingSystem{})
	w.AddSystem(&number.LineBuilding{})
	engo.Input.RegisterButton("AddCity", engo.KeyF)
	//number.Add(w)
}

func Display() {
	fmt.Println("========Function display========")
	opts := engo.RunOptions{
		Title: "View Stack",
		Width:  2000,
		Height: 1000,
	}
	engo.Run(opts, &myScene{})
}
