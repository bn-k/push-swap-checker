package main

import (
	"fmt"
	"bufio"
	"os"
	"engo.io/engo"
)

type myScene struct {}

// Type uniquely defines your game type
func (*myScene) Type() string { return "Viewer" }

// Preload is called before loading any assets from the disk,
// to allow you to register / queue them

// Setup is called before the main loop starts. It allows you
// to add entities and systems to your Scene.
func (*myScene) Setup(engo.Updater) {}

func (*myScene) Preload() {
	engo.Files.Load("assets/textures/city.png")
}

func main() {
	entry := bufio.NewReader(os.Stdin)
	str , _ := entry.ReadString('\n')
	fmt.Printf("%s", str)
	opts := engo.RunOptions{
		Title: "Hello World",
		Width:  400,
		Height: 400,
	}
	engo.Run(opts, &myScene{})
}

