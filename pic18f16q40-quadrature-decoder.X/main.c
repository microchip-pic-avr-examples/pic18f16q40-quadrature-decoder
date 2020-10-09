/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC18F16Q40
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "encoder.h"
#include "constants.h"
#include "volume.h"

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    //Init Encoder Functions
    initEncoders();
    initVolumeControl();
        
    //Start Pulse Counters
    TMR1_StartTimer();
    TMR3_StartTimer();
    
    //Start Polling Timer
    TMR2_SetInterruptHandler(&readTMRs_ISR);
    TMR2_StartTimer();
        
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    
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
                UARTTrigger++;
            }
        }
        
        //Prevent Sleep while transmitting
        if (UART1_is_tx_done())
        {
            Sleep();
            asm("NOP");
        }
        
    }
}
/**
 End of File
*/