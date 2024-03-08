#include <stdio.h>
#include <math.h>

int main() {
    FILE *fp;
    fp = fopen("data_points.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    double t = 1.0;
    double pi = 3.14159265358979323846;
    while (t <= 10.0) {
        double y = sin(t - pi/4);
        fprintf(fp, "%.6f %.6f\n", t, y);
        t += 0.01;
    }
    fclose(fp);

    printf("Data points written to file successfully.\n");

    return 0;
}
