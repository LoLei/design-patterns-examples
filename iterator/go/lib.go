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
  array_ []interface{}
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
  container_ ArrayConcreteContainer
  current_index_ int
}

// Again implement all methods of the interface
func (i *ArrayConcreteIterator) First() {
  i.current_index_ = 0
}

func (i *ArrayConcreteIterator) CurrentItem() interface{} {
  return i.container_.array_[i.current_index_]
}

func (i *ArrayConcreteIterator) IsDone() bool {
  return i.current_index_ == len(i.container_.array_)
}

func (i *ArrayConcreteIterator) Next() {
  if !i.IsDone() {
    i.current_index_++
  }
}
