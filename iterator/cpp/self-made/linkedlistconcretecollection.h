#ifndef LINKEDLISTCONRETECOLLECTION_H
#define LINKEDLISTCONRETECOLLECTION_H

#include "collection.h"
#include "linkedlistconcreteiterator.h"
/*
 * Concrete collection
 */

struct Node
{ 
   int data; 
   struct Node *next; 
}; 

class LinkedListConcreteCollection : public Collection<int>
{
  private:
    struct Node* head_;
  public:
    Iterator<int>* createIterator();

    int getItem(int index) const;
    int getSize() const;
    void insert(int data);
    struct Node* getHead() const;
};

#endif
