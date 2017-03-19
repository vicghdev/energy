/*
 * ModbusLibStub.h
 *  Created on: 18. märts 2017
 */

#ifndef MODBUSLIBSTUB_H
#define MODBUSLIBSTUB_H

typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

struct modbus_t
{
	int stub_val;
};

modbus_t* modbus_new_rtu(const char *device, int baud, char parity, int data_bit, int stop_bit);
void modbus_rtu_set_serial_mode(modbus_t*, int mode);
void modbus_set_slave(modbus_t *ctx, int slave);
int modbus_connect(modbus_t*);
void modbus_read_registers(modbus_t*, int address, int num, uint16_t out_buf[]);
void modbus_close(modbus_t* pmb);
void modbus_free(modbus_t* pmb);
uint32_t MODBUS_GET_INT32_FROM_INT16(uint16_t tab_reg[], int idx);

#endif
