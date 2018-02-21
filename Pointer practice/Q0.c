/* CS261- Assignment 1 - Q. 0*/
/* Name: Shannon Lucas
 * Date: 01/21/2018
 * Solution description:
 *  declare an int, print the address, call fooA,
 *  print its value, memory address it points to,
 *  and its mem address itself
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
    printf("%d\n", *iptr);
     
     /*Print the address pointed to by iptr*/
    printf("%p\n", iptr);
    
     /*Print the address of iptr itself*/
    printf("%p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 100;
    
    /*print the address of x*/
    printf("%p\n",&x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("%d\n",x);
    
    return 0;
}
