#include "ninjaskit/ninjaskit.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

#include "pwm.h"

int main(void)
{
    clock_setup();
    
    Serial1.begin(57600);
    
    const int PRESCALE = 64;
    const int PWM_PERIOD = 20000;
    const int SERVO_NULL = 1500;
    
    auto SERVO_CH1 = TIM_OC2;
    
    pwm_init_timer(&RCC_APB1ENR, RCC_APB1ENR_TIM2EN, TIM2, PRESCALE, PWM_PERIOD);

     /* init output of channel2 of timer2 */
     pwm_init_output_channel(TIM2, SERVO_CH1, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH2);

     pwm_set_pulse_width(TIM2, SERVO_CH1, SERVO_NULL);

     /* start timer1 */
     pwm_start_timer(TIM2);
    
    auto inp = gpio_pin({PA, 7});
    configure_as_input(inp);
    
    while(true)
    {

    	
    	Serial1.print("Diff: ", pulse_in(inp), "\r\n");
    }
}


