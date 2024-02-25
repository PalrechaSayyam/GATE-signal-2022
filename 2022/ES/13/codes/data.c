#include <stdio.h>
#include <math.h>

// Define the Laplace function
double laplace_function(double s, double a) {
    return s / (s * s + a * a);
}

// Define the function sin(ax)
double sin_function(double x) {
    return sin(x);
}

int main() {
    FILE *file1 = fopen("data1.txt", "w");
    FILE *file2 = fopen("data2.txt", "w");
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    // Generate x values
    double x, s;
    for (x = -10; x <= 10; x += 0.05) {
        // Calculate sin(x) values and save to data1.txt
        fprintf(file1, "%.2f, %.4f\n", x, sin_function(x));
    }

    // Generate s values
    for (s = -10; s <= 10; s += 0.05) {
        // Calculate Laplace of sin(x) values and save to data2.txt
        fprintf(file2, "%.2f, %.4f\n", s, laplace_function(s, 1));
    }

    fclose(file1);
    fclose(file2);
    
    printf("Data Generated Successfully.\n");
    return 0;
}

