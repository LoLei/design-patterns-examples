package com.iterator;

import java.util.ArrayList;

public class ConcreteCollection implements Collection {
    private ArrayList<Integer> listCollection;
    public ConcreteCollection()
    {
        listCollection = new ArrayList<>();
    }
    public void addItem(int element)
    {
        listCollection.add(element);
    }

    public Iterator createIterator() {
        return new ConcreteIterator(this);
    }
    public ArrayList<Integer> getItems()
    {
        return listCollection;
    }
}
