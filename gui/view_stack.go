package main

import (
	"fmt"
	"flag"
	"./ps"
)

type flags struct {
	visu *bool;
}

func main() {
	var f flags

	fmt.Println("======== view_stack/main ========")
	f.visu = flag.Bool("v", false, "Graphique Mode")
	flag.Parse()
	ps.Run(f.visu)
}
