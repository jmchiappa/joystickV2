#include <JoystickV2.h>

JoystickV2 joy(A0,A1,JoystickV2::INVERTED,JoystickV2::INVERTED,255);

#define PRINT(A,B)	{Serial.print(A);Serial.print(B);};
#define PRINTLN(A,B)	{Serial.print(A);Serial.print("\t");Serial.println(B);};

void setup() {
	joy.begin();

	Serial.begin(115200);
}

void loop() {
	PRINTLN(joy.getXaxis(),joy.getYaxis());
	delay(10);
}
