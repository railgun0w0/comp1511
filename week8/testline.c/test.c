// Convert command-line arguments to integers and print their sum.
//
// No check is made that the command-line arguments are actually integers.
// See strol for a more powerful library function which would allow checking.
//
// COMP1511 lecture example
// Andrew Taylor - andrewt@unsw.edu.au
// 24/4/18

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int sum = 0;
    int argument = 1;
    while (argument < argc) {
        sum = sum + atoi(argv[argument]);
        argument= argument + 1;
    }
    printf("sum of command-line arguments = %d\n", sum);

    return 0;
}