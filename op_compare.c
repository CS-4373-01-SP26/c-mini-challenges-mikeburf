#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define BENCHMARK_ITERS 10000000
#define ARG_BUFFER_SIZE 2048

void fill_buffer(int* buffer, int size) {
    srand(time(NULL));
    for (int i = 0; i< size; i++) {
        buffer[i] = rand() + 1; // avoid 0
    }
}

double benchmark(int iters, double (*func) (double, double)) {

    int iters_left = iters;

    // to avoid counting the cost of generating random numbers in the measured time, we pregenerate them
    int bufferA[ARG_BUFFER_SIZE];
    int bufferB[ARG_BUFFER_SIZE];

    clock_t total = 0;

    while(iters_left > 0) {
        int iters_next = (iters_left < ARG_BUFFER_SIZE) ? iters_left : ARG_BUFFER_SIZE;
        fill_buffer(bufferA, iters_next);
        fill_buffer(bufferB, iters_next);

        double result;
        clock_t start = clock();
        for (int i = 0; i < iters_next; i++) {
            result = func(bufferA[i], bufferB[i]);
        }
        clock_t end = clock();

        total += (end - start);

        iters_left -= iters_next;
    }

    return (double)total / CLOCKS_PER_SEC;
}


double my_mul(double a, double b) {
    return a * b;
}

double my_div(double n, double d) {
    return n / d;
}

// hopefully the performance cost of passing an unused variable is minimal
// will do some research
double my_sqrt(double x, double trash) {
    return sqrt(x);
}

double my_sin(double x, double trash) {
    return sin(x);
}

int main() {

    double seconds;
    double avg_seconds;

    printf("Benchmarking multiplication...\n");
    seconds = benchmark(BENCHMARK_ITERS, my_mul);
    avg_seconds = seconds / BENCHMARK_ITERS;
    printf("Ran %d iters in %f seconds, avg %f seconds per iter\n", BENCHMARK_ITERS, seconds, avg_seconds);

    

    printf("Benchmarking division...\n");
    seconds = benchmark(BENCHMARK_ITERS, my_div);
    avg_seconds = seconds / BENCHMARK_ITERS;
    printf("Ran %d iters in %f seconds, avg %f seconds per iter\n", BENCHMARK_ITERS, seconds, avg_seconds);

    

    printf("Benchmarking square root...\n");
    seconds = benchmark(BENCHMARK_ITERS, my_sqrt);
    avg_seconds = seconds / BENCHMARK_ITERS;
    printf("Ran %d iters in %f seconds, avg %f seconds per iter\n", BENCHMARK_ITERS, seconds, avg_seconds);

    

    printf("Benchmarking sine...\n");
    seconds = benchmark(BENCHMARK_ITERS, my_sin);
    avg_seconds = seconds / BENCHMARK_ITERS;
    printf("Ran %d iters in %f seconds, avg %f seconds per iter\n", BENCHMARK_ITERS, seconds, avg_seconds);

    return 0;
}