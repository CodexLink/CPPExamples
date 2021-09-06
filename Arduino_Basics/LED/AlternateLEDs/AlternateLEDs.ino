/*
AlternatingLED.ino | LED Simulation | Christmas Lights
Created by Janrey "CodexLink" Licas on 09/04/2021, 9:04pm

https://github.com/CodexLink/StashedCodes | See the LICENSE for more information.
*/

#include <inttypes.h>

#define LED_TRANSITION_TIME 500

struct XMAS {

	enum LED_ACTIONS : uint8_t {
		HANDLE_SETUP,
		XMAS_ALTERNATE
	};

	static const uint8_t LEDS_PIN_RANGE_MIN = 2, LEDS_PIN_RANGE_MAX = 7;
};

void pinsHandler(XMAS::LED_ACTIONS actions);

void setup() {
	pinsHandler(XMAS::LED_ACTIONS::HANDLE_SETUP);
}

void loop() {
	pinsHandler(XMAS::LED_ACTIONS::XMAS_ALTERNATE);
}

void pinsHandler(XMAS::LED_ACTIONS actions) { // * Contain the redundancy here!
  	static bool doAlter = false;
	for (uint8_t LTR = XMAS::LEDS_PIN_RANGE_MIN; LTR <= XMAS::LEDS_PIN_RANGE_MAX; LTR++) {

		switch (actions) {
		case XMAS::LED_ACTIONS::HANDLE_SETUP:
			pinMode(LTR, OUTPUT);
          	continue;

		case XMAS::LED_ACTIONS::XMAS_ALTERNATE:
			digitalWrite(LTR, (doAlter && !(LTR % 2) || !doAlter && LTR % 2) ? HIGH : LOW);
          	continue;

		default:
			break;
        }
	}
    doAlter = !doAlter;
  	delay(LED_TRANSITION_TIME);
}