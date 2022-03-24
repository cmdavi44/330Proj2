#ifndef PRODUCER_CONSUMER_DOT_H
#define PRODUCER_CONSUMER_DOT_H

struct bufferItem {
    int itemNumber;
    int pid;
    int buffIndex;
    int start_time;
};

struct bufferList {
    struct bufferItem* item;
    struct bufferItem* next;
    struct bufferItem* prev;
    int size;
    int itemCount;
};

#endif

