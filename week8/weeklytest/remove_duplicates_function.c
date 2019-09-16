#include<stdio.h>
int remove_duplicates(int length, int source[length], int destination[length]){
    int a = 0;
    int n=0;
    int b;
    int x=0;
    while(a<length){
        b=0;
        if(a == 0){
            destination[n]=source[a];
            n++;
        }else{
            while(b < a){
                if(source[a] == source[b]){
                    x=-1;
                    b=b+length;
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
}
