#include "buzzer.h"

void Buzzer_setState(unsigned char state) {
    BUZZER_PIN = state;
}
