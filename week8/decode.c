#include<stdio.h>
#include<stdlib.h>
int decrypt(int character, char alphabet[]);

int main(int argc, char *argv[]) {
    char alphabet[26]={};
    int i=0;
    while(i<26){
        alphabet[i]=argv[1][i];
        i++;
    }
    int character=getchar(); 
    while(character != EOF){
        int decrypted_character = decrypt(character,alphabet);
        putchar(decrypted_character);
        character=getchar();
    }
    return 0;
}

int decrypt(int character, char alphabet[]){
    if(character >= 'A' && character <= 'Z'){
        int i = 0;
        character = 'a'+(character-'A');
        while(i<26){
            if(character == alphabet[i]){
                break;
            }
            i++;
        }
        return 'A'+i;
    }else if(character >= 'a' && character <= 'z'){
        int i = 0;
        while(i<26){
            if(character == alphabet[i]){
                break;
            }
            i++;
        }
        return 'a'+i;
    }else{
        return character;
    }
}