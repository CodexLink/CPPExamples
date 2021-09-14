/*
ButtonBasedDelay.ino
LED Simulation | Button-Based Delay Setter for 6 LEDs.
Created by Janrey "CodexLink" Licas on 09/15/2021, 12:15am

https://github.com/CodexLink/StashedCodes | See the LICENSE for more information.
*/

const unsigned short MIN_BTN = 4,
MID_BTN = 3,
MAX_BTN = 2,
MIN_MS = 750, // Adjustable.
MID_MS = 500, // Adjustable.
MAX_MS = 300,  // Adjustable.
LED_START_PIN = 5,
LED_COUNTS = 6;

unsigned short delayValue = MID_MS, debounceBtnMs = 300;
bool isInit = false;


enum OPTIONS {
	INIT,
	BLINK,
};

void handleLEDs(enum OPTIONS opt);

void setup() {
	Serial.begin(9600), handleLEDs(OPTIONS::INIT);
	pinMode(MIN_BTN, INPUT), pinMode(MID_BTN, INPUT), pinMode(MAX_BTN, INPUT);
}

void loop()
{
	if (!isInit) Serial.print("Default speed is "), Serial.print(delayValue), Serial.println(" ms."), isInit = !isInit;
	if (digitalRead(MIN_BTN)) { // Won't use ternary condition here.
		Serial.print("Delay Speed adjusted to "), Serial.print(MIN_MS), Serial.println("ms.");
		delayValue = MIN_MS, delay(debounceBtnMs);
	}
	else if (digitalRead(MID_BTN)) {
		Serial.print("Delay Speed adjusted to "), Serial.print(MID_MS), Serial.println("ms.");
		delayValue = MID_MS, delay(debounceBtnMs);
	}
	else if (digitalRead(MAX_BTN)) {
		Serial.print("Delay Speed adjusted to "), Serial.print(MAX_MS), Serial.println("ms.");
		delayValue = MAX_MS, delay(debounceBtnMs);
	}
	else { ; }

	handleLEDs(OPTIONS::BLINK);
}

void handleLEDs(enum OPTIONS opt) {
	static bool shouldAlter = false;

	for (unsigned eachLEDs = LED_START_PIN; eachLEDs < LED_START_PIN + LED_COUNTS; eachLEDs++) {

		switch (opt) {
		case OPTIONS::INIT:
			pinMode(eachLEDs, OUTPUT);
			break;

		case OPTIONS::BLINK:
			digitalWrite(eachLEDs, shouldAlter ? HIGH : LOW);
			break;

		default:
			break;
		}
	}
	if (opt == OPTIONS::BLINK) delay(delayValue), shouldAlter = !shouldAlter;
}