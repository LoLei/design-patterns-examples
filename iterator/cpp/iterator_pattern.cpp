#include <iostream>
#include <array>
#include "arrayconcretecollection.h"
#include "arrayconcreteiterator.h"

int main()
{
  ArrayConcreteCollection my_custom_array;
  int items_to_add[5] = {1, 2, 3, 4, 5};
  my_custom_array.addItems(items_to_add);

  Iterator<int>* my_custom_array_iterator = my_custom_array.createIterator();
  while(!my_custom_array_iterator->isDone())
  {
    my_custom_array_iterator->next();
    std::cout << my_custom_array_iterator->currentItem() << std::endl;
  }

  // TODO: Create different container
  return 0;
}
