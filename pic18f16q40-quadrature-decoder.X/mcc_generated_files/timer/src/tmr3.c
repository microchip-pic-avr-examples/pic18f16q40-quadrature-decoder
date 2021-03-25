/**
  TMR3 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr3.c

  @Summary
    This is the generated driver implementation file for the TMR3 driver

  @Description
    This source file provides APIs for driver for TMR3.
    Generation Information :
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.20
        MPLAB             :  MPLAB X v5.40
*/
/*
Copyright (c) [2012-2020] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "../tmr3.h"

/**
  Section: Global Variables Definitions
*/
volatile uint16_t timer3ReloadVal;
void (*Timer3_InterruptHandler)(void);

const struct TMR_INTERFACE Timer3 = {
    .Initialize = Timer3_Initialize,
    .Start = Timer3_Start,
    .Stop = Timer3_Stop,
    .PeriodCountSet = Timer3_Write,
    .TimeoutCallbackRegister = Timer3_OverflowCallbackRegister,
    .Tasks = Timer3_Tasks
};
static void (*Timer3_OverflowCallback)(void);
static void Timer3_DefaultOverflowCallback(void);

void Timer3_Initialize(void)

{
    //TGGO done; TGSPM disabled; TGTM disabled; TGPOL low; TMRGE disabled; 
    T3GCON = 0x0;
    //TGSS T3GPPS; 
    T3GATE = 0x0;
    //TMRCS CLC2_OUT; 
    T3CLK = 0xE;
    //TMRH 255; 
    TMR3H = 0xFF;
    //TMRL 255; 
    TMR3L = 0xFF;

    // Load the TMR3 value to reload variable
    timer3ReloadVal=(uint16_t)((TMR3H << 8) | TMR3L);

    //Set default callback for TMR3 overflow interrupt
    Timer3_OverflowCallbackRegister(Timer3_DefaultOverflowCallback);

    //Clear interrupt flags
    PIR4bits.TMR3IF = 0;
    PIR4bits.TMR3GIF = 0;
    
    T3CON = 0x4;
}

void Timer3_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T3CONbits.TMR3ON = 1;
}

void Timer3_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T3CONbits.TMR3ON = 0;
}

uint16_t Timer3_Read(void)
{
    uint16_t readVal;
    uint8_t readValHigh;
    uint8_t readValLow;
    
	
    readValLow = TMR3L;
    readValHigh = TMR3H;
    
    readVal = ((uint16_t)readValHigh << 8) | readValLow;

    return readVal;
}

void Timer3_Write(size_t timerVal)
{
    if (T3CONbits.NOT_SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T3CONbits.TMR3ON = 0;

        // Write to the Timer3 register
        TMR3H = (uint8_t)(timerVal >> 8);
        TMR3L = (uint8_t)timerVal;

        // Start the Timer after writing to the register
        T3CONbits.TMR3ON = 1;
    }
    else
    {
        // Write to the Timer3 register
        TMR3H = (uint8_t)(timerVal >> 8);
        TMR3L = (uint8_t)timerVal;
    }
}

void Timer3_Reload(void)
{
    Timer3_Write(timer3ReloadVal);
}

void Timer3_StartSinglePulseAcquisition(void)
{
    T3GCONbits.T3GGO = 1;
}

uint8_t Timer3_CheckGateValueStatus(void)
{
    return (T3GCONbits.T3GVAL);
}


void Timer3_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    Timer3_OverflowCallback = CallbackHandler;
}

static void Timer3_DefaultOverflowCallback(void)
{
    //Add your interrupt code here or
    //Use Timer3_OverflowCallbackRegister function to use Custom ISR
}

bool Timer3_HasOverflowOccured(void)
{
    return(PIR4bits.TMR3IF);
}

void Timer3_GATE_ISR(void)
{
    // clear the TMR3 interrupt flag
    PIR4bits.TMR3GIF = 0;
}

void Timer3_Tasks(void)
{
    if(PIR4bits.TMR3IF)
    {
        PIR4bits.TMR3IF = 0;
        Timer3_OverflowCallback();
    }
}

/**
  End of File
*/