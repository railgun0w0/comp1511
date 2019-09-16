#include<stdio.h>
#include<stdlib.h>
#define modulo 26
int encrypt(int character, int shift);

int main(int argc, char *argv[]) {
    int shift = atoi(argv[1]);
    int character=getchar();
    if(shift < 0){
        shift = shift + (shift % modulo);
    }else if (shift > 25 {
        shift = shift + (shift % modulo);
    }
    
    while(character != EOF){
        int encrypted_character = encrypt(character,shift);
        putchar(encrypted_character);
        character=getchar();
    }
    return 0;
}

int encrypt(int character, int shift){
    if(character >= 'a' && character <= 'z'){
        return 'a'+(character-'a'+shift) % modulo;
    }else if(character >= 'A' && character <= 'Z'){
        return 'A'+(character-'A'+shift) % modulo;
    }else{
        return character;
    }
}