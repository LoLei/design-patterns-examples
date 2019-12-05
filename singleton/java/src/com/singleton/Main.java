package com.singleton;

public class Main {

    public static void main(String[] args) {
        Singleton singleton1 = Singleton.Instance();

        System.out.println("Member: " + singleton1.member);

        singleton1.member++;

        Singleton singleton2 = Singleton.Instance();

        System.out.println("Member: " + singleton2.member);
    }
}
