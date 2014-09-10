#include "stdafx.h"
#include "Registers.h"

void Registers::zero() {
	// intiializes all registers to zero
	 _a_a = 0;
	 _b_a = 0;
	 _c_a = 0;
	 _d_a = 0;
	 _e_a = 0;
	 _f_a = 0;
	 _h_a = 0;
	 _l_a = 0;
	 _a_b = 0;
	 _b_b = 0;
	 _c_b = 0;
	 _d_b = 0;
	 _e_b = 0;
	 _f_b = 0;
	 _h_b = 0;
	 _l_b = 0;
	 _ix = 0;
	 _iy = 0;
	 _sp = 0;
	 _pc = 0;
	_iff1 = 0;
	_iff2 = 0;
}