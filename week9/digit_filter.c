#include<stdio.h>
int replace(int character);
int main(void){
    int character=getchar();
    while(character != EOF){
        character = replace(character);
        putchar(character);
        character=getchar();
    }
    return 0;
}

int replace(int character){
    if(character >= '0' && character <= '9'){
        return character;
    }else{
        return '.';
    }
}