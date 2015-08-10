// z80emu.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Cpu.h"
#include "Ram.h"

int _tmain(int argc, _TCHAR *argv[])
{
	Cpu cpu;
	cpu.execute();
	return 0;
}
