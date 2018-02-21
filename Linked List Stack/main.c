

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct link {
    int value;
    struct link * next;
};

struct linkedListStack {
    struct link *firstLink;
};

void linkedListStackInit (struct linkedListStack * s);
void linkedListStackFree (struct linkedListStack *s);
int linkedListStackIsEmpty (struct linkedListStack *s);
void linkedListStackPop (struct linkedListStack *s);
void linkedListStackPush (struct linkedListStack *s, int d);
int linkedListStackTop (struct linkedListStack *s);



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Singly Linked List Stack Implementation\n");
    printf("O(1)\n\n");
    
    /* create your container */
    struct linkedListStack stackContainer;
    
    /* initialize your stack container's firstLink */
    linkedListStackInit(&stackContainer);
    
    /* push 5 into the stack and print the top */
    linkedListStackPush(&stackContainer, 5);
    int x = linkedListStackTop(&stackContainer);
    printf("%d\n",x);
    
    /* push 15 onto the stack and print the top */
    linkedListStackPush(&stackContainer, 15);
    x = linkedListStackTop(&stackContainer);
    printf("%d\n",x);
    
    /* pop 15 from the stack and print the top */
    linkedListStackPop(&stackContainer);
    x = linkedListStackTop(&stackContainer);
    printf("%d\n",x);
    
    /* free all allocated nodes */
    linkedListStackFree(&stackContainer);
    
    return 0;
}



void linkedListStackInit (struct linkedListStack * s){
    /* set linkedListStack to NULL */
    s->firstLink = 0;
}

void linkedListStackPop (struct linkedListStack *s){
    /* check there is a node in the stack to pop */
    assert(s->firstLink != 0);
    
    
    /* create a temp node to store firstLink for freeing the memory */
    struct link* temp;
    
    /* set temp to the current first link */
    temp = s->firstLink;
    
    /* set firstLink to next link in stack */
    s->firstLink = s->firstLink->next;
    
    /* free memory from front of stack */
    free(temp);
}

void linkedListStackPush (struct linkedListStack *s, int d){
    /* create a new node for the stack */
    struct link* newLink = (struct link*) malloc(sizeof(struct link));
    
    /* make sure newLink has a memory location */
    assert(newLink != 0);
    
    /* set value in node to d, which was passed in */
    newLink->value = d;
    
    /* add the newLink node into the linked list by setting it
     equal to where the current firstLink is located */
    newLink->next = s->firstLink;
    
    /* assign newLink as the first link in the list */
    s->firstLink = newLink;
    
}

int linkedListStackTop (struct linkedListStack *s){
    /* make sure the stack is not NULL */
    assert(s->firstLink != 0);
    
    /* return the top of the stack */
    return s->firstLink->value;
}

void linkedListStackFree (struct linkedListStack *s){
    /* while the linkedListStack is not empty returns TRUE, continue popping */
    
    while(linkedListStackIsEmpty(s)){
        linkedListStackPop(s);
    }
}

int linkedListStackIsEmpty (struct linkedListStack *s){
    return s->firstLink == 0;
    /* returns 1 if link = 0; otherwise returns 0 */
}
