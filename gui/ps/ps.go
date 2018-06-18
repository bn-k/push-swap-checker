package ps

import (
	"fmt"
	"./parser"
	"./display"
)

type Stack struct {
	A	[]int
	B	[]int
	Ope	[]string
	Done	int
}

type  opeFunc func(*Stack)

type opeStruct struct {
	code		string
	function	opeFunc
}

var opeTab =  []opeStruct {
	{"sa", SwapA},
	{"sb", SwapB},
	{"pa", PushA},
	{"pb", PushB},
	{"ra", RotateA},
	{"rb", RotateB},
	{"rra", ReverseRotateA},
	{"rrb", ReverseRotateB},
	{"OK", Done},
	{"KO", Done},
}

func browse (stack *Stack) {
	for i := 0; i < 11 ; i++ {
		if opeTab[i].code == stack.Ope[0] {
			opeTab[i].function(stack)
			i = 11
			stack.Ope = append(stack.Ope[:0], stack.Ope[1:]...)
		}
	}
}

func Run(flag *bool) {
	if (*flag) {
		fmt.Println("Mode graphique")
	} else {
		fmt.Println("Mode CLI")
	}
	operate()
}

func operate () {
	var stack Stack
	stack.A, stack.Ope = parser.Parser()
	display.Display()
	for i:= 0; 0 == stack.Done ; i++ {
		fmt.Println("==============",stack.Ope[0],"==============")
		browse(&stack)
		fmt.Println(stack)
	}
}

func PushB (s *Stack) {
	s.B = append([]int{s.A[0]}, s.B...)
	s.A = append(s.A[1:])
}

func PushA  (s *Stack){
	s.A = append([]int{s.B[0]}, s.A...)
	s.B = append(s.B[1:])
}

func SwapA  (s *Stack){
	s.A[0], s.A[1] = s.A[1], s.A[0]
}

func SwapB  (s *Stack){
	s.B[0], s.B[1] = s.B[1], s.B[0]
}

func RotateA  (s *Stack){
	s.A = append(s.A[1:], s.A[0])
}

func RotateB  (s *Stack){
	s.B = append(s.B[1:], s.B[0])
}

func ReverseRotateB  (s *Stack){
	s.B = append([]int{s.B[len(s.B) - 1]},s.B[:len(s.B) - 1]...)
}

func ReverseRotateA  (s *Stack){
	s.A = append([]int{s.A[len(s.A) - 1]},s.A[:len(s.A) - 1]...)
}

func Done (s *Stack) {
	println("DONE")
	if s.Ope[0] == "OK"{
		s.Done = 1
	} else {
		s.Done = -1
	}
}
