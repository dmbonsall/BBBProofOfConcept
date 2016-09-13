/*
 * ADC.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: davidbonsall
 */


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "ADC.h"

using namespace std;

ADC::ADC(string devicePath) : devicePath(devicePath)
{

}

int ADC::getReading()
{
	ifstream is(devicePath.c_str());

	int reading = -1;
	is >> reading;
	is.close();

	return reading;
}

