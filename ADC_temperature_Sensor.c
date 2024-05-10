/*
 * ADC_lab.c
 *
 * Created: 9/19/2023 7:01:48 PM
 *  Author: Mahmoud Hamdy
 */ 

#include "LCD.h"
#include "ADC_driver.h"

int main(void)
{
	LCD_Init();
	ADC_Init();

	unsigned char temp;
    LCD_send_string("Temperature=");
	while(1)
    {
        temp = (0.25*ADC_u16Read());//mV    Vref*ADC*1000/2^bins mV

		if (temp<10)
		{
			LCD_move_cursor(1,13);
			LCD_sendChar(temp+48);
			LCD_sendChar(0xDF);
			LCD_sendChar('c');
			LCD_sendChar(0x20);
		}
		else if(temp<100)
		{
			LCD_move_cursor(1,13);
			LCD_sendChar(temp/10+48);
			LCD_sendChar(temp%10+48);
			LCD_sendChar(0xDF);
			LCD_sendChar('c');
		}		
    }
}