#include <stdio.h>
#include <math.h>

int main() {
    FILE *outputFile;
    double omega = 1.0;  // You can change the value of omega as needed
    double T = 2 * M_PI / omega;
    double dt = T / 1000;  // Adjust the number of points as needed
    double t;
    
    // Open the output file for writing
    outputFile = fopen("output.dat", "w");
    
    // Check if the file is opened successfully
    if (outputFile == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    // Generate values of v_0(t) and write to the file
    for (t = 0.0; t <= T; t += dt) {
        double v0_t = 1000 * pow(sin(omega * t), 2);
        fprintf(outputFile, "%lf\t%lf\n", omega * t, v0_t);
    }
    
    // Close the output file
    fclose(outputFile);
    
    printf("Data written to output.dat successfully.\n");

    return 0;
}

