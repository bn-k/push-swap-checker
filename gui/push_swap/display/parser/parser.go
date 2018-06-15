package parser

import (
	//"log"
	"os"
	//"path/filepath"
	"bufio"
	"fmt"
	//"io"
	"bytes"
	"strings"
	"strconv"
)

type Stack struct {
	A		[]int
	B		[]int
	Ope		[]string
}

func toSlice (s string) []int {
	var tab []int
	var tmp []string

	tmp = strings.Split(strings.Trim(s, "\n"), " ")
	tab = make([]int, len(tmp))
	for i := range tmp  {
		tab[i], _ = strconv.Atoi(tmp[i])
	//	fmt.Printf("n = %d\n", tab[i])
	}
	return tab
}

func (s *Stack) Parser () ([]int, []int, []string) {
	var buffer	bytes.Buffer
	var str		string

	entry := bufio.NewReader(os.Stdin)
	stack, err := entry.ReadString('\n')
	for  err == nil {
		str, err =  entry.ReadString('\n')
		buffer.WriteString(str)
	}
	str = buffer.String()
	s.Ope = strings.Split(str, "\n")
	for i := 0; i < len(s.Ope) - 2 ; i++ {
	//	fmt.Printf("%s\n", s.Ope[i])
	}
	s.A = toSlice(stack)
	return s.A, s.B, s.Ope
}
