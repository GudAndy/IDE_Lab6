/*
 * Main module for testing the PWM Code for the K64F
 * 
 * Author:  
 * Created:  
 * Modified: Carson Clarke-Magrab <ctc7359@rit.edu> 
 */

#include "MK64F12.h"
#include "uart.h"
#include "DriveMotor.h"
#include "PWM.h"
#include "Steering.h"

void delay(int del);

int main(void)
{
	uart0_init();
	DriveMotor_init();
	Steering_init();
	
	//DriveMotorA_set_duty_cycle(20,DIRECTION_FORWARD);
	//DriveMotorA_enable(1);
	//DriveMotorB_set_duty_cycle(20,DIRECTION_FORWARD);
	//DriveMotorB_enable(1);
	
	// duty cycle = pulse length / period
	// duty cycle = 1.5ms / 20ms = .075 => 7.5
	Steering_set_duty_cycle(6.75);
	
	for(;;)
	{
		
	
	}
}

/* Earlier, non-car parts
int main(void) {
	// Initialize UART and PWM
	uart0_init();
  FTM0_init();

	// Print welcome over serial
	uart0_put("Running... \n\r");
	
	// Generate 20% duty cycle at 10kHz
	//FTM0_set_duty_cycle(40, 10000, 1);
	
	while(1)
	{
		for(int i = 0; i <= 100; i++)
		{
			FTM0_set_duty_cycle(i, 10000, 1);
			delay(10);
		}
		for(int i = 100; i >=0; i--)
		{
			FTM0_set_duty_cycle(i, 10000, 1);
			delay(10);
		}
		
		for(int i = 0; i <= 100; i++)
		{
			FTM0_set_duty_cycle(i, 10000, 0);
			delay(10);
		}
		for(int i = 100; i >=0; i--)
		{
			FTM0_set_duty_cycle(i, 10000, 0);
			delay(10);
		}
	}
	
	// enable port D clocks
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	// configure signal multiplexer for port d gpio pins
	PORTD_PCR0 &= ~(PORT_PCR_MUX_MASK);
	PORTD_PCR0 |= PORT_PCR_MUX(1);
	PORTD_PCR1 &= ~(PORT_PCR_MUX_MASK);
	PORTD_PCR1 |= PORT_PCR_MUX(1);
	PORTD_PCR2 &= ~(PORT_PCR_MUX_MASK);
	PORTD_PCR2 |= PORT_PCR_MUX(1);
	PORTD_PCR3 &= ~(PORT_PCR_MUX_MASK);
	PORTD_PCR3 |= PORT_PCR_MUX(1);
	
	// configure gpio pins for output
	for (int i = 0; i < 4; i++)
	GPIOD_PDDR |= (1 << i);
	
	int forward = 1;
	int phase = 0;
	int iter = 0;
	
	
	while(1)
	{
		// turn off all coils
		for (int i = 0; i < 4; i++)
			GPIOD_PCOR = (1 << i);
		
		// set one pin high at a time
		if (forward)
		{
			switch(phase)
			{
				case 0:
					// coil A
					GPIOD_PSOR = (1 << 0);
					phase++;
					break;
				
				case 1:
					// coil B
					GPIOD_PSOR = (1 << 1);
					phase++;
					break;
				
				case 2:
					// coil C
					GPIOD_PSOR = (1 << 2);
					phase++;
					break;
				
				case 3:
					// coil D
					GPIOD_PSOR = (1 << 3);
					phase = 0;
					if (iter == 1)
					{
					forward = 0;
					iter = 0;
					}
					else
						iter++;
					break;
				default:
					// shouldnt get here
					for(;;);
					break;
			}
		}
		
		else
		{
			
			// reverse
			switch(phase)
			{
				case 0:
					// coil D
					GPIOD_PSOR = (1 << 3);
					phase++;
					break;
				
				case 1:
					// coil C
					GPIOD_PSOR = (1 << 2);
					phase++;
					break;
				
				case 2:
					// coil B
					GPIOD_PSOR = (1 << 1);
					phase++;
					break;
				
				case 3:
					// coil A
					GPIOD_PSOR = (1 << 0);
					phase = 0;
				if (iter == 1)
				{
					forward = 1;
					iter = 0;
				}
				else{
				iter++;
				}
					break;
				default:
					// shouldnt get here
					for(;;);
					break;
			}
		
		}
		delay(10);
	}
	return 0;
}
*/

/**
 * Waits for a delay (in milliseconds)
 * 
 * del - The delay in milliseconds
 */
void delay(int del){
	volatile int i;
	for (i=0; i<del*50000; i++){
		// Do nothing
	}
}
