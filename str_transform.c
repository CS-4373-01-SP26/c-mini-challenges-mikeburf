#include <stdio.h>
#include <stdlib.h>

#define INPUT_BUFFER_SIZE 512


void transform(char **string, int size, int (*transpose)(int, int)) {

    char* out = malloc(size * sizeof(char));
    size--; // dont modify final \0

    for (int i = 0; i < size; i++) {
        out[i] = (*string)[transpose(i, size)];
    }

    free(*string);

    *string = out;
}

int reverse(int i, int size) {
    return size - i - 1;
}

int main() {
    
    char * string = malloc(INPUT_BUFFER_SIZE * sizeof(char));

    printf("Enter a string:\n");

    fgets(string, INPUT_BUFFER_SIZE, stdin);

    int size = 0;
    while(string[size++] != '\0');

    // remove newline
    size--; 
    string[size - 1] = '\0';

    transform(&string, size, reverse);

    printf("%s", string);
}