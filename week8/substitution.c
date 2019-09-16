#include<stdio.h>
#include<stdlib.h>
#define modulo 26
int encrypt(int character, char alphabet[]);

int main(int argc, char *argv[]) {
    char alphabet[26]={};
    int i=0;
    while(i<26){
        alphabet[i]=argv[1][i];
        i++;
    }
    int character=getchar(); 
    while(character != EOF){
        int encrypted_character = encrypt(character,alphabet);
        putchar(encrypted_character);
        character=getchar();
    }
    return 0;
}

int encrypt(int character, char alphabet[]){
    if(character >= 'A' && character <= 'Z'){
        return 'A'+alphabet[character-'A'];
    }else if(character >= 'a' && character <= 'z'){
        return alphabet[character-'a'];
    }else{
        return character;
    }
}