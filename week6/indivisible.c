#include<stdio.h>
#define max_number 1000
int main(void){
    int a=0;
    int array[max_number]={0};
    int factor[max_number]={0};
    int b=0;
    int c=0;
    int d=0;
    int x;
    int n=0;
    while(a<max_number){
        scanf("%d",&array[a]);
        a++;
    }
    int z=0;
    while(z<max_number){
        if(array[z]!=0){
            n=n+1;
            }
            z++;
        }
    printf("Indivisible numbers: ");    
    while(b<n){
        c=0;
        d=0;
        while(c<n){
            if(array[b]%array[c]!=0&&b!=c){
            d++;
            }
            c++;
            }
            if(d==n-1){
                printf("%d",array[b]);
            }
        b++;
        }
        
    printf("\n");
    return 0;
    }
   