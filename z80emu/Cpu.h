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
	// return uuint16_t16_t address of next instruction
	// TODO: look into generating specialized method implementations from generic function template for each opcode (actual template<> or just generic method)

	// LD r, r' instruction opcodes
	uint16_t LD_A_A();
	uint16_t LD_A_B();
	uint16_t LD_A_C();
	uint16_t LD_A_D();
	uint16_t LD_A_E();
	uint16_t LD_A_H();
	uint16_t LD_A_L();

	uint16_t LD_B_A();
	uint16_t LD_B_B();
	uint16_t LD_B_C();
	uint16_t LD_B_D();
	uint16_t LD_B_E();
	uint16_t LD_B_H();
	uint16_t LD_B_L();

	uint16_t LD_C_A();
	uint16_t LD_C_B();
	uint16_t LD_C_C();
	uint16_t LD_C_D();
	uint16_t LD_C_E();
	uint16_t LD_C_H();
	uint16_t LD_C_L();

	uint16_t LD_D_A();
	uint16_t LD_D_B();
	uint16_t LD_D_C();
	uint16_t LD_D_D();
	uint16_t LD_D_E();
	uint16_t LD_D_H();
	uint16_t LD_D_L();

	uint16_t LD_E_A();
	uint16_t LD_E_B();
	uint16_t LD_E_C();
	uint16_t LD_E_D();
	uint16_t LD_E_E();
	uint16_t LD_E_H();
	uint16_t LD_E_L();

	uint16_t LD_H_A();
	uint16_t LD_H_B();
	uint16_t LD_H_C();
	uint16_t LD_H_D();
	uint16_t LD_H_E();
	uint16_t LD_H_H();
	uint16_t LD_H_L();

	uint16_t LD_L_A();
	uint16_t LD_L_B();
	uint16_t LD_L_C();
	uint16_t LD_L_D();
	uint16_t LD_L_E();
	uint16_t LD_L_H();
	uint16_t LD_L_L();

	// LD r, n instructions
	// (where n is immediate contained in PC + 1)
	uint16_t LD_A_N();
	uint16_t LD_B_N();
	uint16_t LD_C_N();
	uint16_t LD_D_N();
	uint16_t LD_E_N();
	uint16_t LD_H_N();
	uint16_t LD_L_N();

	// LD r, (HL)
	// Load contents of memory at address contained in (HL) to register r
	uint16_t LD_A_HL();
	uint16_t LD_B_HL();
	uint16_t LD_C_HL();
	uint16_t LD_D_HL();
	uint16_t LD_E_HL();
	uint16_t LD_H_HL();
	uint16_t LD_L_HL();

	// LD r, (IX+d)
	// first LD_R_IXd
	// then LD r, (HL)

	// LD r, (IY+d)
	// first LD_R_IYd
	// then LD_R_HL

	// LD r, (IX+d)
	// Load contents of memory stored in address (IX+d)
	// where d is a signed 8 bit uint16_teger
	// first LD_R_IXd
	uint16_t LD_R_IXd();

	// LD r, (IY+d)
	// Load contents of memory stored in address (IY+d)
	// where d is a signed 8 bit uint16_teger
	// first LD_R_IYd
	uint16_t LD_R_IYd();

	// LD (HL), r
	// Load contents of register r uint16_to address contained in (HL)
	uint16_t LD_HL_A();
	uint16_t LD_HL_B();
	uint16_t LD_HL_C();
	uint16_t LD_HL_D();
	uint16_t LD_HL_E();
	uint16_t LD_HL_H();
	uint16_t LD_HL_L();

	// LD (IX+d), r
	// Store contents of register r to memory address stored in address(IX + d)
	// where d is a signed 8 bit uint16_teger offset
	uint16_t LD_IXd_R(); // DO NOT USE, same as LD_R_IXd

	// LD (IX+d), r
	// Store contents of register r to memory address stored in address(IY + d)
	// where d is a signed 8 bit uint16_teger offset
	uint16_t LD_IYd_R(); // DO NOT USE, same as LD_R_IYd

	// LD (HL), n
	// Store an immediate value, n, uint16_to the memory address contained in HL
	uint16_t LD_HL_N();

	// LD (IX+d), n
	// Store an immediate value, n, uint16_to the memory address calculated from IX + d
	// where d is a signed 8-bit offset
	// todo: add in later, since it's just 6xDD and 6x36 again

	// LD (IY+d), n
	// Store an immediate value, n, uint16_to the memory address calculated from IY + d
	// where d is a signed 8-bit offset
	// todo: add in later, since it's just 6xFD and 6x36 again

	// LD A, (BC)
	// Load contents of memory, stored at address contained in BC, to register A
	uint16_t LD_A_BC();

	// LD A, (DE)
	// Load contents of memory, stored at address contained in DE, to register A
	uint16_t LD_A_DE();

	// LD A, (nn)
	// Load contents of memory, indicated at the address nn, to register A
	uint16_t LD_A_NN();

	// LD (BC), A
	// Store contents of register A to memory address contained in BC
	uint16_t LD_BC_A();

	// LD (DE), A
	// Store contents of register A to memory address contained in DE
	uint16_t LD_DE_A();

	// LD (nn), A
	// Store contents of register A to address indicated by nn
	uint16_t LD_NN_A();

	// LD A, I
	// Load contents of uint16_terrupt Vector register I uint16_to A
	// Also used for LD A, R; LD I, A; LD R, A
	uint16_t LD_A_I();


	// 16-bit load instructions

	// LD dd, nn
	// Load 2 byte immediate nn uint16_to register dd
	uint16_t LD_BC_NN(); // to BC
	uint16_t LD_DE_NN(); // to DE
	uint16_t LD_HL_NN(); // to HL
	uint16_t LD_SP_NN(); // to SP

	// LD IX, nn
	// Load nn uint16_to index register IX
	// first opcode is 6xDD
	// then 6x21


	// LD IY, nn
	// Load nn uint16_to index register IY
	// 6xFD then 6x21

	// LD HL, (nn)
	uint16_t LD_HL_NN_ADDR();

	// LD dd, (nn)
	// 6xed, then:
	uint16_t LD_HL_NN_ADDR_2();
	uint16_t LD_BC_NN_ADDR();
	uint16_t LD_DE_NN_ADDR();
	uint16_t LD_SP_NN_ADDR();

	// LD IX, (nn)
	// first LD_R_IXd
	// then LD_HL_NN
	// 4 bytes

	// LD IY, (nn)
	// same as previous but with LD_R_IYd

	// LD (nn), HL
	uint16_t LD_NN_HL();

	//LD (nn), dd
	// first LD_A_I
	//then
	uint16_t LD_NN_BC_ADDR();
	uint16_t LD_NN_DE_ADDR();
	uint16_t LD_NN_HL_ADDR();
	uint16_t LD_NN_SP_ADDR();

	// LD (nn), IX
	// first LD_IXd_R
	// then LD_NN_HL
	// then 2 bytes

	// LD SP, HL
	uint16_t LD_SP_HL();

	// LD SP, IX
	// first LD_R_IXd
	// then LD_SP_HL

	// LD SP, IY
	// first LD_R_IYd
	// then LD_SP_HL

	// PUSH qq
	uint16_t PUSH_BC();
	uint16_t PUSH_DE();
	uint16_t PUSH_HL();
	uint16_t PUSH_AF();

	// PUSH IX
	// first LD_R_IXd
	// then PUSH_HL

	// PUSH IY
	// first LD_R_IYd
	// then PUSH_HL

	// POP qq
	uint16_t POP_BC();
	uint16_t POP_DE();
	uint16_t POP_HL();
	uint16_t POP_AF();

	// POP IX
	// first LD_R_IXd
	// THEN POP HL

	// POP IY
	// first LD_R_IYd
	// THEN POP HL

	// Exchange, block transfer, and search instructions

	// EX DE, HL
	uint16_t EX_DE_HL();

	// EX AF, AF'
	uint16_t EX_AF_AF();

	// EXX
	uint16_t EXX();

	// EX (SP), HL
	uint16_t EX_SP_HL();

	// EX (SP), IX
	// first LD_R_IXd
	// then EX_SP_HL

	// EX (SP), IY
	// first LD_R_IYd
	// then EX_SP_HL

	// LDI
	// first LD_A_I
	uint16_t LDI();

	// LDIR
	// first LD_A_I
	uint16_t LDIR();

	// LDD
	// first LD_A_I
	uint16_t LDD();

	// LDDR
	// first LD_A_I
	uint16_t LDDR();

	// CPI
	// first LD_A_I
	uint16_t CPI();

	// CPIR
	// first LD_A_I
	uint16_t CPIR();

	// CPD
	// first LD_A_I
	// then
	uint16_t CPD();

	// CPDR
	// first LD_A_I
	// then
	uint16_t CPDR();

	// ADD A, r
	uint16_t ADD_A_A();
	uint16_t ADD_A_B();
	uint16_t ADD_A_C();
	uint16_t ADD_A_D();
	uint16_t ADD_A_E();
	uint16_t ADD_A_H();
	uint16_t ADD_A_L();

	// ADD A, n
	uint16_t ADD_A_N();

	// ADD A, (HL)
	uint16_t ADD_A_HL();

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
	uint16_t ADC_A_A();
	uint16_t ADC_A_B();
	uint16_t ADC_A_C();
	uint16_t ADC_A_D();
	uint16_t ADC_A_E();
	uint16_t ADC_A_H();
	uint16_t ADC_A_L();

	// ADC A, n
	uint16_t ADC_A_N();

	// ADC A, (HL)
	uint16_t ADC_A_HL();

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
	uint16_t SUB_A();
	uint16_t SUB_B();
	uint16_t SUB_C();
	uint16_t SUB_D();
	uint16_t SUB_E();
	uint16_t SUB_H();
	uint16_t SUB_L();

	// SUB n
	uint16_t SUB_N();

	// SUB (HL)
	uint16_t SUB_HL();

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
	uint16_t SBC_A_A();
	uint16_t SBC_A_B();
	uint16_t SBC_A_C();
	uint16_t SBC_A_D();
	uint16_t SBC_A_E();
	uint16_t SBC_A_H();
	uint16_t SBC_A_L();

	// SBC A, n
	uint16_t SBC_A_N();

	// SBC A, (HL)
	uint16_t SBC_A_HL();

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
	uint16_t AND_A();
	uint16_t AND_B();
	uint16_t AND_C();
	uint16_t AND_D();
	uint16_t AND_E();
	uint16_t AND_H();
	uint16_t AND_L();

	// AND n
	uint16_t AND_N();

	// AND (HL)
	uint16_t AND_HL();

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
	uint16_t OR_A();
	uint16_t OR_B();
	uint16_t OR_C();
	uint16_t OR_D();
	uint16_t OR_E();
	uint16_t OR_H();
	uint16_t OR_L();

	// OR n
	uint16_t OR_N();

	// OR (HL)
	uint16_t OR_HL();

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
	uint16_t XOR_A();
	uint16_t XOR_B();
	uint16_t XOR_C();
	uint16_t XOR_D();
	uint16_t XOR_E();
	uint16_t XOR_H();
	uint16_t XOR_L();

	// XOR n
	uint16_t XOR_N();

	// XOR (HL)
	uint16_t XOR_HL(); // I think, confirm later

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
	uint16_t CP_A();
	uint16_t CP_B();
	uint16_t CP_C();
	uint16_t CP_D();
	uint16_t CP_E();
	uint16_t CP_H();
	uint16_t CP_L();

	// CP n
	uint16_t CP_N();

	// CP (HL)
	uint16_t CP_HL();

	// CP (IX + d)
	// first LD_IXd_R
	// then CP_HL
	// then d

	// CP (IY + d)
	// first LD_IYd_R
	// then CP_HL
	// then d

	// INC r
	uint16_t INC_A();
	uint16_t INC_B();
	uint16_t INC_C();
	uint16_t INC_D();
	uint16_t INC_E();
	uint16_t INC_H();
	uint16_t INC_L();

	// INC (HL)
	uint16_t INC_HL_ADDR();

	// INC (IX + d)
	// first LD_IXd_R
	// then INC (HL) INC_HL_ADDR

	// INC (IY + d)
	// first LD_IYd_R
	// then INC (HL) INC_HL_ADDR

	// DEC m: opcode group
	// DEC r'
	uint16_t DEC_A();
	uint16_t DEC_B();
	uint16_t DEC_C();
	uint16_t DEC_D();
	uint16_t DEC_E();
	uint16_t DEC_H();
	uint16_t DEC_L();

	// DEC (HL)
	uint16_t DEC_HL_ADDR();

	// DEC (IX + d)
	// first LD_IXd_R
	// then DEC_HL_ADDR

	// DEC (IY + d)
	// first LD_IYd_R
	// then DEC_HL_ADDR

	// General purpose Arithmetic and CPU Control

	// DAA
	uint16_t DAA();

	// CPL
	uint16_t CPL();

	// NEG
	// first LD_A_I
	// then
	uint16_t NEG();

	// CCF
	uint16_t CCF();

	// SCF
	uint16_t SCF();

	// NOP
	uint16_t NOP();

	// HALT
	uint16_t HALT();

	// DI
	uint16_t DI();

	// EI
	uint16_t EI();

	// IM 6
	// first LD_A_I
	uint16_t IM_6();

	// IM 1
	// first LD_A_I
	uint16_t IM_1();

	// IM 2
	// first LD_A_I
	uint16_t IM_2();

	// 16-Bit Arithmetic Group

	// ADD HL, ss
	uint16_t ADD_HL_BC();
	uint16_t ADD_HL_DE();
	uint16_t ADD_HL_HL();
	uint16_t ADD_HL_SP();

	// ADC HL, ss
	// first LD_A_I
	// then
	uint16_t ADC_HL_BC();
	uint16_t ADC_HL_DE();
	uint16_t ADC_HL_HL();
	uint16_t ADC_HL_SP();

	// SBC HL, ss
	// first LD_A_I
	// then
	uint16_t SBC_HL_BC();
	uint16_t SBC_HL_DE();
	uint16_t SBC_HL_HL();
	uint16_t SBC_HL_SP();

	// ADD IX, pp
	// first LD_IXd_R
	// then ADD_HL_SS
	uint16_t ADD_IX_BC();
	uint16_t ADD_IX_DE();
	uint16_t ADD_IX_HL();
	uint16_t ADD_IX_SP();

	// ADD IY, pp
	// first LD_IYd_R
	// then ADD_HL_SS
	uint16_t ADD_IY_BC();
	uint16_t ADD_IY_DE();
	uint16_t ADD_IY_HL();
	uint16_t ADD_IY_SP();

	// INC ss
	uint16_t INC_BC();
	uint16_t INC_DE();
	uint16_t INC_HL();
	uint16_t INC_SP();

	// INC IX
	// first LD_IXd_R
	uint16_t INC_IX();

	// INC IY
	// first LD_IYd_R
	uint16_t INC_IY();

	// DEC ss
	uint16_t DEC_BC();
	uint16_t DEC_DE();
	uint16_t DEC_HL();
	uint16_t DEC_SP();

	// DEC IX
	// first LD_IXd_R
	uint16_t DEC_IX();

	// DEC IY
	// first LD_IYd_R
	uint16_t DEC_IY();

	// Rotate and Shift Group

	// RLCA
	uint16_t RCLA();

	// RLA
	uint16_t RLA();

	// RRCA
	uint16_t RRCA();

	// RRA
	uint16_t RRA();

	// RLC r
	//first
	uint16_t RLC_R();
	// then any of 
	uint16_t RLC_A();
	uint16_t RLC_B();
	uint16_t RLC_C();
	uint16_t RLC_D();
	uint16_t RLC_E();
	uint16_t RLC_H();
	uint16_t RLC_L();

	// RLC (HL)
	// first RLC_R
	uint16_t RLC_HL();

	// RLC (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then d
	uint16_t RLC_IXd();

	// RLC (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then d
	uint16_t RLC_IYd();

	// RL m: opcode group

	// RL r'
	// first RLC_R
	// then any of
	uint16_t RL_A();
	uint16_t RL_B();
	uint16_t RL_C();
	uint16_t RL_D();
	uint16_t RL_E();
	uint16_t RL_H();
	uint16_t RL_L();

	// RL (HL)
	// first RLC_R
	uint16_t RL_HL();

	// RL (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then d
	uint16_t RL_IXd();

	// RL (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then d
	uint16_t RL_IYd();

	//RRC m: opcode group

	// RRC r'
	// first RLC_R
	// then one of
	uint16_t RRC_A();
	uint16_t RRC_B();
	uint16_t RRC_C();
	uint16_t RRC_D();
	uint16_t RRC_E();
	uint16_t RRC_H();
	uint16_t RRC_L();

	// RRC (HL)
	// first RLC_R
	uint16_t RRC_HL();

	// RRC (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	uint16_t RRC_IXd();

	// RRC (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	uint16_t RRC_IYd();

	// RR m: opcode group

	// RR r'
	// first RLC_R
	// then
	uint16_t RR_A();
	uint16_t RR_B();
	uint16_t RR_C();
	uint16_t RR_D();
	uint16_t RR_E();
	uint16_t RR_H();
	uint16_t RR_L();

	// RR (HL)
	// first RLC_R
	uint16_t RR_HL();

	// RR (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	uint16_t RR_IXd();

	// RR (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	uint16_t RR_IYd();

	// SLA m: opcode group

	// SLA r'
	// first RLC_R
	// then any of
	uint16_t SLA_A();
	uint16_t SLA_B();
	uint16_t SLA_C();
	uint16_t SLA_D();
	uint16_t SLA_E();
	uint16_t SLA_H();
	uint16_t SLA_L();

	// SLA (HL)
	// first RLC_R
	// then
	uint16_t SLA_HL();

	// SLA (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	uint16_t SLA_IXd();

	// SLA (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	uint16_t SLA_IYd();

	// SRA m: opcode group

	// SRA r'
	// first RLC_R
	// then any of
	uint16_t SRA_A();
	uint16_t SRA_B();
	uint16_t SRA_C();
	uint16_t SRA_D();
	uint16_t SRA_E();
	uint16_t SRA_H();
	uint16_t SRA_L();

	// SRA (HL)
	// first RLC_R
	// then
	uint16_t SRA_HL();

	// SRA (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	uint16_t SRA_IXd();

	// SRA (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	uint16_t SRA_IYd();

	// SRL m: opcode group

	// SRL r'
	// first RLC_R
	// then any of
	uint16_t SRL_A();
	uint16_t SRL_B();
	uint16_t SRL_C();
	uint16_t SRL_D();
	uint16_t SRL_E();
	uint16_t SRL_H();
	uint16_t SRL_L();

	// SRL (HL)
	// first RLC_R
	// then
	uint16_t SRL_HL();

	// SRL (IX + d)
	// first LD_IXd_R
	// then RLC_R
	// then D
	uint16_t SRL_IXd();

	// SRL (IY + d)
	// first LD_IYd_R
	// then RLC_R
	// then D
	uint16_t SRL_IYd();

	// RLD
	// first LD_A_I
	uint16_t RLD();

	// RRD
	// first LD_A_I
	uint16_t RRD();


	// Bit Set, Reset, and Test Group
	// bit b, r
	uint16_t BIT_0_A();
	uint16_t BIT_0_B();
	uint16_t BIT_0_C();
	uint16_t BIT_0_D();
	uint16_t BIT_0_E();
	uint16_t BIT_0_H();
	uint16_t BIT_0_L();

	uint16_t BIT_1_A();
	uint16_t BIT_1_B();
	uint16_t BIT_1_C();
	uint16_t BIT_1_D();
	uint16_t BIT_1_E();
	uint16_t BIT_1_H();
	uint16_t BIT_1_L();

	uint16_t BIT_2_A();
	uint16_t BIT_2_B();
	uint16_t BIT_2_C();
	uint16_t BIT_2_D();
	uint16_t BIT_2_E();
	uint16_t BIT_2_H();
	uint16_t BIT_2_L();

	uint16_t BIT_3_A();
	uint16_t BIT_3_B();
	uint16_t BIT_3_C();
	uint16_t BIT_3_D();
	uint16_t BIT_3_E();
	uint16_t BIT_3_H();
	uint16_t BIT_3_L();

	uint16_t BIT_4_A();
	uint16_t BIT_4_B();
	uint16_t BIT_4_C();
	uint16_t BIT_4_D();
	uint16_t BIT_4_E();
	uint16_t BIT_4_H();
	uint16_t BIT_4_L();

	uint16_t BIT_5_A();
	uint16_t BIT_5_B();
	uint16_t BIT_5_C();
	uint16_t BIT_5_D();
	uint16_t BIT_5_E();
	uint16_t BIT_5_H();
	uint16_t BIT_5_L();

	uint16_t BIT_6_A();
	uint16_t BIT_6_B();
	uint16_t BIT_6_C();
	uint16_t BIT_6_D();
	uint16_t BIT_6_E();
	uint16_t BIT_6_H();
	uint16_t BIT_6_L();

	uint16_t BIT_7_A();
	uint16_t BIT_7_B();
	uint16_t BIT_7_C();
	uint16_t BIT_7_D();
	uint16_t BIT_7_E();
	uint16_t BIT_7_H();
	uint16_t BIT_7_L();

	// BIT b, (HL)
	uint16_t BIT_0_HL();
	uint16_t BIT_1_HL();
	uint16_t BIT_2_HL();
	uint16_t BIT_3_HL();
	uint16_t BIT_4_HL();
	uint16_t BIT_5_HL();
	uint16_t BIT_6_HL();
	uint16_t BIT_7_HL();

	// Bit b, (IX + d)
	uint16_t BIT_0_IXd();
	uint16_t BIT_1_IXd();
	uint16_t BIT_2_IXd();
	uint16_t BIT_3_IXd();
	uint16_t BIT_4_IXd();
	uint16_t BIT_5_IXd();
	uint16_t BIT_6_IXd();
	uint16_t BIT_7_IXd();

	// Bit b, (IY + d)
	uint16_t BIT_0_IYd();
	uint16_t BIT_1_IYd();
	uint16_t BIT_2_IYd();
	uint16_t BIT_3_IYd();
	uint16_t BIT_4_IYd();
	uint16_t BIT_5_IYd();
	uint16_t BIT_6_IYd();
	uint16_t BIT_7_IYd();

	// SET b, r
	uint16_t SET_0_A();
	uint16_t SET_0_B();
	uint16_t SET_0_C();
	uint16_t SET_0_D();
	uint16_t SET_0_E();
	uint16_t SET_0_H();
	uint16_t SET_0_L();

	uint16_t SET_1_A();
	uint16_t SET_1_B();
	uint16_t SET_1_C();
	uint16_t SET_1_D();
	uint16_t SET_1_E();
	uint16_t SET_1_H();
	uint16_t SET_1_L();

	uint16_t SET_2_A();
	uint16_t SET_2_B();
	uint16_t SET_2_C();
	uint16_t SET_2_D();
	uint16_t SET_2_E();
	uint16_t SET_2_H();
	uint16_t SET_2_L();

	uint16_t SET_3_A();
	uint16_t SET_3_B();
	uint16_t SET_3_C();
	uint16_t SET_3_D();
	uint16_t SET_3_E();
	uint16_t SET_3_H();
	uint16_t SET_3_L();

	uint16_t SET_4_A();
	uint16_t SET_4_B();
	uint16_t SET_4_C();
	uint16_t SET_4_D();
	uint16_t SET_4_E();
	uint16_t SET_4_H();
	uint16_t SET_4_L();

	uint16_t SET_5_A();
	uint16_t SET_5_B();
	uint16_t SET_5_C();
	uint16_t SET_5_D();
	uint16_t SET_5_E();
	uint16_t SET_5_H();
	uint16_t SET_5_L();

	uint16_t SET_6_A();
	uint16_t SET_6_B();
	uint16_t SET_6_C();
	uint16_t SET_6_D();
	uint16_t SET_6_E();
	uint16_t SET_6_H();
	uint16_t SET_6_L();

	uint16_t SET_7_A();
	uint16_t SET_7_B();
	uint16_t SET_7_C();
	uint16_t SET_7_D();
	uint16_t SET_7_E();
	uint16_t SET_7_H();
	uint16_t SET_7_L();

	// SET b, (HL)
	uint16_t SET_A_HL();
	uint16_t SET_B_HL();
	uint16_t SET_C_HL();
	uint16_t SET_D_HL();
	uint16_t SET_E_HL();
	uint16_t SET_H_HL();
	uint16_t SET_L_HL();

	// SET b, (IX + d)
	uint16_t SET_A_IXd();
	uint16_t SET_B_IXd();
	uint16_t SET_C_IXd();
	uint16_t SET_D_IXd();
	uint16_t SET_E_IXd();
	uint16_t SET_H_IXd();
	uint16_t SET_L_IXd();

	// SET b, (IY + d)
	uint16_t SET_A_IYd();
	uint16_t SET_B_IYd();
	uint16_t SET_C_IYd();
	uint16_t SET_D_IYd();
	uint16_t SET_E_IYd();
	uint16_t SET_H_IYd();
	uint16_t SET_L_IYd();

	// RES b, m
	uint16_t RES_0_A();
	uint16_t RES_0_B();
	uint16_t RES_0_C();
	uint16_t RES_0_D();
	uint16_t RES_0_E();
	uint16_t RES_0_H();
	uint16_t RES_0_L();

	uint16_t RES_1_A();
	uint16_t RES_1_B();
	uint16_t RES_1_C();
	uint16_t RES_1_D();
	uint16_t RES_1_E();
	uint16_t RES_1_H();
	uint16_t RES_1_L();

	uint16_t RES_2_A();
	uint16_t RES_2_B();
	uint16_t RES_2_C();
	uint16_t RES_2_D();
	uint16_t RES_2_E();
	uint16_t RES_2_H();
	uint16_t RES_2_L();

	uint16_t RES_3_A();
	uint16_t RES_3_B();
	uint16_t RES_3_C();
	uint16_t RES_3_D();
	uint16_t RES_3_E();
	uint16_t RES_3_H();
	uint16_t RES_3_L();

	uint16_t RES_4_A();
	uint16_t RES_4_B();
	uint16_t RES_4_C();
	uint16_t RES_4_D();
	uint16_t RES_4_E();
	uint16_t RES_4_H();
	uint16_t RES_4_L();

	uint16_t RES_5_A();
	uint16_t RES_5_B();
	uint16_t RES_5_C();
	uint16_t RES_5_D();
	uint16_t RES_5_E();
	uint16_t RES_5_H();
	uint16_t RES_5_L();

	uint16_t RES_6_A();
	uint16_t RES_6_B();
	uint16_t RES_6_C();
	uint16_t RES_6_D();
	uint16_t RES_6_E();
	uint16_t RES_6_H();
	uint16_t RES_6_L();

	uint16_t RES_7_A();
	uint16_t RES_7_B();
	uint16_t RES_7_C();
	uint16_t RES_7_D();
	uint16_t RES_7_E();
	uint16_t RES_7_H();
	uint16_t RES_7_L();

	// RES b, (HL)
	uint16_t RES_0_HL();
	uint16_t RES_1_HL();
	uint16_t RES_2_HL();
	uint16_t RES_3_HL();
	uint16_t RES_4_HL();
	uint16_t RES_5_HL();
	uint16_t RES_6_HL();
	uint16_t RES_7_HL();

	// RES b, (IX + d)
	uint16_t RES_0_IXd();
	uint16_t RES_1_IXd();
	uint16_t RES_2_IXd();
	uint16_t RES_3_IXd();
	uint16_t RES_4_IXd();
	uint16_t RES_5_IXd();
	uint16_t RES_6_IXd();
	uint16_t RES_7_IXd();

	// RES b, (IY + d)
	uint16_t RES_0_IYd();
	uint16_t RES_1_IYd();
	uint16_t RES_2_IYd();
	uint16_t RES_3_IYd();
	uint16_t RES_4_IYd();
	uint16_t RES_5_IYd();
	uint16_t RES_6_IYd();
	uint16_t RES_7_IYd();

	// Jump group

	// JP nn
	uint16_t JP_nn();

	// JP cc, nn
	uint16_t JP_NZ_nn();
	uint16_t JP_Z_nn();
	uint16_t JP_NC_nn();
	uint16_t JP_C_nn();
	uint16_t JP_PO_nn();
	uint16_t JP_PE_nn();
	uint16_t JP_P_nn();
	uint16_t JP_M_nn();

	// JR e
	uint16_t JR_e();
	
	// JR C, e
	uint16_t JR_C_e();

	// JR NC, e
	uint16_t JR_NC_e();

	// JR Z, e
	uint16_t JR_Z_e();

	// JR NZ, e
	uint16_t JR_NZ_e();

	// JP (HL)
	uint16_t JP_HL();

	// JP (IX)
	uint16_t JP_IX();

	// JP (IY)
	uint16_t JP_IY();

	// DJNZ, e
	uint16_t DJNZ_e();

	// Call and Return Group
	// CALL nn
	uint16_t CALL_nn();

	// CALL cc, nn
	uint16_t CALL_NZ_nn();
	uint16_t CALL_Z_nn();
	uint16_t CALL_NC_nn();
	uint16_t CALL_C_nn();
	uint16_t CALL_PO_nn();
	uint16_t CALL_PE_nn();
	uint16_t CALL_P_nn();
	uint16_t CALL_M_nn();

	// RET
	uint16_t RET();

	// RET cc
	uint16_t RET_NZ();
	uint16_t RET_Z();
	uint16_t RET_NC();
	uint16_t RET_C();
	uint16_t RET_PO();
	uint16_t RET_PE();
	uint16_t RET_P();
	uint16_t RET_M();

	// RETI
	uint16_t RETI();

	// RETN
	uint16_t RETN();

	// RST p
	uint16_t RST_00h();
	uint16_t RST_08h();
	uint16_t RST_10h();
	uint16_t RST_18h();
	uint16_t RST_20h();
	uint16_t RST_28h();
	uint16_t RST_30h();
	uint16_t RST_38h();

	// Input and Output Group
	
	// IN A, (n)
	uint16_t IN_A();

	// IN r (C)
	uint16_t IN_A_C();
	uint16_t IN_B_C();
	uint16_t IN_C_C();
	uint16_t IN_D_C();
	uint16_t IN_E_C();
	uint16_t IN_F_C();
	uint16_t IN_H_C();
	uint16_t IN_L_C();

	// INI
	uint16_t INI();

	// INIR
	uint16_t INIR();

	// IND
	uint16_t IND();

	// INDR
	uint16_t INDR();

	// OUT (n), A
	uint16_t OUT_N_A();

	// OUT (C), r
	uint16_t OUT_C_A();
	uint16_t OUT_C_B();
	uint16_t OUT_C_C();
	uint16_t OUT_C_D();
	uint16_t OUT_C_E();
	uint16_t OUT_C_H();
	uint16_t OUT_C_L();

	// OTIR
	uint16_t OTIR();

	// OUTD
	uint16_t OUTD();

	// OTDR
	uint16_t OTDR();


	// Not opcodes
	// Opcode groupings
	uint16_t BITS_group();
	uint16_t IX_group();
	uint16_t IY_group();
	uint16_t EXTD_group();


};
#endif