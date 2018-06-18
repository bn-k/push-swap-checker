package parser

import (
	"os"
	"bufio"
	"bytes"
	"strings"
	"strconv"
)

type Stack struct {
	A		[]int
	Ope		[]string
}

func toSlice (s string) []int {
	var tab []int
	var tmp []string

	tmp = strings.Split(strings.Trim(s, "\n"), " ")
	tab = make([]int, len(tmp))
	for i := range tmp  {
		tab[i], _ = strconv.Atoi(tmp[i])
	}
	return tab
}

func Parser () ([]int, []string) {
	var buffer	bytes.Buffer
	var str		string
	var s		Stack

	entry := bufio.NewReader(os.Stdin)
	stack, err := entry.ReadString('\n')
	for  err == nil {
		str, err =  entry.ReadString('\n')
		buffer.WriteString(str)
	}
	str = buffer.String()
	s.Ope = strings.Split(str, "\n")
	s.A = toSlice(stack)
	return s.A, s.Ope
}
