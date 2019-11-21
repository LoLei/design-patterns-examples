"""
Small example on Python's built-in iterator for its built-in collections
"""

if __name__ == "__main__":
    # List and set and other built-in containers implement the `Iterable`
    # interface
    # (/usr/lib/python3.7/_collections_abc.py)
    list_1 = [1, 2, 3, 4, 5]
    for item in list_1:
        print(item)

    set_1 = set(list_1)
    for item in set_1:
        print(item)
