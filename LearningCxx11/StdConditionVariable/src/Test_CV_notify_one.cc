#include <iostream>                // std::cout
#include <thread>                // std::thread
#include <mutex>                // std::mutex, std::unique_lock
#include <condition_variable>    // std::condition_variable

/*
  生产者-消费者 代码
 */

std::mutex mtx;
std::condition_variable cv;

int cargo = 0; // shared value by producers and consumers

void consumer()
{
    std::unique_lock < std::mutex > lck(mtx);
    while (cargo == 0)
        cv.wait(lck);
    std::cout << cargo << '\n';
    cargo = 0;
}

void producer(int id)
{
    std::unique_lock < std::mutex > lck(mtx);
    cargo = id;
    cv.notify_one();  //唤醒某个等待(wait)线程。如果当前没有等待线程，则该函数什么也不做，如果同时存在多个等待线程，则唤醒某个线程是不确定的(unspecified)。
} 

int main()
{
    std::thread consumers[10], producers[10];

    // spawn 10 consumers and 10 producers:
    for (int i = 0; i < 10; ++i) {
        consumers[i] = std::thread(consumer);
        producers[i] = std::thread(producer, i + 1);
    }

    // join them back:
    for (int i = 0; i < 10; ++i) {
        producers[i].join();
        consumers[i].join();
    }

    return 0;
}