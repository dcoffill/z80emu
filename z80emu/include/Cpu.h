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
	void add_hl(const reg::DataReg16 reg);
	void inc_r(const reg::DataReg reg);
	void inc_ss(const reg::DataReg16 reg);
	uint8_t inc(const uint8_t value);
	void dec_r(const reg::DataReg reg);
	void dec_ss(const reg::DataReg16 reg);
	uint8_t dec(const uint8_t value);
	void ld(const reg::DataReg16 reg);
	void ld_n(const reg::DataReg reg);
	void ld(const reg::DataReg16 dest, const reg::DataReg src);
	void ld_acc_address(const reg::DataReg16 addressReg);
	void ld_nn_hl();
	void ld_hl_nn();
	void rlca();
	void rrca();
	void rra();
	void rla();
	void djnz();
	void jr();
	void jr(const bool jump_condition);
	void daa();
	void cpl();
	void nop();

	void BITS_group();
	void IX_group();
	void IY_group();
	void EXTD_group();
};
