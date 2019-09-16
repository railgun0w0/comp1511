// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination
#include<stdio.h>
#define  length1  5
int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int a = 0;
    int c=0;
    while(a < length){
        int b=0;
        while(b < length){
            if(source1[a] == source2[b]){
                destination[c]=source1[a];
                c++;
                b = b + length;
            }else{
                b++;
            }
        }        
        a++;
    }
    int i = 0;
    int n = 0;
    while(i < length){
         if(destination[i] != 0){
            n = n+1;
         }
         i++;
    }     
    return n;
}

int main(void){
    int sourse1[length1]={1,2,3,2,1};
    int sourse2[length1]={1,2,3,4,5};
    int sourse3[length1]={};
    printf("the comon element is %d",common_elements(length1,sourse1,sourse2,sourse3));
    return 0;
}
// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.