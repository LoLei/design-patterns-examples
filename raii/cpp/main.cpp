#include <iostream>
#include <mutex>
#include "noncopyable.h"

template <class T>
class AutoDeleter : NonCopyable
{
  public:
    AutoDeleter(T* p = 0) : to_delete_(p) {}
    ~AutoDeleter() throw() { delete to_delete_; }
    // throw() specifies that the destructor must not throw any exception
  private:
    T *to_delete_;
};

class ScopedLock : NonCopyable
{
  public:
    ScopedLock(std::mutex & m) : lock_(m) { lock_.lock(); }
    ~ScopedLock() throw () { lock_.unlock(); } 
  private:
    std::mutex& lock_;
};

class Resource
{
  public:
    Resource() { std::cout << "Resource acquired" << std::endl; }
    ~Resource() { std::cout << "Resource destroyed" << std::endl; }
    bool resourceMethod();
};

bool Resource::resourceMethod()
{
  std::mutex m;
  ScopedLock scoped_lock(m);
  bool sum_ting_wong = true;
  if(sum_ting_wong)
  {
    // Would return without lock released, but since the scope is ended the
    // scoped lock destuctor unlocks the lock.
    return false;
  }
  // Maybe would have released lock only now
  // m.unlock()
  return true;
};

void doSomethingWithResource()
{
  Resource *r = new Resource();
  AutoDeleter<Resource> auto_del(r);
  // Do something...
  r->resourceMethod();

  // No need to call delete, destructor of AutoDeleter will delete the Resource
  // on the heap. AutoDeleter is on the stack, stack unwinding destroys
  // objects on the stack when their scope ends (In C++)
  return;
}

int main()
{
  doSomethingWithResource();

  // TODO: Show unique_ptr and lock_guard as STL c++ idioms
  return 0;
}
