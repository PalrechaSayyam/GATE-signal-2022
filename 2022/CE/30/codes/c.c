#include <stdio.h>
#include <math.h>
#include "mylib.h"
float f(float x){
return pow(cos(x) , 4);
}
int main() {
    // Define the range and step size
    float start = -M_PI;
    float stop = M_PI;
    float step = 0.1;

    // Calculate the number of values in the range
    int num_values = (stop - start) / step + 1;

    // Allocate arrays to store the generated values
    float x_values[num_values];
    float y_values[num_values];
	float(*func)(float);
	func = f;
    // Call the linspace function
    linspace(start, stop, step, x_values, y_values, num_values, func);
    //Call save function
    save(num_values, x_values, y_values);
    }
