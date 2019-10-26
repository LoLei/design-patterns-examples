#ifndef ARRAYCONCRETEITERATOR_H
#define ARRAYCONCRETEITERATOR_H

#include "iterator.h"
#include "arrayconcretecollection.h"

class ArrayConcreteCollection;

/*
 * Concrete iterator
 */
class ArrayConcreteIterator : public Iterator<int>
{
  private:
    int current_index_;
    const ArrayConcreteCollection* collection_;

  public:
    ArrayConcreteIterator(const ArrayConcreteCollection* c);
    void next();
    void reset();
    bool isDone();
    int currentItem();
};

#endif
