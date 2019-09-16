#include<stdio.h>
int is_vowel(int character);

int main(void) {
    int character=getchar();
    while(character != EOF){
        if(is_vowel(character)){
            putchar(character);
        }
        character=getchar();
    }
    return 0;
}

int is_vowel(int character){
    return character == 'a' ||
           character == 'e' ||
           character == 'i' ||
           character == 'o' ||
           character == 'u' ;
}