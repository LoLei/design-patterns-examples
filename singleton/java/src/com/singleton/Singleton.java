package com.singleton;

public class Singleton {
    // Eager initialization
    private static final  Singleton instance = new Singleton();

    private Singleton() {}
    public int member = 0;

    public static Singleton Instance()
    {
        return Singleton.instance;
    }
}
