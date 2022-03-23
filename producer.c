#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/semaphore.h>

#include "producer.h"

// int (void *arg) // the function to run in the thead
// {
//     for_each_process(p) {
//         ++process_counter;
        
//     }
// }
struct bufferItem {
    int itemNumber;
    int pid;
    int buffIndex;
    int start_time;
};

int &m_buff_size,
    &m_bufferItem;

pthread_mutex_t m_mutex;
sem_t &m_full,
    &m_empty;

void createProducer(semaphore &mutex, semaphore &full, semaphore &empty) {
    m_buff_size = buff_size;
    m_buffer = buffer;
    m_mutex = mutex;
    m_full = full;
    m_empty = empty;
}

static int kthread_func(void *arg) // the function to run in the thead
{
    struct task_struct* p;
    size_t process_counter = 0;
    for_each_process(p) {
        ++process_counter;
        while (true) {
            //create a buffer item
            //wait(empty);
            //wait(mutex);
            // CS: add item to the buffer
            //signal(mutex);
            //signal(full);
        }
    } 

}

void startProducer() {
    kthread_run(kthread_func, NULL, "thread-1");
}



