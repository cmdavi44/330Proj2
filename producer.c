#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/semaphore.h>
#include <linux/vector.h>

#include "producer.h"

// int (void *arg) // the function to run in the thead
// {
//     for_each_process(p) {
//         ++process_counter;
        
//     }
// }
struct bufferItem {
    int itemNumber; // Number of the item
    int pid;
    int buffIndex;  // Index
    int start_time;
};

int &m_buff_size,
    &m_bufferItem;

void createProducer(semaphore &mutex, semaphore &full, semaphore &empty, struct bufferList &buffer) {
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
            bufferItem newItem;
            newItem.itemNumber = process_counter;
            newItem.pid = p->pid;
            // newItem.buffIndex = 
            newItem.start_time = 
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



