/*
 * This is the file in which you'll write the functions required to implement
 * a stack using two queues.  Make sure to add your name and @oregonstate.edu
 * email address below:
 *
 * Name:
 * Email:
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct link{
    int value;
    struct link* next;
};

struct listQueue{
    struct link* firstLink;
    struct link* lastLink;
};

/* Queue */
struct listQueue* createQ();
void listQueueInit(struct listQueue* q);
void initQueues(struct listQueue* q1, struct listQueue* q2);
void listQueueAddBack(struct listQueue* q, int val);
int listQueueFront(struct listQueue* q);
void removeFront(struct listQueue* q);
int listQueueIsEmpty(struct listQueue* q);


/* Stack */
void queuePush(struct listQueue* q, int val);
void queuePop(struct listQueue* q, struct listQueue* q2);
int queueTop(struct listQueue* q);


int main(int argc, const char * argv[]) {
    
    struct listQueue* q1 = createQ();
    struct listQueue* q2 = createQ();
    initQueues(q1, q2);
    
    queuePush(q1, 10);
    int num = queueTop(q1);
    printf("top: %d \n", num);
    
    queuePush(q1, 20);
    num = queueTop(q1);
    printf("top: %d \n", num);
    
    queuePush(q1, 30);
    num = queueTop(q1);
    printf("top: %d \n", num);
    
    printf("first link: %d\n", q1->firstLink->next->value);
    printf("last link: %d\n", q1->lastLink->value);
    
    queuePop(q1, q2);
    printf("\nBack in main-----------\n");
    printf("q1 first link: %d\n", q1->firstLink->value);
    printf("q1 last link: %d\n", q1->lastLink->value);
    
    printf("q2 first link: %d\n", q2->firstLink->value);
    printf("q2 last link: %d\n", q2->lastLink->value);
    
    printf("q1 memory add:%p\n", q1);
    printf("q2 memory add:%p\n", q2);
    
    
    
    return 0;
}









void queuePush(struct listQueue* q, int val){
    
    assert(q != 0);
    listQueueAddBack(q, val);
}

void queuePop(struct listQueue* q, struct listQueue* q2){
    assert(q != 0);
    
    struct link* temp1 = q->firstLink->next; //the first value skipping sentinel
    struct listQueue* tempQueue;
    
    while(temp1 != q->lastLink){
        queuePush(q2, temp1->value);
        temp1 = temp1->next;
        removeFront(q);
    }
    
    removeFront(q);
    
    printf("q1 memory add:%p\n", q);
    printf("q2 memory add:%p\n", q2);
    printf("temp memory add:%p\n", tempQueue);
    
    tempQueue = q;
    q = q2;
    q2 = tempQueue;
    
    
    printf("\nIn function-----------------\n");
    printf("q1 first link: %d\n", q->firstLink->value);
    printf("q1 last link: %d\n", q->lastLink->value);
    
    printf("q2 first link: %d\n", q2->firstLink->value);
    printf("q2 last link: %d\n", q2->lastLink->value);
    
    printf("q1 memory add:%p\n", q);
    printf("q2 memory add:%p\n", q2);
    printf("temp memory add:%p\n", tempQueue);
}

int queueTop(struct listQueue* q){
    /* last link is essentially top of the stack */
    return q->lastLink->value;
}



void listQueueInit(struct listQueue* q){
    struct link *link = (struct link*) malloc(sizeof(struct link));
    assert(link != 0);
    link->next = 0;
    q->firstLink = q->lastLink = link;
}

struct listQueue* createQ(){
    struct listQueue* q = (struct listQueue*) malloc(sizeof(struct listQueue));
    assert(q != 0);
    
    return q;
}

void initQueues(struct listQueue* q1, struct listQueue* q2){
    
    assert(q1 != 0);
    assert(q2 != 0);
    
    listQueueInit(q1);
    listQueueInit(q2);
}

void listQueueAddBack(struct listQueue* q, int val){
    struct link* link = (struct link*) malloc(sizeof(struct link));
    assert(link != 0);
    
    //new link should be last so it points to zero
    link->next = 0;
    link->value = val;
    
    //update the last link to now point at the new node
    q->lastLink->next = link;
    q->lastLink = link;

}

int listQueueFront(struct listQueue* q){
    return q->firstLink->value;
}

void removeFront(struct listQueue* q){
    struct link* temp = q->firstLink->next;
    assert(q != 0);
    
    q->firstLink->next = temp->next;
    
    if(q->firstLink->next == 0){
        q->lastLink = q->firstLink;
    }
    free(temp);
    
}

int listQueueIsEmpty(struct listQueue* q){
    return q->firstLink->next == 0;
}






