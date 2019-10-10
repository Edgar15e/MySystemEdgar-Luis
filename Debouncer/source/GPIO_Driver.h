#include "MKL25Z4.h"
#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

typedef unsigned long uint32;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef enum{
	enDisplay1=10,
	enDisplay2,
	enDisplay3,
	enDisplay4,
	enDisplays
}MyDisplays;

#define ONESECOND 1250
#define SegmentoA (1<<1)
#define SegmentoB (1<<2)
#define SegmentoC (1<<12)
#define SegmentoD (1<<5)
#define SegmentoE (1<<0)
#define SegmentoF (1<<2)
#define SegmentoG (1<<3)

void ClearGPIOS (void);

void UNIDADES (uint8 *VARu);
void SegmentosOnU(uint8 *VAR2u);

uint32 ReadPinGpio(uint32 Pin2Read);
void GPIOS (void);
void DisplayOn (uint8 *VAR);
void SegmentosOn(uint8 *VAR2);
void VEINTE_mSEGUNDOS (void);

#define LED (1<<7)

#define PUERTOSD (1<<12)
#define PUERTOSC (1<<11)
#define PUERTOSA (1<<9)
#define PUERTOSE (1<<13)

#define ON (1<<8)


#endif /* GPIO_DRIVER_H_ */
