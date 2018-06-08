package display

import (
	"log"
	"image/color"
	"engo.io/engo"
	"engo.io/ecs"
	"engo.io/engo/common"
	"os"
	"path/filepath"
	//"../systems"
	"../number"
	//"bufio"
	"fmt"
)

type myScene struct {}


func (*myScene) Preload() {
	dir, err := filepath.Abs(filepath.Dir(os.Args[0]))
	if err != nil {
		log.Fatal(err)
	}
	log.Printf("Root set to: %s", dir + "/")
	engo.Files.SetRoot(dir + "/")
	engo.Files.Load("assets/textures/city.png")
}

func (*myScene) Type() string { return "Viewer" }

func (*myScene) Setup(up engo.Updater) {
	w, _ := up.(*ecs.World)
	w.AddSystem(&common.RenderSystem{})
	w.AddSystem(&common.MouseSystem{})
	common.SetBackground(color.White)
	log.Println("Jusqu'ici tout va bien")
	//w.AddSystem(&systems.CityBuildingSystem{})
	w.AddSystem(&number.LineBuilding{})
	//engo.Input.RegisterButton("AddCity", engo.KeyF)
}

func Display() {
	fmt.Println("========Function display========")
	opts := engo.RunOptions{
		Title: "View Stack",
		Width:  1400,
		Height: 1400,
	}
	engo.Run(opts, &myScene{})
}
