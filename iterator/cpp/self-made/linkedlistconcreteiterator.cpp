#include "linkedlistconcreteiterator.h"

/*
 * Concrete iterator
 */
LinkedListConcreteIterator::LinkedListConcreteIterator(const LinkedListConcreteCollection* c)
{
  collection_ = c;
  reset();
}

void LinkedListConcreteIterator::next()
{
  current_item_ = current_item_->next;
}

void LinkedListConcreteIterator::reset()
{
  current_item_ = collection_->getHead();
}

bool LinkedListConcreteIterator::isDone()
{
  return current_item_->next == nullptr;
}

int LinkedListConcreteIterator::currentItem()
{
  return current_item_->data;
}
