#include "Debouncer.h"
#include "MKL25Z4.h"
#include "GPIO_Driver.h"
#include "PWM_Driver.h"
#include "Carrito.h"
#include "Transmision.h"

uint16 Segundos=0;
MyStateMachine States=Parking;
int main() {
GPIOS ();
PWM_Init ();
ClearGPIOS();
	while(1) {
		VEINTE_mSEGUNDOS ();
		Segundos++;
			if(States==Parking){
				Debouncer(enBotton0,enBotton0);
				Debouncer(enBotton4,enBotton4);
				Transmision_vfnParking ();
			}else if(States==Drive){
				Debouncer(enBotton0,enBotton0);
				Debouncer(enBotton4,enBotton4);
				Debouncer(enBotton1,enBotton1);
				if(Segundos==50){
					Transmision_vfnDrive();
				}
			}else if(States==Reverse){
				Debouncer(enBotton0,enBotton0);
				Debouncer(enBotton4,enBotton4);
				Debouncer(enBotton1,enBotton1);
				if(Segundos==50){
					Transmision_vfnReverse ();
				}
			}
			if(Segundos==50){
				Segundos=0;
			}
		Barrido();
	}
}
void DriveState(void){
	States=Drive;
}

void DriveReverseState(void){
	States=Reverse;
}

void ParkingState(void){
	States=Parking;
}
