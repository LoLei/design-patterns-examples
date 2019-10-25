#include "linkedlistconcretecollection.h"
#include "linkedlistconcreteiterator.h"

/*
 * Concrete collection
 */
Iterator<int>* LinkedListConcreteCollection::createIterator()
{
  return new LinkedListConcreteIterator(this);
}

int LinkedListConcreteCollection::getItem(int index) const
{
  //return collection_.at(index);
  return 0;
}

int LinkedListConcreteCollection::getSize() const
{
  //return collection_.size();
  return 0;
}

void LinkedListConcreteCollection::insert(int data)
{
   struct Node* new_node = new struct Node;
   new_node->data = data; 
   new_node->next = head_; 
   head_ = new_node; 
}

struct Node* LinkedListConcreteCollection::getHead() const
{
  return head_;
}
