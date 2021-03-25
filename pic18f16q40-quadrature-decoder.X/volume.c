#include "volume.h"
#include "constants.h"

#include "mcc_generated_files/system/system.h"

#include <stdint.h>

//"Volume" Variable
static uint8_t volume;

//Variables for a single rotation
static uint8_t pulse_factor;

void initVolumeControl(void)
{
    //Init Volume
    volume = STARTING_VOLUME;
    
    //Init variable for single rotation volume control scale
    uint8_t temp = 100;
    pulse_factor = fastDivide8(PULSES_PER_REVOLUTION, &temp);
    
    //Update the display
    displayVolume();
}

void adjustVolume(int16_t enc)
{
    int16_t t_vol = volume;
#ifdef LINEAR_VOLUME_CONTROL
    
    if (enc >= 0)
    {
        //Positive Encoder Counts
        t_vol += (enc & 0x00FF);
    }
    else
    {
        //Negative Encoder Counts
        t_vol -= ((enc * -1) & 0x00FF);
    }
#endif
#ifdef THRESHOLD_VOLUME_CONTROL
    
    if (enc < 0)    //Volume down
    {
        if ((enc * -1) >= THRESHOLD)
        {
            //Above Threshold
            t_vol += enc * pulse_factor;
        }
        else
        {
            //Below Threshold
            t_vol += enc;
        }
    }
    else            //Volume Up (or no change)
    {
        if (enc >= THRESHOLD)
        {
            //Above Threshold
            t_vol += enc * pulse_factor;
        }
        else
        {
            //Below Threshold
            t_vol += enc;
        }
    }
    
#endif
#ifdef SINGLE_ROTATION_CONTROL    
    
    t_vol += enc * pulse_factor;
    
    //These if statements compensate for divisors that are NOT divisors of 100
    //e.g.: 24, 48, etc... and rounds the volume to reduce the number of pulses
    //These lines can be removed, if desired.
    
    if ((t_vol < 100) && (enc > 0) && (t_vol + pulse_factor >= 100))
    {
        //Round to 100
        t_vol = 100;
    }
    else if ((t_vol > 0) && (enc < 0) && (t_vol - pulse_factor <= 0))
    {
        //Round to 0
        t_vol = 0;
    }
    
#endif
            
    //Limit the volume
    if (t_vol < 0)
    {
        t_vol = 0;
    }
    else if (t_vol > 100)
    {
        t_vol = 100;
    }
    
    //Apply changes
    volume = t_vol;
}

void displayVolume(void)
{
    //Turn off LEDs 7:0
    LATC = 0x00;
    
    //Turn off other LEDs
    LED8_LAT = 0;
    LED9_LAT = 0;
    
    if (volume > 0)
    {
        LED0_LAT = 1;
    }
    if (volume >= 15)
    {
        LED1_LAT = 1;
    }
    if (volume >= 25)
    {
        LED2_LAT = 1;
    }
    if (volume >= 35)
    {
        LED3_LAT = 1;
    }
    if (volume >= 45)
    {
        LED4_LAT = 1;
    }
    if (volume >= 55)
    {
        LED5_LAT = 1;
    }
    if (volume >= 65)
    {
        LED6_LAT = 1;
    }
    if (volume >= 75)
    {
        LED7_LAT = 1;
    }
    if (volume >= 85)
    {
        LED8_LAT = 1;
    }
    if (volume > 99)
    {
        LED9_LAT = 1;
    }
}

uint8_t getCurrentVolume(void)
{
    return volume;
}

uint8_t fastDivide8(uint8_t divisor, uint8_t* original)
{
    uint8_t output = 0;
    while (*original >= divisor)
    {
        output++;
        *original -= divisor;
    }
    return output;
}