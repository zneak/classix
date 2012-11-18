//
//  PEFSymbolResolver.h
//  pefdump
//
//  Created by Félix on 2012-10-22.
//  Copyright (c) 2012 Félix. All rights reserved.
//

#ifndef __pefdump__PEFSymbolResolver__
#define __pefdump__PEFSymbolResolver__

#include "SymbolResolver.h"
#include "Container.h"
#include "FileMapping.h"
#include "FragmentManager.h"

namespace CFM
{
	class PEFSymbolResolver : public virtual SymbolResolver
	{
		Common::FileMapping mapping;
		PEF::Container container;
		Common::IAllocator* allocator;
		
		FragmentManager& cfm;
		
		ResolvedSymbol Symbolize(const uint8_t* address);
		ResolvedSymbol Symbolize(const PEF::LoaderHeader::SectionWithOffset& sectionWithOffset);
		
	public:
		PEFSymbolResolver(Common::IAllocator* allocator, FragmentManager& cfm, const std::string& filePath);
		PEFSymbolResolver(Common::IAllocator* allocator, FragmentManager& cfm, Common::FileMapping&& mapping);
		
		PEF::Container& GetContainer();
		const PEF::Container& GetContainer() const;
		
		virtual ResolvedSymbol GetInitAddress();
		virtual ResolvedSymbol GetMainAddress();
		virtual ResolvedSymbol GetTermAddress();
		
		virtual ResolvedSymbol ResolveSymbol(const std::string& symbolName);
		
		virtual ~PEFSymbolResolver();
	};
}

#endif /* defined(__pefdump__PEFSymbolResolver__) */
