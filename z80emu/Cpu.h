#pragma once

#include "stdafx.h"
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
	void add_hl(reg::DataReg16 reg);
	void inc_r(const reg::DataReg reg);
	void inc_ss(const reg::DataReg16 reg);
	uint8_t inc(const uint8_t value);
	void dec_r(const reg::DataReg reg);
	uint8_t dec(const uint8_t value);
	void ld(const reg::DataReg16 reg);
	void ld_n(const reg::DataReg reg);
	void ld(const reg::DataReg16 dest, const reg::DataReg src);
	void rlca();
	void rrca();
	void rla();
	void djnz();
	void nop();

	void BITS_group();
	void IX_group();
	void IY_group();
	void EXTD_group();
};
