#include "MKL25Z4.h"
#include "GPIO_Driver.h"

uint8 Segundos=0;
uint8 Variable=0;
uint8 Variable2=0;

int main() {
GPIOS ();
	while(1) {
		VEINTE_mSEGUNDOS ();
		Segundos++;
		LED_Toggle ();
    	 	if(Segundos==50){

				SegmentosOn(&Variable2);
				Variable2++;
			if(Variable2==19){
				Variable2=0;
			}
			Segundos=0;
    	 	 }else{

				DisplayOn (&Variable);
				Variable++;
		     if(Variable==4){
					Variable=0;
		     }
    }
}
}
