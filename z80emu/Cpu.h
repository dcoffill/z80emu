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
	inline void ld();
private:
	Registers _registers;
	Ram _memory;

	// CPU opcode implementations

	// LD r, r' instruction opcodes
	int LD_A_A();
	int LD_A_B();
	int LD_A_C();
	int LD_A_D();
	int LD_A_E();
	int LD_A_H();
	int LD_A_L();

	int LD_B_A();
	int LD_B_B();
	int LD_B_C();
	int LD_B_D();
	int LD_B_E();
	int LD_B_H();
	int LD_B_L();

	int LD_C_A();
	int LD_C_B();
	int LD_C_C();
	int LD_C_D();
	int LD_C_E();
	int LD_C_H();
	int LD_C_L();

	int LD_D_A();
	int LD_D_B();
	int LD_D_C();
	int LD_D_D();
	int LD_D_E();
	int LD_D_H();
	int LD_D_L();

	int LD_E_A();
	int LD_E_B();
	int LD_E_C();
	int LD_E_D();
	int LD_E_E();
	int LD_E_H();
	int LD_E_L();

	int LD_H_A();
	int LD_H_B();
	int LD_H_C();
	int LD_H_D();
	int LD_H_E();
	int LD_H_H();
	int LD_H_L();

	int LD_L_A();
	int LD_L_B();
	int LD_L_C();
	int LD_L_D();
	int LD_L_E();
	int LD_L_H();
	int LD_L_L();

	// LD r, n instructions
	// (where n is immediate contained in PC + 1)
	int LD_A_N();
	int LD_B_N();
	int LD_C_N();
	int LD_D_N();
	int LD_E_N();
	int LD_H_N();
	int LD_L_N();

	// LD r, (HL)
	// Load contents of memory at address contained in (HL) to register r
	int LD_A_HL();
	int LD_B_HL();
	int LD_C_HL();
	int LD_D_HL();
	int LD_E_HL();
	int LD_H_HL();
	int LD_L_HL();

	// LD r, (IX+d)
	// first LD_R_IXd
	// then LD r, (HL)

	// LD r, (IY+d)
	// first LD_R_IYd
	// then LD_R_HL

	// LD r, (IX+d)
	// Load contents of memory stored in address (IX+d)
	// where d is a signed 8 bit integer
	// first LD_R_IXd
	int LD_R_IXd();

	// LD r, (IY+d)
	// Load contents of memory stored in address (IY+d)
	// where d is a signed 8 bit integer
	// first LD_R_IYd
	int LD_R_IYd();

	// LD (HL), r
	// Load contents of register r into address contained in (HL)
	int LD_HL_A();
	int LD_HL_B();
	int LD_HL_C();
	int LD_HL_D();
	int LD_HL_E();
	int LD_HL_H();
	int LD_HL_L();

	// LD (IX+d), r
	// Store contents of register r to memory address stored in address(IX + d)
	// where d is a signed 8 bit integer offset
	int LD_IXd_R(); // DO NOT USE, same as LD_R_IXd

	// LD (IX+d), r
	// Store contents of register r to memory address stored in address(IY + d)
	// where d is a signed 8 bit integer offset
	int LD_IYd_R(); // DO NOT USE, same as LD_R_IYd

	// LD (HL), n
	// Store an immediate value, n, into the memory address contained in HL
	int LD_HL_N();

	// LD (IX+d), n
	// Store an immediate value, n, into the memory address calculated from IX + d
	// where d is a signed 8-bit offset
	// todo: add in later, since it's just 6xDD and 6x36 again

	// LD (IY+d), n
	// Store an immediate value, n, into the memory address calculated from IY + d
	// where d is a signed 8-bit offset
	// todo: add in later, since it's just 6xFD and 6x36 again

	// LD A, (BC)
	// Load contents of memory, stored at address contained in BC, to register A
	int LD_A_BC();

	// LD A, (DE)
	// Load contents of memory, stored at address contained in DE, to register A
	int LD_A_DE();

	// LD A, (nn)
	// Load contents of memory, indicated at the address nn, to register A
	int LD_A_NN();

	// LD (BC), A
	// Store contents of register A to memory address contained in BC
	int LD_BC_A();

	// LD (DE), A
	// Store contents of register A to memory address contained in DE
	int LD_DE_A();

	// LD (nn), A
	// Store contents of register A to address indicated by nn
	int LD_NN_A();

	// LD A, I
	// Load contents of Interrupt Vector register I into A
	// Also used for LD A, R; LD I, A; LD R, A
	int LD_A_I();


	// 16-bit load instructions

	// LD dd, nn
	// Load 2 byte immediate nn into register dd
	int LD_BC_NN(); // to BC
	int LD_DE_NN(); // to DE
	int LD_HL_NN(); // to HL
	int LD_SP_NN(); // to SP

	// LD IX, nn
	// Load nn into index register IX
	// first opcode is 6xDD
	// then 6x21


	// LD IY, nn
	// Load nn into index register IY
	// 6xFD then 6x21

	// LD HL, (nn)
	int LD_HL_NN_ADDR();

	// LD dd, (nn)
	// 6xed, then:
	int LD_HL_NN_ADDR_2();
	int LD_BC_NN_ADDR();
	int LD_DE_NN_ADDR();
	int LD_SP_NN_ADDR();

	// LD IX, (nn)
	// first LD_R_IXd
	// then LD_HL_NN
	// 4 bytes

	// LD IY, (nn)
	// same as previous but with LD_R_IYd

	// LD (nn), HL
	int LD_NN_HL();

	//LD (nn), dd
	// first LD_A_I
	//then
	int LD_NN_BC_ADDR();
	int LD_NN_DE_ADDR();
	int LD_NN_HL_ADDR();
	int LD_NN_SP_ADDR();

	// LD (nn), IX
	// first LD_IXd_R
	// then LD_NN_HL
	// then 2 bytes

	// LD SP, HL
	int LD_SP_HL();

	// LD SP, IX
	// first LD_R_IXd
	// then LD_SP_HL

	// LD SP, IY
	// first LD_R_IYd
	// then LD_SP_HL

	// PUSH qq
	int PUSH_BC();
	int PUSH_DE();
	int PUSH_HL();
	int PUSH_AF();

	// PUSH IX
	// first LD_R_IXd
	// then PUSH_HL

	// PUSH IY
	// first LD_R_IYd
	// then PUSH_HL

	// POP qq
	int POP_BC();
	int POP_DE();
	int POP_HL();
	int POP_AF();

	// POP IX
	// first LD_R_IXd
	// THEN POP HL

	// POP IY
	// first LD_R_IYd
	// THEN POP HL

	// Exchange, block transfer, and search instructions

	// EX DE, HL
	int EX_DE_HL();

	// EX AF, AF'
	int EX_AF_AF();

	// EXX
	int EXX();

	// EX (SP), HL
	int EX_SP_HL();

	// EX (SP), IX
	// first LD_R_IXd
	// then EX_SP_HL

	// EX (SP), IY
	// first LD_R_IYd
	// then EX_SP_HL

	// LDI
	// first LD_A_I
	int LDI();

	// LDIR
	// first LD_A_I
	int LDIR();

	// LDD
	// first LD_A_I
	int LDD();

	// LDDR
	// first LD_A_I
	int LDDR();

	// CPI
	// first LD_A_I
	int CPI();

	// CPIR
	// first LD_A_I
	int CPIR();

	// CPD
	// first LD_A_I
	// then
	int CPD();

	// CPDR
	// first LD_A_I
	// then
	int CPDR();

	// ADD A, r
	int ADD_A_A();
	int ADD_A_B();
	int ADD_A_C();
	int ADD_A_D();
	int ADD_A_E();
	int ADD_A_H();
	int ADD_A_L();

	// ADD A, n
	int ADD_A_N();

	// ADD A, (HL)
	int ADD_A_HL();

	// ADD A, (IX + d)
	// first LD_IXd_R
	// then ADD A, (HL)
	// then d

	// ADD A, (IY + d)
	// first LD_IYd_R
	// then ADD A, (HL)
	// then d

	// ADC A, s: opcode group
	// ADC A, r
	int ADC_A_A();
	int ADC_A_B();
	int ADC_A_C();
	int ADC_A_D();
	int ADC_A_E();
	int ADC_A_H();
	int ADC_A_L();

	// ADC A, n
	int ADC_A_N();

	// ADC A, (HL)
	int ADC_A_HL();

	// ADC A, (IX + d)
	// first LD_IXd_R
	// then ADC A, (HL)
	// then d

	// ADC A, (IY + d)
	// first LD_IYd_R
	// then ADC A, (HL)
	// then d

	// SUB s: opcode group
	// SUB r
	int SUB_A();
	int SUB_B();
	int SUB_C();
	int SUB_D();
	int SUB_E();
	int SUB_H();
	int SUB_L();

	// SUB n
	int SUB_N();

	// SUB (HL)
	int SUB_HL();

	// SUB (IX + d)
	// first LD_IXd_R
	// then SUB (HL)
	// then d

	// SUB (IY + d)
	// first LD_IYd_R
	// then SUB (HL)
	// then d


	// SBC A, s: opcode group
	// SBC A, r
	int SBC_A_A();
	int SBC_A_B();
	int SBC_A_C();
	int SBC_A_D();
	int SBC_A_E();
	int SBC_A_H();
	int SBC_A_L();

	// SBC A, n
	int SBC_A_N();

	// SBC A, (HL)
	int SBC_A_HL();

	// SBC A, (IX + d)
	// first LD_IXd_R
	// then SBC A, (HL)
	// then d

	// SBC A, (IY + d)
	// first LD_IYd_R
	// then SBC A, (HL)
	// then d


	// AND s: opcode group
	// AND r'
	int AND_A();
	int AND_B();
	int AND_C();
	int AND_D();
	int AND_E();
	int AND_H();
	int AND_L();

	// AND n
	int AND_N();

	// AND (HL)
	int AND_HL();

	// AND (IX + d)
	// first LD_IXd_R
	// then AND_HL
	// then d

	// AND (IY + d)
	// first LD_IYd_R
	// then AND_HL
	// then d

	// OR s: opcode group
	// OR r'
	int OR_A();
	int OR_B();
	int OR_C();
	int OR_D();
	int OR_E();
	int OR_H();
	int OR_L();

	// OR n
	int OR_N();

	// OR (HL)
	int OR_HL();

	// OR (IX + d)
	// first LD_IXd_R
	// then OR_HL
	// then d

	// OR (IY + d)
	// first LD_IYd_R
	// then OR_HL
	// then d


	// XOR s: opcode group
	// XOR r'
	int XOR_A();
	int XOR_B();
	int XOR_C();
	int XOR_D();
	int XOR_E();
	int XOR_H();
	int XOR_L();

	// XOR n
	int XOR_N();

	// XOR (HL)
	int XOR_HL(); // I think, confirm later

	// XOR (IX + d)
	// first LD_IXd_R
	// then XOR_HL
	// then d

	// XOR (IY + d)
	// first LD_IYd_R
	// then XOR_HL
	// then d

	// CP s: opcode group
	// CP r'
	int CP_A();
	int CP_B();
	int CP_C();
	int CP_D();
	int CP_E();
	int CP_H();
	int CP_L();

	// CP n
	int CP_N();

	// CP (HL)
	int CP_HL();

	// CP (IX + d)
	// first LD_IXd_R
	// then CP_HL
	// then d

	// CP (IY + d)
	// first LD_IYd_R
	// then CP_HL
	// then d

	// INC r
	int INC_A();
	int INC_B();
	int INC_C();
	int INC_D();
	int INC_E();
	int INC_H();
	int INC_L();

	// INC (HL)
	int INC_HL_ADDR();

	// INC (IX + d)
	// first LD_IXd_R
	// then INC (HL) INC_HL_ADDR

	// INC (IY + d)
	// first LD_IYd_R
	// then INC (HL) INC_HL_ADDR

	// DEC m: opcode group
	// DEC r'
	int DEC_A();
	int DEC_B();
	int DEC_C();
	int DEC_D();
	int DEC_E();
	int DEC_H();
	int DEC_L();

	// DEC (HL)
	int DEC_HL_ADDR();

	// DEC (IX + d)
	// first LD_IXd_R
	// then DEC_HL_ADDR

	// DEC (IY + d)
	// first LD_IYd_R
	// then DEC_HL_ADDR

	// General purpose Arithmetic and CPU Control

	// DAA
	int DAA();

	// CPL
	int CPL();

	// NEG
	// first LD_A_I
	// then
	int NEG();

	// CCF
	int CCF();

	// SCF
	int SCF();

	// NOP
	int NOP();

	// HALT
	int HALT();

	// DI
	int DI();

	// EI
	int EI();

	// IM 6
	// first LD_A_I
	int IM_6();

	// IM 1
	// first LD_A_I
	int IM_1();

	// IM 2
	// first LD_A_I
	int IM_2();

	// 16-Bit Arithmetic Group

	// ADD HL, ss
	int ADD_HL_BC();
	int ADD_HL_DE();
	int ADD_HL_HL();
	int ADD_HL_SP();

	// ADC HL, ss
	// first LD_A_I
	// then
	int ADC_HL_BC();
	int ADC_HL_DE();
	int ADC_HL_HL();
	int ADC_HL_SP();

	// SBC HL, ss
	// first LD_A_I
	// then
	int SBC_HL_BC();
	int SBC_HL_DE();
	int SBC_HL_HL();
	int SBC_HL_SP();

	// ADD IX, pp
	// first LD_IXd_R
	// then ADD_HL_SS
	int ADD_IX_BC();
	int ADD_IX_DE();
	int ADD_IX_HL();
	int ADD_IX_SP();

	// ADD IY, pp
	// first LD_IYd_R
	// then ADD_HL_SS
	int ADD_IY_BC();
	int ADD_IY_DE();
	int ADD_IY_HL();
	int ADD_IY_SP();

	// INC ss
	int INC_BC();
	int INC_DE();
	int INC_HL();
	int INC_SP();

	// INC IX
	// first LD_IXd_R
	int INC_IX();

	// INC IY
	// first LD_IYd_R
	int INC_IY();

	// DEC ss
	int DEC_BC();
	int DEC_DE();
	int DEC_HL();
	int DEC_SP();

	// DEC IX
	// first LD_IXd_R
	int DEC_IX();

	// DEC IY
	// first LD_IYd_R
	int DEC_IY();

	// Rotate and Shift Group

	// RLCA
	int RCLA();

	// RLA
	int RLA();

	// RRCA
	int RRCA();

	// RRA
	int RRA();

	// RLC r
	//first
	int RLC_R();
	// then any of 
	int RLC_A();
	int RLC_B();
	int RLC_C();
	int RLC_D();
	int RLC_E();
	int RLC_H();
	int RLC_L();

	// RLC (HL)
	// first RLC_R
	int RLC_HL();

	// RLC (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then d
	int RLC_IXd();

	// RLC (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then d
	int RLC_IYd();

	// RL m: opcode group

	// RL r'
	// first RLC_R
	// then any of
	int RL_A();
	int RL_B();
	int RL_C();
	int RL_D();
	int RL_E();
	int RL_H();
	int RL_L();

	// RL (HL)
	// first RLC_R
	int RL_HL();

	// RL (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then d
	int RL_IXd();

	// RL (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then d
	int RL_IYd();

	//RRC m: opcode group

	// RRC r'
	// first RLC_R
	// then one of
	int RRC_A();
	int RRC_B();
	int RRC_C();
	int RRC_D();
	int RRC_E();
	int RRC_H();
	int RRC_L();

	// RRC (HL)
	// first RLC_R
	int RRC_HL();

	// RRC (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	int RRC_IXd();

	// RRC (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	int RRC_IYd();

	// RR m: opcode group

	// RR r'
	// first RLC_R
	// then
	int RR_A();
	int RR_B();
	int RR_C();
	int RR_D();
	int RR_E();
	int RR_H();
	int RR_L();

	// RR (HL)
	// first RLC_R
	int RR_HL();

	// RR (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	int RR_IXd();

	// RR (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	int RR_IYd();

	// SLA m: opcode group

	// SLA r'
	// first RLC_R
	// then any of
	int SLA_A();
	int SLA_B();
	int SLA_C();
	int SLA_D();
	int SLA_E();
	int SLA_H();
	int SLA_L();

	// SLA (HL)
	// first RLC_R
	// then
	int SLA_HL();

	// SLA (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	int SLA_IXd();

	// SLA (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	int SLA_IYd();

	// SRA m: opcode group

	// SRA r'
	// first RLC_R
	// then any of
	int SRA_A();
	int SRA_B();
	int SRA_C();
	int SRA_D();
	int SRA_E();
	int SRA_H();
	int SRA_L();

	// SRA (HL)
	// first RLC_R
	// then
	int SRA_HL();

	// SRA (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	int SRA_IXd();

	// SRA (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	int SRA_IYd();

	// SRL m: opcode group

	// SRL r'
	// first RLC_R
	// then any of
	int SRL_A();
	int SRL_B();
	int SRL_C();
	int SRL_D();
	int SRL_E();
	int SRL_H();
	int SRL_L();

	// SRL (HL)
	// first RLC_R
	// then
	int SRL_HL();

	// SRL (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	int SRL_IXd();

	// SRL (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	int SRL_IYd();

	// RLD
	// first LD_A_I
	int RLD();

	// RRD
	// first LD_A_I
	int RRD();


	// Bit Set, Reset, and Test Group
	// bit b, r
	int BIT_0_A();
	int BIT_0_B();
	int BIT_0_C();
	int BIT_0_D();
	int BIT_0_E();
	int BIT_0_H();
	int BIT_0_L();

	int BIT_1_A();
	int BIT_1_B();
	int BIT_1_C();
	int BIT_1_D();
	int BIT_1_E();
	int BIT_1_H();
	int BIT_1_L();

	int BIT_2_A();
	int BIT_2_B();
	int BIT_2_C();
	int BIT_2_D();
	int BIT_2_E();
	int BIT_2_H();
	int BIT_2_L();

	int BIT_3_A();
	int BIT_3_B();
	int BIT_3_C();
	int BIT_3_D();
	int BIT_3_E();
	int BIT_3_H();
	int BIT_3_L();

	int BIT_4_A();
	int BIT_4_B();
	int BIT_4_C();
	int BIT_4_D();
	int BIT_4_E();
	int BIT_4_H();
	int BIT_4_L();

	int BIT_5_A();
	int BIT_5_B();
	int BIT_5_C();
	int BIT_5_D();
	int BIT_5_E();
	int BIT_5_H();
	int BIT_5_L();

	int BIT_6_A();
	int BIT_6_B();
	int BIT_6_C();
	int BIT_6_D();
	int BIT_6_E();
	int BIT_6_H();
	int BIT_6_L();

	int BIT_7_A();
	int BIT_7_B();
	int BIT_7_C();
	int BIT_7_D();
	int BIT_7_E();
	int BIT_7_H();
	int BIT_7_L();

	// BIT b, (HL)
	int BIT_0_HL();
	int BIT_1_HL();
	int BIT_2_HL();
	int BIT_3_HL();
	int BIT_4_HL();
	int BIT_5_HL();
	int BIT_6_HL();
	int BIT_7_HL();

	// Bit b, (IX + d)
	int BIT_0_IXd();
	int BIT_1_IXd();
	int BIT_2_IXd();
	int BIT_3_IXd();
	int BIT_4_IXd();
	int BIT_5_IXd();
	int BIT_6_IXd();
	int BIT_7_IXd();

	// Bit b, (IY + d)
	int BIT_0_IYd();
	int BIT_1_IYd();
	int BIT_2_IYd();
	int BIT_3_IYd();
	int BIT_4_IYd();
	int BIT_5_IYd();
	int BIT_6_IYd();
	int BIT_7_IYd();

	// SET b, r
	int SET_0_A();
	int SET_0_B();
	int SET_0_C();
	int SET_0_D();
	int SET_0_E();
	int SET_0_H();
	int SET_0_L();

	int SET_1_A();
	int SET_1_B();
	int SET_1_C();
	int SET_1_D();
	int SET_1_E();
	int SET_1_H();
	int SET_1_L();

	int SET_2_A();
	int SET_2_B();
	int SET_2_C();
	int SET_2_D();
	int SET_2_E();
	int SET_2_H();
	int SET_2_L();

	int SET_3_A();
	int SET_3_B();
	int SET_3_C();
	int SET_3_D();
	int SET_3_E();
	int SET_3_H();
	int SET_3_L();

	int SET_4_A();
	int SET_4_B();
	int SET_4_C();
	int SET_4_D();
	int SET_4_E();
	int SET_4_H();
	int SET_4_L();

	int SET_5_A();
	int SET_5_B();
	int SET_5_C();
	int SET_5_D();
	int SET_5_E();
	int SET_5_H();
	int SET_5_L();

	int SET_6_A();
	int SET_6_B();
	int SET_6_C();
	int SET_6_D();
	int SET_6_E();
	int SET_6_H();
	int SET_6_L();

	int SET_7_A();
	int SET_7_B();
	int SET_7_C();
	int SET_7_D();
	int SET_7_E();
	int SET_7_H();
	int SET_7_L();

	// SET b, (HL)
	int SET_A_HL();
	int SET_B_HL();
	int SET_C_HL();
	int SET_D_HL();
	int SET_E_HL();
	int SET_H_HL();
	int SET_L_HL();

	// SET b, (IX + d)
	int SET_A_IXd();
	int SET_B_IXd();
	int SET_C_IXd();
	int SET_D_IXd();
	int SET_E_IXd();
	int SET_H_IXd();
	int SET_L_IXd();

	// SET b, (IY + d)
	int SET_A_IYd();
	int SET_B_IYd();
	int SET_C_IYd();
	int SET_D_IYd();
	int SET_E_IYd();
	int SET_H_IYd();
	int SET_L_IYd();

	// RES b, m
	int RES_0_A();
	int RES_0_B();
	int RES_0_C();
	int RES_0_D();
	int RES_0_E();
	int RES_0_H();
	int RES_0_L();

	int RES_1_A();
	int RES_1_B();
	int RES_1_C();
	int RES_1_D();
	int RES_1_E();
	int RES_1_H();
	int RES_1_L();

	int RES_2_A();
	int RES_2_B();
	int RES_2_C();
	int RES_2_D();
	int RES_2_E();
	int RES_2_H();
	int RES_2_L();

	int RES_3_A();
	int RES_3_B();
	int RES_3_C();
	int RES_3_D();
	int RES_3_E();
	int RES_3_H();
	int RES_3_L();

	int RES_4_A();
	int RES_4_B();
	int RES_4_C();
	int RES_4_D();
	int RES_4_E();
	int RES_4_H();
	int RES_4_L();

	int RES_5_A();
	int RES_5_B();
	int RES_5_C();
	int RES_5_D();
	int RES_5_E();
	int RES_5_H();
	int RES_5_L();

	int RES_6_A();
	int RES_6_B();
	int RES_6_C();
	int RES_6_D();
	int RES_6_E();
	int RES_6_H();
	int RES_6_L();

	int RES_7_A();
	int RES_7_B();
	int RES_7_C();
	int RES_7_D();
	int RES_7_E();
	int RES_7_H();
	int RES_7_L();

	// RES b, (HL)
	int RES_0_HL();
	int RES_1_HL();
	int RES_2_HL();
	int RES_3_HL();
	int RES_4_HL();
	int RES_5_HL();
	int RES_6_HL();
	int RES_7_HL();

	// RES b, (IX + d)
	int RES_0_IXd();
	int RES_1_IXd();
	int RES_2_IXd();
	int RES_3_IXd();
	int RES_4_IXd();
	int RES_5_IXd();
	int RES_6_IXd();
	int RES_7_IXd();

	// RES b, (IY + d)
	int RES_0_IYd();
	int RES_1_IYd();
	int RES_2_IYd();
	int RES_3_IYd();
	int RES_4_IYd();
	int RES_5_IYd();
	int RES_6_IYd();
	int RES_7_IYd();

	// Jump group

	// JP nn
	int JP_nn();

	// JP cc, nn
	int JP_NZ_nn();
	int JP_Z_nn();
	int JP_NC_nn();
	int JP_C_nn();
	int JP_PO_nn();
	int JP_PE_nn();
	int JP_P_nn();
	int JP_M_nn();

	// JR e
	int JR_e();
	
	// JR C, e
	int JR_C_e();

	// JR NC, e
	int JR_NC_e();

	// JR Z, e
	int JR_Z_e();

	// JR NZ, e
	int JR_NZ_e();

	// JP (HL)
	int JP_HL();

	// JP (IX)
	int JP_IX();

	// JP (IY)
	int JP_IY();

	// DJNZ, e
	int DJNZ_e();

	// Call and Return Group
	// CALL nn
	int CALL_nn();

	// CALL cc, nn
	int CALL_NZ_nn();
	int CALL_Z_nn();
	int CALL_NC_nn();
	int CALL_C_nn();
	int CALL_PO_nn();
	int CALL_PE_nn();
	int CALL_P_nn();
	int CALL_M_nn();

	// RET
	int RET();

	// RET cc
	int RET_NZ();
	int RET_Z();
	int RET_NC();
	int RET_C();
	int RET_PO();
	int RET_PE();
	int RET_P();
	int RET_M();

	// RETI
	int RETI();

	// RETN
	int RETN();

	// RST p
	int RST_00h();
	int RST_08h();
	int RST_10h();
	int RST_18h();
	int RST_20h();
	int RST_28h();
	int RST_30h();
	int RST_38h();

	// Input and Output Group
	
	// IN A, (n)
	int IN_A();

	// IN r (C)
	int IN_A_C();
	int IN_B_C();
	int IN_C_C();
	int IN_D_C();
	int IN_E_C();
	int IN_F_C();
	int IN_H_C();
	int IN_L_C();

	// INI
	int INI();

	// INIR
	int INIR();

	// IND
	int IND();

	// INDR
	int INDR();

	// OUT (n), A
	int OUT_N_A();

	// OUT (C), r
	int OUT_C_A();
	int OUT_C_B();
	int OUT_C_C();
	int OUT_C_D();
	int OUT_C_E();
	int OUT_C_H();
	int OUT_C_L();

	// OTIR
	int OTIR();

	// OUTD
	int OUTD();

	// OTDR
	int OTDR();


	// Not opcodes
	// Opcode groupings
	int BITS_group();
	int IX_group();
	int IY_group();
	int EXTD_group();


};
#endif