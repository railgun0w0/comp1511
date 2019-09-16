#include<stdio.h>
#define MAX_NUMBER 10
void saveodd(int a[],int b[],int c[]);
int main(void){
     int array1[MAX_NUMBER]={0};
     int array2[MAX_NUMBER]={0};
     int array3[MAX_NUMBER]={0};
     int a=0;
     int x;
     while(a<MAX_NUMBER){
         scanf("%d",&x);
         x=array1[a];
         a++;
     }
    saveodd(array1,array2,array3);
    //
    printf("Odd numbers were: ");
    int a1=0;
    while(a1<MAX_NUMBER){
        if(array3[a1]!=0){
            printf("%d ",&array3[a1]);
        }
        a1++;
    }
     
    return 0;
}

void saveodd(int a[],int b[],int c[]){
    int a1=0;
    int a2,a3;
    while(a1<MAX_NUMBER){
        if(a[a1]%2==0){
            a2=a[a1];
            b[a1]=a2;
            a1=a1+1;
        }else{
            a[a1]=a3;
            a3=c[a1];
            a1=a1+1;
        }

    }

}