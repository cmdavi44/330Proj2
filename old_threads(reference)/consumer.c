#include<linux/sched.h>
#include <linux/sched/signal.h>

struct task_struct* p;
size_t process_counter = 0;
for_each_process(p) {
            ++process_counter;
} 