package com.csc450.module_8;

class ThreadSafeCounter {
    private int count = 0;
    private boolean countUpComplete = false;

    // Method for counting up
    public synchronized void countUp() {
        for (int i = 0; i <= 20; i++) {
            count = i;
            System.out.println("Counting up: " + count);
        }
        countUpComplete = true;
        notify(); // Notify the waiting thread
    }

    // Method for counting down
    public synchronized void countDown() {
        while (!countUpComplete) {
            try {
                wait(); // Wait for countUp to complete
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.err.println("Thread interrupted: " + e.getMessage());
            }
        }
        while (count > 0) {
            count--;
            System.out.println("Counting down: " + count);
        }
    }
}

