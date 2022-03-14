#include <linux/kthread.h>

 
static int kthread_func(void *arg) // the function to run in the thead
{
    
}
 
// Create and run “thread-1”
ts1 = kthread_run(kthread_func, NULL, "thread-1");
