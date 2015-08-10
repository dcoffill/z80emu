#include "stdafx.h"
#pragma once
#ifndef CPU_H
#define CPU_H

#include "Registers.h"
#include "Ram.h"
#include <memory>
class Cpu {
public:
	void execute();
private:
	Registers _registers;
	Ram _memory;

	void add_a_r(const reg::DataReg reg);
	void inc_r(const reg::DataReg reg);
	void inc_ss(const reg::DataReg16 reg);
	uint8_t inc(const uint8_t value);
	void dec_r(const reg::DataReg reg);
	uint8_t dec(const uint8_t value);
	void ld(const reg::DataReg16 reg);
	void ld(const reg::DataReg16 dest, const reg::DataReg src);
	void nop();


	// Not opcodes
	// Opcode groupings
	inline void BITS_group();
	inline void IX_group();
	inline void IY_group();
	inline void EXTD_group();
};
#endif