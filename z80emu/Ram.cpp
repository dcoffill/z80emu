#include "stdafx.h"
#include "Ram.h"
#include <fstream>


void Ram::load_from_file(std::string &input_file) {
	std::ifstream infile;
	infile.open(input_file, std::ios::binary | std::ios::in);
	int size = infile.tellg();
	if (size > 65536) {
		return; // file is too large, don't do anything
	}
	infile.seekg(0, std::ios::beg);
	infile.read(reinterpret_cast<char *>(_memory), size); // hopefully this cast doesn't blow up...  TODO: see if there is a better way to do this
	infile.close();
	return;
}

uint8_t Ram::read(uint16_t address) {
	return _memory[address];
}

void Ram::write(uint16_t address, uint8_t data) {
	_memory[address] = data;
}