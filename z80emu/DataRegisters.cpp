#include "stdafx.h"
#include "Registers.h"
#include "DataRegisters.h"
#include <assert.h>

enum DataReg16;
enum DataReg;


DataRegisters::DataRegisters()
{
	_reg16 = reinterpret_cast<uint16_t *>(&_reg);
}

DataRegisters::~DataRegisters()
{
	// doesn't do anything, but this at least allows someone to theoretically extend this class in the future
}

uint16_t& DataRegisters::operator[](const reg::DataReg16 regVal)
{
	assert(regVal >= 0 && regVal <= 3); // ensure that the 16-bit register that was specified is in the proper range
	return _reg16[regVal];
}

uint8_t& DataRegisters::operator[](const reg::DataReg regVal)
{
	assert(regVal <= 7 && regVal >= 0); // ensure that the 8-bit register that was specified is in the proper range
	return _reg[regVal];
}
