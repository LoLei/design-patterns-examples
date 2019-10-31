#include <iostream>
#include <array>

/*
 * A few ways to iterate over multiple containers
 */
int main()
{
  std::array<int, 3> container_1 = {10, 11, 12};
  std::array<int, 3> container_2 = {20, 21, 22};

  // The most naive way, using a counter and index access (Ideally, one should
  // also check before which container contains fewer elements, and stop there)
  for (size_t i = 0; i < container_1.size(); ++i)
  {
    std::cout << container_1.at(i) << " " << container_2.at(i) << std::endl;
  }
  std::cout << std::endl;

  // Using STL iterators
  std::array<int, 3>::iterator it_1;
  std::array<int, 3>::iterator it_2;
  for(it_1 = container_1.begin(),
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

  return 0;
}
