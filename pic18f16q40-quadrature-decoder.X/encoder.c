#include "encoder.h"

#include <stdint.h>
#include <stdbool.h>

#include "mcc_generated_files/mcc.h"

//Net Encoder Change (in Pulses)
static volatile int16_t encoder;

//"Boolean" value that is set to true when a new result has been created
static volatile bool newEncoder;

void initEncoders(void)
{
    encoder = 0;
    newEncoder = false;
}

void readTMRs_ISR(void)
{
    static volatile uint16_t old_TMR1 = 0;
    static volatile uint16_t old_TMR3 = 0;
    
    uint16_t new_TMR1, new_TMR3, net_TMR1, net_TMR3;
    
    //Get Current Values
    new_TMR1 = TMR1_ReadTimer();
    new_TMR3 = TMR3_ReadTimer();
    
    //Zero out the net change
    net_TMR1 = 0;
    net_TMR3 = 0;
       
    if (new_TMR1 < old_TMR1)
    {
        //Rollover occurred
        //Add an offset to the net value and clear old value
        net_TMR1 = 0xFFFF - old_TMR1;
        old_TMR1 = 0;
    }
    
    if (new_TMR3 < old_TMR3)
    {
        //Rollover occurred
        //Add an offset to the net value and clear the old value
        net_TMR3 = 0xFFFF - old_TMR3;
        old_TMR3 = 0;
    }
    
    //Find the net change
    net_TMR1 += new_TMR1 - old_TMR1;
    net_TMR3 += new_TMR3 - old_TMR3;
    
    //Calculate the net encoder change
    encoder = net_TMR1 - net_TMR3;
    
    //Indicate a new value is ready
    newEncoder = true;    

    //Store the old values
    old_TMR1 = new_TMR1;
    old_TMR3 = new_TMR3;
}

void clearNewEncoder(void)
{
    newEncoder = false;
}

bool isNewEncoderValue(void)
{
    return newEncoder;
}

int16_t getNewEncoderValue(void)
{
    return encoder;
}