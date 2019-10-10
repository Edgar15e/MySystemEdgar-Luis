#include "MKL25Z4.h"
#include "PWM_Driver.h"

#ifndef DEBOUNCER_H_
#define DEBOUNCER_H_

typedef unsigned char uint8;
typedef enum{
	enBotton0=0,
	enBotton1,
	enBotton2,
	enBotton3,
	enBotton4,
	enBotton5,
	TotalBottoms
}MyBottoms;

typedef struct{
	uint8 Pin;
	uint8 LastStableState;
	uint8 au8Snapshots[3];
	uint8 u8Cntr;
	uint8 u8StableState;
}MyStruct;



void BottonSeconds (uint8 *VarBtnSuma);
void BottonAcelerator(uint8 *Pison);
void BottonDecremento(uint8 *Decre);
void Debouncer (uint8 Posicion,uint8 ReadPin);
uint8 True (uint8 Posicion);
uint8 UNO_Constante (uint8 Posicion);


#define PUERTOSE (1<<13)



#endif /* DEBOUNCER_H_ */
