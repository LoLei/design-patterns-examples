"""
In Python there are two interfaces already built-in, the Iterable and the
Iterator. For our concrete iterators and collection, we need to implement
`__next__` and `__iter__` (`CreateIterator`).
"""
from collections.abc import Iterable, Iterator


class ConcreteIterator(Iterator):
    """
    Sample concrete iterator for the concrete collection defined below
    """
    def __init__(self, collection):
        self.collection_ = collection
        self.index_ = 0

    def __next__(self):
        try:
            next_element = self.collection_[self.index_]
            self.index_ += 1
        except IndexError:
            raise StopIteration()

        return next_element


class ConcreteCollection(Iterable):
    """
    Sample concrete collection which uses the iterator defined above
    """
    def __init__(self, collection):
        self.collection_ = collection

    def __iter__(self):
        return ConcreteIterator(self.collection_)

    def add_item(self, item_to_add):
        self.collection_.append(item_to_add)


if __name__ == "__main__":
    concrete_collection = ConcreteCollection([])
    concrete_collection.add_item(1)
    concrete_collection.add_item(2)
    concrete_collection.add_item(3)
    concrete_collection.add_item(4)
    concrete_collection.add_item(5)

    for item in concrete_collection:
        print(item)
