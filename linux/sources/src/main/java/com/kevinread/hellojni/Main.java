package com.kevinread.hellojni;

public class Main {

    static {
        //System.loadLibrary("hybris-common");
    }

    public static void main(String[] args) {
        System.out.println("Loading bridge");
        System.load("/usr/local/lib/libHelloJniBridge.so.1.0.1");
        System.out.println("Bridge loaded");
        final HelloJni helloJni = new HelloJni();
        System.out.println(helloJni.stringFromJNI());
    }
}
