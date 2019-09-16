#include<stdio.h>
#define numbermax 10000
int maxmin1(int number[], int num);
int main(void){
    int a[numbermax]={};
    int i=0;
    int min=1;
    
    while(scanf("%d",&a[i]) == 1){
        i++;
    }
    int max = maxmin1(a,i);
    while(min < max){
        int x=0;
        while(x<i){
            if(a[x] = min){
                x = x +numbermax;
            }
            x++;
            }
            if(x < numbermax){
                printf("%d ",min);
            }
    min++;
    }
}


int maxmin1(int number[], int num){
    int i = 0;
    int max = 0;
    while(i < num){
        if(number[i] > max){
            max=number[i];
        }
        i++;
    }
    return max;
}
