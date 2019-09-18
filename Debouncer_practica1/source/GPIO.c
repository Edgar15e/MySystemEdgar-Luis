#include "MKL25Z4.h"

void GPIO_Init (void){
SIM->SCGC5|=(1<<13);
PORTE->PCR[0]|= (1<<8);
PORTE->PCR[1]|= (1<<8);
PORTE->PCR[2]|= (1<<8);
PORTE->PCR[3]|= (1<<8);
PORTE->PCR[4]|= (1<<8);
PORTE->PCR[5]|= (1<<8);
}
