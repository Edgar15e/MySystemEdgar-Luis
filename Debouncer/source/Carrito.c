#include "Debouncer.h"
#include "MKL25Z4.h"
#include "GPIO_Driver.h"
#include "PWM_Driver.h"

uint16 Segundos=0;
uint8 Estado=5;
uint8 FirstDisplayEstado=3;
uint8 Unidades=0;
uint8 SecondDisplay=2;
uint8 Decenas=2;
uint8 ThirdDisplay=1;
uint8 Centenas=1;
uint8 FourthDsiplay=0;
uint8 Barrido=0;
uint32 ReadPin=0;
uint8 Posicion=0;
uint8 Run=0;
uint8 Acel=0;
uint8 Decre=0;

int main() {
GPIOS ();
PWM_Init ();
ClearGPIOS();
	while(1) {
		VEINTE_mSEGUNDOS ();
		Segundos++;
		//BottonSeconds (&Estado);
		BottonAcelerator(&Acel);
		BottonDecremento(&Decre);
   	 	if(Segundos==ONESECOND){
   	 	ClearGPIOS();
			Segundos=0;
				if(Unidades==0){
					Unidades=9;
					if(Decenas==0){
						Unidades=0;
					}
					if(Decenas==0){
						Decenas=9;
						if(Centenas==0){
							Decenas=0;
						}
						if(Centenas==0){
							Centenas=0;
						}else{
							Centenas--;
						}
					}else{
						Decenas--;
					}
				}else{
					Unidades--;
				}
   	 	}else{
		if(Barrido==0){
			SegmentosOn(&Estado);
			DisplayOn(&FirstDisplayEstado);
			Barrido++;
			}else{
			if(Barrido==1){
				SegmentosOn(&Unidades);
				DisplayOn(&SecondDisplay);
				Barrido++;
					}else{
						if(Barrido==2){
							SegmentosOn(&Decenas);
							DisplayOn(&ThirdDisplay);
							Barrido++;
							}else{
								if(Barrido==3){
									SegmentosOn(&Centenas);
									DisplayOn(&FourthDsiplay);
									Barrido=0;
									}else{
						}
					}
				}
			}
   	 	}
	}
}

