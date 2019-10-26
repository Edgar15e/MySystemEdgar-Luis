/*
 * UART0_Driver.h
 *
 *  Created on: 16/07/2019
 *      Author: luigi
 */
#ifndef UART0_DRIVER_H_
#define UART0_DRIVER_H_
typedef unsigned char uint8;
void UART0_Init (void);
void UART_Reciver (void);
void UART_Transmitter (void);
void Imprimir_Letras_UART0 (void);
void Imprimir_Numeros_UART (void);
#endif /* UART0_DRIVER_H_ */
