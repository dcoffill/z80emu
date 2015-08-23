#pragma once

// These are the enums that map registers to array indices used in register access
// They are divided in to DataReg and DataReg 16 for general purpose registers,
// and Special8 and Special16 for the special purpose registers
// These allow the compiler to choose the correct way to access a given register

namespace reg {
	class Reg8 {
	public:
		Reg8(int pos) : position(pos) {};
		const int position;
	};

	class Reg16 {
	public:
		Reg16(int pos) : position(pos) {};
		const int position;
	};

	// 8-bit general purpose registers
	class DataReg : public Reg8 {
	public:
		DataReg(int pos) : Reg8(pos) {};
	};

	// 16-bit general purpose registers
	class DataReg16 : public Reg16 {
	public:
		DataReg16(int pos) : Reg16(pos) {};
	};

	// 8-bit special purpose registers
	class Special8 : public Reg8 {
	public:
		Special8(int pos) : Reg8(pos) {};
	};

	// 16-bit special purpose registers
	class Special16 : public Reg16 {
	public:
		Special16(int pos) : Reg16(pos) {};
	};

	// These magic numbers are the (somewhat) arbitrary positions in the register arrays
	// Note that the position assignment is endian dependent for ease of accessing the 8-bit
	// registers in combined 16-bit mode, without any extra runtime/storage overhead.
	// The position assignments below will need to be changed for big-endian machines.
	const DataReg F(0);
	const DataReg A(1);
	const DataReg C(2);
	const DataReg B(3);
	const DataReg E(4);
	const DataReg D(5);
	const DataReg L(6);
	const DataReg H(7);

	const DataReg16 AF(0);
	const DataReg16 BC(1);
	const DataReg16 DE(2);
	const DataReg16 HL(3);

	const Special8 I(0);
	const Special8 R(1);

	const Special16 IX(0);
	const Special16 IY(1);
	const Special16 PC(2);
	const Special16 SP(3);
}