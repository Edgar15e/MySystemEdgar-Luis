#include "Debouncer.h"
#include "MKL25Z4.h"
#include "PWM_Driver.h"


void PWM_Init (void){
	/*
	 *  PORT and Pin Configuration for TPM
	 * */
	SIM->SCGC5|=(1<<12);       //Activar el PORTA TPM
	PORTD->PCR[1]|= (1<<10);   //pin del PORTA MUX // ALTERNATIVA 3 MACRO

	/*
	 * TPM Configuratin for PWM Centered-Aligned
	 * */
	SIM->SOPT2|=SIM_SOPT2_TPMSRC (1) ;     	//Activamos TPRMSRC PWM timer PWM moduleTPM
	SIM->SCGC6|=SIM_SCGC6_TPM0(1);         	//prende el TPM0 TPM
	TPM0->SC|=0b110;   	             		//Prescale to divide /64
	TPM0->SC|=TPM_SC_CMOD (1) ;          	//CMOD CLOCK MODE SELECTION LPTPM counter clock
	TPM0->CNT = 0;
	TPM0->MOD = 6570;
	TPM0->CONTROLS[1].CnSC |= 0x28;         //activamos todoMode, Edge, and Level Selection (Edge Aligned PWM configuration)

	TPM0->CONTROLS[1].CnV=200;				// Initial Position to 0°
	TPM0->CONF|=TPM_CONF_DBGMODE_MASK;// DEBUG
 }

static uint16_t Aumento=0;
static uint16_t mul=0;
void PWM_Acelerator(void){
    	Aumento++;
    	mul=(Aumento)*(54);
		TPM0->CONTROLS[1].CnV=mul;
		if(Aumento==120){
			Aumento=0;
		}else{
			//Nothing to do
		}
     //   BottonAcelerator(&Aumento);
}


void PWM_Break(void){
    	Aumento--;
    	mul=(Aumento)*(54);
		TPM0->CONTROLS[1].CnV=mul;
		if(Aumento==0){
			Aumento=120;
		}else{
			//Nothing to do
		}
     //   BottonAcelerator(&Aumento);
}

