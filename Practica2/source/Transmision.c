#include "Transmision.h"
#include "Debouncer.h"
#include "GPIO_Driver.h"
#include "Tacometer.h"
#include "Carrito.h"

uint16 mul=0;
uint8 SpeedTacometroyPWM=0;
uint8 VARup=1;

void Transmision_vfnParking (void){
	if((SpeedTacometroyPWM!=0)){
	VARup=1;
	}
	if(UNO_Constante(enBotton0)){
		SpeedDown ();
		Debouncer(enBotton2,enBotton2);
		Debouncer(enBotton3,enBotton3);
		if(UNO_Constante(enBotton4)){
				Clutch ();
		}
	}

}
void Transmision_vfnDrive (void){
	if(UNO_Constante(enBotton0)){
		SpeedDown ();
	}else if(UNO_Constante(enBotton4)){
		Debouncer(enBotton2,enBotton2);
		Debouncer(enBotton3,enBotton3);
			Clutch ();
	}else if(UNO_Constante(enBotton1)){
			if((VARup==2)&&(SpeedTacometroyPWM<30)){
					SpeedTacometroyPWM++;
					Tacometer_vfnSpeedUp ();
			}else if((VARup==3)&&(SpeedTacometroyPWM<60)){
				SpeedTacometroyPWM++;
				Tacometer_vfnSpeedUp ();
			}else if((VARup==4)&&(SpeedTacometroyPWM<90)){
				SpeedTacometroyPWM++;
				Tacometer_vfnSpeedUp ();
			}else if((VARup==5)&&(SpeedTacometroyPWM<120)){
				SpeedTacometroyPWM++;
				Tacometer_vfnSpeedUp ();
			}
			SpeedUp();
		}
}

void Transmision_vfnReverse (void){
	if(UNO_Constante(enBotton0)){
		SpeedReverse ();
	}else if(UNO_Constante(enBotton4)){
		Debouncer(enBotton2,enBotton2);
		Debouncer(enBotton3,enBotton3);

		if(SpeedTacometroyPWM==0){
			Clutch ();
		}
	}else if(UNO_Constante(enBotton1)){
		if((VARup==0)&&(SpeedTacometroyPWM<120)){
					SpeedTacometroyPWM++;
					Tacometer_vfnSpeedUp ();
				}
				SpeedUpReverse();
			}
}

void SpeedUp (void){
Debouncer(enBotton1,enBotton1);
if(UNO_Constante(enBotton1)){
			ClearGPIOS();
			mul=(SpeedTacometroyPWM)*54;
			GPIOC->PSOR = (1<<2);
			GPIOC->PCOR = (1<<2);
			GPIOC->PDOR &= ~(1<<2);
			GPIOC->PDOR |= (1<<1);
			if(SpeedTacometroyPWM>120){
				SpeedTacometroyPWM=120;
			    Tacometer_vfnSpeedUp ();
			}else{
				//Nothing to do
			}


}else{
	//Nothing to do
}
PWM_Acelerator(&mul);



}
void SpeedUpReverse (void){
Debouncer(enBotton1,enBotton1);
if(UNO_Constante(enBotton1)){
			ClearGPIOS();
			mul=(SpeedTacometroyPWM)*54;
			GPIOC->PSOR = (1<<1);
			GPIOC->PCOR = (1<<1);
			GPIOC->PDOR &= ~(1<<1);
			GPIOC->PDOR |= (1<<2);
			if(SpeedTacometroyPWM>120){
				SpeedTacometroyPWM=120;
			    Tacometer_vfnSpeedUp ();
			}else{
				//Nothing to do
			}


}else{
	//Nothing to do
}
PWM_Acelerator(&mul);



}

void SpeedDown (void){
if(UNO_Constante(enBotton0)){
	ClearGPIOS();
	mul=(SpeedTacometroyPWM)*54;
	if(SpeedTacometroyPWM!=0){

	    Tacometer_vfnSpeedDown ();
	    SpeedTacometroyPWM--;
	    if((SpeedTacometroyPWM>60)&&(SpeedTacometroyPWM<90)){
			VARup=4;
	    }else if((SpeedTacometroyPWM>30)&&(SpeedTacometroyPWM<59)){
	    	VARup=3;
	    }else if((SpeedTacometroyPWM>0)&&(SpeedTacometroyPWM<29)){
	    	VARup=2;
	    }
	}else{
		//do nothing
	}

}else{
	//Nothing to do
}
PWM_Acelerator(&mul);
}

void SpeedReverse (void){
	if(UNO_Constante(enBotton0)){
		ClearGPIOS();
		mul=(SpeedTacometroyPWM)*54;
		if(SpeedTacometroyPWM!=0){
			SpeedTacometroyPWM--;
		    Tacometer_vfnSpeedDown ();
		}else{
			//do nothing
		}
	}else{
		//Nothing to do
	}
	PWM_Acelerator(&mul);
}


void GEAR_UP (void){
		SegmentosOn_Estados_Up(&VARup);
		ClearGPIOS();

		if(VARup==5){
			VARup=4;
		}else{
			//Nothing
		}
		VARup++;
}

void GEAR_DOWN (void){
		SegmentosOn_Estados_Up(&VARup);
		ClearGPIOS();
		if(VARup==0){
			VARup=VARup+1;
		}else{
			//Nothing
		}
		VARup--;
}

void Clutch (void){

	if(True(enBotton2)){
		GEAR_UP ();
		DriveState();
		Clean (enBotton2);


	}else{
		if(True(enBotton3)){
			GEAR_DOWN ();
			DriveReverseState();

			if(VARup==1){
				ParkingState();
			}
			Clean (enBotton3);
		}
	}
}



