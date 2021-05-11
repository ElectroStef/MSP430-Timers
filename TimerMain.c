#include <msp430.h>
#include <TimerMain.h>


int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &=  ~LOCKLPM5;

  setUpGPIOs();
  setUpTimerA0();
  setUpTimerA1();
  setUpTimerA2();

  _bis_SR_register(LPM0_bits + GIE);
  _no_operation();

}





