#ifndef ARRAYCONCRETECOLLECTION_H
#define ARRAYCONCRETECOLLECTION_H

#include <array>
#include "collection.h"
#include "arrayconcreteiterator.h"
/*
 * Concrete collection
 */
class ArrayConcreteCollection : public Collection<int>
{
  private:
    std::array<int, 5> collection_;
  public:
    Iterator<int>* createIterator();

    int getItem(int index) const;
    int getSize() const;
    void addItems(int items[]);
};

#endif
