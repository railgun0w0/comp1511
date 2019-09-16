#include<stdio.h>
int main(void){
    int character = getchar();
    int characters = 0;
    int lines = 1;
    int countword=0;
    int words = 0;
    while(character != EOF){
        character=getchar();
        characters++;
    
    if(character == '\n'){
        lines++;
        countword = 1;
    }
    if（character == ' '){
        countword = 1;
    }
    if(countword == 1){
        if(character >= 'a' && character <= 'z'){
            countword=0;
            words++;
        }else if(character >= 'A' && character <= 'Z'){
            countword=0;
            words++;
        }
    }else{
        if(words == 0){
            if(character >= 'a' && character <= 'z'){
                words++;
            }else if(character >= 'A' && character <= 'Z'){
                words++;
            }
        }
    }
    }
    printf("%d lines %d words %d characters\n",lines ,words , characters);
    return 0;
}
