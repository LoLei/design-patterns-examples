/**
 * Prevents copying via private copy constructor 
 * and private assignment operator (pre-C++11 explanation)
 */
class NonCopyable 
{
  public:
    // https://docs.microsoft.com/en-us/cpp/cpp/explicitly-defaulted-and-deleted-functions
    // =default specifies to the compiler to generate the default body/implementation
    NonCopyable() =default;

    // =delete disables the function, similar to private (pre-C++11), but more thoroughly and efficiently
    NonCopyable(const NonCopyable &) =delete;
    NonCopyable & operator = (const NonCopyable &) =delete;
};
