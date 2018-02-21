//  Created by Shannon Lucas on 2/14/18.
//  Copyright © 2018 Shannon Lucas. All rights reserved.


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


struct Link{
    int value;
    struct Link* next;
    struct Link* prev;
};

struct LinkedListBag{
    struct Link* frontSentinel;
    struct Link* backSentinel;
    int size;
};

//function protos
void init(struct LinkedListBag* list);
void add(struct LinkedListBag* list, int value);
void removeLink(struct LinkedListBag* list, struct Link* link);
void removeLinkBag(struct LinkedListBag* list, int val);
int containsBag(struct LinkedListBag* list, int val);
void printBag(struct LinkedListBag* list);
void reverseBag(struct LinkedListBag* list);


int main(int argc, const char * argv[]) {
    printf("Doubly Linked List Bag Implementation\n");
    
    struct LinkedListBag bag;
    
    init(&bag);
    add(&bag, 10);
    add(&bag, 20);
    add(&bag, 30);
    add(&bag, 50);
    
    printf("Contains 10: %d\n", containsBag(&bag, 10));
    printf("Contains 20: %d\n", containsBag(&bag, 20));
    printf("Contains 40: %d\n", containsBag(&bag, 40));
    
    printf("\nprinting bag. . . \n");
    printBag(&bag);
    
    reverseBag(&bag);
    printf("\nprinting bag. . . \n");
    printBag(&bag);
    
    /*
    //testing removal
    printf("\nremoving one link . . .\n");
    removeLinkBag(&bag, 10);
    printf("\nprinting bag. . . \n");
    printBag(&bag);
    */
    
    
    return 0;
}

void init(struct LinkedListBag* list){
    list->frontSentinel = malloc(sizeof(struct Link));
    assert(list->frontSentinel != 0);
    
    list->backSentinel = malloc(sizeof(struct Link));
    assert(list->backSentinel != 0);
    
    list->backSentinel->prev = list->frontSentinel;
    list->frontSentinel->next = list->backSentinel;
    
    list->size = 0;
}

void reverseBag(struct LinkedListBag* list){
    //pointing to the front
    struct Link* current = list->frontSentinel->next;
    struct Link* temp;
    
    while(current != list->backSentinel){
        //swap prev and next of current node
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        
        current = temp;
    }
    
    temp = list->frontSentinel->next;
    list->frontSentinel->next = list->backSentinel->prev;
    list->backSentinel->prev = temp;
    
    
}

void printBag(struct LinkedListBag* list){
    int i;
    struct Link* temp = list->frontSentinel->next;
    
    for(i = 1; i <= list->size; i++){
        printf("Link #%d: %d\n", i, temp->value);
        temp = temp->next;
    }
}

void add(struct LinkedListBag* list, int value){
    struct Link* newLink = malloc(sizeof(struct Link));
    assert(newLink != 0);
    
    newLink->value = value;
    
    //it doesn't matter the order you add this in so i'll just add to the front
    //each time in front of the frontSentinel
    list->frontSentinel->next->prev = newLink;
    newLink->next = list->frontSentinel->next;
    
    newLink->prev = list->frontSentinel;
    list->frontSentinel->next = newLink;
    
    //add to the size of the bag
    list->size++;
}

void removeLinkBag(struct LinkedListBag* list, int val){
    
    struct Link* temp = list->frontSentinel->next;
    int i;
    
    //search the linkedlist for the value passed in
    //and remove it if found
    for(i = 0; i < list->size; i++){
        if(temp->value == val){
            removeLink(list, temp);
        }
        else{
            temp = temp->next;
        }
    }
    
}

void removeLink(struct LinkedListBag* list, struct Link* link){
    //set previous pointer to point to next
    link->prev->next = link->next;
    
    //set next pointer to point to prev
    link->next->prev = link->prev;
    
    //remove link
    free(link);
    link = 0;
    
    //reduce size
    list->size--;
}


int containsBag(struct LinkedListBag* list, int val){
    int i;
    struct Link* temp = list->frontSentinel->next;
    
    //return 1 if you find the value or keep looking
    for(i = 0; i < list->size; i++){
        if(temp->value == val){
            return 1;
        }
        else{
            temp = temp->next;
        }
    }
    
    //return 0 if you looped through the entire list
    //and could not find the value
    return 0;
}

