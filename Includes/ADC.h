/*
 * File:		adc.h
 * Purpose:     
 *
 * Notes:
 */

#ifndef __ADC_H__
#define __ADC_H__

#include "MACROS.h"
//----------------------------------------------------------------------------
//
// Definitions
//
//----------------------------------------------------------------------------

// User should only define wich port and the bit

#define ADCx_PORT   B
#define ADCx_BIT    6

// Compilation time Definitions

#define PCR_ADCx_CONFIG                         (PORT_PCR_MUX(2))   //Pin configured as ADC

/*****************************  ADCx *****************************/

#define ADCx_PCR       							ADCx_PCR_CONFIG(ADCx_PORT,ADCx_BIT)
#define ADCx_PCR_CONFIG(ADCx_PORT,ADCx_BIT)  	PCR(ADCx_PORT,ADCx_BIT)

/********************************************************************/

void       InitADC             ( void );
void       TriggerADC          (__int8_t Channel);
__int16_t  ReadADCPoll         (void);

/********************************************************************/

#endif /* __ADC_H__ */
