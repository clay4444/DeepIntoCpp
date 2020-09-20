#include <unistd.h>
#include <cstdlib>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

//多生产者-多消费者

static const int kItemRepositorySize  = 4; // Item buffer size.
static const int kItemsToProduce  = 10;   // How many items we plan to produce.

struct ItemRepository {
    int item_buffer[kItemRepositorySize];
    size_t read_position;
    size_t write_position;
    size_t produced_item_counter;  //生产了多少个
    size_t consumed_item_counter;  //消费了多少个
    std::mutex mtx;  //全局锁
    std::mutex produced_item_counter_mtx;     //更新生产数目的锁
    std::mutex consumed_item_counter_mtx;     //更新消费数目的锁
    std::condition_variable repo_not_full;    //两个条件变量
    std::condition_variable repo_not_empty;   
} gItemRepository;

typedef struct ItemRepository ItemRepository;

//生产者逻辑
void ProduceItem(ItemRepository *ir, int item)
{
    std::unique_lock<std::mutex> lock(ir->mtx);  //1.获取锁
    while ((ir->write_position) % kItemRepositorySize == ir->read_position) {  //说明buffer已经满了， 开始wait
        std::cout << "Producer is waiting for an empty slot...\n";
        (ir->repo_not_full).wait(lock);     //等待消费者唤醒
    }
    
    //被消费者唤醒之后，执行以下逻辑
    (ir->item_buffer)[ir->write_position] = item;
    (ir->write_position)++;  // 写入位置后移.
    
    if (ir->write_position == kItemRepositorySize)
        ir->write_position = 0;
    
    ir->repo_not_empty.notify_all();  // 通知消费者产品库不为空.
    lock.unlock();   //这里应该不需要释放锁
}

//消费者逻辑
int ConsumeItem(ItemRepository *ir)
{
    int data;
    std::unique_lock<std::mutex> lock(ir->mtx);  //1.获取锁

    // item buffer is empty, just wait here.
    while(ir->write_position == ir->read_position) {
        std::cout << "Consumer is waiting for items...\n";
        (ir->repo_not_empty).wait(lock); // 消费者等待"产品库缓冲区不为空"这一条件发生.
    }

    //被生产者唤醒
    data = (ir->item_buffer)[ir->read_position];
    (ir->write_position)++;

    if (ir->read_position >= kItemRepositorySize) // 读取位置若移到最后，则重新置位.
        ir->read_position = 0;

    (ir->repo_not_full).notify_all(); // 通知消费者产品库不为满.

    lock.unlock(); // 解锁.

    return data; // 返回产品.
}

void ProducerTask()
{
    bool ready_to_exit = false;
    while(1) {
        sleep(1);
        std::unique_lock<std::mutex> lock(gItemRepository.produced_item_counter_mtx);
        if (gItemRepository.produced_item_counter < kItemsToProduce) {
            ++(gItemRepository.produced_item_counter);
            ProduceItem(&gItemRepository, gItemRepository.produced_item_counter);
            std::cout << "Producer thread " << std::this_thread::get_id()
                << " is producing the " << gItemRepository.produced_item_counter
                << "^th item" << std::endl;
        } else ready_to_exit = true;
        lock.unlock();
        if (ready_to_exit == true) break;
    }
    std::cout << "Producer thread " << std::this_thread::get_id()
                << " is exiting..." << std::endl;
}

void ConsumerTask()
{
    bool ready_to_exit = false;
    while(1) {
        sleep(1);
        std::unique_lock<std::mutex> lock(gItemRepository.consumed_item_counter_mtx);
        if (gItemRepository.consumed_item_counter < kItemsToProduce) {
            int item = ConsumeItem(&gItemRepository);
            ++(gItemRepository.consumed_item_counter);
            std::cout << "Consumer thread " << std::this_thread::get_id()
                << " is consuming the " << item << "^th item" << std::endl;
        } else ready_to_exit = true;
        lock.unlock();
        if (ready_to_exit == true) break;
    }
    std::cout << "Consumer thread " << std::this_thread::get_id()
                << " is exiting..." << std::endl;
}

void InitItemRepository(ItemRepository *ir)
{
    ir->write_position = 0;
    ir->read_position = 0;
    ir->produced_item_counter = 0;
    ir->consumed_item_counter = 0;
}

int main()
{
    InitItemRepository(&gItemRepository);
    std::thread producer1(ProducerTask);
    std::thread producer2(ProducerTask);
    std::thread producer3(ProducerTask);
    std::thread producer4(ProducerTask);

    std::thread consumer1(ConsumerTask);
    std::thread consumer2(ConsumerTask);
    std::thread consumer3(ConsumerTask);
    std::thread consumer4(ConsumerTask);

    producer1.join();
    producer2.join();
    producer3.join();
    producer4.join();

    consumer1.join();
    consumer2.join();
    consumer3.join();
    consumer4.join();
}
