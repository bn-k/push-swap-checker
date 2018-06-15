package main

import (
	"./push_swap"
	"testing"
)

func TestPushB(t *testing.T){
	var s push_swap.Stack
	s.A = []int{1,2,3}
	n := s.A[0]
	s.PushB()
	if s.B[0] != n {
		t.Errorf("PushB fail, got: %d, want: %d.", s.B, n)
	}
}
