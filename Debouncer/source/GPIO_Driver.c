
#include "Debouncer.h"
#include "MKL25Z4.h"
#include "GPIO_Driver.h"

void GPIOS (void){
	SIM->SCGC5|=PUERTOSE;
	SIM->SCGC5|=PUERTOSD;
	SIM->SCGC5|=PUERTOSC;
	SIM->SCGC5|=PUERTOSA;

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

	GPIOC->PDDR|=1<<enDisplay1;
	GPIOC->PDDR|=1<<enDisplay2;
	GPIOC->PDDR|=1<<enDisplay3;
	GPIOC->PDDR|=1<<enDisplay4;

	GPIOA->PDDR|= SegmentoA;
	GPIOA->PDDR|= SegmentoB;
	GPIOA->PDDR|= SegmentoC;
	GPIOA->PDDR|= SegmentoD;
	GPIOD->PDDR|= SegmentoE;
	GPIOD->PDDR|= SegmentoF;
	GPIOD->PDDR|= SegmentoG;
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
	GPIOA->PCOR= ~SegmentoA;
	GPIOA->PCOR= ~SegmentoB;
	GPIOA->PCOR= ~SegmentoC;
	GPIOA->PCOR= ~SegmentoD;
	GPIOD->PCOR= ~SegmentoE;
	GPIOD->PCOR= ~SegmentoF;
	GPIOD->PCOR= ~SegmentoG;
	GPIOA->PCOR= SegmentoA;
	GPIOA->PCOR= SegmentoB;
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
		GPIOA->PDOR|= SegmentoA;
		GPIOA->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==8){
		GPIOA->PDOR|= SegmentoA;
		GPIOA->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoE;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==7){
		GPIOA->PDOR|= SegmentoA;
		GPIOA->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
	}else if(*VAR2==6){
		GPIOA->PDOR|= SegmentoA;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoE;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==5 ){
		GPIOA->PDOR|= SegmentoA;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==4 ){
		GPIOA->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOD->PDOR|= SegmentoF;
		GPIOD->PDOR|= SegmentoG;

	}else if(*VAR2==3 ){
		GPIOA->PDOR|= SegmentoA;
		GPIOA->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==2 ){
		GPIOA->PDOR|= SegmentoA;
		GPIOA->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoE;
		GPIOD->PDOR|= SegmentoG;
	}else if(*VAR2==1){
		GPIOA->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
	}else if(*VAR2==0){
		GPIOA->PDOR|= SegmentoA;
		GPIOA->PDOR|= SegmentoB;
		GPIOA->PDOR|= SegmentoC;
		GPIOA->PDOR|= SegmentoD;
		GPIOD->PDOR|= SegmentoE;
		GPIOD->PDOR|= SegmentoF;
	}else{
		//Nothing to do
	}
}
uint32 CheckPin=0;
uint32 ReadPinGpio(uint32 Pin2Read){
	if((GPIOE->PDIR) & (1<<Pin2Read)){
		return 1;
	}else{
		return 0;
	}
}



