#include "MKL25Z4.h"

/**
assign the Botton ports
**/

void GPIO_Init_Botones (void){
	SIM->SCGC5|=(1<<13);
	PORTE->PCR[0]|= (1<<8);
	PORTE->PCR[1]|= (1<<8);
	PORTE->PCR[2]|= (1<<8);
	PORTE->PCR[3]|= (1<<8);
	PORTE->PCR[4]|= (1<<8);
	PORTE->PCR[5]|= (1<<8);
}

/**
assign the Display ports
**/

void GPIO_Init_Displays (void){
	SIM->SCGC5|=(1<<11);
	PORTC->PCR[10]|= (1<<8);
	PORTC->PCR[11]|= (1<<8);
	PORTC->PCR[12]|= (1<<8);
	PORTC->PCR[13]|= (1<<8);
}

/**
assign the ports as inputs | outputs
**/

void GPIO_IO (void){
	GPIOE->PDDR&=~(1<<0);
	GPIOE->PDDR&=~(1<<1);
	GPIOE->PDDR&=~(1<<2);
	GPIOE->PDDR&=~(1<<3);
	GPIOE->PDDR&=~(1<<4);
	GPIOE->PDDR&=~(1<<5);
}

/**
assign Display LED'S
**/

void Display_IO (void){
	GPIOE->PDDR|=(1<<11);
	GPIOE->PDDR|=(1<<12);
	GPIOE->PDDR|=(1<<13);
	GPIOE->PDDR|=(1<<14);
}

void Displays_HIGH (void){
	GPIOC->PDOR|=(1<<11);
	GPIOC->PDOR|=(1<<12);
	GPIOC->PDOR|=(1<<13);
	GPIOC->PDOR|=(1<<14);
}

