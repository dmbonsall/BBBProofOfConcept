//============================================================================
// Name        : BBBProofOfConcept.cpp
// Author      : David Bonsall
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include "GPIO.h"
#include "PWM.h"
#include "Servo.h"
#include "ADC.h"
using namespace std;

int main() {
	cout << "Beginning of the proof of concept program" << endl;

	GPIO led(60, 1);
	GPIO button(115, 0);
	Servo servo("/sys/devices/ocp.3/pwm_test_P9_22.15");
	ADC aIn("/sys/bus/iio/devices/iio:device0/in_voltage0_raw");
	servo.enable();
	bool increasing = true;

	for (int i = 0; i < 10000; i++)	//main program loop to run for 10 seconds
	{
		led.setValue(button.getValue());

		int aRead = aIn.getReading();
		float aRatio = static_cast<float>(aRead) / 4096.0;
		servo.setAngle((180.0 * aRatio) - 90.0);

		//make the servo sweep (with a usleep paramater of 10000)
//		if (increasing)
//		{
//			float angle = servo.getAngle();
//			if (++angle > 90.0)
//			{
//				angle--;
//				increasing = false;
//			}
//			servo.setAngle(angle);
//		}
//		else
//		{
//			float angle = servo.getAngle();
//			if (--angle < -90.0)
//			{
//				angle++;
//				increasing = true;
//			}
//			servo.setAngle(angle);
//		}

		//sleep of a little while


		usleep(10);
	}
	servo.disable();
	cout << "End of the proof of concept program" << endl;

	return 0;
}
