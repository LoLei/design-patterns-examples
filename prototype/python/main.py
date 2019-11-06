"""
Python already offers the cloning capability via the copy module, so you do
not need to define the alternative prototype constructor for each class that
implements the prototype
"""
import copy # Could use copy.deepcopy instead of copy.copy, which is shallow


class Prototype:
    """
    This could e.g. be an abstract "Shape" class, while the concrete prototypes
    below implement e.g. "Rectangle" and "Circle"
    """
    type_ = None
    primitive_ = None

    def clone(self):
        pass

    def get_info(self):
        return self.type_, self.primitive_


class ConcretePrototype1(Prototype):
    def __init__(self, number):
        self.type_ = "t1"
        self.primitive_ = number

    # def __init__prototype_clone__(self, source):
        # super(source) # Needed if super class has private fields that apply to all
        # child classes
        # self.type_ = source.type_
        # self.primitive_ = source.primitive_

    def clone(self):
        """
        This returns a new object with the members set to the primitives of the
        source object, done in the copy module. Otherwise one would have to
        create an alternate prototype constructor, which copies all the fields,
        similar to what's shown above
        """
        # return new ConcretePrototype1(self)::__init_prototype_clone__
        return copy.copy(self)


class ConcretePrototype2(Prototype):
    def __init__(self, number):
        self.type_ = "t2"
        self.primitive_ = number

    def clone(self):
        return copy.copy(self)


if __name__ == "__main__":
    objects = []
    object_t1_1 = ConcretePrototype1(314)
    objects.append(object_t1_1)
    object_t1_2 = object_t1_1.clone()
    objects.append(object_t1_2)
    object_t2_1 = ConcretePrototype2(1337)
    objects.append(object_t2_1)
    object_t2_2 = object_t2_1.clone()
    objects.append(object_t2_2)

    print("Manually created and cloned objects: ")
    for concrete_prototype in objects:
        t, p = concrete_prototype.get_info()
        print("{}, {}".format(t, p))

    # Now we will clone objects with different types, without even knowing what
    # the types are. Working, because each concrete prototype implements its
    # own clone() method
    cloned_objects = []
    for concrete_prototype in objects:
        cloned_objects.append(concrete_prototype.clone())

    print("Cloned objects without knowing exact types: ")
    for concrete_prototype in cloned_objects:
        t, p = concrete_prototype.get_info()
        print("{}, {}".format(t, p))
