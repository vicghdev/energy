/*
 * ModbusLibStub.cpp
 *  Created on: 18. märts 2017
 */

#include "ModbusLibStub.h"

modbus_t* modbus_new_rtu(const char *device, int baud, char parity, int data_bit, int stop_bit)
{
	return 0;
}

void modbus_rtu_set_serial_mode(modbus_t*, int mode)
{
}

void modbus_set_slave(modbus_t *ctx, int slave)
{
}

int modbus_connect(modbus_t* pmt)
{
	return 0; // simulates success
}

void modbus_read_registers(modbus_t* pmt, int address, int num, uint16_t out_buf[])
{
	static uint16_t kwh_low = 34460;		// simulate starting reading from about 100.000 Kw
	//static uint16_t kwh_high = 0;

	if (num > 1)
	{
		out_buf[0] = kwh_low++;
		out_buf[1] = 1;
	}

}

void modbus_close(modbus_t* pmb)
{
}

void modbus_free(modbus_t* pmb)
{

}

// builds an int32 from the two first int16 starting at tab_int16[index]
uint32_t MODBUS_GET_INT32_FROM_INT16(uint16_t tab_reg[], int idx)
{
	  uint32_t kwh_low = tab_reg[idx];
	  uint32_t kwh_high = tab_reg[idx+1];
	  return (kwh_high << 16) + kwh_low;
}

