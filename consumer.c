#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include "consumer.h"

static int kthread_func(void *arg) // the function to run in the thead
{
    return -1;
}


