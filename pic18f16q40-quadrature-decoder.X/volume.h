#ifndef VOLUME_H
#define	VOLUME_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "constants.h"
    
#include <stdint.h>

/**
 * Control Modes for the Encoder
 * Define 1 of the 3 modes
 * 
 * Linear - Each Pulse is counted as 1
 * Threshold - After exceeding a threshold, each pulse is worth more.
 * Single Rotation - Approx. 1 Rotation is 100% of the Output
 **/
    
#define LINEAR_VOLUME_CONTROL
//#define THRESHOLD_VOLUME_CONTROL
//#define SINGLE_ROTATION_CONTROL
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> initVolumeControl(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * This function initializes the volume control functions.
     *  */
    void initVolumeControl(void);
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> adjustVolume(<FONT COLOR=BLUE>int16_t</FONT> enc)</B>
     * @param enc (int16_t) - Net change in encoder position
     * 
     * This function changes the volume based on the net change in encoder position.
     * Volume ranges from 0 to 100
     *  */
    void adjustVolume(int16_t enc);
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> displayVolume(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * This function displays the volume on the LED graph display. 
     *  */
    void displayVolume(void);

    /** 
     * <B><FONT COLOR=BLUE>uint8_t</FONT> getCurrentVolume(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * This function returns the current volume.
     * Volume ranges from 0 to 100
     *  */
    uint8_t getCurrentVolume(void);
    
    /** 
     * <B><FONT COLOR=BLUE>uint8_t</FONT> fastDivide8(<FONT COLOR=BLUE>uint8_t</FONT> divisor, <FONT COLOR=BLUE>uint8_t</FONT>* original)</B>
     * @param divisor (uint8_t) - The divisor used for fast division.
     * @param original (uint8_t*) - The dividend used in this function. The value in the pointer will be the remainder afterwards.
     * 
     * Returns the number of times the divisor can go into the original number. 
     * The "original" number holds the remainder afterwards.
     *  */
    uint8_t fastDivide8(uint8_t divisor, uint8_t* original);

    
#ifdef	__cplusplus
}
#endif

#endif	/* VOLUME_H */

