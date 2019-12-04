#include <iostream>

class Singleton
{
  public:
    static Singleton& getInstance()
    {
      // Static member is initialized on first use and re-used 
      // on every subsequent use (Lazy initialization / Meyer's Singleton)
      static Singleton instance;
      return instance;
    }
  private:
    Singleton() {} // Private constructor - Access only granted via getInstance

    // Same as private, but better (C++ 11)
    // Delete disables the use of the function, compiler does not generate
    // code, friends cannot access.
    // Can be public since it's disabled anyway,
    // produces better error messages
    // See RAII example NonCopyable class for similar usage
  public:
    Singleton(Singleton const&) =delete;
    void operator=(Singleton const&) =delete;

    // Member variable to test functionality
    int member_ = 0;
};

int main()
{
  Singleton& s1 = Singleton::getInstance();
  std::cout << "Member value in s1: " << s1.member_ << std::endl;

  s1.member_++;

  Singleton& s2 = Singleton::getInstance();
  std::cout << "Member value in s2: " << s2.member_ << std::endl;

  return 0;
}
