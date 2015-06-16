#include "stdafx.h"
#include "Cpu.h"
#include "opcodes.h"
#include "Registers.h"
#include "RegisterEnums.h"

void Cpu::execute() {
	// zero all registers
	_registers.zero();
	typedef void (Cpu::*opcode)(void);

	static opcode array[] = {
			// 0x00
			{ &Cpu::NOP }, // 0x01
			{ &Cpu::LD_BC_NN }, // 0x02
			{ &Cpu::LD_BC_NN_ADDR },
			{ &Cpu::INC_BC },
			{ &Cpu::INC_B },
			{ &Cpu::DEC_B },
			{ &Cpu::LD_B_N },
			{ &Cpu::RCLA },
			{ &Cpu::EX_AF_AF },
			{ &Cpu::ADD_HL_BC },
			{ &Cpu::LD_A_BC },
			{ &Cpu::DEC_BC },
			{ &Cpu::INC_C },
			{ &Cpu::DEC_C },
			{ &Cpu::LD_C_N },
			{ &Cpu::RRCA },
			// 0x10
			{ &Cpu::DJNZ_e },
			{ &Cpu::LD_DE_NN },
			{ &Cpu::LD_DE_A },
			{ &Cpu::INC_DE },
			{ &Cpu::INC_D },
			{ &Cpu::DEC_D },
			{ &Cpu::LD_D_N },
			{ &Cpu::RLA },
			{ &Cpu::JR_e },
			{ &Cpu::ADD_HL_DE },
			{ &Cpu::LD_A_DE },
			{ &Cpu::DEC_DE },
			{ &Cpu::INC_E },
			{ &Cpu::DEC_E },
			{ &Cpu::LD_E_N },
			{ &Cpu::RRA },
			// 0x20
			{ &Cpu::JR_NZ_e },
			{ &Cpu::LD_HL_NN },
			{ &Cpu::LD_HL_NN },
			{ &Cpu::LD_NN_HL },
			{ &Cpu::INC_HL },
			{ &Cpu::INC_H },
			{ &Cpu::DEC_H },
			{ &Cpu::LD_H_N },
			{ &Cpu::DAA },
			{ &Cpu::JR_Z_e },
			{ &Cpu::ADD_HL_HL },
			{ &Cpu::LD_HL_NN_ADDR },
			{ &Cpu::DEC_HL },
			{ &Cpu::INC_L },
			{ &Cpu::DEC_L },
			{ &Cpu::LD_L_N },
			{ &Cpu::CPL },
			// 0x30
			{ &Cpu::JR_NC_e },
			{ &Cpu::LD_SP_NN },
			{ &Cpu::LD_NN_A },
			{ &Cpu::INC_SP },
			{ &Cpu::INC_HL_ADDR },
			{ &Cpu::DEC_HL_ADDR },
			{ &Cpu::LD_HL_N },
			{ &Cpu::SCF },
			{ &Cpu::JR_C_e },
			{ &Cpu::ADD_HL_SP },
			{ &Cpu::LD_A_NN },
			{ &Cpu::DEC_SP },
			{ &Cpu::INC_A },
			{ &Cpu::DEC_A },
			{ &Cpu::LD_A_N },
			{ &Cpu::CCF },
			// 0x40
			{ &Cpu::LD_B_B },
			{ &Cpu::LD_B_C },
			{ &Cpu::LD_B_D },
			{ &Cpu::LD_B_E },
			{ &Cpu::LD_B_H },
			{ &Cpu::LD_B_L },
			{ &Cpu::LD_B_HL },
			{ &Cpu::LD_B_A },
			{ &Cpu::LD_C_B },
			{ &Cpu::LD_C_C },
			{ &Cpu::LD_C_D },
			{ &Cpu::LD_C_E },
			{ &Cpu::LD_C_H },
			{ &Cpu::LD_C_L },
			{ &Cpu::LD_C_HL },
			{ &Cpu::LD_C_A },
			// 0x50
			{ &Cpu::LD_D_B },
			{ &Cpu::LD_D_C },
			{ &Cpu::LD_D_D },
			{ &Cpu::LD_D_E },
			{ &Cpu::LD_D_H },
			{ &Cpu::LD_D_L },
			{ &Cpu::LD_D_HL },
			{ &Cpu::LD_D_A },
			{ &Cpu::LD_E_B },
			{ &Cpu::LD_E_C },
			{ &Cpu::LD_E_D },
			{ &Cpu::LD_E_E },
			{ &Cpu::LD_E_H },
			{ &Cpu::LD_E_L },
			{ &Cpu::LD_E_HL },
			{ &Cpu::LD_E_A },
			// 0x60
			{ &Cpu::LD_H_B },
			{ &Cpu::LD_H_C },
			{ &Cpu::LD_H_D },
			{ &Cpu::LD_H_E },
			{ &Cpu::LD_H_H },
			{ &Cpu::LD_H_L },
			{ &Cpu::LD_H_HL },
			{ &Cpu::LD_H_A },
			{ &Cpu::LD_L_B },
			{ &Cpu::LD_L_C },
			{ &Cpu::LD_L_D },
			{ &Cpu::LD_L_E },
			{ &Cpu::LD_L_H },
			{ &Cpu::LD_L_L },
			{ &Cpu::LD_L_HL },
			{ &Cpu::LD_L_A },
			// 0x70
			{ &Cpu::LD_HL_B },
			{ &Cpu::LD_HL_C },
			{ &Cpu::LD_HL_D },
			{ &Cpu::LD_HL_E },
			{ &Cpu::LD_HL_H },
			{ &Cpu::LD_HL_L },
			{ &Cpu::HALT },
			{ &Cpu::LD_HL_A },
			{ &Cpu::LD_A_B },
			{ &Cpu::LD_A_C },
			{ &Cpu::LD_A_D },
			{ &Cpu::LD_A_E },
			{ &Cpu::LD_A_H },
			{ &Cpu::LD_A_L },
			{ &Cpu::LD_A_HL },
			{ &Cpu::LD_A_A },
			// 0x80
			{ &Cpu::ADD_A_B },
			{ &Cpu::ADD_A_C },
			{ &Cpu::ADD_A_D },
			{ &Cpu::ADD_A_E },
			{ &Cpu::ADD_A_H },
			{ &Cpu::ADD_A_L },
			{ &Cpu::ADD_A_HL },
			{ &Cpu::ADD_A_A },
			{ &Cpu::ADC_A_B },
			{ &Cpu::ADC_A_C },
			{ &Cpu::ADC_A_D },
			{ &Cpu::ADC_A_E },
			{ &Cpu::ADC_A_H },
			{ &Cpu::ADC_A_L },
			{ &Cpu::ADC_A_HL },
			{ &Cpu::ADC_A_A },
			// 0x90
			{ &Cpu::SUB_B },
			{ &Cpu::SUB_C },
			{ &Cpu::SUB_D },
			{ &Cpu::SUB_E },
			{ &Cpu::SUB_H },
			{ &Cpu::SUB_L },
			{ &Cpu::SUB_HL },
			{ &Cpu::SUB_A },
			{ &Cpu::SBC_A_B },
			{ &Cpu::SBC_A_C },
			{ &Cpu::SBC_A_D },
			{ &Cpu::SBC_A_E },
			{ &Cpu::SBC_A_H },
			{ &Cpu::SBC_A_L },
			{ &Cpu::SBC_A_HL },
			{ &Cpu::SBC_A_A },
			// 0xA0
			{ &Cpu::AND_B },
			{ &Cpu::AND_C },
			{ &Cpu::AND_D },
			{ &Cpu::AND_E },
			{ &Cpu::AND_H },
			{ &Cpu::AND_L },
			{ &Cpu::AND_HL },
			{ &Cpu::AND_A },
			{ &Cpu::XOR_B },
			{ &Cpu::XOR_C },
			{ &Cpu::XOR_D },
			{ &Cpu::XOR_E },
			{ &Cpu::XOR_H },
			{ &Cpu::XOR_L },
			{ &Cpu::XOR_HL },
			{ &Cpu::XOR_A },
			// 0xB0
			{ &Cpu::OR_B },
			{ &Cpu::OR_C },
			{ &Cpu::OR_D },
			{ &Cpu::OR_E },
			{ &Cpu::OR_H },
			{ &Cpu::OR_L },
			{ &Cpu::OR_HL },
			{ &Cpu::OR_A },
			{ &Cpu::CP_B },
			{ &Cpu::CP_C },
			{ &Cpu::CP_D },
			{ &Cpu::CP_E },
			{ &Cpu::CP_H },
			{ &Cpu::CP_L },
			{ &Cpu::CP_HL },
			{ &Cpu::CP_A },
			// 0xC0
			{ &Cpu::RET_NZ },
			{ &Cpu::POP_BC },
			{ &Cpu::JP_NZ_nn },
			{ &Cpu::JP_nn },
			{ &Cpu::CALL_NZ_nn },
			{ &Cpu::PUSH_BC },
			{ &Cpu::ADD_A_N },
			{ &Cpu::RST_00h },
			{ &Cpu::RET_Z },
			{ &Cpu::RET },
			{ &Cpu::JP_Z_nn },
			{ &Cpu::BITS_group }, //0xCB
			{ &Cpu::CALL_Z_nn },
			{ &Cpu::CALL_nn },
			{ &Cpu::ADC_A_N },
			{ &Cpu::RST_08h },
			// 0xD0
			{ &Cpu::RET_NC },
			{ &Cpu::POP_DE },
			{ &Cpu::JP_NC_nn },
			{ &Cpu::OUT_N_A },
			{ &Cpu::CALL_NC_nn },
			{ &Cpu::PUSH_DE },
			{ &Cpu::SUB_N },
			{ &Cpu::RST_10h },
			{ &Cpu::RET_C },
			{ &Cpu::EXX },
			{ &Cpu::JP_C_nn },
			{ &Cpu::IN_A_C },
			{ &Cpu::CALL_C_nn },
			{ &Cpu::IX_group }, // 0xDD
			{ &Cpu::SBC_A_N },
			{ &Cpu::RST_18h },
			// 0xE0
			{ &Cpu::RET_PO },
			{ &Cpu::POP_HL },
			{ &Cpu::JP_PO_nn },
			{ &Cpu::EX_SP_HL },
			{ &Cpu::CALL_PO_nn },
			{ &Cpu::PUSH_HL },
			{ &Cpu::AND_N },
			{ &Cpu::RST_20h },
			{ &Cpu::RET_PE },
			{ &Cpu::JP_HL },
			{ &Cpu::JP_PE_nn },
			{ &Cpu::EX_DE_HL},
			{ &Cpu::CALL_PE_nn },
			{ &Cpu::EXTD_group },
			{ &Cpu::XOR_N },
			{ &Cpu::RST_28h },
			// 0xF0
			{ &Cpu::RET_P },
			{ &Cpu::POP_AF },
			{ &Cpu::JP_P_nn },
			{ &Cpu::DI },
			{ &Cpu::CALL_P_nn },
			{ &Cpu::PUSH_AF },
			{ &Cpu::OR_N },
			{ &Cpu::RST_30h },
			{ &Cpu::RET_M },
			{ &Cpu::LD_SP_HL },
			{ &Cpu::JP_M_nn },
			{ &Cpu::EI },
			{ &Cpu::CALL_M_nn },
			{ &Cpu::IY_group },
			{ &Cpu::CP_N },
			{ &Cpu::RST_38h }
	};

	uint8_t next_inst; // next instruction to be executed

	while (true)
	{
		// Fetch instruction from address indicated by PC
		next_inst = _memory.read(_registers[reg::PC]);
		// Decode and execute opcode from lookup table, update PC approprately
		switch (next_inst) {
		default: exit(1);
		}
	}
}

void Cpu::NOP() {
	_registers[reg::PC] += 1;
}

#pragma region LD_r_rprime

void Cpu::LD_A_A()
{
	_registers.LD_R_RP(reg::A, reg::A);
}

void Cpu::LD_A_B()
{
	_registers.LD_R_RP(reg::A, reg::B);
}

void Cpu::LD_A_C()
{
	_registers.LD_R_RP(reg::A, reg::C);
}

void Cpu::LD_A_D()
{
	_registers.LD_R_RP(reg::A, reg::D);
}

void Cpu::LD_A_E()
{
	_registers.LD_R_RP(reg::A, reg::E);
}

void Cpu::LD_A_H()
{
	_registers.LD_R_RP(reg::A, reg::H);
}

void Cpu::LD_A_L()
{
	_registers.LD_R_RP(reg::A, reg::L);
}

void Cpu::LD_B_A()
{
	_registers.LD_R_RP(reg::B, reg::A);
}
void Cpu::LD_B_B()
{
	_registers.LD_R_RP(reg::B, reg::B);

}
void Cpu::LD_B_C()
{
	_registers.LD_R_RP(reg::B, reg::C);
}
void Cpu::LD_B_D()
{
	_registers.LD_R_RP(reg::B, reg::D);
}
void Cpu::LD_B_E()
{
	_registers.LD_R_RP(reg::B, reg::E);
}
void Cpu::LD_B_H()
{
	_registers.LD_R_RP(reg::B, reg::H);
}
void Cpu::LD_B_L()
{
	_registers.LD_R_RP(reg::B, reg::L);
}

void Cpu::LD_C_A()
{
	_registers.LD_R_RP(reg::C, reg::A);
}
void Cpu::LD_C_B()
{
	_registers.LD_R_RP(reg::C, reg::B);
}
void Cpu::LD_C_C()
{
	_registers.LD_R_RP(reg::C, reg::C);
}
void Cpu::LD_C_D()
{
	_registers.LD_R_RP(reg::C, reg::D);
}
void Cpu::LD_C_E()
{
	_registers.LD_R_RP(reg::C, reg::E);
}
void Cpu::LD_C_H()
{
	_registers.LD_R_RP(reg::C, reg::H);
}
void Cpu::LD_C_L()
{
	_registers.LD_R_RP(reg::C, reg::L);
}

void Cpu::LD_D_A()
{
	_registers.LD_R_RP(reg::D, reg::A);
}
void Cpu::LD_D_B()
{
	_registers.LD_R_RP(reg::D, reg::B);
}
void Cpu::LD_D_C()
{
	_registers.LD_R_RP(reg::D, reg::C);
}
void Cpu::LD_D_D()
{
	_registers.LD_R_RP(reg::D, reg::D);
}
void Cpu::LD_D_E()
{
	_registers.LD_R_RP(reg::D, reg::E);
}
void Cpu::LD_D_H()
{
	_registers.LD_R_RP(reg::D, reg::H);
}
void Cpu::LD_D_L()
{
	_registers.LD_R_RP(reg::D, reg::L);
}

void Cpu::LD_E_A()
{
	_registers.LD_R_RP(reg::E, reg::A);
}
void Cpu::LD_E_B()
{
	_registers.LD_R_RP(reg::E, reg::B);
}
void Cpu::LD_E_C()
{
	_registers.LD_R_RP(reg::E, reg::C);
}
void Cpu::LD_E_D()
{
	_registers.LD_R_RP(reg::E, reg::D);
}
void Cpu::LD_E_E()
{
	_registers.LD_R_RP(reg::E, reg::E);
}
void Cpu::LD_E_H()
{
	_registers.LD_R_RP(reg::E, reg::H);
}
void Cpu::LD_E_L()
{
	_registers.LD_R_RP(reg::E, reg::L);
}

void Cpu::LD_H_A()
{
	_registers.LD_R_RP(reg::H, reg::A);
}
void Cpu::LD_H_B()
{
	_registers.LD_R_RP(reg::H, reg::B);
}
void Cpu::LD_H_C()
{
	_registers.LD_R_RP(reg::H, reg::C);
}
void Cpu::LD_H_D()
{
	_registers.LD_R_RP(reg::H, reg::D);
}
void Cpu::LD_H_E()
{
	_registers.LD_R_RP(reg::H, reg::E);
}
void Cpu::LD_H_H()
{
	_registers.LD_R_RP(reg::H, reg::H);
}
void Cpu::LD_H_L()
{
	_registers.LD_R_RP(reg::H, reg::L);
}

void Cpu::LD_L_A()
{
	_registers.LD_R_RP(reg::L, reg::A);
}
void Cpu::LD_L_B()
{
	_registers.LD_R_RP(reg::L, reg::B);
}
void Cpu::LD_L_C()
{
	_registers.LD_R_RP(reg::L, reg::C);
}
void Cpu::LD_L_D()
{
	_registers.LD_R_RP(reg::L, reg::D);
}
void Cpu::LD_L_E()
{
	_registers.LD_R_RP(reg::L, reg::E);
}
void Cpu::LD_L_H()
{
	_registers.LD_R_RP(reg::L, reg::H);
}
void Cpu::LD_L_L()
{
	_registers.LD_R_RP(reg::L, reg::L);
}

#pragma endregion

#pragma region LD_r_n

void Cpu::LD_A_N()
{
	_registers.LD_R_N(reg::A, _memory.read(_registers[reg::PC] + 1));
}
void Cpu::LD_B_N()
{
	_registers.LD_R_N(reg::B, _memory.read(_registers[reg::PC] + 1));
}
void Cpu::LD_C_N()
{
	_registers.LD_R_N(reg::C, _memory.read(_registers[reg::PC] + 1));
}
void Cpu::LD_D_N()
{
	_registers.LD_R_N(reg::D, _memory.read(_registers[reg::PC] + 1));
}
void Cpu::LD_E_N()
{
	_registers.LD_R_N(reg::E, _memory.read(_registers[reg::PC] + 1));
}
void Cpu::LD_H_N()
{
	_registers.LD_R_N(reg::H, _memory.read(_registers[reg::PC] + 1));
	}
void Cpu::LD_L_N()
{
	_registers.LD_R_N(reg::L, _memory.read(_registers[reg::PC] + 1));
}

#pragma endregion

#pragma region LD_A_HL
void Cpu::LD_A_HL()
{
	uint8_t value = _memory.read(_registers[reg::HL]);
	_registers.LD_R_N(reg::A, value);
}
void Cpu::LD_B_HL()
{
	uint8_t value = _memory.read(_registers[reg::HL]);
	_registers.LD_R_N(reg::B, value);
}
void Cpu::LD_C_HL()
{
	uint8_t value = _memory.read(_registers[reg::HL]);
	_registers.LD_R_N(reg::C, value);
}
void Cpu::LD_D_HL()
{
	uint8_t value = _memory.read(_registers[reg::HL]);
	_registers.LD_R_N(reg::D, value);
}
void Cpu::LD_E_HL()
{
	uint8_t value = _memory.read(_registers[reg::HL]);
	_registers.LD_R_N(reg::E, value);
}
void Cpu::LD_H_HL()
{
	uint8_t value = _memory.read(_registers[reg::HL]);
	_registers.LD_R_N(reg::H, value);
}
void Cpu::LD_L_HL()
{
	uint8_t value = _memory.read(_registers[reg::HL]);
	_registers.LD_R_N(reg::L, value);
}

#pragma endregion

#pragma region LD_HL_R

void Cpu::LD_HL_A()
{
	uint16_t address = _registers[reg::HL];
	_memory.write(address, _registers[reg::A]);
	_registers[reg::PC] += 1;
}

void Cpu::LD_HL_B()
{
	uint16_t address = _registers[reg::HL];
	_memory.write(address, _registers[reg::B]);
	_registers[reg::PC] += 1;
}

void Cpu::LD_HL_C()
{
	uint16_t address = _registers[reg::HL];
	_memory.write(address, _registers[reg::C]);
	_registers[reg::PC] += 1;
}

void Cpu::LD_HL_D()
{
	uint16_t address = _registers[reg::HL];
	_memory.write(address, _registers[reg::D]);
	_registers[reg::PC] += 1;
}

void Cpu::LD_HL_E()
{
	uint16_t address = _registers[reg::HL];
	_memory.write(address, _registers[reg::E]);
	_registers[reg::PC] += 1;
}

void Cpu::LD_HL_H()
{
	uint16_t address = _registers[reg::HL];
	_memory.write(address, _registers[reg::H]);
	_registers[reg::PC] += 1;
}

void Cpu::LD_HL_L()
{
	uint16_t address = _registers[reg::HL];
	_memory.write(address, _registers[reg::L]);
	_registers[reg::PC] += 1;
}

#pragma endregion

void Cpu::ADD_A_R(reg::DataReg reg)
{
	// TODO: make this take a uint8_t instead of a reg so it's more generalizable
	uint8_t acc = _registers[reg::A];
	uint8_t val = _registers[reg];
	uint8_t result = acc + val;

	// set/reset sign flag
	if (result < 0)
	{
		_registers.setFlag(flag::S);
	}
	else _registers.resetFlag(flag::S);

	if (_registers[reg::A] == 0)
	{
		_registers.setFlag(flag::Z);
	}
	else _registers.resetFlag(flag::Z);

	// TODO: see if there's a way to do this without an if/else
	if (_registers[reg::A] & 0x0F + _registers[reg] & 0x0F > 15)
	{
		_registers.setFlag(flag::H);
	}
	else _registers.resetFlag(flag::H);

	// set/reset P (overflow flag)
	if (_registers[reg::A] + _registers[reg] > 255)
	{
		_registers.setFlag(flag::P);
	}
	else _registers.resetFlag(flag::P);

	// always reset N flag, as per documentation
	_registers.resetFlag(flag::N);

	_registers[reg::A] += result;

	// set/reset C (carry flag)
	if (_registers[reg::A] + _registers[reg] > 255)
	{
		_registers.setFlag(flag::C);
	}
	else _registers.resetFlag(flag::C); 
	
}