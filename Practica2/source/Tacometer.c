#include "Tacometer.h"
#include "GPIO_Driver.h"

	uint8 Unidades=0;
	uint8 Decenas=0;
	uint8 Centenas=0;
void Tacometer_vfnSpeedUp (void){
if(Unidades==9){
		Unidades=0;
		if(Decenas==9){
			Decenas=0;
			if(Centenas==0){
				Decenas=0;
			}
			if(Centenas==9){
				Centenas=0;
			}else{
				Centenas++;

			}
		}else{
			Decenas++;
	}
	}else{
		Unidades++;
	}

}

void Tacometer_vfnSpeedDown (void){
	if(Unidades==0){
			Unidades=9;
			if(Decenas==0){
				Decenas=9;
				if(Centenas==0){
					Decenas=9;
				}
				if(Centenas==9){
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

}

uint8 FirstDisplayEstado=3;
uint8 SecondDisplay=2;
uint8 ThirdDisplay=1;
uint8 FourthDsiplay=0;
extern uint8 VARup;
void Barrido (void){
static uint8 Barrido=0;
if(Barrido==0){
	SegmentosOn_Estados_Up(&VARup);
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

