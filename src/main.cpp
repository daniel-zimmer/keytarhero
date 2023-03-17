#include <Arduino.h>
#include <Keyboard.h>

uint8_t keys[] = {
	0, 0,
	'l', 'k', 'j', 's', 'a', // buttons
	KEY_UP_ARROW, KEY_DOWN_ARROW, //strum
	0, 0, 0, 0, 0,
	KEY_RETURN, 'H', // select, start
	'/', // whammy
};

uint8_t is_pressed[sizeof(keys)] = {0};

void setup() {
	Keyboard.begin();
	Keyboard.releaseAll();

	for (uint8_t i = 0; i < sizeof(keys); i++) {
		if (keys[i]) { pinMode(i, INPUT_PULLUP); }
	}

}

void loop() {
	for (uint8_t i = 0; i < sizeof(keys); i++) {
		if (!keys[i]) continue;

		if(!digitalRead(i)) {
			if (!is_pressed[i]) {
				is_pressed[i] = 1;
				Keyboard.press(keys[i]);
			}
		} else {
			if (is_pressed[i]) {
				is_pressed[i] = 0;
				Keyboard.release(keys[i]);
			}
		}
	}
}
