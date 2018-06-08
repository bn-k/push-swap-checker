package main

import (
	//"log"
	//"os"
	//"path/filepath"
	//"bufio"
	"fmt"
	"flag"
	"./parser"
	"./display"
	"container/list"

)

type flags struct {
	output *bool;
}

func main() {
	var f flags
	var stack parser.Stack

	f.output = flag.Bool("v", false, "Mode graphique")
	flag.Parse()
	stack.Parser()
	if *f.output {
		display.Display()
	} else {
		fmt.Println("========Mode CLI========")
	}
	l := list.New
	l.PushBack("bird")
}
