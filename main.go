package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	buf := bufio.NewReader(os.Stdin)
	read, _ := buf.ReadString('\n')
	fmt.Println(read)
}
