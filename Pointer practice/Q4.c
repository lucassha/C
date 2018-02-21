/* CS261- Assignment 1 - Q.4*/
/* Name: Shannon Lucas
 * Date: 1/21/2018
 * Solution description:
 *   declare and initialize n, some number of students
 *   assign random values, print their values, and then
 *   sort them in
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    
    /* Used bubble sort algorithm to sort the function.
     https://www.geeksforgeeks.org/bubble-sort/ */
    
    /*Sort the given array number , of length n*/
    int i, j;
    
    for(i = 0; i < n - 1; i++){
        
        for (j = 0; j < n - i - 1; j++){
            
            if(students[j].score > students[j + 1].score){
                /* assign temp values */
                int tempScore = students[j].score;
                int tempId = students[j].id;
                
                /* switch the first value */
                students[j].score = students[j + 1].score;
                students[j].id = students[j + 1].id;
                
                /* assign temp value to j + 1 */
                students[j + 1].score = tempScore;
                students[j + 1].id = tempId;
                
            }
        }
        
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 5;
    int i;
    int *id = malloc(n * sizeof(int));
    
    /* generate IDs 1-n */
    for(i = 0; i < n; i++){
        id[i] = i;
    }
    
    /*Allocate memory for n students using malloc.*/
    struct student *newStudents = malloc(n * sizeof(struct student));
    
    /* assign unique value for id */
    for(i = 0; i < n; i++){
        /* set j to random number 0-n */
        int j = rand() % n;
        
        /* switch the numbers */
        int tempNum = id[i];
        id[i] = id[j];
        id[j] = tempNum;
    }
    
    /* Set new array order in newStudents */
    for(i = 0; i < n; i++){
        newStudents[i].id = id[i];
    }
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    for(i = 0; i < n; i++){
        /* limiting the rand() to 100 */
        newStudents[i].score = rand() % 100;
    }
    
    /*Print the contents of the array of n students.*/
    for(i = 0; i < n; i++){
        printf("%d: %d\n", newStudents[i].id, newStudents[i].score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(newStudents, n);
    
    /*Print the contents of the array of n students.*/
    printf("\n\nSorted Array:\n");
    
    for(i = 0; i < n; i++){
        printf("%d: %d\n", newStudents[i].id, newStudents[i].score);
    }
    
    free(id);
    free(newStudents);
    
    return 0;
}
