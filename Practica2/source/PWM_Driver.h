#ifndef PWM_DRIVER_H_
#define PWM_DRIVER_H_

typedef unsigned short uint16;

void PWM_Init (void);
void PWM_Acelerator(uint16 *mul);
void PWM_Break(uint16 *mul);
void PWM_Decremento(void);
#endif /* PWM_DRIVER_H_ */
