package com.iterator;

import java.util.ArrayList;
import java.util.List;

public class ConcreteIterator implements Iterator {
    private int current = 0;
    private ArrayList<Integer> list;

    public ConcreteIterator(ArrayList<Integer> IntList)
    {
        this.list = IntList;
    }
    @Override
    public boolean hasNext() {
        return current < list.size();
    }

    @Override
    public Integer getNext() {
        if(!hasNext())
        {
            return null;
        }
        Integer object = list.get(current);
        current++;
        return object;
    }

    @Override
    public void reset() {
        current = 0;
    }
}
