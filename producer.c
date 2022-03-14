#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include "producer.h"

int kthread_func(void *arg) // the function to run in the thead
{
    for_each_process(p) {
        ++process_counter;
        printk("proccess id: %d", p->pid);
    }
}