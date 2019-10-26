#ifndef ITERATOR_H
#define ITERATOR_H

/*
 * Iterator interface
 */
template <class T>
class Iterator
{
  public:
    virtual void next() = 0;
    virtual void reset() = 0;
    virtual bool isDone() = 0;
    virtual T currentItem() = 0;
};

#endif
