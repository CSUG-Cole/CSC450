package com.csc450.module_8;

public class CounterDemo {
    public static void main(String[] args) {
        ThreadSafeCounter counter = new ThreadSafeCounter();

        // Create and start threads
        Thread t1 = new Thread(counter::countUp);
        Thread t2 = new Thread(counter::countDown);

        t1.start();
        t2.start();

        // Wait for threads to complete
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            System.err.println("Main thread interrupted: " + e.getMessage());
        }
    }
}
