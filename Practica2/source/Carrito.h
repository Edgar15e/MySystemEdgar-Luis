#ifndef CARRITO_H_
#define CARRITO_H_

typedef enum{
	Reverse=0,
	Parking,
	Drive

}MyStateMachine;
void DriveState(void);
void DriveReverseState(void);
void ParkingState(void);

#endif /* CARRITO_H_ */
