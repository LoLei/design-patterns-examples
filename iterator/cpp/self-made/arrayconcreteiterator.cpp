#include "arrayconcreteiterator.h"

/*
 * Concrete iterator
 */
ArrayConcreteIterator::ArrayConcreteIterator(const ArrayConcreteCollection* c)
{
  reset();
  collection_ = c;
}

void ArrayConcreteIterator::next()
{
  current_index_++;
}

void ArrayConcreteIterator::reset()
{
  current_index_ = 0;
}

bool ArrayConcreteIterator::isDone()
{
  return current_index_ == collection_->getSize();
}

int ArrayConcreteIterator::currentItem()
{
  return collection_->getItem(current_index_);
}
