#include <stdint.h>
#include <stdbool.h>
#include <math.h>                   // for the sinf() function 
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h"          // for the floating point unit 
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"

#ifndef M_PI
#define M_PI                    3.14159265358979323846
#endif

#define SERIES_LENGTH 100

float gSeriesData[SERIES_LENGTH];       // an array of floats SERIES_LENGTH long

int32_t i32DataCount = 0;               // counter for computation loop 

int main(void)
{
    float fRadians;                     // to calculate sine 

    ROM_FPULazyStackingEnable();        // turn on lazy stacking 
    ROM_FPUEnable();                    // turn on the FPU 

    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);         // set up the 50 MHZ clock 

    fRadians = ((2 * M_PI) / SERIES_LENGTH);        // full sine wave cycle 

    while(i32DataCount < SERIES_LENGTH)             // calculates the sine value for each of the 100 values of the angle and place them in the array 
    {
        gSeriesData[i32DataCount] = sinf(fRadians * i32DataCount);

        i32DataCount++;
    }

    while(1)
    {
    }
}