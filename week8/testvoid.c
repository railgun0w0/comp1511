#include<stdio.h>
void test(int a);
int main(void){
    int a=0;
    test(a);
    printf("%d",a);
    return 0;
}
void test(int a){
    a=19;
}