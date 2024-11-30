package com.csc450.module_8;

class ThreadSafeCounter {
    private int count = 0;

    // Method for counting up
    public synchronized void countUp() {
        for (int i = 0; i <= 20; i++) {
            count = i;
            System.out.println("Counting up: " + count);
        }
    }

    // Method for counting down
    public synchronized void countDown() {
        while (count > 0) {
            count--;
            System.out.println("Counting down: " + count);
        }
    }
}

