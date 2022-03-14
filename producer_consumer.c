// Create your own directory, for example, /home/cse330/test_module/hello.c 
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/kthread.h>

#include "producer.h"

#define AUTHOR "Vivekananda Holla"
MODULE_LICENSE("GPL");   // defines license of the module 
MODULE_AUTHOR(AUTHOR);

static int Intparameter = 10;
module_param(Intparameter, int, 0644);

MODULE_PARM_DESC(Intparameter, "Integer parameter for the module");

static char *charparameter = "Hello world";
module_param(charparameter, charp, 0644);
MODULE_PARM_DESC(charparameter, "states-Hello world - hello");

struct task_struct* p;
size_t process_counter = 0;

static int __init initialize(void) {
    printk(KERN_INFO "hello\n");
    printk(KERN_INFO "value of integer at init = %d\n", Intparameter);
    printk(KERN_INFO "value of character string at init = %s\n", charparameter);

    kthread_run(kthread_func, NULL, "thread-1");
    
    return 0;
}

static void __exit clean_exit(void) {
    printk(KERN_INFO "Goodbye\n");
    printk(KERN_INFO "value of integer = %d\n", Intparameter);
    printk(KERN_INFO "value of character string = %s\n", charparameter);
}


 
module_init(initialize);            // defines the hello_init to be called at module loading time
module_exit(clean_exit);       // defines the hello_exit to be called at module unload time

