#include "stdafx.h"
#include "Registers.h"

Registers::Registers()
{
	_main = new DataRegisters();
	_alt = new DataRegisters();
}

Registers::~Registers()
{
	delete _main;
	delete _alt;
}

void Registers::zero() {
	// intiializes all registers to zero
	 
}

// This method implements the LD r, r' instruction
void Registers::LD_R_RP(reg::DataReg dest, reg::DataReg src)
{
	(*_main)[dest] = (*_main)[src];
	(*this)[reg::PC] += 1;
}

// Implements LD r, n instruction
void Registers::LD_R_N(reg::DataReg dest, uint8_t value)
{
	(*_main)[dest] = value;
	(*this)[reg::PC] += 2;
}


uint16_t& Registers::operator[](const reg::DataReg16 regVal)
{
	return (*_main)[regVal];
}
uint8_t& Registers::operator[](const reg::DataReg regVal)
{
	return (*_main)[regVal];
}
uint8_t& Registers::operator[](const reg::Special8 regVal)
{
	return other[regVal];
}
uint16_t& Registers::operator[](const reg::Special16 regVal)
{
	return shared16[regVal];
}