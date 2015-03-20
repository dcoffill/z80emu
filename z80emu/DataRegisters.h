#include "stdafx.h"
#pragma once
#ifndef DATAREGISTERS_H
#define DATAREGISTERS_H

#include <memory>

class DataRegisters
{
public:
	uint8_t _reg[8];
	//enum {A, B, C, D, E, F, H, L};
	// Register setters and getters
	inline uint8_t A();
	inline void Set_A(uint8_t value);

	inline uint8_t B();
	inline void Set_B(uint8_t value);

	inline uint8_t C();
	inline void Set_C(uint8_t value);

	inline uint8_t D();
	inline void set_D(uint8_t value);

	inline uint8_t E();
	inline void Set_E(uint8_t value);

	inline uint8_t F();
	inline void Set_F(uint8_t value);

	inline uint8_t H();
	inline void SetH(uint8_t value);

	inline uint8_t L();
	inline void SetL(uint8_t value);

	inline uint8_t AB();
	inline void SetAB(uint8_t value);

	inline uint8_t CD();
	inline void SetCD(uint8_t value);

	inline uint8_t HL();
	inline void SetHL(uint8_t value);

private:
	uint8_t _a;
	uint8_t _b;
	uint8_t _c;
	uint8_t _d;
	uint8_t _e;
	uint8_t _f; // flag register, not sure if I should replace this with a ton of bools or a bit field
	uint8_t _h;
	uint8_t _l;

	uint8_t _reg[8];
};
#endif 