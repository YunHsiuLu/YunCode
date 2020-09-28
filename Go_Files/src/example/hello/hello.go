package main

import (
	"errors"
	"fmt"
	"math"
)

func main() {
	// try print line
	fmt.Println("Hello, World!")
	// try define and addition
	x := 5
	y := 7
	sum := x + y
	fmt.Println("sum is:")
	fmt.Println(sum)
	// try arrays
	a := []int{}
	a = append(a, 13)
	fmt.Println("array is:")
	fmt.Println(a)
	// try maps
	vertices := make(map[string]int)
	vertices["triangles"] = 3
	vertices["squares"] = 2
	vertices["stars"] = 5
	fmt.Println("map is:")
	fmt.Println(vertices["stars"])
	// delete function
	delete(vertices, "squares")
	fmt.Println("delete something:")
	fmt.Println(vertices)
	// try for loop
	fmt.Println("for loop test:")
	for i := 0; i < 5; i++ {
		fmt.Printf("%v ", i)
	}
	fmt.Println()
	// try while loop (same as for loop)
	fmt.Println("while loop test:")
	c := 0
	for c < 5 {
		fmt.Printf("%d ", c)
		c++
	}
	fmt.Println()
	// try for loop with element
	fmt.Println("for loop with elements:")
	arr := []string{"a", "b", "c"}
	for index, value := range arr {
		fmt.Println("index:", index, "value:", value)
	}
	// test function
	fmt.Println("test function (sqrt):")
	result, err := sqrt(16)
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println(result)
	}
	// point the place
	fmt.Println("print address:")
	addr := 7
	fmt.Println(&addr)
	// pointer
	fmt.Println("test pointer")
	pointer := 7
	// if do inc(pointer) and func inc without *, there does nothing
	inc(&pointer)
	fmt.Println(pointer)
}

func sqrt(x float64) (float64, error) {
	if x < 0 {
		return 0, errors.New("Undefine for negative numbers")
	}
	return math.Sqrt(x), nil
}

func inc(x *int) {
	*x++
}
