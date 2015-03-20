#include "stdafx.h"
#pragma once
#ifndef REGISTER_H
#define REGISTER_H

#include <memory>
#include "DataRegisters.h"
class Registers {
public:
	Registers();
	void zero();



	DataRegisters& Main();
	void EXX();
	uint16_t IX();
	void SetIX(uint16_t);

	uint16_t IY();
	void SetIY(uint16_t);

	uint16_t SP();
	void SetSP(uint16_t);

	uint16_t PC();
	void SetPC(uint16_t);

	uint8_t I();
	void SetI(uint8_t);

	uint8_t R();
	void SetR(uint8_t);
	void IncR(); // increment Refresh (R) register

	uint8_t operator[](ByteReg regVal) const
	{
		return _main->_reg[regVal];
	}

	uint16_t& operator[](const WordReg regVal);
	uint8_t& operator[](const ByteReg regVal);



private:

	DataRegisters *_main;
	DataRegisters *_alt;

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


	// interrupt flip flops
	bool _iff1;
	bool _iff2;

};

enum ByteReg : int
{
	A = 0,
	B = 1,
	C = 2,
	D = 3,
	E = 4,
	F = 5,
	H = 6,
	L = 7,
	R,
	I
};

enum WordReg
{
	AB,
	CD,
	HL,
	IX,
	IY,
	SP,
	PC
};

#endif