#ifndef ENCODERCONSTANTS_H
#define	ENCODERCONSTANTS_H

#ifdef	__cplusplus
extern "C" {
#endif

//Number of times TMR2 should trigger for a UART update
#define UART_COUNTER_DELAY 20
    
//Number of Pulses for each turn
#define PULSES_PER_REVOLUTION 22

//Threshold for scaling (~1/8 of Pulses per Revolution)
#define THRESHOLD PULSES_PER_REVOLUTION >> 3
    
//Defines the starting "volume"
#define STARTING_VOLUME 0
        
#ifdef	__cplusplus
}
#endif

#endif	/* ENCODERCONSTANTS_H */

