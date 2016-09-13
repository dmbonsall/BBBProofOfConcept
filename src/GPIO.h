/*
 * GPIO.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: davidbonsall
 */

#pragma once
#include <string>

class GPIO
{
private:
	std::string path;
	int pinNum;
	std::string s_pinNum;

public:
	GPIO(int pinNum, int direction);
	void setDirection(int direction);
	void setValue(int value);
	int getValue();
	std::string getDirection();
};
