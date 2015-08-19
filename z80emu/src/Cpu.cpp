#include "stdafx.h"
#include "Cpu.h"
#include "Registers.h"
#include "RegisterEnums.h"
#include <bitset>

void Cpu::execute()
{
	_registers.zero();

	for (;;) {
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
				ld(reg::BC, reg::A); // LD (BC), A
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
			case 0x06:
				ld_n(reg::B); // LD r, n
				break;
			case 0x07:
				rlca();
				break;
			case 0x08:
				_registers.ex_af_af();
				break;
			case 0x09:
				add_hl(reg::BC);
			case 0x0A:
				ld_acc_address(reg::BC);
				break;
			case 0x0B:
				dec(reg::BC);
				break;
			case 0x0C:
				inc(reg::C);
				break;
			case 0x0D:
				dec(reg::C);
				break;
			case 0x0E:
				ld_n(reg::C);
				break;
			case 0x0F:
				rrca();
				break;
			case 0x10:
				djnz();
				break;
			case 0x11:
				ld(reg::DE);
				break;
			case 0x12:
				ld(reg::DE, reg::A);
				break;
			case 0x13:
				inc(reg::DE);
				break;
			case 0x14:
				inc(reg::D);
				break;
			case 0x15:
				dec(reg::D);
				break;
			case 0x16:
				ld_n(reg::D);
				break;
			case 0x17:
				rla();
				break;
			case 0x18:
				jr();
				break;
			case 0x19:
				add_hl(reg::DE);
				break;
			case 0x1A:
				ld_acc_address(reg::DE);
				break;
			case 0x1B:
				dec(reg::DE);
				break;
			case 0x1C:
				inc(reg::E);
				break;
			case 0x1D:
				dec(reg::E);
				break;
			case 0x1E:
				ld_n(reg::E);
				break;
			case 0x1F:
				rra();
				break;
			case 0x20:
				jr_nz();
				break;
			case 0x21:
				ld(reg::HL);
				break;
			case 0x22:
				ld_nn_hl();
				break;
			case 0x23:
				inc(reg::HL);
				break;
			case 0x24:
				inc(reg::H);
				break;
			case 0x25:
				dec(reg::H);
				break;
			case 0x26:
				ld_n(reg::H);
				break;
			case 0x27:
				daa();
				break;
			case 0x28:
				jr_z();
				break;
			case 0x29:
				add_hl(reg::HL);
				break;
			case 0x2A:
				ld_hl_nn();
				break;
			case 0x2B:
				dec(reg::HL);
				break;
			case 0x2C:
				inc(reg::L);
				break;
			case 0x2D:
				dec(reg::L);
				break;
			case 0x2E:
				ld_n(reg::L);
				break;
			case 0x2F:
				cpl();
				break;
			default:
				std::cerr << "Encountered illegal or unimplemented opcode: 0x" << std::hex << std::uppercase << static_cast<int>(next_instruction) << std::endl;
				break;
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

	_registers.setFlag(flag::S, static_cast<int8_t>(result) < 0);
	_registers.setFlag(flag::Z, result == 0);
	bool halfCarry = (acc & 0x0F) + (val & 0x0F) > 15;
	_registers.setFlag(flag::H, halfCarry);
	bool overflow = acc + val > 255;
	_registers.setFlag(flag::P, overflow);
	_registers.setFlag(flag::N, false);
	_registers.setFlag(flag::C, overflow);
	_registers[reg::A] = result;
	++_registers[reg::PC];
}

void Cpu::add_hl(const reg::DataReg16 reg)
{
	uint16_t hl = _registers[reg::HL];
	uint16_t other = _registers[reg];
	uint16_t result = hl + other;

	_registers.setFlag(flag::S, static_cast<int8_t>(result) < 0);
	_registers.setFlag(flag::Z, result == 0);
	bool overflow = hl + other > 65535;
	_registers.setFlag(flag::C, overflow);
	_registers.setFlag(flag::P, overflow);
	bool halfCarry = (hl & 0x0FFF) + (other & 0x0FFF) > 4095;
	_registers.setFlag(flag::H, halfCarry);
	_registers.setFlag(flag::N, false);
	_registers[reg::HL] = result;
	_registers[reg::PC] += 1;
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
	_registers.setFlag(flag::S, static_cast<int8_t>(result) < 0);
	_registers.setFlag(flag::Z, result == 0);
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
	_registers.setFlag(flag::S, static_cast<int8_t>(result) < 0);
	_registers.setFlag(flag::Z, result == 0);
	_registers.setFlag(flag::H, (value & 0x0F) < 0x01); // Borrow occurs if lower nibble subtrahend > lower nibble minuend
	_registers.setFlag(flag::P, value == 0x80);
	_registers.setFlag(flag::N, true);
	return result;
}

void Cpu::ld_n(const reg::DataReg reg)
{
	uint8_t value = _memory.read(_registers[reg::PC] + 1);
	_registers.ld(reg, value);
	_registers[reg::PC] += 2;
}

void Cpu::ld(const reg::DataReg16 reg)
{
	uint8_t low = _memory.read(_registers[reg::PC] + 1);
	uint8_t high = _memory.read(_registers[reg::PC] + 2);
	uint16_t value = (high << 8) | low;
	_registers.ld(reg, value);
	_registers[reg::PC] += 3;
}

void Cpu::ld(const reg::DataReg16 addressReg, const reg::DataReg src)
{
	uint8_t value = _registers[src];
	uint16_t address = _memory.read(_registers[addressReg]);
	_memory.write(address, value);
	_registers[reg::PC] += 1;
}

void Cpu::ld_acc_address(const reg::DataReg16 addressReg)
{
	uint16_t address = _registers[addressReg];
	uint8_t value = _memory.read(address);
	_registers.ld(reg::A, value);
	_registers[reg::PC] += 1;
}

void Cpu::ld_nn_hl()
{
	uint8_t low_order = _memory.read(_registers[reg::PC] + 1);
	uint8_t high_order = _memory.read(_registers[reg::PC] + 2);
	uint16_t address = (high_order << 8) | low_order;
	_memory.write(address, _registers[reg::L]);
	_memory.write(address + 1, _registers[reg::H]);
	_registers[reg::PC] += 3;
}

void Cpu::ld_hl_nn()
{
	uint8_t low_order = _memory.read(_registers[reg::PC] + 1);
	uint8_t high_order = _memory.read(_registers[reg::PC] + 2);
	uint16_t address = (high_order << 8) | low_order;
	_registers[reg::L] = _memory.read(address);
	_registers[reg::H] = _memory.read(address + 1);
	_registers[reg::PC] += 3;
}

void Cpu::rlca()
{
	uint8_t acc = _registers[reg::A];
	uint8_t shifted = (acc << 1) | (acc >> 7);
	_registers.setFlag(flag::H, false);
	_registers.setFlag(flag::N, false);
	_registers.setFlag(flag::C, acc >> 7);
	_registers[reg::A] = shifted;
	_registers[reg::PC] += 1;
}

void Cpu::rrca()
{
	uint8_t acc = _registers[reg::A];
	uint8_t shifted = (acc >> 1) | (acc << 7);
	_registers.setFlag(flag::H, false);
	_registers.setFlag(flag::N, false);
	_registers.setFlag(flag::C, acc & 0x01);
	_registers[reg::A] = shifted;
	_registers[reg::PC] += 1;
}

void Cpu::rra()
{
	uint8_t acc = _registers[reg::A];
	uint8_t shifted = (acc >> 1) | (_registers[flag::C] << 7);
	_registers.setFlag(flag::H, false);
	_registers.setFlag(flag::N, false);
	_registers.setFlag(flag::C, acc & 0x01);
	_registers[reg::A] = shifted;
	_registers[reg::PC] += 1;
}

void Cpu::rla()
{
	uint8_t acc = _registers[reg::A];
	uint8_t shifted = (acc << 1) | _registers[flag::C];
	_registers.setFlag(flag::H, false);
	_registers.setFlag(flag::N, false);
	_registers.setFlag(flag::C, acc >> 7);
	_registers[reg::A] = shifted;
	_registers[reg::PC] += 1;
}

// Jump group

void Cpu::djnz()
{
	uint8_t b_value = --_registers[reg::B];
	uint8_t offset = _memory.read(_registers[reg::PC] + 1);
	_registers[reg::PC] += 2;
	if (b_value != 0) { // jump
		_registers[reg::PC] += static_cast<int8_t>(offset); // TODO: does static cast need to be here for proper pos/neg offset?
	}
}

void Cpu::jr()
{
	uint8_t offset = _memory.read(_registers[reg::PC] + 1);
	_registers[reg::PC] += 2 + static_cast<int8_t>(offset);
}

void Cpu::jr_nz()
{
	_registers[reg::PC] += 2;
	uint8_t offset = _memory.read(_registers[reg::PC] + 1);
	if (!_registers[flag::Z]) { // jump if NZ
		_registers[reg::PC] += static_cast<int8_t>(offset);
	}
}

void Cpu::jr_z()
{
	_registers[reg::PC] += 2;
	uint8_t offset = _memory.read(_registers[reg::PC] + 1);
	if (_registers[flag::Z]) { // jump if Z
		_registers[reg::PC] += static_cast<int8_t>(offset);
	}
}

void Cpu::daa()
{
	// Implements algorithm from http://www.worldofspectrum.org/faq/reference/z80reference.htm
	const uint8_t acc = _registers[reg::A];
	uint8_t correction = 0;
	if (acc > 0x99 || _registers[flag::C]) {
		correction |= 0x60;
		_registers.setFlag(flag::C, true);
	}
	else {
		_registers.setFlag(flag::C, false);
	}

	if ((acc & 0x0F) > 9 || _registers[flag::H]) {
		correction |= 0x06;
	}

	uint8_t result = acc;
	if (!_registers[flag::N]) {
		result += correction;
	}
	else {
		result -= correction;
	}

	_registers.setFlag(flag::S, result >> 7);
	_registers.setFlag(flag::Z, result == 0);
	_registers.setFlag(flag::H, ((acc ^ result) >> 4) & 0x01);
	bool is_even_parity = std::bitset<8>(result).count() % 2 == 0; // should inline to popcount intrinsic on x86
	_registers.setFlag(flag::P, is_even_parity);
	_registers[reg::A] = result;
	_registers[reg::PC] += 1;
}

void Cpu::cpl()
{
	_registers[reg::A] = ~_registers[reg::A];
	_registers.setFlag(flag::H, true);
	_registers.setFlag(flag::N, true);
	_registers[reg::PC] += 2;
}
