package main

import "fmt"

func main() {
	my_array := []interface{}{1, 2, 3, 4, 5}
        array_concrete_container := ArrayConcreteContainer{my_array}

	iterator := array_concrete_container.CreateIterator()

	for it := iterator; !iterator.IsDone(); iterator.Next() {
          fmt.Println(it.CurrentItem())
	}
}
