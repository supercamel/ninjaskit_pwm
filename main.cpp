#include "ninjaskit/ninjaskit.h" 
 
using namespace etk; 
 

/*
 * This PWM example uses Pulse1 to blink a digital pin with hardware timers. 
 *
 * It's a hardware accelerated blinky!
 *
 */


int main(void) 
{ 
    //initialises the clock and peripherals 
    clock_setup();
    
    //start pulse generator using millisecond timer
    //pulse period is the frequency at which pulses occur
    //pulse period is 1,000 milliseconds ( 1 second )
    //so we'll get one pulse per second from Pulse1
    Pulse1.begin(1'000, Pulse1.MILLI_PRECISION); 
    
    //Pulse1 has four channels which must be explicitly enabled
    //enable channel 0 output
    //channel 0 happens to be pin PA0 - check ninjaskit/pwm.h for all the PWM pin mappings
    Pulse1.enable_output(0); 
    
    //all channels have the same pulse period but their pulse widths must be set individually
    //so now we set pulse width of channel 0 to 500 milliseconds
    //units are milliseconds, because we've configured Pulse1 to use a millisecond timer
    Pulse1.set_pulse_width(0, 500); 
    
    //now actually start the timer 
    Pulse1.start_timer();
    
    //PA0 will now turn ON for 500ms and OFF for 500ms - forever! 
    //while the processor does nothing
    while(true);
    
}
