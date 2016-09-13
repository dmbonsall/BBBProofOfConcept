/*
 * GPIO.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: davidbonsall
 */

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <fstream>
#include "GPIO.h"

using namespace std;

GPIO::GPIO(int pinNum, int direction) : pinNum(pinNum)
{
	setDirection(direction);

	ostringstream os;
	os << pinNum;
	s_pinNum = os.str();
	path = "/sys/class/gpio/gpio";

	cout << s_pinNum << " configured for " << getDirection() << endl;
}

void GPIO::setDirection(int direction)
{
	ofstream os((path + s_pinNum + "/direction").c_str());

	if (direction)
		os << "out" << flush;
	else
		os << "in" << flush;

	os.close();
}
void GPIO::setValue(int value)
{
	ofstream os((path + s_pinNum + "/value").c_str());

	os << value << flush;

	os.close();
}

string GPIO::getDirection()
{
	ifstream is((path + s_pinNum + "/direction").c_str());

	string direction;
	is >> direction;
	is.close();

	return direction;
}

int GPIO::getValue()
{
	ifstream is((path + s_pinNum + "/value").c_str());

	int val;
	is >> val;
	is.close();

	return val;
}

