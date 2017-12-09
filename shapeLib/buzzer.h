#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
short play1(char currNote);
short play2(char currNote);
short play3(char currNote);
short play4(char currNote);
void buzzer_advance_frequency(short note);
void buzzer_set_period(short cycles); 


#endif // included
