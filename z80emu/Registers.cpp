#include "stdafx.h"
#include "Registers.h"

Registers::Registers()
{
	_main = new DataRegisters();
	_alt = new DataRegisters();
}

void Registers::zero() {
	// intiializes all registers to zero
	 
}