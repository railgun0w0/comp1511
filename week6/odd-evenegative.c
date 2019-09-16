//yanghaoyu
//z5223796
#include<stdio.h>
#define number_max 1000
int main(void){
    int number[number_max]={0};
    int a=0;
    while(a<number_max){
        scanf("%d",&number[a]);
        if(number[a]<0){
            a=a+2000;
        }else{
            a++;
        }
    }
    int b=0;
    printf("Odd numbers were: ");
    while(b<number_max){
        if(number[b]%2!=0&&number[b]>0){
            printf("%d ",number[b]);
        }
        b++;
    }
    printf("\n");   
    int c=0;
    printf("Even numbers were: ");
    while(c<number_max){
        if(number[c]%2==0&&number[c]!=0&&number[c]>0){
            printf("%d ",number[c]);
        }
        c++;
    }
    printf("\n");      

}