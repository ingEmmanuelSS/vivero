/*
 * File:        adc.c
 *
 * Notes:       
 *              
 */

#include "MKL02Z4.h"
#include "ADC.h"

/****************************************************************
                  initial the ADC module
*****************************************************************/
void adc_init( void )
{
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;  // enable ADC0 clock

	ADCx_PCR = PCR_ADCx_CONFIG;       // Set the pin multiplexer to ADC mode

  	ADC0_CFG1 = ADC_CFG1_ADIV(1)|     // Clock Divide Select
  				ADC_CFG1_MODE(1)|     // Conversion mode selection
  				ADC_CFG1_ADICLK(0);   // Input Clock Select
}

/****************************************************************
                      software trigger channel x
*****************************************************************/
void adc_Trigger(__int8_t Channel)
{
  if(Channel == 0x1B)                    // Bandgap is selected as input
      PMC_REGSC |= PMC_REGSC_BGBE_MASK;  // Bandgap buffer enabled

  ADC0_SC1A = Channel;                   // update the channel value
  //ADC0_SC1A |= ADC_SC1_ADCH(Channel);
}

/****************************************************************
                      ADC Read
*****************************************************************/
__int16_t ReadADCPoll(void)
{
    while((ADC0_SC1A & ADC_SC1_COCO_MASK) == 0);
    return ADC0_RA;
}

