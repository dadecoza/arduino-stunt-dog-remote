#define IR_SEND_PIN 3
#include <IRremote.h>

const char menu_0[] PROGMEM = "+---------------------------------------------------+";
const char menu_1[] PROGMEM = "|                     STUNT DOG                     |";
const char menu_2[] PROGMEM = "+-------------------------+-------------------------+";
const char menu_3[] PROGMEM = "|a. Voice commands        |k. Music 2               |";
const char menu_4[] PROGMEM = "|b. Show all functions    |l. Music 3               |";
const char menu_5[] PROGMEM = "|c. Go forward            |m. Sit down              |";
const char menu_6[] PROGMEM = "|d. Stop                  |n. Say hello             |";
const char menu_7[] PROGMEM = "|e. Stand at attention    |o. Touch                 |";
const char menu_8[] PROGMEM = "|f. Increase volume       |p. Crouch                |";
const char menu_9[] PROGMEM = "|g. Turn volume down      |q. Wrath                 |";
const char menu_10[] PROGMEM = "|h. Hand stand            |r. Sitting and standing  |";
const char menu_11[] PROGMEM = "|i. Push-ups              |s. Get into programming  |";
const char menu_12[] PROGMEM = "|j. Music 1               |                         |";
const char menu_13[] PROGMEM = "+-------------------------+-------------------------+";
const char menu_14[] PROGMEM = "Please choose an action:";

const char *const menu_table[] PROGMEM = {menu_0, menu_1, menu_2, menu_3, menu_4, menu_5, menu_6, menu_7, menu_8, menu_9, menu_10, menu_11, menu_12, menu_13, menu_14};

char buffer[80];

//We used the "ReceiveDump" sketch that is part of the IRremote library to get the command timings.
const uint8_t irCommands[19][17] = {
  {119, 11, 31, 11, 31, 11, 11, 31, 31, 11, 11, 31, 31, 11, 31, 11, 31},  //  0 Voice Commands
  {119, 11, 31, 11, 31, 11, 11, 31, 31, 11, 31, 11, 11, 31, 11, 31, 31},  //  1  Show All of the function
  {119, 11, 12, 31, 31, 11, 31, 11, 31, 11, 11, 31, 11, 31, 12, 30, 12},  //  2  Go Forward
  {119, 11, 31, 11, 11, 31, 31, 11, 31, 11, 11, 31, 31, 11, 11, 31, 11},  //  3  Stop
  {119, 11, 11, 31, 31, 11, 31, 11, 31, 11, 31, 11, 11, 31, 31, 11, 31},  //  4  Stand at attention
  {119, 11, 11, 31, 31, 11, 11, 31, 31, 11, 11, 31, 31, 11, 11, 31, 11},  //  5  Increase the volume
  {119, 11, 11, 31, 31, 11, 31, 11, 31, 11, 31, 11, 11, 31, 11, 31, 31},  //  6  Turn down the volume
  {119, 11, 11, 31, 31, 11, 31, 11, 31, 11, 11, 31, 31, 11, 31, 11, 31},  //  7  Hand stand
  {119, 11, 31, 11, 11, 31, 31, 11, 31, 11, 11, 31, 31, 11, 31, 11, 31},  //  8  Push-ups
  {119, 11, 11, 31, 31, 11, 11, 31, 31, 11, 31, 11, 11, 31, 11, 31, 31},  //  9  Music 1
  {119, 11, 11, 31, 31, 11, 11, 31, 31, 11, 11, 31, 11, 31, 31, 11, 11},  //  10 Music 2
  {119, 11, 31, 11, 11, 31, 31, 11, 31, 11, 31, 11, 11, 31, 11, 31, 31},  //  11 Music 3
  {119, 11, 31, 11, 11, 31, 31, 11, 31, 11, 11, 31, 11, 31, 11, 31, 11},  //  12 Sit down
  {119, 11, 31, 11, 11, 31, 31, 11, 31, 11, 11, 31, 11, 31, 31, 11, 11},  //  13 Say hello
  {119, 11, 31, 11, 31, 11, 11, 31, 31, 11, 11, 31, 11, 31, 11, 31, 11},  //  14 Touch
  {119, 11, 31, 11, 31, 11, 11, 31, 31, 11, 11, 31, 31, 11, 11, 31, 11},  //  15 Crouch
  {119, 11, 31, 11, 11, 31, 31, 11, 31, 11, 31, 11, 11, 31, 31, 11, 31},  //  16 Wrath
  {119, 11, 31, 11, 31, 11, 11, 31, 31, 11, 31, 11, 11, 31, 31, 11, 31},  //  17 Sitting and standing
  {119, 11, 31, 11, 31, 11, 11, 31, 31, 11, 11, 31, 11, 31, 31, 11, 11},  //  18 Get into the programming
};

void printMenu() {
  for (int i = 0; i < 15; i++) {
    strcpy_P(buffer, (char *)pgm_read_word(&(menu_table[i])));
    Serial.println(buffer);
  }
}

void sendCommand(int cmd) {
  IrSender.sendRaw(irCommands[cmd], 17, 38);
  delay(500);
}

void setup()
{
  Serial.begin(115200);
  printMenu();
}

void loop() {
  if (Serial.available() > 0)  {
    int c = Serial.read();
    if ((c > 96) && (c < 116)) {
      int index = c - 97;
      Serial.println((char) c);
      sendCommand(index);
    }
  }
}
