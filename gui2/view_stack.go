package main

import (
	"flag"
	"fmt"
	"./display"
	"./display/number/parser"
	"./display/number/ps"
	"./display/number"
)

type flags struct {
	visu *bool;
}

func cli () {
	var s number.LineBuilding
	s.A, s.Ope = parser.Parser()
	for s.Done == 0 {
		fmt.Println(s)
		s.A, s.B, s.Ope, s.Done = ps.Operate(s.A, s.B, s.Ope, s.Done)
	}
}

func main() {
	var f flags

	f.visu = flag.Bool("v", false, "Graphique Mode")
	flag.Parse()
	if (*f.visu) {
		display.Display()
	} else {
		cli()
	}
}
