
#include "UART0_Driver.h"
#include "Debouncer.h"
#include "MKL25Z4.h"
#include "GPIO_Driver.h"
#include "PWM_Driver.h"
#include "Carrito.h"
#include "Transmision.h"

void UART0_Init (void){
	SIM->SOPT2|=SIM_SOPT2_UART0SRC(1);
	SIM->SCGC4|=SIM_SCGC4_UART0_MASK ;
	UART0->BDL=137;
	UART0->C1 =0;
	UART0->C4 |=UART0_C4_OSR(15) ;
	SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;
	PORTA->PCR[1]|= PORT_PCR_MUX(2);
	PORTA->PCR[2]|= PORT_PCR_MUX(2);
	UART0->C2|=UART0_C2_TE_MASK;
	UART0->C2|=UART0_C2_RE_MASK;
}

static uint8_t Gobernar=0;
static uint8_t Gobernar1=0;
uint8_t index1=0;
uint8_t x=0;
uint8_t y=0;
static uint8 GobernarVel[3]={};
void UART_Reciver (void){
	if(UART0->S1&UART_S1_RDRF_MASK){
	if(Gobernar!='3'){
		Gobernar=UART0->D;
		}else {
			Gobernar1=UART0->D;
		}
	switch(Gobernar){
	case'1'://Ajusta la velocidad maxima del vehiculo
		Imprimir_Letras_UART0 ();
		for(x=0; x<sizeof(GobernarVel);x++){
			while((UART0->S1&UART_S1_RDRF_MASK)==0){}
			if(UART0->S1&UART_S1_RDRF_MASK){
				GobernarVel[index1]=UART0->D;
				index1++;
			}
		}
		index1=0;
		Imprimir_Numeros_UART ();
		break;

	case '2'://obtiene velocidad actual del comando
		Imprimir_Letras_UART0 ();
	break;

	case '3': //entra al modo libre por diagnostico
		y=3;
		if(Gobernar1=='s'){
		Imprimir_Letras_UART0 ();
		y=1;
		}else if(Gobernar1=='w'){
		Imprimir_Letras_UART0 ();
		y=2;
		}else if(Gobernar1=='2'){
			Imprimir_Letras_UART0 ();
		}else if(Gobernar1=='4'){
		Imprimir_Letras_UART0 ();
		y=0;
		Gobernar=0;
		Gobernar1=0;
		}
		//Imprimir_Letras_UART0 ();
	break;
	default:
		//nothing to do
	break;
	}

}
}
uint8 PrimerNum=0;
void UART_Transmitter (void){
	switch(Gobernar){
	case'1'://Ajusta la velocidad maxima del vehiculo
		SpeedUp1 (PrimerNum);
		Gobernar=0;
	break;

	case '2'://obtiene velocidad actual del comando


	break;

	case '3': //entra al modo libre por diagnostico


	break;

	default:
		//nothing to do
	break;
	}

}


void Imprimir_Numeros_UART (void){

uint8 x=0;
uint8 index1=0;

	switch (Gobernar){
		case '1':
		for (x = 0; x < sizeof(GobernarVel); x++)
			{
			if(index1==0){
				PrimerNum=((GobernarVel [0]-48)*(100));
				}else if(index1==1){
				PrimerNum+=((GobernarVel [1]-48)*(10));
				}else if(index1==2){
				PrimerNum+=GobernarVel[2]-48;

				}
				while((UART0->S1&UART_S1_TDRE_MASK)==0){
				}
				if(UART0->S1&UART_S1_TDRE_MASK )
				{
				UART0->D = GobernarVel [index1];
				index1++;
				}


			}
		UART_Transmitter ( );
		break;

		/*case '2':

			for (x = 0; x <sizeof(tacometro); x++)
			{
				while((UART0->S1&UART_S1_TDRE_MASK)==0){

				}
				if(UART0->S1&UART_S1_TDRE_MASK )
				{
				UART0->D = tacometro [index1];
				index1++;
				}
			}

		break;*/
/*
		case '3':
			for (i = 0; i < sizeof(Letras3); i++)
			{
				while((UART0->S1&UART_S1_TDRE_MASK)==0){

				}
				if(UART0->S1&UART_S1_TDRE_MASK )
				{
				UART0->D = Letras3 [index];
				index++;
				}
			}
		break;

		case '4':
			for (i = 0; i < sizeof(Letras4); i++)
			{
				while((UART0->S1&UART_S1_TDRE_MASK)==0){

				}
				if(UART0->S1&UART_S1_TDRE_MASK )
				{
				UART0->D = Letras4 [index];
				index++;
				}
			}

		break;

		case'5':
			for (i = 0; i < sizeof(Letras5); i++)
			{
				while((UART0->S1&UART_S1_TDRE_MASK)==0){

				}
				if(UART0->S1&UART_S1_TDRE_MASK )
				{
				UART0->D = Letras5 [index];
				index++;
				}
			}

		break;

		case '6':
			for (i = 0; i < sizeof(Letras6); i++)
			{
				while((UART0->S1&UART_S1_TDRE_MASK)==0){

				}
				if(UART0->S1&UART_S1_TDRE_MASK )
				{
				UART0->D = Letras6 [index];
				index++;
				}
			}
		break;*/

	default :

	break;
}
}


void Imprimir_Letras_UART0 (void){
	uint8_t Letras1 []= {'A','j','u','s','t','e',' ','v','e','l',' ','M','a','x',' '};
	uint8_t Letras2 [] = {'V', 'e', 'l', ' ','A','c','t'};
	uint8_t Letras4 []= {'S','a','l','i','r',' ','M','o','t','o','r',' ','L','i','b','r','e'};
	uint8_t Letras6 []= {'S','u','b','i','r',' ','V','e','l',' ','M','a','x',' ','W'};
	uint8_t Letras5 []= {'B','a','j','a','r',' ','V','e','l',' ','M','a','x',' ','S'};
	uint8_t index=0;
	uint8_t i=0;
	switch (Gobernar){
	case '1':
		for (i = 0; i < sizeof(Letras1); i++)
		{
			while((UART0->S1&UART_S1_TDRE_MASK)==0){
			}
			if(UART0->S1&UART_S1_TDRE_MASK )
			{
			UART0->D = Letras1 [index];
			index++;
			}
		}
	break;

	case '2':
		for (i = 0; i <sizeof(Letras2); i++)
		{
			while((UART0->S1&UART_S1_TDRE_MASK)==0){

			}
			if(UART0->S1&UART_S1_TDRE_MASK )
			{
			UART0->D = Letras2 [index];
			index++;
			}
		}
	break;




default :

break;
}
	switch(Gobernar1){
	case '2':
		for (i = 0; i <sizeof(Letras2); i++)
		{
			while((UART0->S1&UART_S1_TDRE_MASK)==0){

			}
			if(UART0->S1&UART_S1_TDRE_MASK )
			{
			UART0->D = Letras2 [index];
			index++;
			}
		}
	break;
	case '4':
			for (i = 0; i < sizeof(Letras4); i++)
			{
				while((UART0->S1&UART_S1_TDRE_MASK)==0){

				}
				if(UART0->S1&UART_S1_TDRE_MASK )
				{
				UART0->D = Letras4 [index];
				index++;
				}
			}

		break;

		case's':
			for (i = 0; i < sizeof(Letras5); i++)
			{
				while((UART0->S1&UART_S1_TDRE_MASK)==0){

				}
				if(UART0->S1&UART_S1_TDRE_MASK )
				{
				UART0->D = Letras5 [index];
				index++;
				}
			}

		break;

		case 'w':
			for (i = 0; i < sizeof(Letras6); i++)
			{
				while((UART0->S1&UART_S1_TDRE_MASK)==0){

				}
				if(UART0->S1&UART_S1_TDRE_MASK )
				{
				UART0->D = Letras6 [index];
				index++;
				}
			}
		break;

}
}

