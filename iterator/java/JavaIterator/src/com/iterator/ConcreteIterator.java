package com.iterator;

import java.util.ArrayList;

public class ConcreteIterator implements Iterator {
    private int current = 0;
    private ConcreteCollection collection;

    public ConcreteIterator(ConcreteCollection collection)
    {
       this.collection = collection;
    }
    @Override
    public boolean hasNext() {
        return current < collection.getItems().size();
    }

    @Override
    public Integer getNext() {
        if(!hasNext())
        {
            return null;
        }
        Integer object = collection.getItems().get(current);
        current++;
        return object;
    }

}
