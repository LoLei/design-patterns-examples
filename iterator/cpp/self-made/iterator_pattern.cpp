#include <iostream>
#include <array>
#include "arrayconcretecollection.h"
#include "arrayconcreteiterator.h"
#include "linkedlistconcretecollection.h"
#include "linkedlistconcreteiterator.h"

int main()
{
  // Use custom array container
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
  LinkedListConcreteCollection my_custom_linked_list;
  my_custom_linked_list.insert(1);
  my_custom_linked_list.insert(2);
  my_custom_linked_list.insert(3);
  my_custom_linked_list.insert(4);
  my_custom_linked_list.insert(5);

  std::cout << "LL insertion finished." << std::endl;

  Iterator<int>* my_custom_linked_list_iterator = my_custom_linked_list.createIterator();
  std::cout << "Before loop" << std::endl;
  while(!my_custom_linked_list_iterator->isDone())
  {
    std::cout << "Loop iteration" << std::endl;
    std::cout << my_custom_linked_list_iterator->currentItem() << std::endl;
    my_custom_array_iterator->next();
  }

  std::cout << "LL traversal finished." << std::endl;

  return 0;
}
