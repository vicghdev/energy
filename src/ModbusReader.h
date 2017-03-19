/*
 * ModbusReader.h
 *  Created on: 18. märts 2017
 */

#ifndef MODBUSREADER_H
#define MODBUSREADER_H

#include "ModbusLibStub.h"

class ModbusReader
{
public:
	ModbusReader(const char* port_name, int deviceId, int baud);
	virtual ~ModbusReader();
	//
	unsigned int ReadRegister(unsigned int adr);

private:
	modbus_t* pmb;
};

#endif
