/*
 * ADC.h
 *
 *  Created on: Aug 17, 2016
 *      Author: davidbonsall
 */

#pragma once;
#include <string>

class ADC
{
private:
	std::string devicePath;
public:
	ADC(std::string devicePath);
	int getReading();
};
