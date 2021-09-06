/*
LED Simulation | TrafficLights.ino
Created by Janrey "CodexLink" Licas
Created on 09/05/2021, 5:16pm

https://github.com/CodexLink/StashedCodes | See the LICENSE for more information.
*/


#include <inttypes.h>
#define waitBySeconds(n) delay(n * 1000) // Evaluate single digit to seconds.

const uint8_t LEDS_PIN_RANGE_MIN = 2, LEDS_PIN_RANGE_MAX = 4;

enum LIGHTS : uint8_t {
	UNKNOWN = 0,
	RED = 2,
	YELLOW = 3,
	GREEN = 4
};

enum TIMEOUTS : uint8_t { // Using std::map here is too costly, seperating it with enum LIGHTS instead.
	GREEN_L = 7,
	YELLOW_L = 4,
	RED_L = 10
};

enum OPTIONS : uint8_t {
	LITERALLY_SETUP,
	TOGGLE_TRAFFIC
};

void _displayState(enum LIGHTS current);
void pinsHandle(enum OPTIONS opt, enum LIGHTS toLight); // -fpermissive is not possible here :(


void setup() {
	pinsHandle(OPTIONS::LITERALLY_SETUP, LIGHTS::UNKNOWN);
	Serial.begin(9600); // Required this time to show the state of traffic light.
}

void loop()
{
	pinsHandle(OPTIONS::TOGGLE_TRAFFIC, LIGHTS::RED);
	pinsHandle(OPTIONS::TOGGLE_TRAFFIC, LIGHTS::GREEN);
}

void pinsHandle(enum OPTIONS opt, enum LIGHTS toLight) { // Adapted from First Supplementary Activity.
	switch (opt) {
	case OPTIONS::LITERALLY_SETUP:
		for (auto LED = LEDS_PIN_RANGE_MIN; LED <= LEDS_PIN_RANGE_MIN; LED++) {
		pinMode(LED, OUTPUT);
        }
		break;

	case OPTIONS::TOGGLE_TRAFFIC:
		static bool hasStarted = false;

		if (toLight == LIGHTS::YELLOW) {
			Serial.println("You cannot toggle to Warning (YELLOW). This is a mistake, please check the sketch.");
			while (true) { yield(); };
		}
		else {

          if (!hasStarted) {
          	digitalWrite(toLight, HIGH);
            hasStarted = !hasStarted;
            break;
          }
          else {
            for (auto LED = LEDS_PIN_RANGE_MIN; LED <= LEDS_PIN_RANGE_MAX; LED++) {
				digitalWrite(LED, LOW);
        	}
          	digitalWrite(LIGHTS::YELLOW, HIGH);
			_displayState(LIGHTS::YELLOW);
            digitalWrite(LIGHTS::YELLOW, LOW);
            digitalWrite(toLight, HIGH);
          }

		}

		break;

    }
	_displayState(toLight);
}

void _displayState(enum LIGHTS current) { // Cannot DRY this function.
	Serial.print("The traffic state is currently on ");
	enum TIMEOUTS lightsTimeout;

	switch (current) {
	case LIGHTS::GREEN:
		Serial.print("Go State (GREEN). This will took ");
		lightsTimeout = TIMEOUTS::GREEN_L;
		break;
	case LIGHTS::YELLOW:
		Serial.print("Warning State (YELLOW). This will took ");
		lightsTimeout = TIMEOUTS::YELLOW_L;
		break;
	case LIGHTS::RED:
		Serial.print("Stop State (RED). This will took ");
		lightsTimeout = TIMEOUTS::RED_L;
		break;
	default:
		break;
	}

	Serial.print(lightsTimeout);
	Serial.println(" seconds before changing state.");
	waitBySeconds(lightsTimeout);
}