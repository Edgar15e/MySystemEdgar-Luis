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
    	 	 if(Segundos==50){
				Variable2++;
				SegmentosOn(&Variable2);
				LED_Toggle ();
				Segundos=0;
    	 	 }else{
				Variable++;
				DisplayOn (&Variable);
				if(Variable==3){
					Variable=0;
				}
   	 	 }

}
}

