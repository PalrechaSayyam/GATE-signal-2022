#include <stdio.h>
#include <complex.h>
#include <math.h>
int main() {
    
    double complex z , s ;// z is impedance and s is complex frequency variable
    float C ;// C is the capacitance 
    float w=5000 , L ;// w is the angular frequency and L be the inductance 
    L=5/w ;
    s = w*I;
   
     //From figure :
   //  z = 10+sL+{[(sL+1/sC)*sL]/sL+1/sC+sL}
     //For I=0 , z=infinity and 2+1/(Ls^2C)
    // C= -1/(2*(s)^2*L);
    double complex S =s*s ;
    
    
    if(cimag(S)==0){
        C= -1/(2*creal(S)*L);
    }
    // To convert it into mew Farad
  
   C = C * pow(10 , 6);
    printf("The value of capacitance is %f \u03BCF" , C);
    return 0;
}
