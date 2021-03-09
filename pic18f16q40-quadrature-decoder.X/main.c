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
#include "mcc_generated_files/system/system.h"

#include "encoder.h"
#include "constants.h"
#include "volume.h"

void __interrupt(irq(U1TX),base(8)) UART_TX_HOTFIX_ISR()
{
    UART1_Transmit_ISR();
}

#define TIMER1_16BIT_ENABLE() do { TMR1CONbits.RD16 = 0b1; } while (0)
#define TIMER3_16BIT_ENABLE() do { TMR3CONbits.RD16 = 0b1; } while (0)

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    //Init Encoder Functions
    initEncoders();
    initVolumeControl();
        
    //Start Pulse Counters
    TIMER1_16BIT_ENABLE();
    Timer1_Write(0x0000);
    Timer1_Start();
    
    TIMER3_16BIT_ENABLE();
    Timer3_Write(0x0000);
    Timer3_Start();
    
    //Start Polling Timer
    Timer2_OverflowCallbackRegister(&readTMRs_ISR);
    Timer2_Start();
        
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptHighEnable();
    INTERRUPT_GlobalInterruptLowEnable();
    
    //Sum of all encoder values in the period
    int encoderCounter = 0;
    
    //Counter to trigger UART update
    int UARTTrigger = 1;
    
    while (1)
    {
        if (isNewEncoderValue())
        {
            //Clears the "new encoder" flag
            clearNewEncoder();
            
            encoderCounter += getNewEncoderValue();
            
            //Adjusts the "Volume"
            adjustVolume(getNewEncoderValue());
            
            //Display the volume on the LEDs
            displayVolume();
            
            //Send data every 1 second
            if (UARTTrigger == UART_COUNTER_DELAY)
            {
                //Transmit the Encoder Value via UART
                printf("Encoder Value: %i\n\rVolume: %i\n\r", encoderCounter, getCurrentVolume());  
                
                //Reset the Counter
                UARTTrigger = 1;
                
                //Clear accumulated encoderValues
                encoderCounter = 0;
            }
            else
            {
                //Increment Counter
                UARTTrigger++;
            }
        }
        
        //Prevent Sleep while transmitting
        if (UART1_is_tx_done())
        {
            //Sleep();
            asm("NOP");
        }
        
    }
}
/**
 End of File
*/