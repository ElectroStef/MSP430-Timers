#ifndef TimerMain
#define TimerMain

void setUpTimerA0()
{
  TA0CCTL0 = CCIE;
  TA0CCR0 = 51000;
  TA0CTL = TASSEL__SMCLK |ID__4| MC__UP;
}

void setUpTimerA1()
{
  TA1CCTL0 = CCIE;
  TA1CCR0 = 52000;
  TA1CTL = TASSEL__SMCLK |ID__4 | MC__UP;
}

void setUpTimerA2()
{
  TA2CCTL0 = CCIE;
  TA2CCR0 = 53000;
  TA2CTL = TASSEL__SMCLK |ID__4|MC__UP;
}

void setUpGPIOs()
{
  PJOUT &= ~0x01;
  PJDIR |= 0x01;
  PJOUT &= ~0x02;
  PJDIR |= 0x02;
  PJOUT &= ~0x04;
  PJDIR |= 0x04;
  PJOUT &= ~0x08;
  PJDIR |= 0x08;
  P1REN |= 0x01;
  P1OUT &= ~0x01;
  P1IE |= 0x01;
  P1IES |= 0x01;
  P1IFG &= ~0x01;
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void delay1 ()
{
  PJOUT ^= BIT0;
}

#pragma vector = TIMER2_A0_VECTOR
__interrupt void delay2()
{
  PJOUT ^= BIT1;
}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void delay3()
{
  PJOUT ^= BIT2;
}

#pragma vector = PORT1_VECTOR
__interrupt void pushButton()
{
  PJOUT ^= BIT3;
  P1IFG &= ~BIT0;
}
#endif
