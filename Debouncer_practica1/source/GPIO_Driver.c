#include "MKL25Z4.h"
#include "GPIO_Driver.h"

/**
assign the Botton ports
**/

void GPIOS (void){
	SIM->SCGC5|=PUERTOSE;//E
	SIM->SCGC5|=PUERTOSD;//D
	SIM->SCGC5|=PUERTOSC;//C
	SIM->SCGC5|=PUERTOSA;//A

	PORTE->PCR[0]|= ON;
	PORTE->PCR[1]|= ON;
	PORTE->PCR[2]|= ON;
	PORTE->PCR[3]|= ON;
	PORTE->PCR[4]|= ON;
	PORTE->PCR[5]|= ON;

	PORTC->PCR[10]|= ON;
	PORTC->PCR[11]|= ON;
	PORTC->PCR[12]|= ON;
	PORTC->PCR[13]|= ON;

	PORTA->PCR[2]|= ON;
	PORTA->PCR[1]|= ON;
	PORTA->PCR[12]|=ON;
	PORTA->PCR[5]|= ON;
	PORTD->PCR[0]|= ON;
	PORTD->PCR[2]|= ON;
	PORTD->PCR[3]|= ON;

	GPIOE->PDDR&=~(1<<0);
	GPIOE->PDDR&=~(1<<1);
	GPIOE->PDDR&=~(1<<2);
	GPIOE->PDDR&=~(1<<3);
	GPIOE->PDDR&=~(1<<4);
	GPIOE->PDDR&=~(1<<5);

	GPIOE->PDDR|=(1<<10);
	GPIOE->PDDR|=(1<<11);
	GPIOE->PDDR|=(1<<12);
	GPIOE->PDDR|=(1<<13);

	GPIOA->PDDR|= (1<<2);
	GPIOA->PDDR|= (1<<1);
	GPIOA->PDDR|= (1<<12);
	GPIOA->PDDR|= (1<<5);
	GPIOD->PDDR|= (1<<0);
	GPIOD->PDDR|= (1<<2);
	GPIOD->PDDR|= (1<<3);

	GPIOC->PSOR|=(1<<10);
	GPIOC->PSOR|=(1<<11);
	GPIOC->PSOR|=(1<<12);
	GPIOC->PSOR|=(1<<13);

	GPIOA->PSOR|= (1<<2);
	GPIOA->PSOR|= (1<<1);
	GPIOA->PSOR|= (1<<12);
	GPIOA->PSOR|= (1<<5);
	GPIOD->PSOR|= (1<<0);
	GPIOD->PSOR|= (1<<2);
	GPIOD->PSOR|= (1<<3);
}


