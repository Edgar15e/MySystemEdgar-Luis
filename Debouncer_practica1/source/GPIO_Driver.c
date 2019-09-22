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

	PORTD->PCR[LED]|=ON;

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

	PORTA->PCR[2]|= ON;
	PORTA->PCR[1]|= ON;
	PORTA->PCR[12]|=ON;
	PORTA->PCR[5]|= ON;
	PORTD->PCR[0]|= ON;
	PORTD->PCR[2]|= ON;
	PORTD->PCR[3]|= ON;

	GPIOC->PDDR|=1<<enDisplay1;//(1<<10)
	GPIOC->PDDR|=1<<enDisplay2;//(1<<11)
	GPIOC->PDDR|=1<<enDisplay3;//(1<<12)
	GPIOC->PDDR|=1<<enDisplay4;//(1<<13)

	GPIOA->PDDR|= SegmentoA;//enSegmentoA
	GPIOA->PDDR|= SegmentoB;//enSegmentoB
	GPIOA->PDDR|= SegmentoC;//enSegmentoC
	GPIOA->PDDR|= SegmentoD;//enSegmentoD
	GPIOD->PDDR|= SegmentoE;// enSegmentoE
	GPIOD->PDDR|= SegmentoF;//enSegmentoF
	GPIOD->PDDR|= SegmentoG;//enSegmentoG

	GPIOC->PSOR|=1<<enDisplay1;
	GPIOC->PSOR|=1<<enDisplay2;
	GPIOC->PSOR|=1<<enDisplay3;
	GPIOC->PSOR|=1<<enDisplay4;

	GPIOA->PSOR|= SegmentoA;
	GPIOA->PSOR|= SegmentoB;
	GPIOA->PSOR|= SegmentoC;
	GPIOA->PSOR|= SegmentoD;
	GPIOD->PSOR|= SegmentoE;
	GPIOD->PSOR|= SegmentoF;
	GPIOD->PSOR|= SegmentoG;
}


void VEINTE_mSEGUNDOS (void){
	static uint16 x =1000;
	while(x!=20){
			x--;
		}
}

void LED_Toggle (void){
	GPIOD->PTOR|=GPIO_PTOR_PTTO(7);
}

uint8 VAR=0;
void DisplayOn (uint8 *VAR)
{
	if(*VAR==1){
		GPIOC->PSOR|=1<<enDisplay1;
		GPIOC->PCOR|=1<<enDisplay2;
		GPIOC->PCOR|=1<<enDisplay3;
		GPIOC->PCOR|=1<<enDisplay4;
	}else if(*VAR==2){
		GPIOC->PCOR|=1<<enDisplay1;
		GPIOC->PSOR|=1<<enDisplay2;
		GPIOC->PCOR|=1<<enDisplay3;
		GPIOC->PCOR|=1<<enDisplay4;
	}else if(*VAR==3){
		GPIOC->PCOR|=1<<enDisplay1;
		GPIOC->PCOR|=1<<enDisplay2;
		GPIOC->PSOR|=1<<enDisplay3;
		GPIOC->PCOR|=1<<enDisplay4;
	}else if(*VAR==4){
		GPIOC->PCOR|=1<<enDisplay1;
		GPIOC->PCOR|=1<<enDisplay2;
		GPIOC->PCOR|=1<<enDisplay3;
		GPIOC->PSOR|=1<<enDisplay4;
	}

}

uint8 VAR2=0;
void SegmentosOn(uint8 *VAR2){
	if(*VAR2==0){

		GPIOA->PSOR|= SegmentoA;
		GPIOA->PSOR|= SegmentoB;
		GPIOA->PSOR|= SegmentoC;
		GPIOA->PSOR|= SegmentoD;
		GPIOD->PSOR|= SegmentoE;
		GPIOD->PSOR|= SegmentoF;
		GPIOD->PCOR|= SegmentoG;

	}else if(*VAR2==1){

		GPIOA->PCOR|= SegmentoA;
		GPIOA->PCOR|= SegmentoB;
		GPIOA->PSOR|= SegmentoC;
		GPIOA->PSOR|= SegmentoD;
		GPIOD->PCOR|= SegmentoE;
		GPIOD->PCOR|= SegmentoF;
		GPIOD->PCOR|= SegmentoG;

	}else if(*VAR2==2){

		GPIOA->PSOR|= SegmentoA;
		GPIOA->PSOR|= SegmentoB;
		GPIOA->PCOR|= SegmentoC;
		GPIOA->PSOR|= SegmentoD;
		GPIOD->PSOR|= SegmentoE;
		GPIOD->PCOR|= SegmentoF;
		GPIOD->PSOR|= SegmentoG;

	}else if(*VAR2==3){

		GPIOA->PSOR|= SegmentoA;
		GPIOA->PSOR|= SegmentoB;
		GPIOA->PSOR|= SegmentoC;
		GPIOA->PSOR|= SegmentoD;
		GPIOD->PCOR|= SegmentoE;
		GPIOD->PCOR|= SegmentoF;
		GPIOD->PSOR|= SegmentoG;
	}else if(*VAR2==4){

		GPIOA->PCOR|= SegmentoA;
		GPIOA->PSOR|= SegmentoB;
		GPIOA->PSOR|= SegmentoC;
		GPIOA->PCOR|= SegmentoD;
		GPIOD->PCOR|= SegmentoE;
		GPIOD->PSOR|= SegmentoF;
		GPIOD->PSOR|= SegmentoG;
	}else if(*VAR2==5){

		GPIOA->PSOR|= SegmentoA;
		GPIOA->PCOR|= SegmentoB;
		GPIOA->PSOR|= SegmentoC;
		GPIOA->PSOR|= SegmentoD;
		GPIOD->PCOR|= SegmentoE;
		GPIOD->PSOR|= SegmentoF;
		GPIOD->PSOR|= SegmentoG;
	}else if(*VAR2==6){

		GPIOA->PSOR|= SegmentoA;
		GPIOA->PCOR|= SegmentoB;
		GPIOA->PSOR|= SegmentoC;
		GPIOA->PSOR|= SegmentoD;
		GPIOD->PSOR|= SegmentoE;
		GPIOD->PSOR|= SegmentoF;
		GPIOD->PSOR|= SegmentoG;
	}else if(*VAR2==7){

		GPIOA->PSOR|= SegmentoA;
		GPIOA->PSOR|= SegmentoB;
		GPIOA->PSOR|= SegmentoC;
		GPIOA->PCOR|= SegmentoD;
		GPIOD->PCOR|= SegmentoE;
		GPIOD->PCOR|= SegmentoF;
		GPIOD->PCOR|= SegmentoG;
	}else if(*VAR2==8){

		GPIOA->PSOR|= SegmentoA;
		GPIOA->PSOR|= SegmentoB;
		GPIOA->PSOR|= SegmentoC;
		GPIOA->PSOR|= SegmentoD;
		GPIOD->PSOR|= SegmentoE;
		GPIOD->PSOR|= SegmentoF;
		GPIOD->PSOR|= SegmentoG;
	}else if(*VAR2==9){

		GPIOA->PSOR|= SegmentoA;
		GPIOA->PSOR|= SegmentoB;
		GPIOA->PSOR|= SegmentoC;
		GPIOA->PSOR|= SegmentoD;
		GPIOD->PCOR|= SegmentoE;
		GPIOD->PSOR|= SegmentoF;
		GPIOD->PSOR|= SegmentoG;
	}


}
/*
void BottonRigth (void){
//	GPIOE->PDIR[enBotton0]|=(1<<0);
}

void BottonLeft (void){

}

void BottonUp (void){

}

void BottonDown (void){

}

void BottonRun (void){

}

void BottonConfig (void){

}
*/
