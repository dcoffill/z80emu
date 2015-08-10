#include "stdafx.h"
#include "Cpu.h"
#include "Registers.h"
#include "RegisterEnums.h"

void Cpu::execute() {
	// zero all registers
	_registers.zero();

	for (;;)
	{
		uint8_t next_instruction = _memory.read(_registers[reg::PC]);
		// Decode and execute opcode
		switch (next_instruction) {
		case 0x00:
			nop();
			break;
		case 0x01:
			ld(reg::BC); // LD dd, nn
			break;
		case 0x02:
			ld(reg::BC, reg::A);
			break;
		case 0x03:
			inc_ss(reg::BC);
			break;
		case 0x04:
			inc_r(reg::B);
			break;
		case 0x05:
			dec_r(reg::B);
			break;
		default:
			exit(1);
		}
	}
}

void Cpu::nop()
{
	++_registers[reg::PC];
}

void Cpu::add_a_r(const reg::DataReg reg)
{
	uint8_t acc = _registers[reg::A];
	uint8_t val = _registers[reg];
	uint8_t result = acc + val;

	_registers.setFlag(flag::S, result < 0);
	_registers.setFlag(flag::Z, result == 0);
	bool halfCarry = (acc & 0x0F) + (val & 0x0F) > 15;
	_registers.setFlag(flag::H, halfCarry);
	bool overflow = acc + val  > 255;
	_registers.setFlag(flag::P, overflow);
	_registers.setFlag(flag::N, false);
	_registers.setFlag(flag::C, overflow);
	_registers[reg::A] = result;
	++_registers[reg::PC];
}

void Cpu::inc_r(const reg::DataReg reg)
{
	_registers[reg] = inc(_registers[reg]);
	++_registers[reg::PC];
}

void Cpu::inc_ss(const reg::DataReg16 reg)
{
	++_registers[reg];
	++_registers[reg::PC];
}

uint8_t Cpu::inc(const uint8_t value)
{
	uint8_t result = value + 1;
	_registers.setFlag(flag::S, result < 0);
	_registers.setFlag(flag::Z, _registers[reg::A] == 0);
	bool halfCarry = (value & 0x0F) + 0x01 > 15;
	_registers.setFlag(flag::H, halfCarry);
	_registers.setFlag(flag::P, value == 0x7F);
	_registers.setFlag(flag::N, false);
	return result;
}

void Cpu::dec_r(const reg::DataReg reg)
{
	_registers[reg] = dec(_registers[reg]);
	++_registers[reg::PC];
}

uint8_t Cpu::dec(const uint8_t value)
{
	uint8_t result = value - 1;
	_registers.setFlag(flag::S, result < 0);
	_registers.setFlag(flag::Z, result == 0);
	_registers.setFlag(flag::H, (value & 0x0F) < 0x01); // Borrow occurs if lower nibble subtrahend > lower nibble minuend
	_registers.setFlag(flag::P, value == 0x80);
	_registers.setFlag(flag::N, true);
	return result;
}

void Cpu::ld(const reg::DataReg16 reg)
{
	uint8_t low = _memory.read(_registers[reg::PC] + 1);
	uint8_t high = _memory.read(_registers[reg::PC] + 2);
	uint16_t value = (high << 8) | low;
	_registers.LD(reg, value);
	_registers[reg::PC] += 3;
}

void Cpu::ld(const reg::DataReg16 addressReg, const reg::DataReg src)
{
	uint8_t value = _registers[src];
	uint16_t address = _memory.read(_registers[addressReg]);
	_memory.write(address, value);
	_registers[reg::PC] += 1;
}