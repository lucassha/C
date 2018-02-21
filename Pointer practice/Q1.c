/* CS261- Assignment 1 - Q.1*/
/* Name: Shannon Lucas
 * Date: 01/21/2018
 * Solution description:
 *   create new struct of 10 students,
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    /* how to declare new struct: int *myInt = malloc(sizeof(int)) */
    struct student* newStudent = malloc(10 * sizeof(struct student));
    
     /*return the pointer*/
    
    return newStudent;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    int i = 1;
    int id[10];
    
    /* generate IDs 1-10 */
    for(i = 1; i < 11; i++){
        id[i-1] = i;
    }
    
    /* Testing array
    for(i = 0; i < 10; i++){
        printf("%d ", id[i]);
    }
    printf("\n");
    */
     
    for(i=0; i < 10; i++){
        /* set j to random number 0-10 */
        int j = rand() % 10;
        
        /* switch the numbers */
        int tempNum = id[i];
        id[i] = id[j];
        id[j] = tempNum;
    }
    
    for (i = 0; i < 10; i++){
        students[i].score = (rand() % 100);
    }
    
    for (i=0; i < 10; i++){
        students[i].id = id[i];
    }
    
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    
    int i;
    
    for(i = 0; i < 10; i++){
        printf("%d ", students[i].id);
        printf("%d\n", students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    double avg = 0;
    int max = students[0].score;
    int min = students[0].score;
    
    int i;
    
    for (i = 0; i < 10; i++){
        if(students[i].score < min){
            min = students[i].score;
        }
        
        if(students[i].score > max){
            max = students[i].score;
        }
        
        avg = avg + students[i].score;
    }
    
    avg = avg / 10.0;
    
    printf("Max score: %d\n", max);
    printf("Min score: %d\n", min);
    printf("Avg score: %.2f\n", avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
        /* allocate function creates a struct of 10 new students */
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);
    
    return 0;
}
