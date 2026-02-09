#include <math.h>
#include <stdio.h>
#include <time.h>


int main() {

    const int max_sides = 800;

    // initial values for regular hexagons inscribed and circumscribed on unit circle
    int sides = 6;
    double peri_inner = 3.0;
    double peri_outer = sqrt(12.0);
    double pi_approx;

    clock_t start_all = clock();
    while (1) {
        pi_approx = (peri_outer + peri_inner) / 2; // pi approximated with average of both polygons
        printf("%d sides: p = %f\n", sides, pi_approx);
        sides *= 2;
        if (sides > max_sides) break;

        // calculate new perimeters from previous
        peri_outer = 2 / ((1 / peri_inner) + (1 / peri_outer));
        peri_inner = sqrt(peri_inner * peri_outer); // use of new peri_outer val is intentional
    }
    clock_t end_all = clock();

    printf("%d clock ticks to finish\n", end_all - start_all);
}