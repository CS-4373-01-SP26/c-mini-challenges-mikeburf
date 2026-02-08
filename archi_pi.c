#include <math.h>
#include <stdio.h>


int main() {

    const int max_sides = 800;

    // initial values for regular hexagons inscribed and circumscribed on unit circle
    int sides = 6;
    double peri_inner = 3.0;
    double peri_outer = sqrt(12.0);
    double pi_approx;

    while (1) {
        pi_approx = (peri_outer + peri_inner) / 2; // pi approximated with average of both polygons
        printf("%d sides: p = %f\n, error:", sides, pi_approx);
        sides *= 2;
        if (sides > max_sides) break;

        // calculate new perimeters from previous
        peri_outer = 2 / ((1 / peri_inner) + (1 / peri_outer));
        peri_inner = sqrt(peri_inner * peri_outer); // use of new peri_outer val is intentional
    }
}