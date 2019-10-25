#include "arrayconcretecollection.h"
#include "arrayconcreteiterator.h"

/*
 * Concrete collection
 */
Iterator<int>* ArrayConcreteCollection::createIterator()
//Enumerable createIterator()
//ArrayConcreteIterator* ArrayConcreteCollection::createIterator()
{
  return new ArrayConcreteIterator(this);
  //return Enumerable();
}

int ArrayConcreteCollection::getItem(int index) const
{
  return collection_.at(index);
}

int ArrayConcreteCollection::getSize() const
{
  return collection_.size();
}

void ArrayConcreteCollection::addItems(int items[])
{
  collection_[0] = items[0];
  collection_[1] = items[1];
  collection_[2] = items[2];
  collection_[3] = items[3];
  collection_[4] = items[4];
}
