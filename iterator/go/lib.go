package main

// ----------------------------------------------------------------------------
// Interfaces

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

// ----------------------------------------------------------------------------
// Concrete classes: Concrete aggregate, concrete iterator

// Concrete aggregate/container (Array-like)
type ArrayConcreteContainer struct {
  array []interface{}
}

// In Go one just needs to implement all methods of the interface in the
// concrete class, no special `Interface` syntax needed in the class declaration
// above
func (c *ArrayConcreteContainer) CreateIterator() Iterator {
  return &ArrayConcreteIterator{*c, 0}
}

// ----------------------------------------------------------------------------

// Concrete iterator (For concrete array-like container)
type ArrayConcreteIterator struct {
  container ArrayConcreteContainer
  current_index int
}

// Again implement all methods of the interface
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
