#include <iostream>
#include <array>
#include "arrayconcretecollection.h"
#include "arrayconcreteiterator.h"
#include "linkedlistconcretecollection.h"
#include "linkedlistconcreteiterator.h"

int main()
{
  // Use custom array container
  std::cout << "#### Array container" << std::endl;
  ArrayConcreteCollection my_custom_array;
  int items_to_add[5] = {1, 2, 3, 4, 5};
  my_custom_array.addItems(items_to_add);

  Iterator<int>* my_custom_array_iterator = my_custom_array.createIterator();
  while(!my_custom_array_iterator->isDone())
  {
    std::cout << my_custom_array_iterator->currentItem() << std::endl;
    my_custom_array_iterator->next();
  }

  // Use custom linked list container
  std::cout << "#### Linked list container" << std::endl;
  LinkedListConcreteCollection my_custom_linked_list;
  my_custom_linked_list.insert(5);
  my_custom_linked_list.insert(4);
  my_custom_linked_list.insert(3);
  my_custom_linked_list.insert(2);
  my_custom_linked_list.insert(1);

  Iterator<int>* my_custom_linked_list_iterator = my_custom_linked_list.createIterator();
  while(!my_custom_linked_list_iterator->isDone())
  {
    std::cout << my_custom_linked_list_iterator->currentItem() << std::endl;
    my_custom_linked_list_iterator->next();
  }

  return 0;
}
