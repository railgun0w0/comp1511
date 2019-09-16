#include<stdio.h>
#define max 4096
int is_palindrome(char line[]);

int main(void){
    char line [max] = {0};
    printf("Enter a string: ");
    fgets(line, max, stdin);
    if(is_palindrome(line) == 1 ){
        printf("String is a palindrome\n");
    }else{
        printf("String is not a palindrome\n");
    }

    return 0;
}

int is_palindrome(char line[]){
    int R=0;
    while(line[R] != '\0' && line[R] != '\n') {
        R++;
    }
    R--;
    int L = 0;
    while(L < R){
        if(line[L] != line[R]){
            return 0;
        }
        L++
        R--;
    }
    return 1;
}