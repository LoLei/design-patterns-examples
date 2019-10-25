#include "linkedlistconcretecollection.h"
#include "linkedlistconcreteiterator.h"

/*
 * Concrete collection
 */
LinkedListConcreteCollection::LinkedListConcreteCollection()
{
  head_ = new struct Node();
  head_->data = 0;
  head_->next = nullptr;
}

Iterator<int>* LinkedListConcreteCollection::createIterator()
{
  return new LinkedListConcreteIterator(this);
}

int LinkedListConcreteCollection::getItem(int index) const
{
  // TODO: Either implement or remove
  return 0;
}

int LinkedListConcreteCollection::getSize() const
{
  // TODO: Either implement or remove
  return 0;
}

void LinkedListConcreteCollection::insert(int data)
{
   struct Node* new_node = new struct Node();
   new_node->data = data; 
   new_node->next = head_; 
   head_ = new_node; 
}

struct Node* LinkedListConcreteCollection::getHead() const
{
  return head_;
}
