/*
 * main.c
 *
 *  Created on: Dec 3, 2019
 *      Author: ahmed
 */

#include "led.h"
#include "gpio.h"
#include "softwareDelay.h"
#include "pushButton.h"
#include "timers.h"

enum state{
    Go,
    Stop,
    Ready
}state;

int main(){

    Led_Init(0);
    Led_Init(1);
    Led_Init(2);

    //timer1Init(T1_NORMAL_MODE,T1_OC1_DIS,T1_PRESCALER_64,0,0,0,0,T1_POLLING);

   timer2Init(T2_NORMAL_MODE,T2_OC2_DIS,T2_PRESCALER_64,0,0,0,T2_POLLING);

    while(1)
	{
	    static uint8 u8_State=Go;
	    switch(u8_State)
	    {
		case Go:
		    Led_Off(1);
		    Led_Off(2);
		    Led_On(0);
		    u8_State=Stop;
		    timer2Delay_ms(1000);
		    break;

		case Stop:
		    Led_On(1);
		    Led_Off(0);
		    Led_Off(2);
		    u8_State=Ready;
		    timer2Delay_ms(1000);
		    break;

		case Ready:
		    Led_On(2);
		    Led_Off(0);
		    Led_Off(1);
		    u8_State=Go;
		    timer2Delay_ms(1000);
		    break;
	    }
	}
}
