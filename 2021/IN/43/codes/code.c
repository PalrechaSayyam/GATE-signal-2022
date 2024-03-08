#include <stdio.h>
#include <math.h>

#define NUM_POINTS 1000
#define TIME_MIN -4
#define TIME_MAX 10

// Step function u(t)
double u(double t) {
    return t >= 0 ? 1.0 : 0.0;
}

// Function y(t)
double y(double t) {
    return u(t + 3) / 3.0 - exp(-3 * (t + 3)) * u(t + 3) / 3.0;
}

int main() {
    double t_values[NUM_POINTS];
    double y_values[NUM_POINTS];
    double t_step = (TIME_MAX - TIME_MIN) / (double)(NUM_POINTS - 1);
    
    // Generate t values
    for (int i = 0; i < NUM_POINTS; i++) {
        t_values[i] = TIME_MIN + i * t_step;
    }
    
    // Generate y values
    for (int i = 0; i < NUM_POINTS; i++) {
        y_values[i] = y(t_values[i]);
    }
    
    // Save the generated values to file
    FILE *file = fopen("data.dat", "w");
    if (file != NULL) {
        fprintf(file, "t\ty(t)\n");
        for (int i = 0; i < NUM_POINTS; i++) {
            fprintf(file, "%.6f\t%.6f\n", t_values[i], y_values[i]);
        }
        fclose(file);
    }
    
    return 0;
}

