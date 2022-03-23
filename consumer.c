#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include "producer.h"

// int (void *arg) // the function to run in the thead
// {
//     for_each_process(p) {
//         ++process_counter;
        
//     }
// }

static int kthread_func(void *arg) // the function to run in the thead
{
    
}

void createConsumer(int numConsumers) {
    for (int i = 0; i < numConsumers; i++) {
        kthread_run(kthread_func, NULL, "thread-1");
    }
}