#ifndef ENCODER_H
#define	ENCODER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> initEncoders(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * This function initializes the encoder counter variables.
     *  */
    void initEncoders(void);
    
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> readTMRs_ISR(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * This function reads the value in TMR1 and TMR3, and computes the net change in
     * encoder position. Usually triggered from the TMR2 ISR.
     *  */
    void readTMRs_ISR(void);
        
    /** 
     * <B><FONT COLOR=BLUE>void</FONT> clearNewEncoder(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * This function clears the new encoder value flag set by readTMRs_ISR.
     *  */
    void clearNewEncoder(void);
    
    /** 
     * <B><FONT COLOR=BLUE>bool</FONT> isNewEncoderValue(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * This function returns true if a new encoder value is available, otherwise
     * it returns false.
     *  */
    bool isNewEncoderValue(void);
    
    
    /** 
     * <B><FONT COLOR=BLUE>int16_t</FONT> getNewEncoderValue(<FONT COLOR=BLUE>void</FONT>)</B>
     * 
     * This function returns the net change in encoder position calculated by 
     * readTMRs_ISR. 
     *  */
    int16_t getNewEncoderValue(void);

#ifdef	__cplusplus
}
#endif

#endif	/* VOLUME_H */

