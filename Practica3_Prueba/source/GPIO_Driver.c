#include "Debouncer.h"
#include "MKL25Z4.h"
#include "GPIO_Driver.h"
#include "Tacometer.h"
#include "Carrito.h"

void GPIOS (void){
	SIM->SCGC5|=PUERTOSE;
	SIM->SCGC5|=PUERTOSD;
	SIM->SCGC5|=PUERTOSC;
	SIM->SCGC5|=PUERTOSA;
	PORTA->PCR[16]|=ON;
	PORTA->PCR[17]|=ON;

	PORTC->PCR[1]|= ON;
	PORTC->PCR[2]|= ON;

	PORTE->PCR[enBotton0]|= ON;
	PORTE->PCR[enBotton1]|= ON;
	PORTE->PCR[enBotton2]|= ON;
	PORTE->PCR[enBotton3]|= ON;
	PORTE->PCR[enBotton4]|= ON;

	PORTC->PCR[enDisplay1]|= ON;
	PORTC->PCR[enDisplay2]|= ON;
	PORTC->PCR[enDisplay3]|= ON;
	PORTC->PCR[enDisplay4]|= ON;

	PORTD->PCR[6]|= ON;
	PORTD->PCR[7]|= ON;
	PORTA->PCR[12]|=ON;
	PORTA->PCR[5]|= ON;
	PORTD->PCR[0]|= ON;
	PORTD->PCR[2]|= ON;
	PORTD->PCR[3]|= ON;

	GPIOC->PDDR|=1<<enDisplay1;
	GPIOC->PDDR|=1<<enDisplay2;
	GPIOC->PDDR|=1<<enDisplay3;
	GPIOC->PDDR|=1<<enDisplay4;

	GPIOD->PDDR|= SegmentoA;
	GPIOD->PDDR|= SegmentoB;
	GPIOA->PDDR|= SegmentoC;
	GPIOA->PDDR|= SegmentoD;
	GPIOD->PDDR|= SegmentoE;
	GPIOD->PDDR|= SegmentoF;
	GPIOD->PDDR|= SegmentoG;

	GPIOC->PDDR|= (1<<1);
	GPIOC->PDDR|= (1<<2);

}

static uint16 x =1000;
void VEINTE_mSEGUNDOS (void){
	x=1000;
	while(x!=20){
		x--;
	}
}


uint8 VAR=0;
void DisplayOn (uint8 *VAR){
	if(*VAR==0){

		GPIOC->PSOR=0xF<<enDisplay1;
		GPIOC->PCOR=1<<enDisplay1;

	}else if(*VAR==1){
		GPIOC->PSOR=0xF<<enDisplay1;
		GPIOC->PCOR=1<<enDisplay2;

	}else if(*VAR==2){

		GPIOC->PSOR=0xF<<enDisplay2;
		GPIOC->PCOR=1<<enDisplay3;

	}else if(*VAR==3){

		GPIOC->PSOR=0xF<<enDisplay1;
		GPIOC->PCOR=1<<enDisplay4;

	}else{
	}
}
void ClearGPIOS (void){
	GPIOD->PCOR= SegmentoA;
	GPIOD->PCOR= SegmentoB;
	GPIOA->PCOR= SegmentoC;
	GPIOA->PCOR= SegmentoD;
	GPIOD->PCOR= SegmentoE;
	GPIOD->PCOR= SegmentoF;
	GPIOD->PCOR= SegmentoG;
}

uint8 VAR2=0;
void SegmentosOn(uint8 *VAR2){
	GPIOA->PCOR=0xFFFF;
	GPIOD->PCOR=0xFFFF;
	if(*VAR2==9){
		GPIOD->PDOR|= SegmentoA;
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==8){
		GPIOD->PDOR|= SegmentoA;
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoE;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==7){
		GPIOD->PDOR|= SegmentoA;
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
	}else if(*VAR2==6){
		GPIOD->PDOR|= SegmentoA;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoE;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==5 ){
		GPIOD->PDOR|= SegmentoA;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==4 ){
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;

	}else if(*VAR2==3 ){
		GPIOD->PDOR|= SegmentoA;
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==2 ){
		GPIOD->PDOR|= SegmentoA;
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoE;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==1){
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
	}else if(*VAR2==0){
		GPIOD->PDOR|= SegmentoA;
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoE;
		GPIOD->PDOR|= SegmentoF;
	}else{
		//Nothing to do
	}
}

uint8 ReadPinGpio(uint8 Pin2Read){
	uint32 Reg;
	Reg=(GPIOE->PDIR)>> Pin2Read;
	if(Reg&1){
		return 1;
	}else{
		return 0;
	}
}



void SegmentosOn_Estados_Up(uint8 *VAR3){
	GPIOA->PCOR=0xFFFF;
	GPIOD->PCOR=0xFFFF;

	if(*VAR3==0){
		GPIOD->PDOR|= SegmentoE;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR3==1){
		GPIOD->PDOR|= SegmentoA;
		GPIOD->PDOR|= SegmentoB;
		GPIOD->PDOR|= SegmentoE;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR3==2){
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
	}else if(*VAR3==3){
		GPIOD->PDOR|= SegmentoA;
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoE;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR3==4){
		GPIOD->PDOR|= SegmentoA;
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR3==5){
		GPIOD->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;
	}
}
