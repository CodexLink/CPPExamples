/*
BackandForth.ino
LED Simulation | Back and Forth
Created by Janrey "CodexLink" Licas on 09/05/2021, 1:52pm

https://github.com/CodexLink/StashedCodes | See the LICENSE for more information.
*/

#include <inttypes.h>

#define TRAVEL_TIME 150

enum DIRECTION {
	UP,
	DOWN,
};

const uint8_t LEDS_PIN_RANGE_MIN = 2, LEDS_PIN_RANGE_MAX = 9;

void setup() {
	for (uint8_t PIN = LEDS_PIN_RANGE_MIN; PIN <= LEDS_PIN_RANGE_MAX; PIN++) {
		pinMode(PIN, OUTPUT);
	}
}

void loop() {
	static DIRECTION currDirection = DIRECTION::DOWN; // Customizable startpoint.
	static uint8_t currPin = currDirection == DIRECTION::UP ? LEDS_PIN_RANGE_MIN : LEDS_PIN_RANGE_MAX;

	digitalWrite(currPin, HIGH), delay(TRAVEL_TIME);
	currDirection == DIRECTION::UP ? currPin += 1 : currPin -= 1;
	digitalWrite((currDirection == DIRECTION::UP && currPin != LEDS_PIN_RANGE_MIN ? (currPin - 1) : (currDirection == DIRECTION::DOWN && currPin != LEDS_PIN_RANGE_MAX ? currPin + 1 : false)), LOW);
	currDirection = (currPin == LEDS_PIN_RANGE_MAX) ? DIRECTION::DOWN : (currPin == LEDS_PIN_RANGE_MIN) ? DIRECTION::UP : currDirection;
}