/**
  @Generated CCL Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    config_bits.c

  @Summary:
    This is the config_bits.c file generated using CCL

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information : 
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.31
        MPLAB             :  MPLAB X 5.45
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

// Configuration bits: selected in the GUI

//CONFIG1
#pragma config FEXTOSC = OFF     // External Oscillator Mode Selection->Oscillator not enabled
#pragma config RSTOSC = HFINTOSC_64MHZ     // Power-up Default Value for COSC->HFINTOSC with HFFRQ = 64 MHz and CDIV = 1:1

//CONFIG2
#pragma config FCMENP = ON     // Fail-Safe Clock Monitor Enable - Primary XTAL Enable->Fail-Safe Clock Monitor enabled; timer will flag FSCMP bit and OSFIF interrupt on EXTOSC failure.
#pragma config CLKOUTEN = OFF     // Clock Out Enable->CLKOUT function is disabled
#pragma config FCMEN = ON     // Fail-Safe Clock Monitor Enable->Fail-Safe Clock Monitor enabled
#pragma config CSWEN = ON     // Clock Switch Enable->Writing to NOSC and NDIV is allowed
#pragma config FCMENS = ON     // Fail-Safe Clock Monitor Enable - Secondary XTAL Enable->Fail-Safe Clock Monitor enabled; timer will flag FSCMP bit and OSFIF interrupt on SOSC failure.
#pragma config PR1WAY = ON     // PRLOCKED One-Way Set Enable->PRLOCKED bit can be cleared and set only once

//CONFIG3
#pragma config MVECEN = OFF     // Multivector Enable->Interrupt contoller does not use vector table to prioritze interrupts
#pragma config MCLRE = EXTMCLR     // Master Clear (MCLR) Enable->If LVP = 0, MCLR pin is MCLR; If LVP = 1, RE3 pin function is MCLR 
#pragma config BOREN = SBORDIS     // Brown-out Reset Enable->Brown-out Reset enabled , SBOREN bit is ignored
#pragma config PWRTS = PWRT_OFF     // Power-up Timer Selection->PWRT is disabled
#pragma config IVT1WAY = ON     // IVTLOCK One-Way Set Enable->IVTLOCKED bit can be cleared and set only once
#pragma config LPBOREN = OFF     // Low-Power BOR Enable->Low-Power BOR disabled

//CONFIG4
#pragma config XINST = OFF     // Extended Instruction Set Enable->Extended Instruction Set and Indexed Addressing Mode disabled
#pragma config LVP = ON     // Low-Voltage Programming Enable->Low voltage programming enabled. MCLR/VPP pin function is MCLR. MCLRE configuration bit is ignored
#pragma config ZCD = OFF     // ZCD Disable->ZCD module is disabled. ZCD can be enabled by setting the ZCDSEN bit of ZCDCON
#pragma config STVREN = ON     // Stack Overflow/Underflow Reset Enable->Stack full/underflow will cause Reset
#pragma config BORV = VBOR_1P9     // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (VBOR) set to 1.9V
#pragma config PPS1WAY = ON     // PPSLOCKED One-Way Set Enable->PPSLOCKED bit can be cleared and set only once; PPS registers remain locked after one clear/set cycle

//CONFIG5
#pragma config WDTCPS = WDTCPS_31     // WDT Period Select->Divider ratio 1:65536; software control of WDTPS
#pragma config WDTE = OFF     // WDT Operating Mode->WDT Disabled; SWDTEN is ignored

//CONFIG6
#pragma config WDTCWS = WDTCWS_7     // WDT Window Select->window always open (100%); software control; keyed access not required
#pragma config WDTCCS = SC     // WDT Input Clock Selector->Software Control

//CONFIG7
#pragma config SAFEN = OFF     // Storage Area Flash (SAF) Enable->SAF disabled
#pragma config BBEN = OFF     // Boot Block Enable->Boot block disabled
#pragma config BBSIZE = BBSIZE_512     // Boot Block Size Selection->Boot Block size is 512 words
#pragma config DEBUG = OFF     // Debugger Enable->Background Debugger disabled

//CONFIG8
#pragma config WRTB = OFF     // Boot Block Write Protection->Boot Block not Write protected
#pragma config WRTC = OFF     // Configuration Register Write Protection->Configuration registers not Write protected
#pragma config WRTD = OFF     // Data EEPROM Write Protection->Data EEPROM not Write protected
#pragma config WRTAPP = OFF     // Application Block Write Protection->Application Block not write protected
#pragma config WRTSAF = OFF     // Storage Area Flash (SAF) Write Protection->SAF not Write Protected

//CONFIG9
#pragma config CP = OFF     // User Program Flash Memory and Data EEPROM Code Protection->PFM and Data EEPROM code protection disabled

