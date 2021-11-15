/*
This program doesnt really have a definite thing to do.
I was just playing around with different methods and functions.
*/

package main

import (
	"fmt"
	"log"
	"os"
)

func main() {
	a()
	b()
}

func a() {
	d, _ := os.Getwd()
	fmt.Println("current dir is:", d)

	f, err := os.Create("test.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	l, err := f.WriteString("Hello World")
	if err != nil {
		fmt.Println(err)
		f.Close()
		return
	}
	fmt.Println(l, "bytes written successfully")

	p, err := f.Seek(0, 1)
	fmt.Println("current position in file", p)
	p, _ = f.Seek(5, 0)
	f.WriteString(",")
	p, _ = f.Seek(0, 1)
	fmt.Println("current position in file", p)
	_, _ = f.Seek(0, 2)
	fmt.Fprintln(f, "! blah!")

	err = f.Close()
	if err != nil {
		fmt.Println(err)
		return
	}
}

func b() {
	file, err := os.Open("file.go") // For read access.
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

}
