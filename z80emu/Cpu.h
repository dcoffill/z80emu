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
	// return uinline void16_t address of next instruction
	// TODO: look into generating specialized method implementations from generic function template for each opcode (actual template<> or just generic method)

	// LD r, r' instruction opcodes
	inline void LD_A_A();
	inline void LD_A_B();
	inline void LD_A_C();
	inline void LD_A_D();
	inline void LD_A_E();
	inline void LD_A_H();
	inline void LD_A_L();

	inline void LD_B_A();
	inline void LD_B_B();
	inline void LD_B_C();
	inline void LD_B_D();
	inline void LD_B_E();
	inline void LD_B_H();
	inline void LD_B_L();

	inline void LD_C_A();
	inline void LD_C_B();
	inline void LD_C_C();
	inline void LD_C_D();
	inline void LD_C_E();
	inline void LD_C_H();
	inline void LD_C_L();

	inline void LD_D_A();
	inline void LD_D_B();
	inline void LD_D_C();
	inline void LD_D_D();
	inline void LD_D_E();
	inline void LD_D_H();
	inline void LD_D_L();

	inline void LD_E_A();
	inline void LD_E_B();
	inline void LD_E_C();
	inline void LD_E_D();
	inline void LD_E_E();
	inline void LD_E_H();
	inline void LD_E_L();

	inline void LD_H_A();
	inline void LD_H_B();
	inline void LD_H_C();
	inline void LD_H_D();
	inline void LD_H_E();
	inline void LD_H_H();
	inline void LD_H_L();

	inline void LD_L_A();
	inline void LD_L_B();
	inline void LD_L_C();
	inline void LD_L_D();
	inline void LD_L_E();
	inline void LD_L_H();
	inline void LD_L_L();

	// LD r, n instructions
	// (where n is immediate contained in PC + 1)
	inline void LD_A_N();
	inline void LD_B_N();
	inline void LD_C_N();
	inline void LD_D_N();
	inline void LD_E_N();
	inline void LD_H_N();
	inline void LD_L_N();

	// LD r, (HL)
	// Load contents of memory at address contained in (HL) to register r
	inline void LD_A_HL();
	inline void LD_B_HL();
	inline void LD_C_HL();
	inline void LD_D_HL();
	inline void LD_E_HL();
	inline void LD_H_HL();
	inline void LD_L_HL();

	// LD r, (IX+d)
	// first LD_R_IXd
	// then LD r, (HL)

	// LD r, (IY+d)
	// first LD_R_IYd
	// then LD_R_HL

	// LD r, (IX+d)
	// Load contents of memory stored in address (IX+d)
	// where d is a signed 8 bit inline voideger
	// first LD_R_IXd
	inline void LD_R_IXd();

	// LD r, (IY+d)
	// Load contents of memory stored in address (IY+d)
	// where d is a signed 8 bit inline voideger
	// first LD_R_IYd
	inline void LD_R_IYd();

	// LD (HL), r
	// Load contents of register r inline voido address contained in (HL)
	inline void LD_HL_A();
	inline void LD_HL_B();
	inline void LD_HL_C();
	inline void LD_HL_D();
	inline void LD_HL_E();
	inline void LD_HL_H();
	inline void LD_HL_L();

	// LD (IX+d), r
	// Store contents of register r to memory address stored in address(IX + d)
	// where d is a signed 8 bit inline voideger offset
	inline void LD_IXd_R(); // DO NOT USE, same as LD_R_IXd

	// LD (IX+d), r
	// Store contents of register r to memory address stored in address(IY + d)
	// where d is a signed 8 bit inline voideger offset
	inline void LD_IYd_R(); // DO NOT USE, same as LD_R_IYd

	// LD (HL), n
	// Store an immediate value, n, inline voido the memory address contained in HL
	inline void LD_HL_N();

	// LD (IX+d), n
	// Store an immediate value, n, inline voido the memory address calculated from IX + d
	// where d is a signed 8-bit offset
	// todo: add in later, since it's just 6xDD and 6x36 again

	// LD (IY+d), n
	// Store an immediate value, n, inline voido the memory address calculated from IY + d
	// where d is a signed 8-bit offset
	// todo: add in later, since it's just 6xFD and 6x36 again

	// LD A, (BC)
	// Load contents of memory, stored at address contained in BC, to register A
	inline void LD_A_BC();

	// LD A, (DE)
	// Load contents of memory, stored at address contained in DE, to register A
	inline void LD_A_DE();

	// LD A, (nn)
	// Load contents of memory, indicated at the address nn, to register A
	inline void LD_A_NN();

	// LD (BC), A
	// Store contents of register A to memory address contained in BC
	inline void LD_BC_A();

	// LD (DE), A
	// Store contents of register A to memory address contained in DE
	inline void LD_DE_A();

	// LD (nn), A
	// Store contents of register A to address indicated by nn
	inline void LD_NN_A();

	// LD A, I
	// Load contents of inline voiderrupt Vector register I inline voido A
	// Also used for LD A, R; LD I, A; LD R, A
	inline void LD_A_I();


	// 16-bit load instructions

	// LD dd, nn
	// Load 2 byte immediate nn inline voido register dd
	inline void LD_BC_NN(); // to BC
	inline void LD_DE_NN(); // to DE
	inline void LD_HL_NN(); // to HL
	inline void LD_SP_NN(); // to SP

	// LD IX, nn
	// Load nn inline voido index register IX
	// first opcode is 6xDD
	// then 6x21


	// LD IY, nn
	// Load nn inline voido index register IY
	// 6xFD then 6x21

	// LD HL, (nn)
	inline void LD_HL_NN_ADDR();

	// LD dd, (nn)
	// 6xed, then:
	inline void LD_HL_NN_ADDR_2();
	inline void LD_BC_NN_ADDR();
	inline void LD_DE_NN_ADDR();
	inline void LD_SP_NN_ADDR();

	// LD IX, (nn)
	// first LD_R_IXd
	// then LD_HL_NN
	// 4 bytes

	// LD IY, (nn)
	// same as previous but with LD_R_IYd

	// LD (nn), HL
	inline void LD_NN_HL();

	//LD (nn), dd
	// first LD_A_I
	//then
	inline void LD_NN_BC_ADDR();
	inline void LD_NN_DE_ADDR();
	inline void LD_NN_HL_ADDR();
	inline void LD_NN_SP_ADDR();

	// LD (nn), IX
	// first LD_IXd_R
	// then LD_NN_HL
	// then 2 bytes

	// LD SP, HL
	inline void LD_SP_HL();

	// LD SP, IX
	// first LD_R_IXd
	// then LD_SP_HL

	// LD SP, IY
	// first LD_R_IYd
	// then LD_SP_HL

	// PUSH qq
	inline void PUSH_BC();
	inline void PUSH_DE();
	inline void PUSH_HL();
	inline void PUSH_AF();

	// PUSH IX
	// first LD_R_IXd
	// then PUSH_HL

	// PUSH IY
	// first LD_R_IYd
	// then PUSH_HL

	// POP qq
	inline void POP_BC();
	inline void POP_DE();
	inline void POP_HL();
	inline void POP_AF();

	// POP IX
	// first LD_R_IXd
	// THEN POP HL

	// POP IY
	// first LD_R_IYd
	// THEN POP HL

	// Exchange, block transfer, and search instructions

	// EX DE, HL
	inline void EX_DE_HL();

	// EX AF, AF'
	inline void EX_AF_AF();

	// EXX
	inline void EXX();

	// EX (SP), HL
	inline void EX_SP_HL();

	// EX (SP), IX
	// first LD_R_IXd
	// then EX_SP_HL

	// EX (SP), IY
	// first LD_R_IYd
	// then EX_SP_HL

	// LDI
	// first LD_A_I
	inline void LDI();

	// LDIR
	// first LD_A_I
	inline void LDIR();

	// LDD
	// first LD_A_I
	inline void LDD();

	// LDDR
	// first LD_A_I
	inline void LDDR();

	// CPI
	// first LD_A_I
	inline void CPI();

	// CPIR
	// first LD_A_I
	inline void CPIR();

	// CPD
	// first LD_A_I
	// then
	inline void CPD();

	// CPDR
	// first LD_A_I
	// then
	inline void CPDR();

	// ADD A, r
	inline void ADD_A_A();
	inline void ADD_A_B();
	inline void ADD_A_C();
	inline void ADD_A_D();
	inline void ADD_A_E();
	inline void ADD_A_H();
	inline void ADD_A_L();

	// ADD A, n
	inline void ADD_A_N();

	// ADD A, (HL)
	inline void ADD_A_HL();

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
	inline void ADC_A_A();
	inline void ADC_A_B();
	inline void ADC_A_C();
	inline void ADC_A_D();
	inline void ADC_A_E();
	inline void ADC_A_H();
	inline void ADC_A_L();

	// ADC A, n
	inline void ADC_A_N();

	// ADC A, (HL)
	inline void ADC_A_HL();

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
	inline void SUB_A();
	inline void SUB_B();
	inline void SUB_C();
	inline void SUB_D();
	inline void SUB_E();
	inline void SUB_H();
	inline void SUB_L();

	// SUB n
	inline void SUB_N();

	// SUB (HL)
	inline void SUB_HL();

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
	inline void SBC_A_A();
	inline void SBC_A_B();
	inline void SBC_A_C();
	inline void SBC_A_D();
	inline void SBC_A_E();
	inline void SBC_A_H();
	inline void SBC_A_L();

	// SBC A, n
	inline void SBC_A_N();

	// SBC A, (HL)
	inline void SBC_A_HL();

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
	inline void AND_A();
	inline void AND_B();
	inline void AND_C();
	inline void AND_D();
	inline void AND_E();
	inline void AND_H();
	inline void AND_L();

	// AND n
	inline void AND_N();

	// AND (HL)
	inline void AND_HL();

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
	inline void OR_A();
	inline void OR_B();
	inline void OR_C();
	inline void OR_D();
	inline void OR_E();
	inline void OR_H();
	inline void OR_L();

	// OR n
	inline void OR_N();

	// OR (HL)
	inline void OR_HL();

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
	inline void XOR_A();
	inline void XOR_B();
	inline void XOR_C();
	inline void XOR_D();
	inline void XOR_E();
	inline void XOR_H();
	inline void XOR_L();

	// XOR n
	inline void XOR_N();

	// XOR (HL)
	inline void XOR_HL(); // I think, confirm later

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
	inline void CP_A();
	inline void CP_B();
	inline void CP_C();
	inline void CP_D();
	inline void CP_E();
	inline void CP_H();
	inline void CP_L();

	// CP n
	inline void CP_N();

	// CP (HL)
	inline void CP_HL();

	// CP (IX + d)
	// first LD_IXd_R
	// then CP_HL
	// then d

	// CP (IY + d)
	// first LD_IYd_R
	// then CP_HL
	// then d

	// INC r
	inline void INC_A();
	inline void INC_B();
	inline void INC_C();
	inline void INC_D();
	inline void INC_E();
	inline void INC_H();
	inline void INC_L();

	// INC (HL)
	inline void INC_HL_ADDR();

	// INC (IX + d)
	// first LD_IXd_R
	// then INC (HL) INC_HL_ADDR

	// INC (IY + d)
	// first LD_IYd_R
	// then INC (HL) INC_HL_ADDR

	// DEC m: opcode group
	// DEC r'
	inline void DEC_A();
	inline void DEC_B();
	inline void DEC_C();
	inline void DEC_D();
	inline void DEC_E();
	inline void DEC_H();
	inline void DEC_L();

	// DEC (HL)
	inline void DEC_HL_ADDR();

	// DEC (IX + d)
	// first LD_IXd_R
	// then DEC_HL_ADDR

	// DEC (IY + d)
	// first LD_IYd_R
	// then DEC_HL_ADDR

	// General purpose Arithmetic and CPU Control

	// DAA
	inline void DAA();

	// CPL
	inline void CPL();

	// NEG
	// first LD_A_I
	// then
	inline void NEG();

	// CCF
	inline void CCF();

	// SCF
	inline void SCF();

	// NOP
	inline void NOP();

	// HALT
	inline void HALT();

	// DI
	inline void DI();

	// EI
	inline void EI();

	// IM 6
	// first LD_A_I
	inline void IM_6();

	// IM 1
	// first LD_A_I
	inline void IM_1();

	// IM 2
	// first LD_A_I
	inline void IM_2();

	// 16-Bit Arithmetic Group

	// ADD HL, ss
	inline void ADD_HL_BC();
	inline void ADD_HL_DE();
	inline void ADD_HL_HL();
	inline void ADD_HL_SP();

	// ADC HL, ss
	// first LD_A_I
	// then
	inline void ADC_HL_BC();
	inline void ADC_HL_DE();
	inline void ADC_HL_HL();
	inline void ADC_HL_SP();

	// SBC HL, ss
	// first LD_A_I
	// then
	inline void SBC_HL_BC();
	inline void SBC_HL_DE();
	inline void SBC_HL_HL();
	inline void SBC_HL_SP();

	// ADD IX, pp
	// first LD_IXd_R
	// then ADD_HL_SS
	inline void ADD_IX_BC();
	inline void ADD_IX_DE();
	inline void ADD_IX_HL();
	inline void ADD_IX_SP();

	// ADD IY, pp
	// first LD_IYd_R
	// then ADD_HL_SS
	inline void ADD_IY_BC();
	inline void ADD_IY_DE();
	inline void ADD_IY_HL();
	inline void ADD_IY_SP();

	// INC ss
	inline void INC_BC();
	inline void INC_DE();
	inline void INC_HL();
	inline void INC_SP();

	// INC IX
	// first LD_IXd_R
	inline void INC_IX();

	// INC IY
	// first LD_IYd_R
	inline void INC_IY();

	// DEC ss
	inline void DEC_BC();
	inline void DEC_DE();
	inline void DEC_HL();
	inline void DEC_SP();

	// DEC IX
	// first LD_IXd_R
	inline void DEC_IX();

	// DEC IY
	// first LD_IYd_R
	inline void DEC_IY();

	// Rotate and Shift Group

	// RLCA
	inline void RCLA();

	// RLA
	inline void RLA();

	// RRCA
	inline void RRCA();

	// RRA
	inline void RRA();

	// RLC r
	//first
	inline void RLC_R();
	// then any of 
	inline void RLC_A();
	inline void RLC_B();
	inline void RLC_C();
	inline void RLC_D();
	inline void RLC_E();
	inline void RLC_H();
	inline void RLC_L();

	// RLC (HL)
	// first RLC_R
	inline void RLC_HL();

	// RLC (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then d
	inline void RLC_IXd();

	// RLC (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then d
	inline void RLC_IYd();

	// RL m: opcode group

	// RL r'
	// first RLC_R
	// then any of
	inline void RL_A();
	inline void RL_B();
	inline void RL_C();
	inline void RL_D();
	inline void RL_E();
	inline void RL_H();
	inline void RL_L();

	// RL (HL)
	// first RLC_R
	inline void RL_HL();

	// RL (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then d
	inline void RL_IXd();

	// RL (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then d
	inline void RL_IYd();

	//RRC m: opcode group

	// RRC r'
	// first RLC_R
	// then one of
	inline void RRC_A();
	inline void RRC_B();
	inline void RRC_C();
	inline void RRC_D();
	inline void RRC_E();
	inline void RRC_H();
	inline void RRC_L();

	// RRC (HL)
	// first RLC_R
	inline void RRC_HL();

	// RRC (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	inline void RRC_IXd();

	// RRC (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	inline void RRC_IYd();

	// RR m: opcode group

	// RR r'
	// first RLC_R
	// then
	inline void RR_A();
	inline void RR_B();
	inline void RR_C();
	inline void RR_D();
	inline void RR_E();
	inline void RR_H();
	inline void RR_L();

	// RR (HL)
	// first RLC_R
	inline void RR_HL();

	// RR (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	inline void RR_IXd();

	// RR (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	inline void RR_IYd();

	// SLA m: opcode group

	// SLA r'
	// first RLC_R
	// then any of
	inline void SLA_A();
	inline void SLA_B();
	inline void SLA_C();
	inline void SLA_D();
	inline void SLA_E();
	inline void SLA_H();
	inline void SLA_L();

	// SLA (HL)
	// first RLC_R
	// then
	inline void SLA_HL();

	// SLA (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	inline void SLA_IXd();

	// SLA (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	inline void SLA_IYd();

	// SRA m: opcode group

	// SRA r'
	// first RLC_R
	// then any of
	inline void SRA_A();
	inline void SRA_B();
	inline void SRA_C();
	inline void SRA_D();
	inline void SRA_E();
	inline void SRA_H();
	inline void SRA_L();

	// SRA (HL)
	// first RLC_R
	// then
	inline void SRA_HL();

	// SRA (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	inline void SRA_IXd();

	// SRA (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	inline void SRA_IYd();

	// SRL m: opcode group

	// SRL r'
	// first RLC_R
	// then any of
	inline void SRL_A();
	inline void SRL_B();
	inline void SRL_C();
	inline void SRL_D();
	inline void SRL_E();
	inline void SRL_H();
	inline void SRL_L();

	// SRL (HL)
	// first RLC_R
	// then
	inline void SRL_HL();

	// SRL (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	inline void SRL_IXd();

	// SRL (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	inline void SRL_IYd();

	// RLD
	// first LD_A_I
	inline void RLD();

	// RRD
	// first LD_A_I
	inline void RRD();


	// Bit Set, Reset, and Test Group
	// bit b, r
	inline void BIT_0_A();
	inline void BIT_0_B();
	inline void BIT_0_C();
	inline void BIT_0_D();
	inline void BIT_0_E();
	inline void BIT_0_H();
	inline void BIT_0_L();

	inline void BIT_1_A();
	inline void BIT_1_B();
	inline void BIT_1_C();
	inline void BIT_1_D();
	inline void BIT_1_E();
	inline void BIT_1_H();
	inline void BIT_1_L();

	inline void BIT_2_A();
	inline void BIT_2_B();
	inline void BIT_2_C();
	inline void BIT_2_D();
	inline void BIT_2_E();
	inline void BIT_2_H();
	inline void BIT_2_L();

	inline void BIT_3_A();
	inline void BIT_3_B();
	inline void BIT_3_C();
	inline void BIT_3_D();
	inline void BIT_3_E();
	inline void BIT_3_H();
	inline void BIT_3_L();

	inline void BIT_4_A();
	inline void BIT_4_B();
	inline void BIT_4_C();
	inline void BIT_4_D();
	inline void BIT_4_E();
	inline void BIT_4_H();
	inline void BIT_4_L();

	inline void BIT_5_A();
	inline void BIT_5_B();
	inline void BIT_5_C();
	inline void BIT_5_D();
	inline void BIT_5_E();
	inline void BIT_5_H();
	inline void BIT_5_L();

	inline void BIT_6_A();
	inline void BIT_6_B();
	inline void BIT_6_C();
	inline void BIT_6_D();
	inline void BIT_6_E();
	inline void BIT_6_H();
	inline void BIT_6_L();

	inline void BIT_7_A();
	inline void BIT_7_B();
	inline void BIT_7_C();
	inline void BIT_7_D();
	inline void BIT_7_E();
	inline void BIT_7_H();
	inline void BIT_7_L();

	// BIT b, (HL)
	inline void BIT_0_HL();
	inline void BIT_1_HL();
	inline void BIT_2_HL();
	inline void BIT_3_HL();
	inline void BIT_4_HL();
	inline void BIT_5_HL();
	inline void BIT_6_HL();
	inline void BIT_7_HL();

	// Bit b, (IX + d)
	inline void BIT_0_IXd();
	inline void BIT_1_IXd();
	inline void BIT_2_IXd();
	inline void BIT_3_IXd();
	inline void BIT_4_IXd();
	inline void BIT_5_IXd();
	inline void BIT_6_IXd();
	inline void BIT_7_IXd();

	// Bit b, (IY + d)
	inline void BIT_0_IYd();
	inline void BIT_1_IYd();
	inline void BIT_2_IYd();
	inline void BIT_3_IYd();
	inline void BIT_4_IYd();
	inline void BIT_5_IYd();
	inline void BIT_6_IYd();
	inline void BIT_7_IYd();

	// SET b, r
	inline void SET_0_A();
	inline void SET_0_B();
	inline void SET_0_C();
	inline void SET_0_D();
	inline void SET_0_E();
	inline void SET_0_H();
	inline void SET_0_L();

	inline void SET_1_A();
	inline void SET_1_B();
	inline void SET_1_C();
	inline void SET_1_D();
	inline void SET_1_E();
	inline void SET_1_H();
	inline void SET_1_L();

	inline void SET_2_A();
	inline void SET_2_B();
	inline void SET_2_C();
	inline void SET_2_D();
	inline void SET_2_E();
	inline void SET_2_H();
	inline void SET_2_L();

	inline void SET_3_A();
	inline void SET_3_B();
	inline void SET_3_C();
	inline void SET_3_D();
	inline void SET_3_E();
	inline void SET_3_H();
	inline void SET_3_L();

	inline void SET_4_A();
	inline void SET_4_B();
	inline void SET_4_C();
	inline void SET_4_D();
	inline void SET_4_E();
	inline void SET_4_H();
	inline void SET_4_L();

	inline void SET_5_A();
	inline void SET_5_B();
	inline void SET_5_C();
	inline void SET_5_D();
	inline void SET_5_E();
	inline void SET_5_H();
	inline void SET_5_L();

	inline void SET_6_A();
	inline void SET_6_B();
	inline void SET_6_C();
	inline void SET_6_D();
	inline void SET_6_E();
	inline void SET_6_H();
	inline void SET_6_L();

	inline void SET_7_A();
	inline void SET_7_B();
	inline void SET_7_C();
	inline void SET_7_D();
	inline void SET_7_E();
	inline void SET_7_H();
	inline void SET_7_L();

	// SET b, (HL)
	inline void SET_A_HL();
	inline void SET_B_HL();
	inline void SET_C_HL();
	inline void SET_D_HL();
	inline void SET_E_HL();
	inline void SET_H_HL();
	inline void SET_L_HL();

	// SET b, (IX + d)
	inline void SET_A_IXd();
	inline void SET_B_IXd();
	inline void SET_C_IXd();
	inline void SET_D_IXd();
	inline void SET_E_IXd();
	inline void SET_H_IXd();
	inline void SET_L_IXd();

	// SET b, (IY + d)
	inline void SET_A_IYd();
	inline void SET_B_IYd();
	inline void SET_C_IYd();
	inline void SET_D_IYd();
	inline void SET_E_IYd();
	inline void SET_H_IYd();
	inline void SET_L_IYd();

	// RES b, m
	inline void RES_0_A();
	inline void RES_0_B();
	inline void RES_0_C();
	inline void RES_0_D();
	inline void RES_0_E();
	inline void RES_0_H();
	inline void RES_0_L();

	inline void RES_1_A();
	inline void RES_1_B();
	inline void RES_1_C();
	inline void RES_1_D();
	inline void RES_1_E();
	inline void RES_1_H();
	inline void RES_1_L();

	inline void RES_2_A();
	inline void RES_2_B();
	inline void RES_2_C();
	inline void RES_2_D();
	inline void RES_2_E();
	inline void RES_2_H();
	inline void RES_2_L();

	inline void RES_3_A();
	inline void RES_3_B();
	inline void RES_3_C();
	inline void RES_3_D();
	inline void RES_3_E();
	inline void RES_3_H();
	inline void RES_3_L();

	inline void RES_4_A();
	inline void RES_4_B();
	inline void RES_4_C();
	inline void RES_4_D();
	inline void RES_4_E();
	inline void RES_4_H();
	inline void RES_4_L();

	inline void RES_5_A();
	inline void RES_5_B();
	inline void RES_5_C();
	inline void RES_5_D();
	inline void RES_5_E();
	inline void RES_5_H();
	inline void RES_5_L();

	inline void RES_6_A();
	inline void RES_6_B();
	inline void RES_6_C();
	inline void RES_6_D();
	inline void RES_6_E();
	inline void RES_6_H();
	inline void RES_6_L();

	inline void RES_7_A();
	inline void RES_7_B();
	inline void RES_7_C();
	inline void RES_7_D();
	inline void RES_7_E();
	inline void RES_7_H();
	inline void RES_7_L();

	// RES b, (HL)
	inline void RES_0_HL();
	inline void RES_1_HL();
	inline void RES_2_HL();
	inline void RES_3_HL();
	inline void RES_4_HL();
	inline void RES_5_HL();
	inline void RES_6_HL();
	inline void RES_7_HL();

	// RES b, (IX + d)
	inline void RES_0_IXd();
	inline void RES_1_IXd();
	inline void RES_2_IXd();
	inline void RES_3_IXd();
	inline void RES_4_IXd();
	inline void RES_5_IXd();
	inline void RES_6_IXd();
	inline void RES_7_IXd();

	// RES b, (IY + d)
	inline void RES_0_IYd();
	inline void RES_1_IYd();
	inline void RES_2_IYd();
	inline void RES_3_IYd();
	inline void RES_4_IYd();
	inline void RES_5_IYd();
	inline void RES_6_IYd();
	inline void RES_7_IYd();

	// Jump group

	// JP nn
	inline void JP_nn();

	// JP cc, nn
	inline void JP_NZ_nn();
	inline void JP_Z_nn();
	inline void JP_NC_nn();
	inline void JP_C_nn();
	inline void JP_PO_nn();
	inline void JP_PE_nn();
	inline void JP_P_nn();
	inline void JP_M_nn();

	// JR e
	inline void JR_e();
	
	// JR C, e
	inline void JR_C_e();

	// JR NC, e
	inline void JR_NC_e();

	// JR Z, e
	inline void JR_Z_e();

	// JR NZ, e
	inline void JR_NZ_e();

	// JP (HL)
	inline void JP_HL();

	// JP (IX)
	inline void JP_IX();

	// JP (IY)
	inline void JP_IY();

	// DJNZ, e
	inline void DJNZ_e();

	// Call and Return Group
	// CALL nn
	inline void CALL_nn();

	// CALL cc, nn
	inline void CALL_NZ_nn();
	inline void CALL_Z_nn();
	inline void CALL_NC_nn();
	inline void CALL_C_nn();
	inline void CALL_PO_nn();
	inline void CALL_PE_nn();
	inline void CALL_P_nn();
	inline void CALL_M_nn();

	// RET
	inline void RET();

	// RET cc
	inline void RET_NZ();
	inline void RET_Z();
	inline void RET_NC();
	inline void RET_C();
	inline void RET_PO();
	inline void RET_PE();
	inline void RET_P();
	inline void RET_M();

	// RETI
	inline void RETI();

	// RETN
	inline void RETN();

	// RST p
	inline void RST_00h();
	inline void RST_08h();
	inline void RST_10h();
	inline void RST_18h();
	inline void RST_20h();
	inline void RST_28h();
	inline void RST_30h();
	inline void RST_38h();

	// Input and Output Group
	
	// IN A, (n)
	inline void IN_A();

	// IN r (C)
	inline void IN_A_C();
	inline void IN_B_C();
	inline void IN_C_C();
	inline void IN_D_C();
	inline void IN_E_C();
	inline void IN_F_C();
	inline void IN_H_C();
	inline void IN_L_C();

	// INI
	inline void INI();

	// INIR
	inline void INIR();

	// IND
	inline void IND();

	// INDR
	inline void INDR();

	// OUT (n), A
	inline void OUT_N_A();

	// OUT (C), r
	inline void OUT_C_A();
	inline void OUT_C_B();
	inline void OUT_C_C();
	inline void OUT_C_D();
	inline void OUT_C_E();
	inline void OUT_C_H();
	inline void OUT_C_L();

	// OTIR
	inline void OTIR();

	// OUTD
	inline void OUTD();

	// OTDR
	inline void OTDR();


	// Not opcodes
	// Opcode groupings
	inline void BITS_group();
	inline void IX_group();
	inline void IY_group();
	inline void EXTD_group();


};
#endif