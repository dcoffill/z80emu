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

// This method implements the LD instruction
void Registers::LD(reg::DataReg dest, reg::DataReg src)
{
	(*_main)[dest] = (*_main)[src];
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