#include "MKL25Z4.h"

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


uint8 True (uint8 Posicion);
void BottonSeconds (uint8 *VarBtnSuma);
void BottonRun (uint8 *VarBtnRun);
void Debouncer (uint8 Posicion,uint8 ReadPin);


#define PUERTOSE (1<<13)



#endif /* DEBOUNCER_H_ */
