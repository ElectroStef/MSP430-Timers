/*
This program is for the MSP430FR5969
Author: Stefan Tomovic
Date: 05/10/21
*/

#include <msp430.h>
#include <TimerMain.h>

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
  PM5CTL0 &=  ~LOCKLPM5;    //Disable the GPIO power-on default high-impedance mode to activate previously configured port settings

  setUpGPIOs();
  setUpTimerA0();
  setUpTimerA1();
  setUpTimerA2();
  _bis_SR_register(LPM0_bits + GIE);
  _no_operation();

}
