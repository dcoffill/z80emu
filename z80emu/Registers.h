#include "stdafx.h"
#pragma once
#ifndef REGISTER_H
#define REGISTER_H

#include <memory>
class Registers {
	friend class Cpu;
public:
	void zero();
private:
	// main register set
	uint8_t _a_a;
	uint8_t _b_a;
	uint8_t _c_a;
	uint8_t _d_a;
	uint8_t _e_a;
	uint8_t _f_a; // flag register
	uint8_t _h_a;
	uint8_t _l_a;
	// alternate register set
	uint8_t _a_b;
	uint8_t _b_b;
	uint8_t _c_b;
	uint8_t _d_b;
	uint8_t _e_b;
	uint8_t _f_b; // alt flag register
	uint8_t _h_b;
	uint8_t _l_b;

	// 16 bit address/index registers
	uint16_t _ix;
	uint16_t _iy;

	// stack pointer
	uint16_t _sp;

	// program counter
	uint16_t _pc;

	// interrupt vector
	uint8_t _i;

	// refresh counter
	uint8_t _r;


	// flags from fl
	// interrupt flags
	bool _iff1;
	bool _iff2;

	// carry flag


};

#endif