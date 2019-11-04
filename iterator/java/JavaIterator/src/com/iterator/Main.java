package com.iterator;
import com.iterator.ConcreteIterator;
import com.iterator.ConcreteCollection;
public class Main {
    public static void main(String[] args) {
        ConcreteCollection coll = new ConcreteCollection();

        coll.addItem(1);
        coll.addItem(2);
        coll.addItem(3);
        coll.addItem(4);
        coll.addItem(5);

        Iterator it = coll.createIterator();
        while(it.hasNext()){
            Object number = it.getNext();
            System.out.println("Number: " + (int)number);
        }
    }
}
