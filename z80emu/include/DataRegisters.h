#pragma once

#include "stdafx.h"
#include <memory>
#include "RegisterEnums.h"

class DataRegisters {
public:
	DataRegisters();
	virtual ~DataRegisters();
	uint16_t& operator[](const reg::DataReg16 regVal);
	uint8_t& operator[](const reg::DataReg regVal);

private:
	uint8_t _reg[8];
	uint16_t *_reg16; // Pointer to _reg that lets us interpret two adjacent 8-bit registers as one 16-bit register

};
