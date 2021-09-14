/*
VoteCounter.ino
LED Simulation | Voter Machine Simulation
Created by Janrey "CodexLink" Licas on 09/15/2021, 12:14am

https://github.com/CodexLink/StashedCodes | See the LICENSE for more information.
*/

const unsigned char GREEN_VOTE_BTN = 2, RED_VOTE_BTN = 3, GREEN_LED = 4, RED_LED = 5, VOTERS = 4;
const char* intro = "The first person to get the highest votes wins!", * end = "The voting has been ended. Press RESTART in Arduino if you want to simulate again.";
bool isInit = false;
unsigned char p1_votes, p2_votes;
unsigned char voters_left = VOTERS;

const unsigned char showVotersLeft() noexcept(true);
void showWinners() noexcept(true);

void setup()
{
	Serial.begin(9600);
	for (unsigned char eachPins = GREEN_VOTE_BTN; eachPins <= RED_LED; eachPins++) {
		pinMode(eachPins, eachPins <= (GREEN_VOTE_BTN / 2) ? INPUT : OUTPUT);
	}
}

void loop()
{
	if (!isInit)
		Serial.println(intro), isInit = !isInit;

	while (voters_left) {
		if (digitalRead(RED_VOTE_BTN)) {
			Serial.print("Vote added to Person 1!");
			voters_left--, p1_votes++; // Don't care for redundancy this time.
			showVotersLeft();
			delay(300); // Debounce without complexity.
		}
		else if (digitalRead(GREEN_VOTE_BTN)) {
			Serial.print("Vote added to Person 2!");
			voters_left--, p2_votes++;
			showVotersLeft();
			delay(300); // Debounce without complexity.
		}
		else {
			; // No condition to handle but put it here for reference.
		}
	}
	showWinners();
}

const unsigned char showVotersLeft() noexcept(true) {
	Serial.print(" | There ");
	Serial.print(voters_left <= 1 ? "is" : "are");
	Serial.print(" ");
	Serial.print(voters_left);
	Serial.println(" voter/s left!");
}

void showWinners() noexcept(true) {
	Serial.println(); // Invoke \n without invoking \n.
	if (p1_votes == p2_votes) {
		Serial.print("There is no winner! It's a draw!!! | Person 1: ");
		Serial.print(p1_votes);
		Serial.print(" votes | Person 2: ");
		Serial.print(p2_votes);
		Serial.println(" votes");
		digitalWrite(GREEN_LED, HIGH), digitalWrite(RED_LED, HIGH);
	}
	else {
		Serial.print("The winner is ");
		Serial.print("Person ");
		Serial.print(p1_votes > p2_votes ? "1" : "2");
		Serial.print(" who accumulates ");
		Serial.print(p1_votes > p2_votes ? p1_votes : p2_votes);
		Serial.print(" votes! While, Person ");
		Serial.print(p1_votes < p2_votes ? "1" : "2");
		Serial.print(" gets at least ");
		Serial.print(p1_votes < p2_votes ? p1_votes : p2_votes);
		Serial.println(" votes!");

		digitalWrite(p1_votes > p2_votes ? RED_LED : GREEN_LED, HIGH);
	}

	Serial.println();
	Serial.println(end);
	while (true) { yield(); };
}
