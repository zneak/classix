//
// DebugStub.h
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

#ifndef __Classix__DebugStub__
#define __Classix__DebugStub__

#include <memory>
#include <deque>
#include <unordered_map>

#include "WaitQueue.h"
#include "ControlStream.h"
#include "Allocator.h"
#include "Managers.h"
#include "LibraryResolver.h"
#include "MachineState.h"
#include "FragmentManager.h"
#include "DebugThreadManager.h"
#include "ThreadContext.h"

struct DebugContext
{
	std::unique_ptr<Common::Allocator> allocator;
	std::deque<std::unique_ptr<CFM::LibraryResolver>> resolvers;
	DebugThreadManager threads;
	OSEnvironment::Managers managers;
	CFM::FragmentManager fragmentManager;
	
	std::unordered_map<char, DebugThreadManager::ThreadId> operationTargetThreads;
	DebugThreadManager::ThreadId globalTargetThread;
	
	uint32_t pid;
	
	DebugContext(const std::string& executable, uint32_t pid);
	void Start(std::shared_ptr<WaitQueue<std::string>>& sink);
};

class DebugStub
{
	typedef uint8_t (DebugStub::*RemoteCommand)(const std::string&, std::string&);
	
	// lifecycle
	std::shared_ptr<WaitQueue<std::string>> sink;
	std::unique_ptr<ControlStream> stream;
	std::unique_ptr<DebugContext> context;
	
	// program initialization
	std::string executablePath;
	std::deque<std::string> args;
	std::deque<std::string> env;
	uint16_t runCount;
	
	// commands state
	static const std::unordered_map<std::string, RemoteCommand> commands;
	
	void SinkMain();
	
	// Commands
	uint8_t SetOperationTargetThread(const std::string& commandString, std::string& output);
	uint8_t GetStopReason(const std::string& commandString, std::string& output);
	uint8_t ThreadResume(const std::string& commandString, std::string& output);
	uint8_t ReadMemory(const std::string& commandString, std::string& outputString);
	uint8_t WriteMemory(const std::string& commandString, std::string& outputString);
	uint8_t Kill(const std::string& commandString, std::string& outputString);
	uint8_t Continue(const std::string& commandString, std::string& outputString);
	uint8_t ReadSingleRegister(const std::string& commandString, std::string& outputString);
	uint8_t SetBreakpoint(const std::string& commandString, std::string& outputString);
	uint8_t RemoveBreakpoint(const std::string& commandString, std::string& outputString);
	uint8_t AllocateMemory(const std::string& commandString, std::string& outputString);
	uint8_t DeallocateMemory(const std::string& commandString, std::string& outputString);
	
	// Query commands
	uint8_t QueryCurrentThread(const std::string& commandString, std::string& output);
	uint8_t QueryThreadList(const std::string& commandString, std::string& output);
	uint8_t QuerySectionOffsets(const std::string& commandString, std::string& output);
	uint8_t QueryHostInformation(const std::string& commandString, std::string& output);
	uint8_t QueryRegisterInformation(const std::string& commandString, std::string& output);
	uint8_t QueryProcessInformation(const std::string& commandString, std::string& output);
	uint8_t QueryMemoryRegionInfo(const std::string& commandString, std::string& output);
	
	// Private Commands (commands that aren't passed by the debugger)
	uint8_t PrivateStreamClosed(const std::string& commandString, std::string& output);
	
public:
	DebugStub(const std::string& executablePath);
	
	template<typename TIter>
	void SetArguments(TIter begin, TIter end)
	{
		args.clear();
		for (TIter iter = begin; iter != end; iter++)
			args.emplace_back(*iter);
	}
	
	template<typename TIter>
	void SetEnvironment(TIter begin, TIter end)
	{
		env.clear();
		for (TIter iter = begin; iter != end; iter++)
			env.emplace_back(*iter);
	}
	
	void Accept(uint16_t port);
	void Execute();
};

#endif /* defined(__Classix__DebugStub__) */
