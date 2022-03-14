#include <linux/semaphore.h>
#include "countProc.h"
 
#define BUFFER_SIZE 5;

// TODO: Look into how to actually create a buffer and an item for the buffer

// Semaphore Definition
struct semaphore empty, mutex, full; // define a semaphore named ‘empty’
sema_init(&muetx, 1)
sema_init(&full, 0)
sema_init(&empty, BUFFER_SIZE); 

struct task_struct {
    struct task_struct* next;
    struct task_struct* prev;
    int pid;
    int uid;
}
struct task_list {
    struct task_struct* head;
    struct task_struct* tail;
}

struct task_struct* p;
struct task_list taskList;
size_t process_counter = 0;
 
while (!kthread_should_stop()) { 
    // if the thread works in an infinite loop, this is how it knows 
    // when to stop. Check d. module_exit for more information.
    
    // TODO: Produce an item
    /* START OF Producing item */
    for_each_process(p) {
        ++process_counter;

        if (process_counter == 1) {
            struct task_struct* task;
            task->pid = p->pid;
            task->uid = p->cred->uid.val;
            task->next = p->next;
            taskList.head = &task;
        } else if (proccess_counter == emptyNum) {
            struct task_struct* task;
            task->pid = p->pid;
            task->uid = p->cred->uid.val;
            task->next = taskList.head;
            taskList.tail = &task;
        }

        struct task_struct* task;
        task->pid = p->pid;
        task->uid = p->cred->uid.val;
        task->next = p->next;
        task->prev = p->
    }
    /* END OF Producing item */


    /* START OF Entry section */
    if (down_interruptible(&empty)) {
        // down_interruptible allows the calling thread to be
        // interrupted even if it has not acquired the                                                      // semaphore that it has been waiting for
        break; // exit
    }

    if (down_interruptible(&mutex)) {
        // down_interruptible allows the calling thread to be
        // interrupted even if it has not acquired the                                                      // semaphore that it has been waiting for
        break; // exit
    }
    /* END OF Entry section */


    // TODO: Critical section - add item to the buffer
    /* START OF Critical Section */

    /* END OF Critical Section */



    // Exit
    up(mutex);
    up(full);
}
