#include <stdio.h>
#include <math.h>

// Given constants
double e = -1.6e-19;        // Charge on electron (C)
double m = 9.1e-31;         // Mass of electron (kg)
double epsilon_0 = 8.85e-12; // Permittivity of free space (C^2/N*m^2)

// Frequency range for the spectrometer (rad/s)
double omega_min = 3e12;
double omega_max = 30e12;

// Specific carrier concentration
double n = 2.83e21; // m^-3

// Function for spectrometer response
double spectrometer_response(double omega, double omega_min, double omega_max) {
    return exp(-(pow(omega - (omega_min + omega_max) / 2, 2) / pow((omega_max - omega_min) / 2, 2)));
}

int main() {
    // Calculate plasma frequency for the specific n
    double omega_p = sqrt((n * pow(e, 2)) / (epsilon_0 * m));

    // Open file for writing
    FILE *file = fopen("ph35.dat", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return 1;
    }

    // Print title to the file
    fprintf(file, "# Plasma Frequency Calculation Results\n");
    fprintf(file, "# Frequency (rad/s)\tSpectrometer Response\n");

    // Calculate and write spectrometer response to file
    int num_points = 1000;
    double omega_range[num_points];
    double response[num_points];

    for (int i = 0; i < num_points; i++) {
        omega_range[i] = omega_min + i * (omega_max - omega_min) / (num_points - 1);
        response[i] = spectrometer_response(omega_range[i], omega_min, omega_max);
        fprintf(file, "%.15f\t%.15f\n", omega_range[i], response[i]);
    }

    // Close the file
    fclose(file);
    
    return 0;
}


