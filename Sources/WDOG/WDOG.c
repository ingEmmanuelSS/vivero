/*
 * File:        wdog.c
 * Purpose:     Provide common watchdog module routines
 *
 * Notes:		Need to add more functionality. Right now it
 * 				is just a disable routine since we know almost
 * 				all projects will need that.       
 *              
 */
#include "MKL02Z4.h"
#include "wdog.h"
       

void wdog_enable(void)
{
    SIM_COPC |= SIM_COPC_COPT(3);
}

void wdog_disable(void)
{
    SIM_COPC = 0x00;
}
/********************************************************************/
