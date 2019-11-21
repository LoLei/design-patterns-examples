"""
Often you want to iterate through multiple containers at the same time, this
shows a few ways to do this
"""
if __name__ == "__main__":
    container_1 = [10, 11, 12]
    container_2 = [20, 21, 22]

    # The most basic way is just a for loop over the length of the containers,
    # using index access:
    for i in range(len(container_1)):
        print(container_1[i])
        print(container_2[i])

    print("--")

    # A commonly used anti-pattern would be what a few people might call a
    # "shitty iterator", which is a manual counter used to access the
    # second container:
    shitty_iterator = 0
    for item in container_1:
        print(item)
        print(container_2[shitty_iterator])
        shitty_iterator += 1

    print("--")

    # Python at least lets you create this counter automatically with
    # `enumerate`:
    for i, item in enumerate(container_1):
        print(item)
        print(container_2[i])

    print("--")

    # Even better, Python has a built-in zip function, which offers an iterator
    # of tuples:
    for item_1, item_2 in zip(container_1, container_2):
        print(item_1)
        print(item_2)
    # This stops when the end of the container with fewer items is reached.
    # `zip_longest` exists to go until the longer end is reached.
