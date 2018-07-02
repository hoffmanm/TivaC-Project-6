// lab 09 task 02

#include <stdint.h>
#include <stdbool.h>
#include <math.h> // sine function
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h" // floating point unit
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define SERIES_LENGTH 1000 // change to 1000 test values

float gSeriesData[SERIES_LENGTH]; // Array of floating point numbers (each SERIES_LENGTH long)

int32_t i32DataCount = 0;// counter used for computation loop

int main(void)
{
    float fRadians; // to calculate sine value

    // Turn on lazy stacking and FPU
    FPULazyStackingEnable();
    FPUEnable();

    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN); // 50 MHZ clock

    // full sine wave cycle
    fRadians = ((2 * M_PI) / SERIES_LENGTH);

    // calculates the sine value for each of the 100 values of the angle and place them in the gSeriesData Array
    while(i32DataCount < SERIES_LENGTH)
    {
        // modified equation
        gSeriesData[i32DataCount] = 10*sinf(fRadians * i32DataCount) + 4*sinf(2*fRadians * i32DataCount)+ 3*sinf(4*fRadians * i32DataCount);

        i32DataCount++;
    }//while

    while(1) // infinite while
    {
    }

}//main