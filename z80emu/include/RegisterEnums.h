#pragma once

// These are the enums that map registers to array indices used in register access
// They are divided in to DataReg and DataReg 16 for general purpose registers,
// and Special8 and Special16 for the special purpose registers
// These allow the compiler to choose the correct way to access a given register

namespace reg {
	// The arrangement of the items in this enum are endian-dependent, so perhaps
	// put in some sort of #ifdef here to substitute little/big endian arrangement

	// 8-bit general purpose registers
	enum DataReg : int {
		F = 0,
		A = 1,
		C = 2,
		B = 3,
		E = 4,
		D = 5,
		L = 6,
		H = 7
	};

	// 16-bit general purpose registers
	enum DataReg16 : int {
		AF = 0,
		BC = 1,
		DE = 2,
		HL = 3,
	};

	// 8-bit special-purpose registers
	enum Special8 : int {
		R,
		I
	};

	// 16-bit general purpose registers
	enum Special16 : int {
		IX,
		IY,
		SP,
		PC
	};
}
