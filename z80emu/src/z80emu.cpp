// z80emu.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Cpu.h"
#include "Ram.h"

int main(int argc, char *argv[])
{
	Cpu cpu;
	cpu.execute();
	return 0;
}
