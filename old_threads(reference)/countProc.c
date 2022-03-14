#include<linux/sched.h>
#include <linux/sched/signal.h>
#include "countProc.h"
 
struct task_struct* p;
size_t process_counter = 0;
int numProcesses() {
    
    for_each_process(p) {
        ++process_counter;
    } 

    return process_counter;
}

