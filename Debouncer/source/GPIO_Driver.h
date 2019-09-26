#include "MKL25Z4.h"

typedef unsigned char uint8;
typedef unsigned short uint16;

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

void GPIOS (void);
void LED_Toggle  (void);
void DisplayOn (uint8 *VAR);
void SegmentosOn(uint8 *VAR2);
void VEINTE_mSEGUNDOS (void);

#define LED (1<<7)

#define PUERTOSE (1<<13)
#define PUERTOSD (1<<12)
#define PUERTOSC (1<<11)
#define PUERTOSA (1<<9)

#define SegmentoA (1<<1)
#define SegmentoB (1<<2)
#define SegmentoC (1<<12)
#define SegmentoD (1<<5)
#define SegmentoE (1<<0)
#define SegmentoF (1<<2)
#define SegmentoG (1<<3)

#define ON (1<<8)




#endif /* GPIO_DRIVER_H_ */
