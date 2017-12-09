#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

static unsigned short period = 500;

#define MIN_PERIOD 100
#define MAX_PERIOD 5000

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */

    buzzer_advance_frequency(0);	/* start buzzing!!! */
}

short play1(char currNote){
  short song[] = {3000,3000,3000,4000,4000,8000,8000,8000,8000,8000,6000,6000,6000,6500, 4000, 8000, 6000};

  return song[currNote];    
}
short play2(char currNote){
  short song[] = {2650,2650,2650,2650,2650, 2800,2800,2800,3300,3200,3250,4300,4300,4300};

  return song[currNote];
}
short play3(char currNote){
  short song[] = {2100,2100,2300,2300,2500,2500,2650,2650,2100,2100,3100,3100,3500,3500};
  
  return song[currNote];
  
}
short play4(char currNote){
  short song[] = {4036,4036,5086,5086,4530,4530,5380,5380,5086,5380,6040,5380,6790,6790,6040,6040,5086,5086,6040,6040,4036,4530,5086,5380,5086,4530,5080,5380,5380};
  
  return song[currNote];
}

void buzzer_advance_frequency(short note) {
  period = note;
  buzzer_set_period(period);
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


    
    
  

