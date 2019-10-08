#include "Debouncer.h"
#include "MKL25Z4.h"
#include "GPIO_Driver.h"
uint16 Segundos=0;
uint8 UniSeg=0;
uint8 FirstDisplay=3;
uint8 DecSeg=1;
uint8 SecondDisplay=2;
uint8 UniMin=0;
uint8 ThirdDisplay=1;
uint8 DecMin=0;
uint8 CuartoDsiplay=0;
uint8 Barrido=0;

uint32 ReadPin=0;
uint8 Posicion=0;

uint8 Run=0;



int main() {
GPIOS ();
//ClearGPIOS();
	while(1) {
		VEINTE_mSEGUNDOS ();
		Segundos++;
		BottonSeconds (&UniSeg);

//if(BottonR==1){

   	 	if(Segundos==ONESECOND){
   			LED_Toggle ();
			Segundos=0;
			//	ClearGPIOS();
			if(UniSeg==0){
				UniSeg=9;
				if(DecSeg==0){
					DecSeg=9;
					if(UniMin==0){
						UniMin=9;
						if(DecMin==0){
							DecMin=9;
						}else{
							DecMin--;
						}
					}else{
						UniMin--;
					}
				}else{
					DecSeg--;
				}
			}else{
			UniSeg--;
			}
   	 	}else{
		if(Barrido==0){
			SegmentosOn(&UniSeg);
			DisplayOn(&FirstDisplay);
			Barrido++;
			}else{
			if(Barrido==1){
				SegmentosOn(&DecSeg);
				DisplayOn(&SecondDisplay);
				Barrido++;
					}else{
						if(Barrido==2){
							SegmentosOn(&UniMin);
							DisplayOn(&ThirdDisplay);
							Barrido++;
							}else{
								if(Barrido==3){
									SegmentosOn(&DecMin);
									DisplayOn(&CuartoDsiplay);
									Barrido=0;
									}else{
									//Nohing to do
								}
							}
					}
			}
   	 	}
//}//
	}
	}


