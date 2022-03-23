// Create your own directory, for example, /home/cse330/test_module/hello.c 
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/kthread.h>
#include <linux/semaphore.h>

#include "producer.h"
#include "consumer.h"


#define AUTHOR "Vivekananda Holla"


MODULE_LICENSE("GPL");   // defines license of the module 
MODULE_AUTHOR(AUTHOR);

static int uid = 0;
module_param(uid, int, 0644);
MODULE_PARM_DESC(uid, "user id");

static int buff_size = 10; // This will change
module_param(buff_size, int, 0644);
MODULE_PARM_DESC(p, "size of buffer");

static int p = 0;
module_param(p, int, 0644);
MODULE_PARM_DESC(p, "number of producers");

static int c = 0;
module_param(c, int, 0644);
MODULE_PARM_DESC(c, "number of consumers");



// Buffer
struct bufferItem {
    int itemNumber;
    int pid;
    int buffIndex;
    int start_time;
};
struct bufferItem buffer[buff_size];

// Semaphores
struct semaphore mutex;
struct semaphore full;
struct semaphore empty;

sema_init(&mutex, 1);
sema_init(&full, 0);
sema_init(&empty, buff_size);


static int __init initialize(void) {
    printk(KERN_INFO "UID = %d\n", uid);
    printk(KERN_INFO "Size of buffer = %s\n", buff_size);
    printk(KERN_INFO "Number of producers = %d\n", p);
    printk(KERN_INFO "Number of consumers = %s\n", c);

    if (numProcesses == 0) {
        clean_exit();
    }

    
    
    return 0;
}

static void __exit clean_exit(void) {
    printk(KERN_INFO "Goodbye\n");
    printk(KERN_INFO "value of integer = %d\n", Intparameter);
    printk(KERN_INFO "value of character string = %s\n", charparameter);
}


 
module_init(initialize);            // defines the hello_init to be called at module loading time
module_exit(clean_exit);            // defines the hello_exit to be called at module unload time

