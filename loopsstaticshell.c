#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void work(int n)
{
  int i, j;
  double sum;
  clock_t end, start;
  double arr[n][n];

  // THIS FILLS THE MATRIX WITH NUMBERS
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      arr[i][j] = (double)rand() / RAND_MAX;

  sum = 0;
  
  // perform and measure row-major work
  start = clock();
  for (i = 0; i < n; i++)   // iterate over rows
    for (j = 0; j < n; j++) // iterate over columns
      sum += arr[i][j];
  end = clock();

  // output
  printf("Row Major: sum = %lf and Clock Ticks are %ld\n", sum, end - start);

  sum = 0;

  // perform and measure column-major work
  start = clock();
  for (j = 0; j < n; j++) // iterate over columns
    for (i = 0; i < n; i++)   // iterate over rows
        sum += arr[i][j];
  end = clock();

  printf("Column Major: sum = %lf and Clock Ticks are %ld\n", sum, end - start);
}

int main(int argc, char **argv)
{ 
  int n = 128;
  for (int i = 0; i < 2; i++) { // i has to stay small due to restrictions on stack size
    printf("For %d by %d matrix...\n", n, n);
    work(n);
    printf("\n");
    n *= 2;
  }
  return 0;
}
