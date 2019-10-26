#ifndef LINKEDLISTCONCRETEITERATOR_H
#define LINKEDLISTCONCRETEITERATOR_H

#include "iterator.h"
#include "linkedlistconcretecollection.h"

class LinkedListConcreteCollection;

/*
 * Concrete iterator
 */
class LinkedListConcreteIterator : public Iterator<int>
{
  private:
    struct Node* current_item_;
    const LinkedListConcreteCollection* collection_;

  public:
    LinkedListConcreteIterator(const LinkedListConcreteCollection* c);
    void next();
    void reset();
    bool isDone();
    int currentItem();
};

#endif
