package main

// Iterator interface
type Iterator interface {
  First()
  CurrentItem() interface{}
  IsDone() bool
  Next()
}

// Aggegrate interface
type Aggregate interface {
  CreateIterator() Iterator
}

// Concrete container (Array-like)
type ArrayConcreteContainer struct {
  array []interface{}
}

func (c *ArrayConcreteContainer) CreateIterator() Iterator {
  return &ArrayConcreteIterator{*c, 0}
}

// Concrete iterator (For concrete array-like container)
type ArrayConcreteIterator struct {
  container ArrayConcreteContainer
  current_index int
}

func (i *ArrayConcreteIterator) First() {
  i.current_index = 0
}

func (i *ArrayConcreteIterator) CurrentItem() interface{} {
  return i.container.array[i.current_index]
}

func (i *ArrayConcreteIterator) IsDone() bool {
  return i.current_index == len(i.container.array)
}

func (i *ArrayConcreteIterator) Next() {
  if !i.IsDone() {
    i.current_index++
  }
}
