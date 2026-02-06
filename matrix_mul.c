#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUT_FILE "mv.txt"
#define READ_FAILED "Failed to read file\n"

int main() {

    FILE* file_ptr = fopen(INPUT_FILE, "r");

    if (file_ptr == NULL) {
        printf("File %s not found\n", INPUT_FILE);
        return 0;
    }

    int numrows;
    int numcols;

    if (fscanf(file_ptr, "%d %d", &numrows, &numcols) != 2) {
        printf(READ_FAILED);
        return 0;
    }

    int matrix[numrows][numcols];

    for (int r = 0; r < numrows; r++) {
        for (int c = 0; c < numcols; c++) {
            if (fscanf(file_ptr, "%d ", &matrix[r][c]) != 1) {
                printf(READ_FAILED);
                return 0;
            }
        }
    }

    int vecsize;

    if (fscanf(file_ptr, "%d", &vecsize) != 1) {
        printf(READ_FAILED);
        return 0;
    }

    if (vecsize != numcols) {
        printf("Cannot multiply %d by %d matrix with %d-vector\n");
        return 0;
    }

    int vector[vecsize];

    for (int i = 0; i < vecsize; i++) {
        if (fscanf(file_ptr, "%d ", &vector[i]) != 1) {
            printf("Failed to read file\n");
            return 0;
        }
    }

    int out_vector[numrows];

    clock_t start = clock();
    for (int r = 0; r < numrows; r++) {
        out_vector[r] = 0;
        for (int c = 0; c < numcols; c++) {
            out_vector[r] += matrix[r][c] * vector[c];
        }
    }
    clock_t end = clock();

    double seconds = (end - start) / CLOCKS_PER_SEC;

    printf("Resultant vector:\n(");
    for (int i = 0; i < numrows - 1; i++) {
        printf("%d, ", out_vector[i]);
    }
    printf("%d)\n", out_vector[numrows - 1]);
    printf("Calculation took %f seconds", seconds);

}

