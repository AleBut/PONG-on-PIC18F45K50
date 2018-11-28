#include <xc.h>

#include "config.h"
#include "potentiometer.h"

void pot_Init()            /* Initialize CAN */
{
    ADCON1 = 0b00001110;//VSS,VDD ref. AN0 analog only
    // bit 7-6 : Unimplemented 0
    // bit 5-4 : parameters
    // bit 3-0 : Port Configuration Control bits
	ADCON0 = 0b0000000;//clear ADCON0 to select channel 0 (AN0)
	// bit 7-6 : unimplemented 0
	// bit 5-2 : Analog Channel Select bits
	// bit 1-0 : 10
	ADCON2 = 0b00001000;//ADCON2 setup: Left justified, Tacq=2Tad, Tad=2*Tosc (or Fosc/2) - ACQUISITION TIME

	ADCON0bits.ADON = 0x01;//Enable A/D module
}

int getPotValue()      /* Get the % of input */
{
    int adc_in=0; // Value that we will send back
    
    ADCON0bits.GO_DONE = 1;//Start A/D Conversion

	while(ADCON0bits.GO_DONE != 0);//Loop here until A/D conversion completes

	adc_in = ADRESH;

	adc_in *= 100; // We want the result in %
    adc_in /= 255; // We had a ratio over 255

	return adc_in;
}

