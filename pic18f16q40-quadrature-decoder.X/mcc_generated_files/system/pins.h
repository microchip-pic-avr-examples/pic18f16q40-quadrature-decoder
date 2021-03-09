/**
  Generated Pins header File

  Company:
    Microchip Technology Inc.

  File Name:
    pins.h

  Summary:
    This is generated driver header for pins. 

  Description:
    This header file provides APIs for all pins selected in the GUI.

  Generation Information:
    Driver Version:  3.0.0

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

#ifndef PINS_H
#define PINS_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA4 aliases
#define LED8_TRIS                 TRISAbits.TRISA4
#define LED8_LAT                  LATAbits.LATA4
#define LED8_PORT                 PORTAbits.RA4
#define LED8_WPU                  WPUAbits.WPUA4
#define LED8_OD                   ODCONAbits.ODCA4
#define LED8_ANS                  ANSELAbits.ANSELA4
#define LED8_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED8_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED8_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED8_GetValue()           PORTAbits.RA4
#define LED8_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED8_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED8_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED8_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED8_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LED8_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LED8_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define LED8_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 aliases
#define LED9_TRIS                 TRISAbits.TRISA5
#define LED9_LAT                  LATAbits.LATA5
#define LED9_PORT                 PORTAbits.RA5
#define LED9_WPU                  WPUAbits.WPUA5
#define LED9_OD                   ODCONAbits.ODCA5
#define LED9_ANS                  ANSELAbits.ANSELA5
#define LED9_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED9_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED9_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED9_GetValue()           PORTAbits.RA5
#define LED9_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED9_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED9_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED9_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED9_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED9_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED9_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED9_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB4 aliases
#define A_INPUT_TRIS                 TRISBbits.TRISB4
#define A_INPUT_LAT                  LATBbits.LATB4
#define A_INPUT_PORT                 PORTBbits.RB4
#define A_INPUT_WPU                  WPUBbits.WPUB4
#define A_INPUT_OD                   ODCONBbits.ODCB4
#define A_INPUT_ANS                  ANSELBbits.ANSELB4
#define A_INPUT_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define A_INPUT_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define A_INPUT_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define A_INPUT_GetValue()           PORTBbits.RB4
#define A_INPUT_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define A_INPUT_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define A_INPUT_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define A_INPUT_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define A_INPUT_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define A_INPUT_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define A_INPUT_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define A_INPUT_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RB6 aliases
#define B_INPUT_TRIS                 TRISBbits.TRISB6
#define B_INPUT_LAT                  LATBbits.LATB6
#define B_INPUT_PORT                 PORTBbits.RB6
#define B_INPUT_WPU                  WPUBbits.WPUB6
#define B_INPUT_OD                   ODCONBbits.ODCB6
#define B_INPUT_ANS                  ANSELBbits.ANSELB6
#define B_INPUT_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define B_INPUT_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define B_INPUT_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define B_INPUT_GetValue()           PORTBbits.RB6
#define B_INPUT_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define B_INPUT_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define B_INPUT_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define B_INPUT_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define B_INPUT_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define B_INPUT_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define B_INPUT_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define B_INPUT_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODCB7
#define IO_RB7_ANS                  ANSELBbits.ANSELB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set RC0 aliases
#define LED0_TRIS                 TRISCbits.TRISC0
#define LED0_LAT                  LATCbits.LATC0
#define LED0_PORT                 PORTCbits.RC0
#define LED0_WPU                  WPUCbits.WPUC0
#define LED0_OD                   ODCONCbits.ODCC0
#define LED0_ANS                  ANSELCbits.ANSELC0
#define LED0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LED0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LED0_GetValue()           PORTCbits.RC0
#define LED0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LED0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define LED0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define LED0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define LED0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define LED0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define LED0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 aliases
#define LED1_TRIS                 TRISCbits.TRISC1
#define LED1_LAT                  LATCbits.LATC1
#define LED1_PORT                 PORTCbits.RC1
#define LED1_WPU                  WPUCbits.WPUC1
#define LED1_OD                   ODCONCbits.ODCC1
#define LED1_ANS                  ANSELCbits.ANSELC1
#define LED1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LED1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LED1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LED1_GetValue()           PORTCbits.RC1
#define LED1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define LED1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC2 aliases
#define LED2_TRIS                 TRISCbits.TRISC2
#define LED2_LAT                  LATCbits.LATC2
#define LED2_PORT                 PORTCbits.RC2
#define LED2_WPU                  WPUCbits.WPUC2
#define LED2_OD                   ODCONCbits.ODCC2
#define LED2_ANS                  ANSELCbits.ANSELC2
#define LED2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED2_GetValue()           PORTCbits.RC2
#define LED2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LED2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 aliases
#define LED3_TRIS                 TRISCbits.TRISC3
#define LED3_LAT                  LATCbits.LATC3
#define LED3_PORT                 PORTCbits.RC3
#define LED3_WPU                  WPUCbits.WPUC3
#define LED3_OD                   ODCONCbits.ODCC3
#define LED3_ANS                  ANSELCbits.ANSELC3
#define LED3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED3_GetValue()           PORTCbits.RC3
#define LED3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LED3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 aliases
#define LED4_TRIS                 TRISCbits.TRISC4
#define LED4_LAT                  LATCbits.LATC4
#define LED4_PORT                 PORTCbits.RC4
#define LED4_WPU                  WPUCbits.WPUC4
#define LED4_OD                   ODCONCbits.ODCC4
#define LED4_ANS                  ANSELCbits.ANSELC4
#define LED4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LED4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LED4_GetValue()           PORTCbits.RC4
#define LED4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LED4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LED4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LED4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define LED4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define LED4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define LED4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define LED5_TRIS                 TRISCbits.TRISC5
#define LED5_LAT                  LATCbits.LATC5
#define LED5_PORT                 PORTCbits.RC5
#define LED5_WPU                  WPUCbits.WPUC5
#define LED5_OD                   ODCONCbits.ODCC5
#define LED5_ANS                  ANSELCbits.ANSELC5
#define LED5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED5_GetValue()           PORTCbits.RC5
#define LED5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LED5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LED5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define LED5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 aliases
#define LED6_TRIS                 TRISCbits.TRISC6
#define LED6_LAT                  LATCbits.LATC6
#define LED6_PORT                 PORTCbits.RC6
#define LED6_WPU                  WPUCbits.WPUC6
#define LED6_OD                   ODCONCbits.ODCC6
#define LED6_ANS                  ANSELCbits.ANSELC6
#define LED6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LED6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LED6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LED6_GetValue()           PORTCbits.RC6
#define LED6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LED6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LED6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define LED6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define LED6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define LED6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define LED6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define LED6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 aliases
#define LED7_TRIS                 TRISCbits.TRISC7
#define LED7_LAT                  LATCbits.LATC7
#define LED7_PORT                 PORTCbits.RC7
#define LED7_WPU                  WPUCbits.WPUC7
#define LED7_OD                   ODCONCbits.ODCC7
#define LED7_ANS                  ANSELCbits.ANSELC7
#define LED7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED7_GetValue()           PORTCbits.RC7
#define LED7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LED7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LED7_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LED7_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LED7_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define LED7_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PINS_H
/**
 End of File
*/