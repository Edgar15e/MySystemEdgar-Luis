/*
 * Transmision.h
 *
 *  Created on: 13/10/2019
 *      Author: Ervin
 */
typedef unsigned char uint8;
#ifndef TRANSMISION_H_
#define TRANSMISION_H_
void Transmision_vfnParking (void);
void Transmision_vfnDrive (void);
void Transmision_vfnReverse (void);
void ALV_Bottones_Up(void);
void ALV_Bottones_Down (void);
void SpeedUp (uint8 SpeedTacometroyPWM);
void SpeedUpReverse (void);
void SpeedDown (void);
void SpeedReverse (void);
void Barrido (void);
void GEAR_UP (void);
void GEAR_DOWN (void);
void Clutch (void);
void SpeedUp1 (uint8 SpeedTacometroyPWM);
void SpeedUp2 (uint8 SpeedTacometroyPWM);


#endif /* TRANSMISION_H_ */
