/*
 * EnergyMeterDevice.cpp
 *  Created on: 19. märts 2017
 */

#include "EnergyMeterDevice.h"

EnergyMeterDevice::EnergyMeterDevice(const char* port_name, int deviceId, int baud)
: modbusRd(port_name, deviceId, baud)
{
}

EnergyMeterDevice::~EnergyMeterDevice()
{
}

unsigned int EnergyMeterDevice::ReadKwh()
{
	return modbusRd.ReadRegister(1);
}

