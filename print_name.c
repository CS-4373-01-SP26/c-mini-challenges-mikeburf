#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) printf("No name provided as input");
    else if (argc > 2) printf("Too many arguments provided as input");
    else {
        printf(argv[1]);
    }
    return 0;
}