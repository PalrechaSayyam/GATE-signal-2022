#include <stdio.h>
#include <math.h>

#define N 100

// Define the function to calculate V_out for the given t
double V_out(double t) {
    if (t <= 0.5)
        return 0.8 * t;
    else if (t <= 2)
        return 0.4;
    else if (t <= 3)
        return 0.4 + (1 - 0.4) / (3 - 2) * (t - 2);
    else
        return 1;
}

int main() {
    double t_values[N], V_out_values[N];
    FILE *output_file;

    // Calculate V_out values for the specified t range
    int i;
    for (i = 0; i < N; i++) {
        t_values[i] = i * 0.1;  // Adjust the increment according to your needs
        V_out_values[i] = V_out(t_values[i]);
    }

    // Write t and V_out values to output_data.txt
    output_file = fopen("output_data.txt", "w");
    if (output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(output_file, "t\tV_out\n");
    for (i = 0; i < N; i++) {
        fprintf(output_file, "%.2f\t%.2f\n", t_values[i], V_out_values[i]);
    }

    fclose(output_file);

    return 0;
} 
