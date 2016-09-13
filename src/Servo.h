/*
 * Servo.h
 *
 *  Created on: Aug 16, 2016
 *      Author: davidbonsall
 */

#pragma once
#include <stdio.h>
#include <string>
#include "PWM.h"


class Servo : private PWM
{
private:
	const int lowerDuty = 500000;
	const int upperDuty = 2500000;
public:
	Servo(std::string devicePath);
	void setAngle(float degree);
	float getAngle();
	void enable();
	void disable();
};
