/* CS261- Assignment 1 - Q.3*/
/* Name: Shannon Lucas
 * Date: 01/21/2018
 * Solution description:
 *   generate 20 random values, and then pass
 *   them into a function and sort them w bubble sort
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
    /* Used bubble sort algorithm to sort the function.
     https://www.geeksforgeeks.org/bubble-sort/ */
    
    /*Sort the given array number , of length n*/
    int i, j;
    
    for(i = 0; i < n - 1; i++){
        
        for (j = 0; j < n - i - 1; j++){
            
            if(number[j] > number[j + 1]){
                int temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
        
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *newArray = malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
    int i;
    for(i = 0; i < n; i++){
        newArray[i] = rand();
    }
    
    /*Print the contents of the array.*/
    for(i = 0; i < n; i++){
        printf("%d: %d\n", i, newArray[i]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(newArray, n);
    
    /*Print the contents of the array.*/
    printf("\nSorted Array: \n\n");
    for(i = 0; i < n; i++){
        printf("%d: %d\n", i, newArray[i]);
    }
    
    free(newArray);
    
    return 0;
}
