#include <unistd.h>

#include <cstdlib>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

//单生产者-单消费者

static const int kItemRepositorySize = 10;   //缓冲区大小
static const int kItemToProduce = 1000;  //要生产1000个；

struct ItemRepository {
    int item_buffer[kItemRepositorySize];  //产品缓冲区，配合 read_position 和 write_position 模拟环形队列.
    size_t read_position;  // 消费者读取产品位置.
    size_t write_position;  // 生产者写入产品位置.
    std::mutex mtx;  // 互斥量,保护产品缓冲区
    std::condition_variable repo_not_full; // 条件变量, 指示产品缓冲区不为满.
    std::condition_variable repo_not_empty;  // 条件变量, 指示产品缓冲区不为空.
} gItemRepository;   // 产品库全局变量, 生产者和消费者操作该变量.

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

void ProducerTask() // 生产者任务
{
    for (int i = 1; i <= kItemToProduce; ++i) {
        // sleep(1);
        std::cout << "Produce the " << i << "^th item..." << std::endl;
        ProduceItem(&gItemRepository, i); // 循环生产 kItemsToProduce 个产品.
    }
}

void ConsumerTask() // 消费者任务
{
    static int cnt = 0;
    while(1) {
        sleep(1);
        int item = ConsumeItem(&gItemRepository); // 消费一个产品.
        std::cout << "Consume the " << item << "^th item" << std::endl;
        if (++cnt == kItemToProduce) break; // 如果产品消费个数为 kItemsToProduce, 则退出.
    }
}


void InitItemRepository(ItemRepository *ir)
{
    ir->read_position = 0;
    ir->write_position = 0;
}

int main()
{
    InitItemRepository(&gItemRepository);
    std::thread producer(ProducerTask);
    std::thread consumer(ConsumerTask);

    producer.join();
    consumer.join();
}