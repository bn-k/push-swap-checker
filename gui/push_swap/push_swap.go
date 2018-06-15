package push_swap

import (
	"fmt"
)

func (s *Stack) Print_slice(a, b, tb *[]int) {
	println("=========================================================================================")
	println("address")
	fmt.Printf("a= %p b= %p tb= %p\n",*a, *b, *tb)
	println("content")
	fmt.Println("a=",*a,"b=", *b, "tb=", *tb)
}

type Stack struct {
	A	[]int
	B	[]int
	Ope	[]string
}

func (s *Stack) PushB () {
	s.B = append([]int{s.A[0]}, s.B...)
	s.A = append(s.A[1:])
}

func (s *Stack) PushA () {
	s.B = append([]int{s.A[0]}, s.B...)
	s.A = append(s.A[1:])
}

func (s *Stack) SwapA () {
	s.A[0], s.A[1] = s.A[1], s.A[0]
}

func (s *Stack) SwapB () {
	s.B[0], s.B[1] = s.B[1], s.B[0]
}

func (s *Stack) RotateA () {
	s.A = append(s.A[1:], s.A[0])
}

func (s *Stack) RotateB () {
	s.B = append(s.B[1:], s.B[0])
}

func (s *Stack) ReverseRotateB () {
	s.B = append([]int{s.B[len(s.B) - 1]},s.B[:len(s.B) - 1]...)
}

func (s *Stack) ReverseRotateA () {
	s.A = append([]int{s.A[len(s.A) - 1]},s.A[:len(s.A) - 1]...)
}

func RunPushSwap (flag *bool) {
	fmt.Println("Run PS")
}
