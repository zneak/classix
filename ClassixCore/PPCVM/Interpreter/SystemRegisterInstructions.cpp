//
// SystemRegisterInstructions.cpp
// Classix
//
// Copyright (C) 2012 Félix Cloutier
//
// This file is part of Classix.
//
// Classix is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// Classix is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
// A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// Classix. If not, see http://www.gnu.org/licenses/.
//

#include <cassert>
#include "Interpreter.h"

namespace
{
	using namespace PPCVM;
	
	inline bool GetCRBit(MachineState* state, int bit)
	{
		int crIndex = bit / 4;
		int bitIndex = 3 - (bit & 3);
		return (state->cr[crIndex] >> bitIndex) & 1;
	}
	
	inline void SetCRBit(MachineState* state, int bit, bool value)
	{
		int bitIndex = bit / 4;
		int bitValue = 8 >> (bit & 3);
		if (value)
			state->cr[bitIndex] |= bitValue;
		else
			state->cr[bitIndex] &= ~bitValue;
	}
	
	inline int GetCRField(MachineState* state, int field)
	{
		return state->cr[field];
	}
	
	inline void SetCRField(MachineState* state, int field, uint8_t value)
	{
		state->cr[field] = value;
	}
}

namespace PPCVM
{
	namespace Execution
	{
		void Interpreter::crand(Instruction inst)
		{
			SetCRBit(state, inst.CRBD, GetCRBit(state, inst.CRBA) & GetCRBit(state, inst.CRBB));
		}

		void Interpreter::crandc(Instruction inst)
		{
			SetCRBit(state, inst.CRBD, GetCRBit(state, inst.CRBA) & (1 ^ GetCRBit(state, inst.CRBB)));
		}

		void Interpreter::creqv(Instruction inst)
		{
			SetCRBit(state, inst.CRBD, 1 ^ (GetCRBit(state, inst.CRBA) ^ GetCRBit(state, inst.CRBB)));
		}

		void Interpreter::crnand(Instruction inst)
		{
			SetCRBit(state, inst.CRBD, 1 ^ (GetCRBit(state, inst.CRBA) & GetCRBit(state, inst.CRBB)));
		}

		void Interpreter::crnor(Instruction inst)
		{
			SetCRBit(state, inst.CRBD, 1 ^ (GetCRBit(state, inst.CRBA) | GetCRBit(state, inst.CRBB)));
		}

		void Interpreter::cror(Instruction inst)
		{
			SetCRBit(state, inst.CRBD, (GetCRBit(state, inst.CRBA) | GetCRBit(state, inst.CRBB)));
		}

		void Interpreter::crorc(Instruction inst)
		{
			SetCRBit(state, inst.CRBD, (GetCRBit(state, inst.CRBA) | (1 ^ GetCRBit(state, inst.CRBB))));
		}

		void Interpreter::crxor(Instruction inst)
		{
			SetCRBit(state, inst.CRBD, (GetCRBit(state, inst.CRBA) ^ GetCRBit(state, inst.CRBB)));
		}

		void Interpreter::isync(Instruction inst)
		{
			__sync_synchronize();
		}

		void Interpreter::mcrf(Instruction inst)
		{
			int cr_f = GetCRField(state, inst.CRFS);
			SetCRField(state, inst.CRFD, cr_f);
		}

		void Interpreter::mcrfs(Instruction inst)
		{
			abort();
		}

		void Interpreter::mcrxr(Instruction inst)
		{
			SetCRField(state, inst.CRFD, state->xer >> 28); 
			state->xer &= ~0xF0000000; // clear 0-3
		}

		void Interpreter::mfcr(Instruction inst)
		{
			state->gpr[inst.RD] = state->GetCR();
		}

		void Interpreter::mffsx(Instruction inst)
		{
			abort();
		}

		void Interpreter::mfspr(Instruction inst)
		{
			uint8_t spr = (inst.RB << 5) | inst.RA;
			switch (spr)
			{
				case 1: // xer
					state->gpr[inst.RD] = state->xer;
					break;
					
				case 8: // lr
					state->gpr[inst.RD] = state->lr;
					break;
					
				case 9: // ctr
					state->gpr[inst.RD] = state->ctr;
					break;
					
				default:
					assert(!"Getting value of unknown system register");
					break;
			}
		}

		void Interpreter::mftb(Instruction inst)
		{
			abort();
		}

		void Interpreter::mtcrf(Instruction inst)
		{
			uint32_t crm = inst.CRM;
			if (crm == 0xFF)
			{
				state->SetCR(state->gpr[inst.RS]);
			}
			else
			{
				//TODO: use lookup table? probably not worth it
				uint32_t mask = 0;
				for (int i = 0; i < 8; i++) {
					if (crm & (1 << i))
						mask |= 0xF << (i*4);
				}
				state->SetCR((state->GetCR() & ~mask) | (state->gpr[inst.RS] & mask));
			}
		}

		void Interpreter::mtfsb0x(Instruction inst)
		{
			abort();
		}

		void Interpreter::mtfsb1x(Instruction inst)
		{
			abort();
		}

		void Interpreter::mtfsfix(Instruction inst)
		{
			abort();
		}

		void Interpreter::mtfsfx(Instruction inst)
		{
			abort();
		}

		void Interpreter::mtspr(Instruction inst)
		{
			uint8_t spr = (inst.RB << 5) | inst.RA;
			switch (spr)
			{
				case 1: // xer
					state->xer = state->gpr[inst.RD];
					break;
					
				case 8: // lr
					state->lr = state->gpr[inst.RD];
					break;
					
				case 9: // ctr
					state->ctr = state->gpr[inst.RD];
					break;
					
				default:
					assert(!"Getting value of unknown system register");
					break;
			}
		}
	}
}
