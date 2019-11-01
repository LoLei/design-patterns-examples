package main

import "fmt"

func main() {
	array := []interface{}{1, 2, 3, 4, 5}
        array_concrete_container := ArrayConcreteContainer{array}

	iterator := array_concrete_container.CreateIterator()

	for it := iterator; !iterator.IsDone(); iterator.Next() {
          fmt.Println(it.CurrentItem())
	}
}
