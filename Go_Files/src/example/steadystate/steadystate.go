package main

import (
	"fmt"
)

func main() {
	fmt.Printf("Hello\n")
	pMat := [][]float64{{0.95, 0.6}, {0.05, 0.4}}
	CalMatSteady(pMat)
}

func CalMatSteady(mat [][]float64) {
	var n int = 0
	n = len(mat)
	newMat := make([][]float64, n)
	for i := 0; i < n; i++ {
		newMat[i] = make([]float64, n)
	}
	counter := 0
	for counter < 5 {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				for c := 0; c < n; c++ {
					newMat[i][j] += mat[i][c] * mat[c][j]
				}
			}
		}
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				mat[i][j] = newMat[i][j]
			}
			newMat[i] = make([]float64, n)
		}
		counter++
	}
	fmt.Println(mat)
}
