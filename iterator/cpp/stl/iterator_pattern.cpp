#include <array>
#include <iostream>
#include <list>

int main()
{
  // STL Array
  std::cout << "#### Array container" << std::endl;

  // Create STL array (Concrete collection)
  std::array<int, 5> stl_array = {1, 2, 3, 4, 5};

  // Create STL array iterator (Concrete iterator pertaining to STL array)
  std::array<int, 5>::iterator stl_array_it;

  // Use standard iterator interface mechanisms independent of underlying container
  for (stl_array_it = stl_array.begin();      // like `first()`/`reset()`
      stl_array_it != stl_array.end();        // like `isDone()`
      ++stl_array_it)                         // like `next()`
  {
    std::cout << *stl_array_it << std::endl;  // like `currentItem()`
  }

  // STL List (Doubly linked list)
  std::cout << "#### List container" << std::endl;

  // Same functionality for a different container
  std::list<int> stl_list;
  stl_list.push_back(1);
  stl_list.push_back(2);
  stl_list.push_back(3);
  stl_list.push_back(4);
  stl_list.push_back(5);

  std::list<int>::iterator stl_list_it;

  for (stl_list_it = stl_list.begin();      // like `reset()`
      stl_list_it != stl_list.end();        // like `isDone()`
      ++stl_list_it)                        // like `next()`
  {
    std::cout << *stl_list_it << std::endl; // like `currentItem()`
  }

  // Auto
  std::cout << "#### Auto iterator" << std::endl;

  // The container type can be left blank via auto, which deduces the type
  for (auto it : stl_array)
  {
    std::cout << it << std::endl;
  }
  std::cout << std::endl;

  // Even better, if you don't want to change the values, just read them, and
  // avoid copying as well:
  // `&` just gets a reference to the actual element in the container instead of
  // copying it
  // `const` prohibits changing the original value (Leave this if you want to
  // change the original values)
  for (const auto &it : stl_array)
  {
    std::cout << it << std::endl;
  }

  // Without auto, you can also use the `const_iterator` for concrete containers
  // of which the type is given

  return 0;
}
