#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void work(int n)
{
  int i, j;
  double sum;
  clock_t end, start;
  double *arr = malloc(n * n * sizeof(double));

  if(arr == NULL) {
    printf("Failed to allocate array");
    return;
  }

  // THIS FILLS THE MATRIX WITH NUMBERS
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      arr[i * n + j] = (double)rand() / RAND_MAX;

  sum = 0;
  
  // row-major work
  start = clock();
  for (i = 0; i < n; i++)   // iterate over rows
    for (j = 0; j < n; j++) // iterate over columns
      sum += arr[i * n + j];
  end = clock();

  
  printf("Row Major: sum = %lf and Clock Ticks are %ld\n", sum, end - start);

  sum = 0;

  // column major work
  start = clock();
  for (j = 0; j < n; j++) // iterate over columns
    for (i = 0; i < n; i++)   // iterate over rows
      sum += arr[i * n + j];
  end = clock();

  printf("Column Major: sum = %lf and Clock Ticks are %ld\n", sum, end - start);

  free(arr); // free array
}

int main(int argc, char **argv)
{
  int n = 128;
  for (int i = 0; i < 7; i++) {
    printf("For %d by %d matrix...\n", n, n);
    work(n);
    printf("\n");
    n *= 2;
  }
  return 0;
}
