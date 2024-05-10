/*
 * ADC_driver.c
 *
 * Created: 9/19/2023 7:04:02 PM
 *  Author: Mahmoud Hamdy
 */ 

#include "ADC_driver.h"

void ADC_Init()
{
	//configure VREF
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	
	SET_BIT(ADCSRA,ADEN);//enable ADC
	
	//Adjust ADC clock
	SET_BIT(ADMUX,ADPS1);
	SET_BIT(ADMUX,ADPS2);
	
	//select pin for MUX
	CLR_BIT(ADMUX,MUX0);
	CLR_BIT(ADMUX,MUX1);
	CLR_BIT(ADMUX,MUX2);
		
}

unsigned short ADC_u16Read(void)
{
	unsigned short return_val;
	
	SET_BIT(ADCSRA,ADSC);//enable ADC
	while(READ_BIT(ADCSRA,ADSC)==1);//wait for conversion

	return_val = ADCL;
	return_val |= ADCH<<8;
	return return_val;
	
}