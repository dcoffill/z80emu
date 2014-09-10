#include "stdafx.h"
#include "Cpu.h"

void Cpu::execute() {
	// zero all registers
	_registers.zero();

	uint8_t next_inst; // next instruction to be executed

	while (true) {
		// Fetch instruction from address indicated by PC
		next_inst = _memory.read(_registers._pc);
		switch (next_inst) {
			
			default:
				std::cout << "Unrecognized opcode: " << std::hex << next_inst << std::endl;
				break;
		}
	}
}