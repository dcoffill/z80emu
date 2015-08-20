#include "stdafx.h"
#include <assert.h>
#include "Registers.h"
#include "DataRegisters.h"
#include "RegisterEnums.h"

DataRegisters::DataRegisters()
{
	_reg16 = reinterpret_cast<uint16_t *>(&_reg);
}

DataRegisters::~DataRegisters()
{
}

uint16_t& DataRegisters::operator[](const reg::DataReg16 regVal)
{
	assert(regVal.position >= 0 && regVal.position <= 3); // ensure that the 16-bit register that was specified is in the proper range
	return _reg16[regVal.position];
}

uint8_t& DataRegisters::operator[](const reg::DataReg regVal)
{
	assert(regVal.position <= 7 && regVal.position >= 0); // ensure that the 8-bit register that was specified is in the proper range
	return _reg[regVal.position];
}
