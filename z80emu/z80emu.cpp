// z80emu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

class Cpu {
public:
	void execute();
private:
	Registers register_file;

};

class Memory {
	public:
		uint8_t read(uint16_t address);
		void write(uint16_t address, uint8_t data);
	private:
		uint8_t memory[65536];
};

class Registers {
	public:
		uint8_t get_byte();
		uint16_t get_word();
		void set(uint8_t input);
		void set(uint16_t input);
	private:
		// main register set
		uint8_t _a_a;
		uint8_t _b_a;
		uint8_t _d_a;
		uint8_t _h_a;
		uint8_t _f_a;
		uint8_t _c_a;
		uint8_t _e_a;
		uint8_t _l_a;
		// alternate register set
		uint8_t _a_b;
		uint8_t _b_b;
		uint8_t _d_b;
		uint8_t _h_b;
		uint8_t _f_b;
		uint8_t _c_b;
		uint8_t _e_b;
		uint8_t _l_b;

		// 16 bit address/index registers
		uint16_t _ix;
		uint16_t _iy;

		// stack pointer
		uint16_t _sp;

		// program counter
		uint16_t _pc;

		// interrupt flags
		bool _iff1;
		bool _iff2;

		// interrupt vector
		uint8_t _i;

		// refresh counter
		uint8_t _r;



};

class Computer {
	public:
		void initialize();
		void run();
	private:
		Cpu _cpu;
		Memory _memory;
};