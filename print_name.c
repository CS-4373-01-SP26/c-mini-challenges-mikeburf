#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) printf("No name provided as input\n");
    else if (argc > 2) printf("Too many arguments provided as input\n");
    else {
        printf("%s\n", argv[1]);
    }
    return 0;
}