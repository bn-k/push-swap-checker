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
)

type flags struct {
	output *bool;
}

func main() {
	var f flags
	f.output = flag.Bool("v", false, "Mode graphique")
	flag.Parse()
	parser.Parser()
	if *f.output {
		display.Display()
	} else {
		fmt.Println("========Mode CLI========")
	}
}
