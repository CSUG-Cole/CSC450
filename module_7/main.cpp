#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

/* ThreadSafeCounter class to handle counting up and down */
class ThreadSafeCounter {
private:
    int count;
    std::mutex mtx; /* Protects count and countUpComplete */
    std::condition_variable cv;
    bool countUpComplete;

public:
    ThreadSafeCounter() : count(0), countUpComplete(false) {}

    /* Thread-safe function to increment counter */
    void countUp() {
        for (int i = 0; i <= 20; i++) {
            {
                std::unique_lock<std::mutex> lock(mtx);
                count = i;
                std::cout << "Counting up: " << count << std::endl;
            }
        }

        {
            std::lock_guard<std::mutex> lock(mtx);
            countUpComplete = true;
            cv.notify_one();
        }
    }

    /* Thread-safe function to decrement counter */
    void countDown() {
        /* Wait for countUp to finish before counting down using `condition_variable` */
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return countUpComplete; });

        while (count > 0) {
            count--;
            std::cout << "Counting down: " << count << std::endl;
        }
    }
};

auto
main(int argc, char *argv[]) -> int
{
    ThreadSafeCounter counter;

    /* Create threads to count up and count down */
    std::thread t1(&ThreadSafeCounter::countUp, &counter);
    std::thread t2(&ThreadSafeCounter::countDown, &counter);

    /* Wait for threads to complete counting */
    t1.join();
    t2.join();

    return 0;
}
