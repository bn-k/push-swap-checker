package main

import (
	"fmt"
	"image/color"
	"log"
	"time"
	"github.com/hajimehoshi/ebiten"
	"github.com/hajimehoshi/ebiten/ebitenutil"
	"./parser"
)

var speed time.Duration
const (
	screenWidth  = 1000
	screenHeight = 700
	margin = 30
	windowHeight = screenHeight - (margin * 2)
	windowWidth = (screenWidth - (margin * 3)) / 2
)

type Stack struct {
	A	[]line
	B	[]line
	Ope	[]string
	Done	int
	pad	float64
	thick	float64
	n	int
	slice	float64
	max	int
	K	float64
	step	int
}

type line struct {
	value	int
	rank	int
	x	float64
	y	float64
	width	float64
	sideB	int
	clr	color.Color
}

type  opeFunc func(*Stack)

type opeStruct struct {
	code		string
	function	opeFunc
}

var stk Stack
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

func Done (s *Stack) {
	if s.Ope[0] == "OK"{
		s.Done = 1
	} else {
		s.Done = -1
	}
}

func PushB (s *Stack) {
	s.B = append([]line{s.A[0]}, s.B...)
	s.A = append(s.A[1:])
}

func PushA  (s *Stack){
	s.A = append([]line{s.B[0]}, s.A...)
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
	s.B = append([]line{s.B[len(s.B) - 1]},s.B[:len(s.B) - 1]...)
}

func ReverseRotateA  (s *Stack){
	s.A = append([]line{s.A[len(s.A) - 1]},s.A[:len(s.A) - 1]...)
}

func ReverseRotateAll (s *Stack){
	ReverseRotateB(s)
	ReverseRotateA(s)
}

func (stk *Stack) init() {
	fmt.Println("init stack")
	a, ope := parser.Parser()
	stk.A = make([]line, len(a))
	stk.Ope = ope
	for i ,value := range a {
		stk.A[i].value = value
		i++
	}
}

func (stk *Stack) initMath () {
	stk.n = len(stk.A)
	stk.slice = (windowHeight) / float64(stk.n)
	stk.thick = ((stk.slice / 8) * 6)
	stk.pad = (stk.slice - stk.thick) / 2
	for i := 0 ; i < len(stk.A) ; i++ {
		stk.A[i].clr = color.White
		if stk.A[i].value < 0 {
			stk.A[i].value = -stk.A[i].value
			stk.A[i].clr = color.RGBA{0, 100, 100, 100}
		}
		if stk.max < stk.A[i].value {
			stk.max = stk.A[i].value
		}
	}
	stk.K = float64(windowWidth) / float64(stk.max)
	fmt.Println(stk.K)
}

func updateGeoData(stk *Stack) {
	for i := range stk.A {
		stk.A[i].width = float64(stk.A[i].value) * stk.K + 3
		stk.A[i].x = (windowWidth - stk.A[i].width) / 2 + margin
		stk.A[i].y = float64(i) * stk.slice + margin
	}
	for i := range stk.B {
		stk.B[i].width = float64(stk.B[i].value) * stk.K + 3
		stk.B[i].x = (windowWidth - stk.B[i].width) / 2 + margin + windowWidth + margin
		stk.B[i].y = float64(i) * stk.slice + margin
	}
}

func draw(stk *Stack, screen *ebiten.Image) {
	for i := range stk.A {
		ebitenutil.DrawRect(screen, stk.A[i].x, stk.A[i].y, stk.A[i].width, stk.thick, stk.A[i].clr)
	}
	for i := range stk.B {
		ebitenutil.DrawRect(screen, stk.B[i].x, stk.B[i].y, stk.B[i].width, stk.thick, stk.B[i].clr)
	}
}

func update(screen *ebiten.Image) error {
	if stk.Done == 0 {
		stk.step++
		select {
		case <-time.After(speed * time.Millisecond):
			browse(&stk)
			updateGeoData(&stk)
			draw(&stk, screen)
		}
	}
	if stk.Done == 1 || stk.Done == -1 {
			draw(&stk, screen)
	}
	if ebiten.IsRunningSlowly() {
		return nil
	}
	ebitenutil.DebugPrint(screen, fmt.Sprintf("  FPS: %0.2f Step = %d", ebiten.CurrentFPS(), stk.step))
	return nil
}

func main() {
	speed = 0
	stk.init()
	stk.initMath()
	if err := ebiten.Run(update, screenWidth, screenHeight, 1, "ViewStack"); err != nil { log.Fatal(err)}
}
