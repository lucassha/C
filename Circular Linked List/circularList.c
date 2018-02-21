#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	/* create your sentinel */
    list->sentinel = malloc(sizeof(struct Link));
    assert(list->sentinel != 0);
    
    /* won't have the first node pointing correctly
     without setting this part */
    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;
    
    /* size size to zero */
    list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
    /* allocate new memory for the link */
    struct Link* newLink = (struct Link*) malloc(sizeof(struct Link));
    assert(newLink != 0);
    /* set value */
    newLink->value = value;
    
	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	/* use createLink function to allocate new node */
    struct Link* newLink = createLink(value);
    assert(newLink != 0);
    
    /* order is important here. these two must come first */
    newLink->next = link->next;
    newLink->prev = link;
    
    /* set the after link to the new link */
    link->next->prev = newLink;
    link->next = newLink;
    
    /* add 1 to size */
    list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
    assert(list != 0);
    
    /* set the two outside links to point at one another */
    link->next->prev = link->prev;
    link->prev->next = link->next;
    
    free(link);
    
    list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
    assert(list != 0);
    init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
    /* free the nodes */
    while(!circularListIsEmpty(list)){
        circularListRemoveFront(list);
    }
    /* free the sentinel */
    free(list->sentinel);
    
    /*free the container */
    free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
    /* already using add link AFTER */
    addLinkAfter(list, list->sentinel, value);
        
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
    /* need to use prev because ADD LINK AFTER */
    addLinkAfter(list, list->sentinel->prev, value);
    
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
    return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
    assert(list != 0);
    
    removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
    removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
    return list->size == 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
    int nodeVal;
    struct Link* temp = list->sentinel->next;
    
    printf("Circular linked list output . . .\n");
    
    while(temp != list->sentinel){
        nodeVal = temp->value;
        printf("%d ", nodeVal);
        temp = temp->next;
    }
    
    printf("\n");
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	/* do i need to adjust the memory locations or just values? */
    assert(list != 0);
    
    struct Link* temp1 = list->sentinel->next;
    struct Link* temp2 = list->sentinel->next;
    
    /* swap the sentinel next and prev */
    list->sentinel->next = list->sentinel->prev;
    list->sentinel->prev = temp1;
    
    /* swap until you reach the sentinel */
    while(temp1 != list->sentinel){
        temp2 = temp1->prev;
        temp1->prev = temp1->next;
        temp1->next = temp2;
        temp1 = temp1->prev;
    }
}








