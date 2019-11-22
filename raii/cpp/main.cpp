#include <iostream>
#include <mutex>
#include <memory>
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
  // Also since this method is a member function it might also return early
  // due to the object to which the method belongs being destroyed
  
  // Maybe would have released lock only now
  // m.unlock()
  return true;
};

/**
 * Example showing own implementation of auto deletion and scoped lock
 */
void selfMadeExample()
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

/**
 * Example showing C++'s STL idioms of handling auto deletion and scoped locking
 * std::unique_ptr, std::shared_ptr
 * std::lock_guard
 */
void stlExample()
{
  // unique_ptr will delete the resource it is managing when it goes out of
  // scope
  std::unique_ptr<Resource> res(new Resource);

  std::mutex m;
  // lock_guard releases the mutex when it goes out of scope
  std::lock_guard<std::mutex> lk(m);
  return;
}

int main()
{
  selfMadeExample();
  stlExample();

  return 0;
}
