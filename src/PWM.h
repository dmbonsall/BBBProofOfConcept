/*
 * PWM.h
 *
 *  Created on: Aug 16, 2016
 *      Author: davidbonsall
 */

#pragma once

#include <stdio.h>
#include <string>

class PWM
{
private:
	std::string devicePath;
public:
	PWM(std::string devicePath, int period, int duty, bool polarity = false);
	PWM(std::string devicePath, int period, float duty, bool polarity = false);
	void setPeriod(int period);
	void setDuty(int duty);
	void setDuty(float duty);
	void setPolarity(bool polarity);
	int getPeriod();
	int getDuty();
	float getDutyPercentage();
	bool getPolarity();
	void enable();
	void disable();
};
