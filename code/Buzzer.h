#ifndef BUZZER_H
#define BUZZER_H

#include <reg51.h>

// Define buzzer pin
sbit BUZZER_PIN = P3^6;

// Buzzer states
#define BUZZER_ON  1
#define BUZZER_OFF 0

// Function prototype
void Buzzer_setState(unsigned char state);

#endif
