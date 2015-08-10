#pragma once

#include "stdafx.h"
#include <memory>
#include <iostream>

class Ram {
public:
	uint8_t read(uint16_t address) const;
	void write(uint16_t address, uint8_t data);
	void load_from_file(std::string &input_file);
private:
	uint8_t _memory[65536];
};
