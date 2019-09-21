#include "MKL25Z4.h"
#include "GPIO_Driver.h"

/**
assign the Botton ports
**/
typedef enum{
	enBotton0=0,
	enBotton1,
	enBotton2,
	enBotton3,
	enBotton4,
	enBotton5,
	enBottoms
}MyBottoms;

typedef enum{
	enDisplay1=10,
	enDisplay2,
	enDisplay3,
	enDisplay4,
	enDisplays
}MyDisplays;


void GPIOS (void){
	SIM->SCGC5|=PUERTOSE;//E
	SIM->SCGC5|=PUERTOSD;//D
	SIM->SCGC5|=PUERTOSC;//C
	SIM->SCGC5|=PUERTOSA;//A

	PORTE->PCR[enBotton0]|= ON;
	PORTE->PCR[enBotton1]|= ON;
	PORTE->PCR[enBotton2]|= ON;
	PORTE->PCR[enBotton3]|= ON;
	PORTE->PCR[enBotton4]|= ON;
	PORTE->PCR[enBotton5]|= ON;

	PORTC->PCR[enDisplay1]|= ON;
	PORTC->PCR[enDisplay2]|= ON;
	PORTC->PCR[enDisplay3]|= ON;
	PORTC->PCR[enDisplay4]|= ON;

	PORTD->PCR[0]|= ON;
	PORTA->PCR[1]|= ON;
	PORTA->PCR[2]|= ON;
	PORTD->PCR[3]|= ON;
	PORTA->PCR[12]|=ON;
	PORTA->PCR[5]|= ON;
	PORTD->PCR[2]|= ON;

	GPIOE->PDDR&=~enBotton0;
	GPIOE->PDDR&=~enBotton1;
	GPIOE->PDDR&=~enBotton2;
	GPIOE->PDDR&=~enBotton3;
	GPIOE->PDDR&=~enBotton4;
	GPIOE->PDDR&=~enBotton5;

	GPIOE->PDDR|=enDisplay1;//(1<<10)
	GPIOE->PDDR|=enDisplay2;//(1<<11)
	GPIOE->PDDR|=enDisplay3;//(1<<12)
	GPIOE->PDDR|=enDisplay4;//(1<<13)

	GPIOA->PDDR|= SegmentoA;//enSegmentoA
	GPIOA->PDDR|= SegmentoB;//enSegmentoB
	GPIOA->PDDR|= SegmentoC;//enSegmentoC
	GPIOA->PDDR|= SegmentoD;//enSegmentoD
	GPIOD->PDDR|= SegmentoE;// enSegmentoE
	GPIOD->PDDR|= SegmentoF;//enSegmentoF
	GPIOD->PDDR|= SegmentoG;//enSegmentoG

	GPIOC->PSOR|=enDisplay1;
	GPIOC->PSOR|=enDisplay2;
	GPIOC->PSOR|=enDisplay3;
	GPIOC->PSOR|=enDisplay4;

	GPIOA->PSOR|= SegmentoA;
	GPIOA->PSOR|= SegmentoB;
	GPIOA->PSOR|= SegmentoC;
	GPIOA->PSOR|= SegmentoD;
	GPIOD->PSOR|= SegmentoE;
	GPIOD->PSOR|= SegmentoF;
	GPIOD->PSOR|= SegmentoG;
}


