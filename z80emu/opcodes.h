#include "stdafx.h"



namespace opcodes {
	struct instruction
	{
		const int opcode;
		const int op_size; // how many bytes instruction is, so we know how far to advance PC
	};

	// LD r, r' instruction opcodes
	const instruction LD_A_A { 0x7F, 1 };
	const instruction LD_A_B { 0x78, 1 };
	const instruction LD_A_C { 0x79, 1 };
	const instruction LD_A_D { 0x7A, 1 };
	const instruction LD_A_E { 0x7B, 1 };
	const instruction LD_A_H { 0x7C, 1 };
	const instruction LD_A_L { 0x7D, 1 };

	const instruction LD_B_A { 0x4F, 1 };
	const instruction LD_B_B { 0x48, 1 };
	const instruction LD_B_C { 0x49, 1 };
	const instruction LD_B_D { 0x4A, 1 };
	const instruction LD_B_E { 0x4B, 1 };
	const instruction LD_B_H { 0x4C, 1 };
	const instruction LD_B_L { 0x4D, 1 };

	const instruction LD_C_A { 0x47, 1 };
	const instruction LD_C_B { 0x40, 1 };
	const instruction LD_C_C { 0x41, 1 };
	const instruction LD_C_D { 0x42, 1 };
	const instruction LD_C_E { 0x43, 1 };
	const instruction LD_C_H { 0x44, 1 };
	const instruction LD_C_L { 0x45, 1 };

	const instruction LD_D_A { 0x57, 1 };
	const instruction LD_D_B { 0x50, 1 };
	const instruction LD_D_C { 0x51, 1 };
	const instruction LD_D_D { 0x52, 1 };
	const instruction LD_D_E { 0x53, 1 };
	const instruction LD_D_H { 0x54, 1 };
	const instruction LD_D_L { 0x55, 1 };

	const instruction LD_E_A { 0x5F, 1 };
	const instruction LD_E_B { 0x58, 1 };
	const instruction LD_E_C { 0x59, 1 };
	const instruction LD_E_D { 0x6A, 1 };
	const instruction LD_E_E { 0x6B, 1 };
	const instruction LD_E_H { 0x6C, 1 };
	const instruction LD_E_L { 0x6D, 1 };

	const instruction LD_H_A { 0x67, 1 };
	const instruction LD_H_B { 0x60, 1 };
	const instruction LD_H_C { 0x61, 1 };
	const instruction LD_H_D { 0x62, 1 };
	const instruction LD_H_E { 0x63, 1 };
	const instruction LD_H_H { 0x64, 1 };
	const instruction LD_H_L { 0x65, 1 };

	const instruction LD_L_A { 0x6F, 1 };
	const instruction LD_L_B { 0x68, 1 };
	const instruction LD_L_C { 0x69, 1 };
	const instruction LD_L_D { 0x6A, 1 };
	const instruction LD_L_E { 0x6B, 1 };
	const instruction LD_L_H { 0x6C, 1 };
	const instruction LD_L_L { 0x6D, 1 };

	// LD r, n instructions
	// (where n is immediate contained in PC + 1)
	const instruction LD_A_N { 0x3E, 2 };
	const instruction LD_B_N { 0x06, 2 };
	const instruction LD_C_N { 0x0E, 2 };
	const instruction LD_D_N { 0x16, 2 };
	const instruction LD_E_N { 0x1E, 2 };
	const instruction LD_H_N { 0x26, 2 };
	const instruction LD_L_N { 0x2E, 2 };

	// LD r, (HL)
	// Load contents of memory at address contained in (HL) to register r
	const instruction LD_A_HL { 0x7E, 2 };
	const instruction LD_B_HL { 0x46, 2 };
	const instruction LD_C_HL { 0x4E, 2 };
	const instruction LD_D_HL { 0x56, 2 };
	const instruction LD_E_HL { 0x5E, 2 };
	const instruction LD_H_HL { 0x66, 2 };
	const instruction LD_L_HL { 0x6E, 2 };

	// LD r, (IX+d)
	// first LD_R_IXD
	// then LD r, (HL)

	// LD r, (IY+d)
	// first LD_R_IYD
	// then LD_R_HL

	// LD r, (IX+d)
	// Load contents of memory stored in address (IX+d)
	// where d is a signed 8 bit integer
	// first LD_R_IXD
	const instruction LD_R_IXD { 0xDD, 3 };

	// LD r, (IY+d)
	// Load contents of memory stored in address (IY+d)
	// where d is a signed 8 bit integer
	// first LD_R_IYD
	const instruction LD_R_IYD { 0xFD, 3 };

	// LD (HL), r
	// Load contents of register r into address contained in (HL)
	const instruction LD_HL_A { 0x77, 1 };
	const instruction LD_HL_B { 0x70, 1 };
	const instruction LD_HL_C { 0x71, 1 };
	const instruction LD_HL_D { 0x72, 1 };
	const instruction LD_HL_E { 0x73, 1 };
	const instruction LD_HL_H { 0x74, 1 };
	const instruction LD_HL_L { 0x75, 1 };

	// LD (IX+d), r
	// Store contents of register r to memory address stored in address(IX + d)
	// where d is a signed 8 bit integer offset
	const instruction LD_IXD_R { 0xDD, 1 }; // DO NOT USE, same as LD_R_IXD

	// LD (IX+d), r
	// Store contents of register r to memory address stored in address(IY + d)
	// where d is a signed 8 bit integer offset
	const instruction LD_IYD_R { 0xFD, 1 }; // DO NOT USE, same as LD_R_IYD

	// LD (HL), n
	// Store an immediate value, n, into the memory address contained in HL
	const instruction LD_HL_N { 0x36, 2 };

	// LD (IX+d), n
	// Store an immediate value, n, into the memory address calculated from IX + d
	// where d is a signed 8-bit offset
	// todo: add in later, since it's just 0xDD and 0x36 again

	// LD (IY+d), n
	// Store an immediate value, n, into the memory address calculated from IY + d
	// where d is a signed 8-bit offset
	// todo: add in later, since it's just 0xFD and 0x36 again

	// LD A, (BC)
	// Load contents of memory, stored at address contained in BC, to register A
	const instruction LD_A_BC { 0x0A, 1 };

	// LD A, (DE)
	// Load contents of memory, stored at address contained in DE, to register A
	const instruction LD_A_BC { 0x1A, 1 };

	// LD A, (nn)
	// Load contents of memory, indicated at the address nn, to register A
	const instruction LD_A_NN { 0x3A, 3 };

	// LD (BC), A
	// Store contents of register A to memory address contained in BC
	const instruction LD_BC_A { 0x02, 1 };

	// LD (DE), A
	// Store contents of register A to memory address contained in DE
	const instruction LD_DE_A { 0x12, 1 };

	// LD (nn), A
	// Store contents of register A to address indicated by nn
	const instruction LD_A_NN { 0x32, 3 };

	// LD A, I
	// Load contents of Interrupt Vector register I into A
	// Also used for LD A, R; LD I, A; LD R, A
	const instruction LD_A_I { 0xED, 2 };


	// 16-bit load instructions

	// LD dd, nn
	// Load 2 byte immediate nn into register dd
	const instruction LD_BC_NN { 0x01, 3 }; // to BC
	const instruction LD_BC_NN { 0x11, 3 }; // to DE
	const instruction LD_BC_NN { 0x21, 3 }; // to HL
	const instruction LD_BC_NN { 0x31, 3 }; // to SP

	// LD IX, nn
	// Load nn into index register IX
	// first opcode is 0xDD
	// then 0x21


	// LD IY, nn
	// Load nn into index register IY
	// 0xFD then 0x21

	// LD HL, (nn)
	const instruction LD_HL_NN { 0x2A, 3 };

	// LD dd, (nn)
	// 0xed, then:
	const instruction LD_HL_NN_2 { 0x6B, 4 };
	const instruction LD_BC_NN { 0x4B, 4 };
	const instruction LD_DE_NN { 0x5B, 4 };
	const instruction LD_SP_NN { 0x7B, 4 };

	// LD IX, (nn)
	// first LD_R_IXD
	// then LD_HL_NN
	// 4 bytes

	// LD IY, (nn)
	// same as previous but with LD_R_IYD

	// LD (nn), HL
	const instruction LD_NN_HL { 0x22, 3 };

	//LD (nn), dd
	// first LD_A_I
	//then
	const instruction LD_NN_BC { 0x43, 4 };
	const instruction LD_NN_DE { 0x53, 4 };
	const instruction LD_NN_HL { 0x63, 4 };
	const instruction LD_NN_SP { 0x73, 4 };

	// LD (nn), IX
	// first LD_IXD_R
	// then LD_NN_HL
	// then 2 bytes

	// LD SP, HL
	const instruction LD_SP_HL { 0xF9, 1 };

	// LD SP, IX
	// first LD_R_IXD
	// then LD_SP_HL

	// LD SP, IY
	// first LD_R_IYD
	// then LD_SP_HL
	
	// PUSH qq
	const instruction PUSH_BC { 0xC5, 1 };
	const instruction PUSH_DE { 0xD5, 1 };
	const instruction PUSH_HL { 0xE5, 1 };
	const instruction PUSH_AF { 0xF5, 1 };

	// PUSH IX
	// first LD_R_IXD
	// then PUSH_HL

	// PUSH IY
	// first LD_R_IYD
	// then PUSH_HL

	// POP qq
	const instruction PUSH_BC { 0xC1, 1 };
	const instruction PUSH_DE { 0xD1, 1 };
	const instruction PUSH_HL { 0xE1, 1 };
	const instruction PUSH_AF { 0xF1, 1 };

	// POP IX
	// first LD_R_IXD
	// THEN POP HL

	// POP IY
	// first LD_R_IYD
	// THEN POP HL

	// Exchange, block transfer, and search instructions

	// EX DE, HL
	const instruction EX_DE_HL { 0xEB, 1 };

	// EX AF, AF'
	const instruction EX_AF_AF { 0x08, 1 };

	// EXX
	const instruction EXX { 0xD9, 1 };

	// EX (SP), HL
	const instruction EX_SP_HL { 0xE3, 1 };
	
	// EX (SP), IX
	// first LD_R_IXD
	// then EX_SP_HL

	// EX (SP), IY
	// first LD_R_IYD
	// then EX_SP_HL

	// LDI
	// first LD_A_I
	const instruction LDI { 0xA0, 2 };

	// LDIR
	// first LD_A_I
	const instruction LDIR { 0xB0, 2 };

	// LDD
	// first LD_A_I
	const instruction LDD { 0xA8, 2 };

	// LDDR
	// first LD_A_I
	const instruction LDDR { 0xB8, 2 };

	// CPI
	// first LD_A_I
	const instruction CPI { 0xA1, 2 };

	// CPIR
	// first LD_A_I
	const instruction CPIR { 0xB1, 2 };

	// CPD
	// first LD_A_I
	// then
	const instruction CPD { 0xA9, 2 };

	// CPDR
	// first LD_A_I
	// then
	const instruction CPDR { 0xB9, 2 };

	// ADD A, r
	const instruction ADD_A_A { 0x87, 1 };
	const instruction ADD_A_B { 0x80, 1 };
	const instruction ADD_A_C { 0x81, 1 };
	const instruction ADD_A_D { 0x82, 1 };
	const instruction ADD_A_E { 0x83, 1 };
	const instruction ADD_A_H { 0x84, 1 };
	const instruction ADD_A_L { 0x85, 1 };

	// ADD A, n
	const instruction ADD_A_N { 0xC6, 2 };

	// ADD A, (HL)
	const instruction ADD_A_HL { 0x86, 1 };

	// ADD A, (IX + d)
	// first LD_IXD_R
	// then ADD A, (HL)
	// then d

	// ADD A, (IY + d)
	// first LD_IYD_R
	// then ADD A, (HL)
	// then d

	// ADC A, s: opcode group
	// ADC A, r
	const instruction ADC_A_A { 0x8F, 1 };
	const instruction ADC_A_B { 0x88, 1 };
	const instruction ADC_A_C { 0x89, 1 };
	const instruction ADC_A_D { 0x8A, 1 };
	const instruction ADC_A_E { 0x8B, 1 };
	const instruction ADC_A_H { 0x8C, 1 };
	const instruction ADC_A_L { 0x8D, 1 };

	// ADC A, n
	const instruction ADC_A_N { 0xCE, 2 };

	// ADC A, (HL)
	const instruction ADC_A_N { 0x8E, 1 };

	// ADC A, (IX + d)
	// first LD_IXD_R
	// then ADC A, (HL)
	// then d

	// ADC A, (IY + d)
	// first LD_IYD_R
	// then ADC A, (HL)
	// then d

	// SUB s: opcode group
	// SUB r
	const instruction SUB_A { 0x97, 1 };
	const instruction SUB_B { 0x90, 1 };
	const instruction SUB_C { 0x91, 1 };
	const instruction SUB_D { 0x92, 1 };
	const instruction SUB_E { 0x93, 1 };
	const instruction SUB_H { 0x94, 1 };
	const instruction SUB_L { 0x95, 1 };

	// SUB n
	const instruction SUB_N { 0xD6, 2 };

	// SUB (HL)
	const instruction SUB_HL { 0x96, 1 };

	// SUB (IX + d)
	// first LD_IXD_R
	// then SUB (HL)
	// then d

	// SUB (IY + d)
	// first LD_IYD_R
	// then SUB (HL)
	// then d

	
	// SBC A, s: opcode group
	// SBC A, r
	const instruction SBC_A_A { 0x9F, 1 };
	const instruction SBC_A_B { 0x98, 1 };
	const instruction SBC_A_C { 0x99, 1 };
	const instruction SBC_A_D { 0x9A, 1 };
	const instruction SBC_A_E { 0x9B, 1 };
	const instruction SBC_A_H { 0x9C, 1 };
	const instruction SBC_A_L { 0x9D, 1 };

	// SBC A, n
	const instruction SBC_A_N { 0xDE, 2 };

	// SBC A, (HL)
	const instruction SBC_A_N { 0x9E, 1 };

	// SBC A, (IX + d)
	// first LD_IXD_R
	// then SBC A, (HL)
	// then d

	// SBC A, (IY + d)
	// first LD_IYD_R
	// then SBC A, (HL)
	// then d


	// AND s: opcode group
	// AND r'
	const instruction AND_A { 0xA7, 1 };
	const instruction AND_B { 0xA0, 1 };
	const instruction AND_C { 0xA1, 1 };
	const instruction AND_D { 0xA2, 1 };
	const instruction AND_E { 0xA3, 1 };
	const instruction AND_H { 0xA4, 1 };
	const instruction AND_L { 0xA5, 1 };
	
	// AND n
	const instruction AND_N { 0xE6, 2 };
	
	// AND (HL)
	const instruction AND_HL { 0xA6, 1 };

	// AND (IX + d)
	// first LD_IXD_R
	// then AND_HL
	// then d
	
	// AND (IY + d)
	// first LD_IYD_R
	// then AND_HL
	// then d

	// OR s: opcode group
	// OR r'
	const instruction OR_A { 0xB7, 1 };
	const instruction OR_B { 0xB0, 1 };
	const instruction OR_C { 0xB1, 1 };
	const instruction OR_D { 0xB2, 1 };
	const instruction OR_E { 0xB3, 1 };
	const instruction OR_H { 0xB4, 1 };
	const instruction OR_L { 0xB5, 1 };

	// OR n
	const instruction OR_N { 0xF6, 2 };

	// OR (HL)
	const instruction OR_HL { 0xB6, 1 };

	// OR (IX + d)
	// first LD_IXD_R
	// then OR_HL
	// then d

	// OR (IY + d)
	// first LD_IYD_R
	// then OR_HL
	// then d


	// XOR s: opcode group
	// XOR r'
	const instruction XOR_A { 0xAF, 1 };
	const instruction XOR_B { 0xA8, 1 };
	const instruction XOR_C { 0xA9, 1 };
	const instruction XOR_D { 0xAA, 1 };
	const instruction XOR_E { 0xAB, 1 };
	const instruction XOR_H { 0xAC, 1 };
	const instruction XOR_L { 0xAD, 1 };

	// XOR n
	const instruction XOR_N { 0xF6, 2 };

	// XOR (HL)
	const instruction XOR_HL { 0xEE, 1 }; // I think, confirm later

	// XOR (IX + d)
	// first LD_IXD_R
	// then XOR_HL
	// then d

	// XOR (IY + d)
	// first LD_IYD_R
	// then XOR_HL
	// then d

	// CP s: opcode group
	// CP r'
	const instruction CP_A { 0xBF, 1 };
	const instruction CP_B { 0xB8, 1 };
	const instruction CP_C { 0xB9, 1 };
	const instruction CP_D { 0xBA, 1 };
	const instruction CP_E { 0xBB, 1 };
	const instruction CP_H { 0xBC, 1 };
	const instruction CP_L { 0xBD, 1 };

	// CP n
	const instruction CP_N { 0xFE, 2 };
	
	// CP (HL)
	const instruction CP_HL { 0xBE, 1 };

	// CP (IX + d)
	// first LD_IXD_R
	// then CP_HL
	// then d

	// CP (IY + d)
	// first LD_IYD_R
	// then CP_HL
	// then d

	// INC r
	const instruction INC_A { 0x3C, 1 };
	const instruction INC_B { 0x04, 1 };
	const instruction INC_C { 0x0C, 1 };
	const instruction INC_D { 0x14, 1 };
	const instruction INC_E { 0x1C, 1 };
	const instruction INC_H { 0x24, 1 };
	const instruction INC_L { 0x2C, 1 };

	// INC (HL)
	const instruction INC_HL { 0x34, 1 };

	// INC (IX + d)
	// first LD_IXD_R
	// then INC (HL)

	// INC (IY + d)
	// first LD_IYD_R
	// then INC (HL)

	// DEC m: opcode group
	// DEC r'
	const instruction DEC_A { 0x3D, 1 };
	const instruction DEC_B { 0x05, 1 };
	const instruction DEC_C { 0x0D, 1 };
	const instruction DEC_D { 0x15, 1 };
	const instruction DEC_E { 0x1D, 1 };
	const instruction DEC_H { 0x25, 1 };
	const instruction DEC_L { 0x2D, 1 };

	// DEC (HL)
	const instruction DEC_HL { 0x35, 1 };

	// DEC (IX + d)
	// first LD_IXD_R
	// then DEC_HL

	// DEC (IY + d)
	// first LD_IYD_R
	// then DEC_HL

	// General purpose Arithmetic and CPU Control

	// DAA
	const instruction DAA { 0x27, 1 };

	// CPL
	const instruction CPL { 0x2F, 1 };

	// NEG
	// first LD_A_I
	// then
	const instruction NEG { 0x44, 2 };

	// CCF
	const instruction CCF { 0x3F, 1 };

	// SCF
	const instruction SCF { 0x37, 1 };

	// NOP
	const instruction NOP { 0x00, 1 };

	// HALT
	const instruction HALT { 0x76, 1 };

	// DI
	const instruction DI { 0xF3, 1 };

	// EI
	const instruction EI { 0xFB, 1 };

	// IM 0
	// first LD_A_I
	const instruction IM_0 { 0x46, 1 };

	// IM 1
	// first LD_A_I
	const instruction IM_0 { 0x56, 1 };

	// IM 2
	// first LD_A_I
	const instruction IM_0 { 0x5E, 1 };

	// 16-Bit Arithmetic Group

	// ADD HL, ss
	const instruction ADD_HL_BC { 0x09, 1 };
	const instruction ADD_HL_DE { 0x19, 1 };
	const instruction ADD_HL_HL { 0x29, 1 };
	const instruction ADD_HL_SP { 0x39, 1 };

	// ADC HL, ss
	// first LD_A_I
	// then
	const instruction ADC_HL_BC { 0x4A, 1 };
	const instruction ADC_HL_DE { 0x5A, 1 };
	const instruction ADC_HL_HL { 0x6A, 1 };
	const instruction ADC_HL_SP { 0x7A, 1 };

	// SBC HL, ss
	// first LD_A_I
	// then
	const instruction SBC_HL_BC { 0x42, 1 };
	const instruction SBC_HL_DE { 0x52, 1 };
	const instruction SBC_HL_HL { 0x62, 1 };
	const instruction SBC_HL_SP { 0x72, 1 };

	// ADD IX, pp
	// first LD_IXD_R
	// then ADD_HL_SS
	const instruction ADD_IX_BC { 0x09, 1 };
	const instruction ADD_IX_DE { 0x19, 1 };
	const instruction ADD_IX_HL { 0x29, 1 };
	const instruction ADD_IX_SP { 0x39, 1 }; 

	// ADD IY, pp
	// first LD_IYD_R
	// then ADD_HL_SS
	const instruction ADD_IY_BC { 0x09, 1 };
	const instruction ADD_IY_DE { 0x19, 1 };
	const instruction ADD_IY_HL { 0x29, 1 };
	const instruction ADD_IY_SP { 0x39, 1 };

	// INC ss
	const instruction INC_BC { 0x03, 1 };
	const instruction INC_DE { 0x13, 1 };
	const instruction INC_HL { 0x23, 1 };
	const instruction INC_SP { 0x33, 1 };

	// INC IX
	// first LD_IXD_R
	const instruction INC_IX { 0x23, 2 };

	// INC IY
	// first LD_IYD_R
	const instruction INC_IY { 0x23, 2 };

	// DEC ss
	const instruction DEC_BC { 0x0B, 1 };
	const instruction DEC_DE { 0x1B, 1 };
	const instruction DEC_HL { 0x2B, 1 };
	const instruction DEC_SP { 0x3B, 1 };

	// DEC IX
	// first LD_IXD_R
	const instruction DEC_IX { 0x2B, 2 };

	// DEC IY
	// first LD_IYD_R
	const instruction DEC_IY { 0x2B, 2 };

	// Rotate and Shift Group

	// RLCA
	const instruction RCLA { 0x07, 1 };

	// RLA
	const instruction RLA { 0x17, 1 };

	// RRCA
	const instruction RRCA { 0x0F, 1 };

	// RRA
	const instruction RRA { 0x1F, 1 };

	// RLC r
	//first
	const instruction RLC_R { 0xCB, 2 };
	// then any of 
	const instruction RLC_A {0x07};
	const instruction RLC_B { 0x07 };
	const instruction RLC_C { 0x01 };
	const instruction RLC_D { 0x02 };
	const instruction RLC_E { 0x03 };
	const instruction RLC_H { 0x04 };
	const instruction RLC_L { 0x05 };

	// RLC (HL)
	// first RLC_R
	const instruction RLC_HL { 0x06, 1 };

	// RLC (IX + d)
	// first LD_IXD_R
	// then RLC_R
	// then d
	const instruction RLC_IXD { 0x06, 4 };

	// RLC (IY + d)
	// first LD_IYD_R
	// then RLC_R
	// then d
	const instruction RLC_IYD { 0x06, 4 };

}
