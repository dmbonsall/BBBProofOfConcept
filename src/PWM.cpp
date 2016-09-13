/*
 * PWM.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: davidbonsall
 */

#include "PWM.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

PWM::PWM(string devicePath, int period, int duty, bool polarity) :
		devicePath(devicePath)
{
	disable();	//for safety reasons
	//set the period and the duty
	setPeriod(period);
	setDuty(duty);
	setPolarity(polarity);

	cout << "PWM configured at " << devicePath << endl;
}

PWM::PWM(string devicePath, int period, float duty, bool polarity) :
		devicePath(devicePath)
{
	disable();	//for safety reasons

	//set the period and the duty
	setPeriod(period);
	setDuty(duty);
	setPolarity(polarity);
}

void PWM::setPeriod(int period)
{
	ofstream os((devicePath + "/period").c_str());

	os << period << flush;

	os.close();
}

void PWM::setDuty(int duty)
{
	int period = getPeriod();
	if (duty < 0 || duty > period)
	{
		cerr << "Duty must be greater than 0 and less than the period" << endl;
		cerr << period << " " << duty << endl;
		return;
	}
	ofstream os((devicePath + "/duty").c_str());

	os << duty << flush;

	os.close();
}

void PWM::setDuty(float duty)
{
	if (duty < 0 || duty > 1)
	{
		cerr << "Duty must be between 0 and 1 to represent 0% to 100%" << endl;
		return;
	}

	int period = getPeriod();
	int iDuty = duty * period;
	setDuty(iDuty);
}

void PWM::setPolarity(bool polarity)
{
	ofstream os((devicePath + "/polarity").c_str());

	os << (int)polarity << flush;

	os.close();
}

int PWM::getDuty()
{
	ifstream is((devicePath + "/duty").c_str());

	int duty;
	is >> duty;
	is.close();

	return duty;
}

int PWM::getPeriod()
{
	ifstream is((devicePath + "/period").c_str());

	int period;
	is >> period;
	is.close();

	return period;
}

float PWM::getDutyPercentage()
{
	int period = getPeriod();
	int duty = getDuty();

	return static_cast<float>(duty) / static_cast<float>(period);
}

bool PWM::getPolarity()
{
	ifstream is((devicePath + "/period").c_str());

	int polarity;
	is >> polarity;
	is.close();

	return polarity;
}

void PWM::enable()
{
	ofstream os((devicePath + "/run").c_str());

	os << 1 << flush;

	os.close();
}

void PWM::disable()
{
	ofstream os((devicePath + "/run").c_str());

	os << 0 << flush;

	os.close();
}
