//
//  FancyDisassembler.h
//  Classix
//
//  Created by Félix on 2012-11-17.
//  Copyright (c) 2012 Félix. All rights reserved.
//

#ifndef __Classix__FancyDisassembler__
#define __Classix__FancyDisassembler__

#include <iostream>
#include <string>
#include <unordered_map>

#include "IAllocator.h"
#include "Container.h"
#include "Disassembler.h"

class SectionDisassembler
{
	friend class FancyDisassembler;
	
	Common::IAllocator* allocator;
	const PEF::InstantiableSection& section;
	PPCVM::Disassembly::Disassembler* disasm;
	uint32_t sectionNumber;
	
public:
	typedef std::unordered_map<const Common::UInt32*, std::string> MetadataMap;
	
	SectionDisassembler(Common::IAllocator* allocator, uint32_t sectionNumber, const PEF::InstantiableSection& section);
	SectionDisassembler(const SectionDisassembler& that) = delete;
	SectionDisassembler(SectionDisassembler&& that);
	
	void WriteTo(std::ostream& into, MetadataMap metadata) const;
	
	~SectionDisassembler();
};

class FancyDisassembler
{
	typedef PPCVM::Disassembly::InstructionRange InstructionRange;
	
	Common::IAllocator* allocator;
	SectionDisassembler::MetadataMap metadata;
	std::map<uint32_t, SectionDisassembler> sections;
	std::unordered_map<InstructionRange*, PPCVM::Disassembly::Disassembler*> rangeToDisasm;
	std::unordered_set<InstructionRange*> unprocessedRanges;
	std::unordered_map<InstructionRange*, const uint8_t*> r2Values;
	
	void DoDisassemble(PEF::Container& container);
	void TryInitR2WithMainSymbol(PEF::Container& container);
	void ProcessRange(PPCVM::Disassembly::InstructionRange& range, const uint8_t* r2);
	void TryFollowBranch(PPCVM::Disassembly::InstructionRange* range, const Common::UInt32* currentAddress, const Common::UInt32 *targetAddress, const uint8_t* r2);
	
public:
	FancyDisassembler(Common::IAllocator* allocator);
	
	void Disassemble(PEF::Container& container, std::ostream& into);
};

#endif /* defined(__Classix__FancyDisassembler__) */