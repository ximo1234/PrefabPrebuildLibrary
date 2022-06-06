package com.example.mylib;

public class myJavaClass {
    static {
        System.loadLibrary("mylib");
    }
    native public static int myPublicJavaMethod();
}
