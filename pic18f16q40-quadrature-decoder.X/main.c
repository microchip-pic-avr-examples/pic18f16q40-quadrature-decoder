/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"

#include "encoder.h"
#include "constants.h"
#include "volume.h"

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
    Timer1_Start();
    Timer3_Start();
    
    //Start Polling Timer
    Timer2_OverflowCallbackRegister(&readTMRs_ISR);
    Timer2_Start();
        
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
                //Increment Counter
                UARTTrigger++;
            }
        }
        
        //Prevent Sleep while transmitting
        if (UART1_IsTxDone())
        {
            Sleep();
            Nop();
        }
        
    }
}
/**
 End of File
*/