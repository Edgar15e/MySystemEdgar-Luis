#include "Debouncer.h"
#include "MKL25Z4.h"
#include "GPIO_Driver.h"
#include "PWM_Driver.h"
#include "Carrito.h"
#include "Transmision.h"
#include "UART0_Driver.h"

uint16 Segundos=0;
uint16 Segundos1=0;
MyStateMachine States=Parking;
extern uint8 y;
int main() {
GPIOS ();
PWM_Init ();
ClearGPIOS();
UART0_Init();

	while(1) {
	UART_Reciver ();
		UART_Transmitter();
		VEINTE_mSEGUNDOS ();
		Segundos++;

		if(y==1){
			while(Segundos1<900){
				Segundos1++;
			}
			Segundos1=0;
			ALV_Bottones_Up();
		}else if(y==2){
			while(Segundos1<900){
				Segundos1++;
			}
			Segundos1=0;
			ALV_Bottones_Down ();
		}
		if(y!=1&&y!=2&&y!=3){
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
		}else{
				//do nothing
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
