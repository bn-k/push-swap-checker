package push_swap

import (
	"fmt"
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
	{"ss", SwapAll},
	{"pa", PushA},
	{"pb", PushB},
	{"ra", RotateA},
	{"rb", RotateB},
	{"rr", RotateAll},
	{"rra", ReverseRotateA},
	{"rrb", ReverseRotateB},
	{"rrr", ReverseRotateAll},
	{"KO", Done},
	{"OK", Done},
}

func browse (stack *Stack) {
	for i := 0; i < 13 ; i++ {
		if opeTab[i].code == stack.Ope[0] {
			opeTab[i].function(stack)
			i = 13
			stack.Ope = append(stack.Ope[:0], stack.Ope[1:]...)
		}
	}
}

func Test () {
	fmt.Println("testttt")
}

func Operate (A, B []int, Ope []string, Done int)  ([]int, []int, []string, int){
	var stack Stack
	stack.A, stack.B, stack.Ope, stack.Done = A, B, Ope, Done
	browse(&stack)
	return stack.A, stack.B, stack.Ope, stack.Done
}

func Operate2 (A, B []int, Ope []string, Done int){
	var stack Stack
	stack.A, stack.B, stack.Ope, stack.Done = A, B, Ope, Done
	browse(&stack)
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

func SwapAll (s *Stack){
	SwapA(s)
	SwapB(s)
}

func RotateA  (s *Stack){
	s.A = append(s.A[1:], s.A[0])
}

func RotateB  (s *Stack){
	s.B = append(s.B[1:], s.B[0])
}

func RotateAll (s *Stack){
	RotateB(s)
	RotateA(s)
}

func ReverseRotateB  (s *Stack){
	s.B = append([]int{s.B[len(s.B) - 1]},s.B[:len(s.B) - 1]...)
}

func ReverseRotateA  (s *Stack){
	s.A = append([]int{s.A[len(s.A) - 1]},s.A[:len(s.A) - 1]...)
}

func ReverseRotateAll (s *Stack){
	ReverseRotateB(s)
	ReverseRotateA(s)
}

func Done (s *Stack) {
	println("DONE")
	if s.Ope[0] == "OK"{
		s.Done = 1
	} else {
		s.Done = -1
	}
}
