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