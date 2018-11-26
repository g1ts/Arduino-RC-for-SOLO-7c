/*
 * An IR LED must be connected to Arduino PWM pin 3.
 * (for Mega pin 9, for other see in IRremoteInt.h)
 */

#include <IRremote.h>

IRsend irsend;

void setup(){
  Serial.begin(9600);
}


int c;

void loop() {
  c = Serial.read();
  if (c != -1) {
    switch (c) {
        case 0x31: // 1 - muteBtn
            irsend.sendNEC(0x807f40bf, 32);
            break;
        case 0x32: // 2 - vupBtn
            irsend.sendNEC(0x807F8877, 32);
            break;
        case 0x33: // 3 - vdownBtn
            irsend.sendNEC(0x807F08F7, 32);
            break;
        case 0x34: // 4 - tUpBtn
            irsend.sendNEC(0x807F906F, 32);
            break;
        case 0x35: // 5 - tDownBtn
            irsend.sendNEC(0x807FB04F, 32);
            break;
        case 0x36: // 6 - bUpBtn
            irsend.sendNEC(0x807F50AF, 32);
            break;
        case 0x37: // 7 - bDownBtn
            irsend.sendNEC(0x807F708F, 32);
            break;
        case 0x38: // 8 - resetBtn
            irsend.sendNEC(0x807F10EF, 32);
            break;
        case 0x39: // 9 - inputBtn
            irsend.sendNEC(0x807F20DF, 32);
            break;
        case 0x40: // 10 - pwrBtn
            irsend.sendNEC(0x807FC0F, 32);
            break;
        default:
            Serial.println("1 - mute");
            Serial.println("2 - vup \t3 - vdown");
            Serial.println("4 - tup \t5 - tdown");
            Serial.println("6 - bup \t7 - bdown");
            Serial.println("8 - reset\t9 - input");
            Serial.println("10 - pwr");
            break;
    }
    Serial.println("ok");
    delay(40);
  }
}
