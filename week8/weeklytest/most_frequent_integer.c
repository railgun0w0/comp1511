#include<stdio.h>
#define maxint 100000
int remove_duplicates(int length, int source[length], int destination[length]);

int main(void){
    int length=0;
    int source[maxint]={};
    int destination[maxint]={};
    int b;
    while(scanf("%d",&source[length])!=EOF){
        length++;
    }
    int a=0;
    int num;
    int count[maxint]={};
    while(a < remove_duplicates(length,source,destination)){
        b=0;
        num=0;
        while(b < length){
            if(destination[a]==source[b]){
                num=num+1;
            }
            b++;
        }
        count[a] = num;
        a++;
    }
    int max=0;
    a=0;
    while(a < remove_duplicates(length,source,destination)){
        if(count[a] > max){
            max = count[a];
        }
        a++;
    }
    //frequence equal
    int frq[maxint]={};
    a=0;
    int n=0;
    while(a < remove_duplicates(length,source,destination)){
        if(count[a]== max){
            frq[n]=destination[a];
            n++;
        }
        a++;
    }
    a=0;
    max=frq[0];
    while(a < n){
        if(frq[a]>max){
            max = frq[a];
        }
        a++;
    }
    printf("%d\n",max);
    return 0;
}



int remove_duplicates(int length, int source[length], int destination[length]){
    int a = 0;
    int n=0;
    int b;
    int x=0;
    while(a<length){
        b=0;
        x=0;
        if(a == 0){
            destination[n]=source[a];
            n++;
        }else{
            while(b < a){
                if(source[a] == source[b]){
                    x=-1;
                }
                b++;
            }
            if(x != -1){
                destination[n]=source[a];
                n++;
            }
        }
        a++;
    }
    return n;
}