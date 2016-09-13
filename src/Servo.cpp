/*
 * Servo.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: davidbonsall
 */



#include <stdio.h>
#include <iostream>
#include <string>
#include "PWM.h"
#include "Servo.h"

using namespace std;

Servo::Servo(string devicePath) : PWM(devicePath, 25000000, 1500000, false)
{}

void Servo::setAngle(float degree)
{
	if (!(degree < 90.0 && degree > -90.0))
	{
		cerr << "Degree must be between -90.0 and 90.0" << endl;
		return;
	}

	degree += 90.0;	//make it positive

	//find out what "percentage" through the sweep range we are
	float degreeRatio = degree / 180.0;

	//calculate the appropriate duty and then set it
	int duty = static_cast<int>(lowerDuty +
			static_cast<float>(upperDuty - lowerDuty) * degreeRatio);
	PWM::setDuty(duty);
}

float Servo::getAngle()
{
	int duty = PWM::getDuty();
	duty -= lowerDuty;	//offset the min to zero

	//find out what "percentage" through the sweep range we are
	float dutyRatio = static_cast<float>(duty) / static_cast<float>(upperDuty - lowerDuty);

	return (180.0 * dutyRatio) - 90.0;	//apply the ratio
}

void Servo::enable()
{
	PWM::enable();
}

void Servo::disable()
{
	PWM::disable();
}
