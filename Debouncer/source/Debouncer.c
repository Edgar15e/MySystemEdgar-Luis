#include "MKL25Z4.h"
#include "Debouncer.h"
#include "GPIO_Driver.h"
#include "PWM_Driver.h"

void INIT_DEBOUNCE (void){

	SIM->SCGC5|=PUERTOSE;
	PORTE->PCR[enBotton0]|= ON;
	PORTE->PCR[enBotton1]|= ON;
	PORTE->PCR[enBotton2]|= ON;
	PORTE->PCR[enBotton3]|= ON;
	PORTE->PCR[enBotton4]|= ON;
	PORTE->PCR[enBotton5]|= ON;

}

MyStruct BottomsData[TotalBottoms];

void Debouncer (uint8 Posicion,uint8 ReadPin){
	BottomsData[Posicion].au8Snapshots[BottomsData[Posicion].u8Cntr] = ReadPinGpio(ReadPin);
	if(BottomsData[Posicion].au8Snapshots[BottomsData[Posicion].u8Cntr]!=BottomsData[Posicion].u8StableState){
		BottomsData[Posicion].u8Cntr++;
	}else{
		BottomsData[Posicion].u8Cntr=0;
	}

	if(BottomsData[Posicion].au8Snapshots[0]==BottomsData[Posicion].au8Snapshots[2]){
		BottomsData[Posicion].u8Cntr=0;
		BottomsData[Posicion].LastStableState=BottomsData[Posicion].u8StableState;
		BottomsData[Posicion].u8StableState=BottomsData[Posicion].au8Snapshots[2];
	}else{
		//nothing to do
	}
}

uint8 True (uint8 Posicion){
	if(BottomsData[Posicion].LastStableState!=BottomsData[Posicion].u8StableState){
		return 1;
	}else{
		return 0;
	}
}

uint8 UNO_Constante (uint8 Posicion){
	return BottomsData[Posicion].u8StableState;
}


/*
void BottonSeconds (uint8 *VarBtnSuma){
	Debouncer(enBotton0,enBotton0);
	if(True(enBotton0)){
		*VarBtnSuma=*VarBtnSuma+1;
		if(*VarBtnSuma==10){
			*VarBtnSuma=0;
		}else{
			//Nothing to do
		}
	    }else{
	    	//Nothing to do
	}
}*/

uint8 Datos_Aumento=0;
void BottonAcelerator(uint8 *Pison){
	Debouncer(enBotton0,enBotton0);
	if(UNO_Constante(enBotton0)){
		PWM_Acelerator();

	}else{
		//Nothing to do
	}
}

void BottonDecremento(uint8 *Frenon){
	Debouncer(enBotton1,enBotton1);
	if(UNO_Constante(enBotton1)){
		PWM_Break();

	}else{
		//Nothing to do
	}
}
