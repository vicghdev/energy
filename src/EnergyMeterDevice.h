/*
 * EnergyMeterDevice.h
 *  Created on: 19. märts 2017
 */

#ifndef ENERGYMETERDEVICE_H
#define ENERGYMETERDEVICE_H

#include "ModbusReader.h"

class EnergyMeterDevice
{
public:
	EnergyMeterDevice(const char* port_name, int deviceId, int baud);
	virtual ~EnergyMeterDevice();
	//
	unsigned int ReadKwh();

private:
	ModbusReader modbusRd;
};

#endif
