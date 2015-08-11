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

void Registers::zero()
{
	// initializes all registers to zero
}

// Implements LD r, n instruction
void Registers::ld(reg::DataReg dest, uint8_t value)
{
	(*_main)[dest] = value;
}

void Registers::ld(reg::DataReg16 dest, uint16_t value)
{
	(*_main)[dest] = value;
}

void Registers::INC(reg::DataReg16 dest)
{
	++(*_main)[dest];
}

void Registers::INC(reg::DataReg dest)
{
	++(*_main)[dest];
}

void Registers::ex_af_af()
{
	uint16_t temp = (*_main)[reg::AF];
	(*_main)[reg::AF] = (*_alt)[reg::AF];
	(*_alt)[reg::AF] = temp;
}

void Registers::ex(const reg::DataReg16 reg)
{
	uint16_t temp = (*_main)[reg];
	(*_main)[reg] = (*_alt)[reg];
	(*_alt)[reg] = temp;
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

uint8_t Registers::operator[](const flag::StatusFlag statusFlag)
{
	uint8_t regF = (*this)[reg::F]; // copy contents of Flags register
	return (regF >> statusFlag) & 0x01; // shift bit in question to become new LSB, then mask to get its value
}

// set a flag to a given value (true or false)
void Registers::setFlag(const flag::StatusFlag statusFlag, bool value)
{
	(*this)[reg::F] &= ~(0x01 << statusFlag); // force that value to 0
	(*this)[reg::F] |= (static_cast<uint8_t>(value) << statusFlag); // set flag with appropriate value
}
