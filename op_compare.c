#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

const int BENCHMARK_ITERS = 100000000;
const int ARG_BUFFER_SIZE = 4096;

// fills a buffer with random integers from 1 to RAND_MAX + 1 (whatever that is)
void fill_buffer(int* buffer, int size) {
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

    // to avoid huge buffers and precision errors we do the measuring in medium-sized chunks
    while(iters_left > 0) {
        // run min(iters_left, ARG_BUFFER_SIZE) iters
        int iters_next = (iters_left < ARG_BUFFER_SIZE) ? iters_left : ARG_BUFFER_SIZE;

        // fill both buffers
        fill_buffer(bufferA, iters_next);
        fill_buffer(bufferB, iters_next);

        // run the function
        double result;
        clock_t start = clock();
        for (int i = 0; i < iters_next; i++) {
            result = func(bufferA[i], bufferB[i]);
        }
        clock_t end = clock();

        // add time to total time
        total += (end - start);

        // decrement iters
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

double my_sqrt(double x, double trash) {
    return sqrt(x);
}

double my_sin(double x, double trash) {
    return sin(x);
}


int main() {

    double secs;
    double secs_avg;

    printf("Will run %d iters per op\n\n", BENCHMARK_ITERS);

    printf("Benchmarking multiplication...\n");
    secs = benchmark(BENCHMARK_ITERS, my_mul);
    secs_avg = secs / BENCHMARK_ITERS;
    printf("Ran in %f seconds, avg %.10f seconds/iter\n\n", secs, secs_avg);

    printf("Benchmarking division...\n");
    secs = benchmark(BENCHMARK_ITERS, my_div);
    secs_avg = secs / BENCHMARK_ITERS;
    printf("Ran in %f seconds, avg %.10f seconds/iter\n\n", secs, secs_avg);

    printf("Benchmarking square root...\n");
    secs = benchmark(BENCHMARK_ITERS, my_sqrt);
    secs_avg = secs / BENCHMARK_ITERS;
    printf("Ran in %f seconds, avg %.10f seconds/iter\n\n", secs, secs_avg);

    printf("Benchmarking sine...\n");
    secs = benchmark(BENCHMARK_ITERS, my_sin);
    secs_avg = secs / BENCHMARK_ITERS;
    printf("Ran in %f seconds, avg %.10f seconds/iter\n\n", secs, secs_avg);

    return 0;
}