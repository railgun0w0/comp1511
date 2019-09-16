#include<stdio.h>
#define largestnumber 26

int swap_case(int character);
void count(int character, int alghbat_count[], double frequency[]);
void countalg(int character, int alghbat_count[]);
int main(void){
    int character=getchar();
    int alghbat_count[largestnumber] = {0};
    double frequency[largestnumber] = {0}; 
    while(character != EOF){
        character = swap_case(character);
        countalg(character,alghbat_count);
        character=getchar();
    }
    count(character,alghbat_count,frequency);
    return 0;
}

void countalg(int character, int alghbat_count[]){
    if (character >= 'a' && character <= 'z'){
        alghbat_count[character-'a']=alghbat_count[character-'a']+1;
    }
}

void count(int character, int alghbat_count[], double frequency[]){

    int i=0;
    double sum=0;
    
    //how many alghbat_count
    while(i<largestnumber){
        sum = sum + alghbat_count[i];
        i++;
    }
    i=0;
    while(i<largestnumber){
        frequency[i]=alghbat_count[i]/sum;
        i++;
    }
    i=0;
    while(i<largestnumber){
        printf("'%c' %f %d\n",'a'+i,frequency[i],alghbat_count[i]);
        i++;
    }
}

int swap_case(int character){
    if(character >= 'A' && character <= 'Z'){
        int alphabetPosition = character - 'A';
        return 'a'+ alphabetPosition;
    }else{
        return character;
    }
}