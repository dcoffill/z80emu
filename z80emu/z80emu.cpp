// z80emu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Cpu.h"
#include "Ram.h"
#include "opcodes.h"

int _tmain(int argc, _TCHAR* argv[]) {
	Cpu cpu;
	std::cout << opcodes::LD_A_A.opcode << " " << opcodes::LD_A_A.pc_advance << std::endl;
	return 0;
}

