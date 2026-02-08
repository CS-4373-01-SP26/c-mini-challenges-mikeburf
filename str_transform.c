#include <stdio.h>
#include <stdlib.h>

const int INPUT_BUFFER_SIZE = 100;

// creates a transformed copy of the string, free()s the original, then makes the original's pointer point to the copy
// probably not smart or useful but I think I get pointers now
void transform(char **string, int size, int (*transpose)(int, int)) {

    // create copy
    char* out = malloc(size * sizeof(char));
    size--; // dont modify final \0

    // perform transposition
    for (int i = 0; i < size; i++) {
        out[i] = (*string)[transpose(i, size)];
    }

    // free orig
    free(*string);

    // point to copy
    *string = out;
}

// example transformation function
int reverse(int i, int size) {
    return size - i - 1;
}

int main() {
    
    char * string = malloc(INPUT_BUFFER_SIZE * sizeof(char));

    printf("Enter a string:\n");

    fgets(string, INPUT_BUFFER_SIZE, stdin);

    // finds the actual size of the input string
    int size = 0;
    while(string[size++] != '\0');

    // remove newline
    size--; 
    string[size - 1] = '\0';

    transform(&string, size, reverse);

    printf("%s", string);
}