/*
#############################################################################################################

	File	    : GPIO.c
	Init date   : april / 2019

 -------------------------------------------------------------------------------------------------------------
*/
#include "MKL02Z4.h"   // include peripheral declarations
#include "GPIO.h"      // include library gpio

void  gpio_init(void)
{
SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; // turn on clock to port B

#ifdef LED1
  LED1_PCR = PCR_OUTPUT_CONFIG;     // Set the pin multiplexer to GPIO mode
  LED1_SET;                         // Set the initial output state to higth
  LED1_OUTPUT_EN;                   // Set the pins direcction to output
#endif

#ifdef LED2
  LED2_PCR = PCR_OUTPUT_CONFIG;
  LED2_OFF;
  LED2_OUTPUT_EN;
#endif

#ifdef LED3
  LED3_PCR = PCR_OUTPUT_CONFIG;
  LED3_OFF;
  LED3_OUTPUT_EN;
#endif

#ifdef LED4
  LED4_PCR = PCR_OUTPUT_CONFIG;
  LED4_OFF;
  LED4_OUTPUT_EN;
#endif

#ifdef SW1
   SW1_PCR = PCR_INPUT_CONFIG;
   SW1_INPUT_EN;
#endif

#ifdef SW2
   SW2_PCR = PCR_INPUT_CONFIG;
   SW2_INPUT_EN;
#endif
}
