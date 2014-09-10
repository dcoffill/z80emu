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

};
#endif