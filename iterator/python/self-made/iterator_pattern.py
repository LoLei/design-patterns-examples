from collections.abc import Iterable, Iterator


class ConcreteIterator(Iterator):
    def __init__(self, collection):
        self._collection = collection
        self._position = 0

    def __next__(self):
        try:
            next_element = self._collection[self._position]
            self._position += 1
        except IndexError:
            raise StopIteration()

        return next_element


class ConcreteCollection(Iterable):
    def __init__(self, collection):
        self._collection = collection

    def __iter__(self):
        return ConcreteIterator(self._collection)

    def add_item(self, item):
        self._collection.append(item)


if __name__ == "__main__":
    concrete_collection = ConcreteCollection([])
    concrete_collection.add_item(1)
    concrete_collection.add_item(2)
    concrete_collection.add_item(3)
    concrete_collection.add_item(4)
    concrete_collection.add_item(5)

    for item in concrete_collection:
        print(item)
