/*
Again, name of folder is pretty self-explanatory.
This program gets user input (a number) and doubles it.
*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func double(number *int) {
	*number *= 2
	fmt.Println("doubled value:", *number)
}

func main() {

	fmt.Print("enter an amount: ")
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}

	input = strings.TrimSpace(input)
	amount, err := strconv.Atoi(input)
	if err != nil {
		log.Fatal(err)
	}

	double(&amount)

}

//Yay it works !
