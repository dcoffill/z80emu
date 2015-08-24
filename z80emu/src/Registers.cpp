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

/**
 * @brief Access or write general purpose registers in 16-bit mode
 * @param regVal Register pair to access
 *
 * Access register pairs AF, BC, DE, and HL in 16-bit mode.
 */
uint16_t& Registers::operator[](const reg::DataReg16 regVal)
{
	return (*_main)[regVal];
}

/**
 * @brief Access or write general purpose registers
 * @param regVal Register to access
 *
 * Access general purpose registers B, C, D, E, F, H, and L.
 */
uint8_t& Registers::operator[](const reg::DataReg regVal)
{
	return (*_main)[regVal];
}

/**
 * @brief Access or write special purpose 8-bit registers
 * @param regVal Register to access
 *
 * Access the 8-bit special purpose registers I and R.
 */
uint8_t& Registers::operator[](const reg::Special8 regVal)
{
	return other[regVal.position];
}

/**
 * @brief Access or write special purpose 16-bit registers
 * @param regVal Register to access
 *
 * Access the 16-bit special purpose registers: IX, IY, PC, and SP.
 */
uint16_t& Registers::operator[](const reg::Special16 regVal)
{
	return shared16[regVal.position];
}

/**
 * @brief Access status flag
 * @param statusFlag Flag to access
 *
 * Access the status flags S, Z, H, P, N, and C.  This method performs bitwise arithmetic on the
 * current "A" register and is guaranteed to contain the same flag values.
 */

uint8_t Registers::operator[](const flag::StatusFlag statusFlag)
{
	uint8_t regF = (*this)[reg::F]; // copy contents of Flags register
	return (regF >> statusFlag) & 0x01; // shift bit in question to become new LSB, then mask to get its value
}

/**
 * @brief Assign a status flag
 * @param statusFlag Flag to set
 * @param value Status to set
 *
 * Assign a status to the specified status flag
 */
void Registers::setFlag(const flag::StatusFlag statusFlag, bool value)
{
	(*this)[reg::F] &= ~(0x01 << statusFlag); // force that value to 0
	(*this)[reg::F] |= (static_cast<uint8_t>(value) << statusFlag); // set flag with appropriate value
}
