#include <stdio.h>

int main(int argc, char* argv[]) {

    // if not enough args provided. arg[0] is program name
    if (argc < 2) printf("No name provided as input\n");

    // if too many args provided
    else if (argc > 2) printf("Too many arguments provided as input\n");

    // print name
    else {
        printf("%s\n", argv[1]);
    }
    return 0;
}