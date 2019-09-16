#include<stdio.h>
#define number_max 10
int main(void){
    int number[number_max]={0};
    int a=0;
    while(a<number_max){
        scanf("%d",&number[a]);
        a++;
    }
    int b=0;
    printf("Odd numbers were: ");
    while(b<number_max){
        if(number[b]%2!=0){
            printf("%d ",number[b]);
        }
        b++;
    }   
    int c=0;
    printf("Even numbers were: ");
    while(c<number_max){
        if(number[c]%2==0){
            printf("%d ",number[c]);
        }
        c++;
    }   

}