#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float trueRMS(float *volts, int samples);

int main(){
    float voltage[5] = {3.3, 1.8, 4.6, 3.9, 2.9};

    printf("Vrms = %.3fV\n", trueRMS(voltage, 5));

    return 0;
}

float trueRMS(float *volts, int samples){
    float rms = 0.0;

    for (int i = 0; i < samples; i++){
        volts[i] *= volts[i];
    }
    for (int i = 0; i < samples; i++){
        rms += volts[i];
    }

    rms /= samples;

    return sqrt(rms);
}