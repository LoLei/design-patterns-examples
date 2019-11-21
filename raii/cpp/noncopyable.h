/**
 * Prevents copying via private copy constructor 
 * and private assignment operator
 */
class NonCopyable 
{
  public:
    NonCopyable();
  private:
    NonCopyable(const NonCopyable &);
    NonCopyable & operator = (const NonCopyable &);
};
