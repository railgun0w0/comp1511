#include <stdio.h>
#define MAX 4096

void print (char line[MAX]);
int main(void) {
    char line[MAX];
    int i;
    printf("Enter a string: ");
    fgets(line, MAX, stdin);
    print(line);
    return 0;
}

void print (char line[MAX]) {
    int i;
    for (i = 0; line[i] != '\n';i++) {
    printf("%c\n",line[i]);
    }
}