#include <iostream>
#include <array>
#include <boost/range/combine.hpp>

/*
 * A few ways to iterate over multiple containers
 */
int main()
{
  std::array<int, 3> container_1 = {10, 11, 12};
  std::array<int, 3> container_2 = {20, 21, 22};

  // The most naive way, using a counter and index access
  for (size_t i = 0; i < container_1.size() && i < container_2.size(); ++i)
  {
    std::cout << container_1.at(i) << " " << container_2.at(i) << std::endl;
  }
  std::cout << std::endl;

  // Using STL iterators
  std::array<int, 3>::iterator it_1;
  std::array<int, 3>::iterator it_2;
  for (it_1 = container_1.begin(),
      it_2 = container_2.begin();
      it_1 != container_1.end() &&
      it_2 != container_2.end();
      ++it_1, ++it_2)
  {
    std::cout << *it_1 << " " << *it_2 << std::endl;
  }
  std::cout << std::endl;

  // A little simpler with auto
  for (auto it_1 = container_1.begin(),
            it_2 = container_2.begin();
      it_1 != container_1.end() &&
      it_2 != container_2.end();
      ++it_1, ++it_2)
  {
    std::cout << *it_1 << " " << *it_2 << std::endl;
  }
  std::cout << std::endl;

  // A common anti-pattern: The "shitty iterator", which is a counter to access
  // elements of other containers
  size_t shitty_iterator = 0;
  for (const auto& it : container_1)
  {
    std::cout << it << " " << container_2.at(shitty_iterator) << std::endl;
    shitty_iterator++;
  }
  std::cout << std::endl;

  // C++ does not have built-in zip-like functionality (as seen in the Python
  // example), but Boost offers similar functionality via `boost::combine()`,
  // which uses Boosts's `zip_iterator` internally
  for (const auto&& combined_iterator : boost::combine(container_1, container_2))
  {
    std::cout << combined_iterator.get<0>() << " " 
              << combined_iterator.get<1>() << std::endl;
  }

  return 0;
}
