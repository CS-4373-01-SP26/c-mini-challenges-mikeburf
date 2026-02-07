#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void work(int n)
{
  int i, j;
  double sum;
  clock_t end, start;
  double arr[n][n];

  printf("Matrix created\n");

  // THIS FILLS THE MATRIX WITH NUMBERS
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      arr[i][j] = (double)rand() / RAND_MAX;

  printf("matrix filled\n");

  sum = 0;
  
  start = clock();
  for (i = 0; i < n; i++)   // iterate over rows
    for (j = 0; j < n; j++) // iterate over columns
      sum += arr[i][j];
  end = clock();

  // NOTE:  YOU'LL NEED TO PROVIDE MEANING TO end AND start
  printf("Row Major: sum = %lf and Clock Ticks are %ld\n", sum, end - start);

  sum = 0;

  start = clock();
  for (j = 0; j < n; j++) // iterate over columns
    for (i = 0; i < n; i++)   // iterate over rows
        sum += arr[i][j];
  end = clock();

  // NOTE:  YOU'LL NEED TO PROVIDE MEANING TO end AND start
  printf("Column Major: sum = %lf and Clock Ticks are %ld\n", sum, end - start);
}

int main(int argc, char **argv)
{  
  int n = 128;
  for (int i = 0; i < 5; i++) {
    printf("For %d by %d matrix...\n", n, n);
    int arr_size = n * n * sizeof(double);
    printf("%d\n", arr_size);
    work(n);
    printf("\n");
    n *= 2;
  }
  return 0;
}
