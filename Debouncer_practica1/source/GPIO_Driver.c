#include "MKL25Z4.h"

/**
assign the Botton ports
**/

void GPIOS (void){
	SIM->SCGC5|=(1<<13);//E
	SIM->SCGC5|=(1<<12);//D
	SIM->SCGC5|=(1<<11);//C
	SIM->SCGC5|=(1<<9);//A

	PORTE->PCR[0]|= (1<<8);
	PORTE->PCR[1]|= (1<<8);
	PORTE->PCR[2]|= (1<<8);
	PORTE->PCR[3]|= (1<<8);
	PORTE->PCR[4]|= (1<<8);
	PORTE->PCR[5]|= (1<<8);

	PORTC->PCR[10]|= (1<<8);
	PORTC->PCR[11]|= (1<<8);
	PORTC->PCR[12]|= (1<<8);
	PORTC->PCR[13]|= (1<<8);

	PORTA->PCR[2]|= (1<<8);
	PORTA->PCR[1]|= (1<<8);
	PORTA->PCR[12]|= (1<<8);
	PORTA->PCR[5]|= (1<<8);
	PORTD->PCR[0]|= (1<<8);
	PORTD->PCR[2]|= (1<<8);
	PORTD->PCR[3]|= (1<<8);

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


