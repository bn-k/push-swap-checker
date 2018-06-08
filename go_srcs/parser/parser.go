package parser

import (
	//"log"
	"os"
	//"path/filepath"
	"bufio"
	"fmt"
	//"io"
)

func Parser () {
	fmt.Printf("===========Parser============\n")
	entry := bufio.NewReader(os.Stdin)
	str ,err := entry.ReadString('\n')
		fmt.Printf("%s", str)
	for ; err == nil; {
		str ,err =  entry.ReadString('\n')
		fmt.Printf("%s", str)
	}
}
