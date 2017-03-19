/*
 * ModbusReader.cpp
 *  Created on: 18. märts 2017
 */

#include "ModbusReader.h"
#define MODBUS_RTU_RS485 1

ModbusReader::ModbusReader(const char* port_name, int deviceId, int baud)
{
	  pmb = modbus_new_rtu(port_name, 9600, 0, 8, 1);
	  modbus_rtu_set_serial_mode(pmb, MODBUS_RTU_RS485);
	  modbus_set_slave(pmb, deviceId);

	  if (modbus_connect(pmb) == -1)
	  {
	      modbus_free(pmb);			// Error occurred, here an exception could be thrown
	  }
}

ModbusReader::~ModbusReader()
{
	  modbus_close(pmb);
	  modbus_free(pmb);
}


unsigned int ModbusReader::ReadRegister(unsigned int adr)
{
	  uint16_t tab_reg[2];
	  /* Read 2 registers from the address */
	  modbus_read_registers(pmb, adr, 2, tab_reg);
	  return MODBUS_GET_INT32_FROM_INT16(tab_reg, 0);
}
