/* CS261- Assignment 1 - Q.5*/
/* Name: Shannon Lucas
 * Date: 1/21/2018
 * Solution description:
 * get a char, put it into the sticky caps function,
 * and output the WoRd LiKe ThIs
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
    int i = 0;
    int wordLength = strlen(word);
    
    for(i = 0; i < wordLength; i++){
        /* first check for null terminator */
        /* not sure if this part is actually needed? looks like you can't 
           just press enter in C you need some type of input */
        if(word[i] == '\n'){
            return;
        }
        
        if(i % 2 == 0){
            /* if it's lower case, uppercase it. otherwise, leave alone as it's already right*/
            if(islower(word[i])){
                word[i] = toUpperCase(word[i]);
            }
            else{
                /* do nothing */
            }
        }
        else{
            /* if it's upper case, lowercase it. otherwise, leave alone as it's already right*/
            if(isupper(word[i])){
                word[i] = toLowerCase(word[i]);
            }
            else{
                /* do nothing */
            }
        }
    }
    
}

int main(){
    /*Read word from the keyboard using scanf*/
        /* max characters of 1000 */
    char userInput[1000];
    
    printf("Enter a word to sticky cap: ");
    scanf("%s", userInput);
    
    
    /*Call sticky*/
    sticky(userInput);
    
    /*Print the new word*/
    printf("%s \n", userInput);
    
    return 0;
}
