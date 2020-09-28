package main

import (
	funcs "example/testfuncs/examplefuncs"
	"fmt"
)

func main() {
	fmt.Println("Test function from other files")
	result := funcs.Sum(6.4, 17.3)
	fmt.Println(result)
	fmt.Println("testing:", funcs.S)
}
