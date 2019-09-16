#include<stdio.h>
#include<stdlib.h>
int replace(int character, char alphabet[]);

int main(int argc, char *argv[]) {
    char alphabet[10]={};
    int i=0;
    while(i<10){
        alphabet[i]=argv[1][i];
        i++;
    }
    int character=getchar(); 
    while(character != EOF){
        int replaced_character = replace(character,alphabet);
        putchar(replaced_character);
        character=getchar();
    }
    return 0;
}

int replace(int character, char alphabet[]){
    if(character >= '0' && character <= '9'){
        return alphabet[character-'0'];
    }else{
        return character;
    }
}