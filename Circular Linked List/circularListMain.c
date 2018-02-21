#include "circularList.h"
#include <stdio.h>

int main()
{	
	struct CircularList* deque = circularListCreate(); 
	circularListAddBack(deque, (TYPE)1);
    printf("front:%g\n", circularListFront(deque));
    printf("back:%g\n", circularListBack(deque));
    
    
	circularListAddBack(deque, (TYPE)2);
    printf("front:%g\n", circularListFront(deque));
    printf("back:%g\n", circularListBack(deque));
    
    
	circularListAddBack(deque, (TYPE)3);
    printf("front:%g\n", circularListFront(deque));
    printf("back:%g\n", circularListBack(deque));
    
    
    printf("now adding in front \n\n");
    circularListAddFront(deque, (TYPE)4);
    printf("front:%g\n", circularListFront(deque));
    printf("back:%g\n", circularListBack(deque));
    
	circularListAddFront(deque, (TYPE)5);
	circularListAddFront(deque, (TYPE)6);
	circularListPrint(deque);
    printf("front:%g\n", circularListFront(deque));
    printf("back:%g\n", circularListBack(deque));
    
    
	circularListRemoveFront(deque);
    //circularListRemoveFront(deque);
    circularListPrint(deque);
    printf("front:%g\n", circularListFront(deque));
    printf("back:%g\n", circularListBack(deque));
    
    printf("\n\n");
	circularListRemoveBack(deque);
	circularListPrint(deque);
    printf("front:%g\n", circularListFront(deque));
    printf("back:%g\n", circularListBack(deque));
	
	circularListReverse(deque);
	circularListPrint(deque);
	
    
	circularListDestroy(deque);
	
	return 0;
}

