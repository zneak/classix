//
// DummySymbolResolver.cpp
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

#include "DummySymbolResolver.h"
#include <iostream>

namespace CFM
{
	std::vector<ResolvedSymbol> DummySymbolResolver::GetEntryPoints() const
	{
		return std::vector<ResolvedSymbol>();
	}
	
	const std::string* DummySymbolResolver::FilePath() const
	{
		return nullptr;
	}
	
	std::vector<std::string> DummySymbolResolver::SymbolList() const
	{
		return std::vector<std::string>();
	}
	
	ResolvedSymbol DummySymbolResolver::ResolveSymbol(const std::string &name)
	{
		return ResolvedSymbol(SymbolUniverse::Intel, name, 0);
	}
	
	DummySymbolResolver::~DummySymbolResolver()
	{ }
}