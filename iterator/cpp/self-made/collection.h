#ifndef COLLECTION_H
#define COLLECTION_H

#include "iterator.h"

/*
 * Collection interface
 */
template <class T>
class Collection
{
  public:
    virtual Iterator<T>* createIterator() = 0;
};

#endif
