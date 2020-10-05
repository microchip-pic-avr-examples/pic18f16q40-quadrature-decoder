<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>
# Quadrature Decoder with PIC18F16Q40

This code example creates a simple quadrature decoder implementation on the PIC18F16Q40 device. It utilizes the Core Independent Peripherals (CIPs): 2 of the Configurable Logic Cells (CLCs) and TMR1/2/3 to measure the quadrature. A UART interface is also used for a serial readout.

## Related Documentation

* [Datasheet for PIC18F16Q40 Devices](#)
* [AN2434, Interfacing Quadrature Encoder using CCL with TCA and TCB](http://www.microchip.com//wwwAppNotes/AppNotes.aspx?appnote=en599697)
* [Quadrature Encoder Example on AVR DB](https://github.com/microchip-pic-avr-examples/avr128db48-quadrature-decoder.git)

## Software Used

* [MPLAB X v5.40](https://www.microchip.com/mplab/mplab-x-ide)
* [XC8 v2.30](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-xc-compilers)
* [MPLAB Code Configurator v5.0.1](https://www.microchip.com/mplab/mplab-code-configurator)
* [PIC18F-Q_DFP v1.8.154](https://packs.download.microchip.com/)
* [MPLAB Data Visualizer](https://www.microchip.com/mplab/mplab-data-visualizer) or a Serial COM Terminal (*optional*)


## Hardware Used

* [PIC18F16Q40 Curiosity Nano (PN: EV70C97A)](#)
* [PIC18F16Q40 Curiosity LPC, Rev 4 (PN: DM164137)](#https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM164137)
* [PIC18F16Q40 Device Information](https://www.microchip.com/wwwproducts/en/PIC18F16Q40)
* Incremental Encoder

## Setup

| Pin Name | Function
| -------- | --------
| RA2      | UART TX Output
| RB6      | Encoder "A" Input
| RB7      | Encoder "B" Input
| RC7-RC0  | LED "Volume" Outputs

Note: To Reverse Direction, Swap "A" and "B" lines on the encoder.

### Encoder Wiring and Setup

Depending on the encoder, the specific circuit required for it may vary. The manufacturer of the device will specify the circuits required for proper operation.

## Operation

This example has 2 outputs - a UART output at 115,200 baud which indicates the net turns and direction of the encoder (see [Theory of Operation](#theory-of-operation) below), or a 10-position LED bar graph which acts as a "volume" control. These outputs run independently of each other - it is not required to use both outputs.

### UART Output

The UART output run at 115,200 baud through the programmer to the PC. [MPLAB Data Visualizer](https://www.microchip.com/mplab/mplab-data-visualizer) can be used to visualize the serial output. After connecting the board, select the COM port (but do not connect) to:

* Baud Rate: 115,200
* Char Length: 8 bits
* Parity: None
* Stop Bits: 1 bit

After setting these options, press apply then "connect" to the COM port. In the terminal window, set the source to the connected COM port, and wait. Within a few seconds, text should start printing to the screen.

### LED Bar Graph Output

The LED bar graph is a graphical "volume" styled output. Each bar in the display represents 10 - with 100 being the "loudest". The control options macros in the program can be used to set the way the "volume" is modified by the encoder.


Due to differences in encoder parameters, some of the constants will have to be tweaked to find the right balance of speed and accuracy.

#### Control options

* Linear Output - Each pulse from the encoder is counted as 1
* Stepped Function - Stepwise function for pulse counting
* 1 Rotation - Each rotation is worth 100%

## Theory of Operation

The quadrature decoder takes 2 inputs, A and B, that are out-of-phase by 90 degrees. One of the inputs is considered a reference waveform, for which the phase is measured against. The other waveform determines the direction based on if it leads or lags the reference, as shown below.

![Example Waveform](./images/exampleWaveform.png)

This phase difference can be exploited by using the Configurable Logic Cells (CLCs) on the PIC18F16Q40 in JK Flip-Flop mode. The JK flip-flop is a clocked gate - meaning that it only applies the inputs (J and K) to the output (Q) on the rising edge of the clock. The truth table for the JK Flip-Flop is reproduced below.

| J   | K   | Q
| --- | --- | ---
| 0   | 0   | Q
| 0   | 1   | 0
| 1   | 0   | 1
| 1   | 1   | ~Q

The reset lines in this implementation operate asynchronously - if the line is high, then Q immediately goes to 0. In the cell, one of the lines (A or B) is used as a clock line while the other is used as the input to set and clear the flip-flop, as shown below.

![CLC Implementation](./images/CLC_Implementation.png)

There are 2 CLCs used in this project, with the only difference being that A and B are swapped between the two. Swapping A and B causes one of the CLCs to see the input lag while the other sees the input lead. In a JK flip-flop, J must be high when the clock is rising in order to set the output high. The only flip-flop that will be set is the configuration where the input leads the clock signal, as shown in the images below.

![Waveform 1](./images/waveform1.PNG)

![Waveform 2](./images/waveform2.PNG)

Both images were taken with a test signal of ~30Hz. Between runs, the wires to A and B were switched, causing 1 CLC to become active while the other becomes inactive. The output of the CLCs is internally routed to either TMR1 or TMR3. The rising edge of the output causes the timer to count. Normally TMR1 or TMR3 is used as an interrupt, however since the pulse count is unknown and is likely to be relatively small, it makes more sense to use a timer (such as TMR2) as an interrupt to poll the number of pulses in each.

If the encoder was spun in the same direction between each polling event, then one of the timers will be 0, while the other will contain a value. If the direction was changed, then both counters will be non-zero. To find the net direction, subtract one of the timers from the other. The sign of this value indicates the net direction, while the value indicates the surplus of pulses in that direction.

The maximum frequency of this example will be determined by how often a polling event occurs. For a user-interface encoder, the number of pulses is likely to be small, thus a larger time between polling events is appropriate. If the encoder is on a motor, then a faster polling rate is required. Enabling the overflow interrupt for TMR1/3 will detect the condition where the polling rate is too slow.

## Summary
The Core Independent Peripherals on the PIC18F16Q40 provide a flexible means of implementing more complex operations. In this case, the quadrature decoder is almost completely done in hardware - the amount of software required is minimized.
