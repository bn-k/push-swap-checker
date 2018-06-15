package main

import (
	"fmt"
	"flag"
	"./push_swap"
	"./push_swap/parser"
)

type flags struct {
	visu *bool;
}

func main() {
	var f flags
	var ps push_swap

	fmt.Println("======== view_stack/main ========")
	f.visu = flag.Bool("v", false, "Graphique Mode")
	flag.Parse()
	ps.Run(f.visu)
}
