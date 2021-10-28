// Buffer Register Programming | A Programmed Version for the Buffer Register
// Activity on Registers | Microprocessor Systems 
// Copyright 2021 | Janrey Licas (https://github.com/CodexLink)
// Layout will further change later.

int latchPin = 6;

// These constraints are symmetrical anyway.
int LED_SW_RANGE_MIN = 10, LED_SW_RANGE_MAX = 13,
		LED_RANGE_MIN = 2, LED_RANGE_MAX = 5;

void setup() {
	for (unsigned LED_SW = LED_SW_RANGE_MIN; LED_SW <= LED_SW_RANGE_MAX; LED_SW++) {
		pinMode(LED_SW, INPUT);
	}

	for (unsigned LED_LITERAL = LED_RANGE_MIN; LED_LITERAL <= LED_RANGE_MAX; LED_LITERAL++) {
		pinMode(LED_LITERAL, OUTPUT);
	}

	// Singleton Pin Initialization.
	pinMode(latchPin, INPUT);
}

// Keep note that we need to invoke '!' because of inverted HIGH in circuit!

void loop() {
	if (!digitalRead(latchPin)) {
			applyToLEDs();
	}
}

void applyToLEDs() {
	int SW_COUNTER = 0;

	for (int eachLeds = LED_RANGE_MIN; eachLeds <= LED_RANGE_MAX; eachLeds++) {
		digitalWrite(eachLeds, !digitalRead(LED_SW_RANGE_MIN + SW_COUNTER) ? HIGH : LOW);

		SW_COUNTER++;
	}
}

