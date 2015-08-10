#include "stdafx.h"
#pragma once
#ifndef REGISTER_H
#define REGISTER_H

#include <memory>
#include "DataRegisters.h"
#include "RegisterEnums.h"
#include "Flags.h"

class Registers {
public:
	Registers();
	virtual ~Registers();

	void zero(); // zero all registers, not sure if this is necessary anymore

	void LD(reg::DataReg, reg::DataReg);
	void LD(reg::DataReg, uint8_t);
	void LD(reg::DataReg16, uint16_t);
	void INC(reg::DataReg16 dest);
	void INC(reg::DataReg dest);
	void EXX(); // Perform the EXX instruction (swap BC, DE, and HL with their shadow counterparts)

	// Setters/getters for accessing special and general purpose registers
	uint16_t& operator[](const reg::DataReg16 regVal);
	uint8_t& operator[](const reg::DataReg regVal);
	uint8_t& operator[](const reg::Special8 regVal);
	uint16_t& operator[](const reg::Special16 regVal);
	uint8_t operator[](const flag::StatusFlag statusFlag); // read bit from status flags
	void setFlag(const flag::StatusFlag, bool value);

private:

	// DataRegisters for main/alternate general purpose registers
	DataRegisters *_main;
	DataRegisters *_alt;
	
	// Special purpose registers
	uint16_t shared16[4]; // IX, IY, SP, and PC registers
	uint8_t other[2]; // I and R registers


	// TODO: figure out how to treat flags and the interrupt flip flops
	// interrupt flip flops
	bool _iff1;
	bool _iff2;

};

#endif