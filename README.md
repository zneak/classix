Classix, a Mac OS 9 Compatibility Layer
=======================================

The Classix project's goal is to make it possible to run Classic applications
under Mac OS X again. Apple officially removed Classic environment support from
Mac OS X in 2004, and while some alternatives slowly appeared, none of them are
fully satisfying. All of them offer to run Mac OS 9 inside a stripped-down
virtual machine, which will probably work fine if you want to use MacWrite II
again, but will not cut it to play games from the awkward gap where they weren't
developed for MS-DOS anymore (and thus unavailable in [DOSBOX][1] or [Boxer][2])
but not yet for Mac OS X either, let alone Mac OS X Intel.

Classix is not meant to be a perfect old-world Macintosh emulator. It is rather
meant to be a _compatibility layer_, like [Wine][3], that will run Mac OS 9
inside the native desktop environment we love. (Focus is currently given to Mac
OS X development, but the Classix core should be easy to port to any other
POSIX-compliant platform.) This allows Classix to use native functions to do the
library work, making it potentially much faster than a classic virtual machine
with a CPU emulator.

Classix is currently licensed under the GPL v3.0 license as a legal requirement
(it uses [Dolphin][5] code, which is itself GPL). The license may be changed to
something less restrictive in the future if we make the interpreter different
enough from Dolphin's.

Using Classix
-------------

Classix is still under heavy development and nothing useful can be done with it
right now. If you're not a developer, you're not going to be interested in
getting it at the moment.

State of the Project
--------------------

Classix is currently able to do _some_ of the work of the Code Fragment Manager,
the [system component responsible for loading executables and running them][4].
It is able to load PowerPC PEF executables, but not 68k PEF executables, nor
XCOFF executables (of any architecture). Design changes will be necessary to
support 68k emulation (though XCOFF loading should be rather "easy"). It also
does not support any of the runtime features of the CFM; it's only able to link
together applications and libraries at startup.

The PowerPC emulator is based on [Dolphin][5]'s interpreter, with some important
changes made to better achieve certain goals (for instance, our interpreter
accesses raw memory directly, does not use global state to represent CPU
registers, and does not need to implement supervisor-level PPC instructions).

It is currently possible to run very simple programs inside Classix, like "Hello
World" programs. However, interpreter bugs (most likely introduced by us) causes
anything non-trivial to fail.

General Design of the Project
-----------------------------

Classix is implemented as a library, `ClassixCore`, that projects link against.
This library is programmed in C++11. Global state is strictly forbidden, and up
to now this has served us well.

The library itself has several components:

* A `Common` namespace, where shared tools that can serve many purposes live;
* A `PEF` namespace, that handles PEF parsing (but not linking);
* A `CFM` namespace, that handles linking executables together;
* A `PPCVM` namespace, that handles PowerPC emulation and disassembly;
* A `ClassixCore` namespace, that handles communication with the external world
  (it includes the component responsible for bridging to native functions).

Around that are built the _classix_ command-line executable, a general-purpose
tool to use the ClassixCore library, and the _Classix Debugger_, a Cocoa
application that serves as a debugging GUI (because debugging PowerPC
applications from within lldb in Xcode is a real pain). The project also
includes an incomplete implementation of the _StdCLib_ Mac OS 9 shared library.

TODO List
---------

* Mac OS Classic documentation is _extremely_ hard to find. Recently, Apple
  pulled the MPW environment from its website, making it a lot harder to do
  anything. We need more documentation for libraries.
* Classix currently only works as a 32-bits executable because memory always
  needs to be allocated somewhere the PowerPC emulator will be able to access
  (this means that all allocations that the PPC emulator needs to work with must
  be allocated within the same `0x100000000`-bytes block, and the easiest way to
  achieve that is to run Classix as a 32-bits program). There would be a lot of
  advantages to switching to 64-bits, so [a handful of possibilities are being
  evaluated at the moment][6].
* Classix has *gasp* __no unit test__, and that's a shame. To my defense, _not a
  single PowerPC emulator_ seems to have unit tests: I looked at gdb's psim,
  PearPC, SheepShaver/Basilisk, qemu and Dolphin, and apparently that's not
  very popular. We *really* should have unit tests though, as that would make
  debugging a lot less painful.
* The disassembler seems fairly good, but not all simplified mnemonics are
  identified. Also, it lacks unit tests.
* The only partially-implemented library is the _StdCLib_. We need more
  libraries, and we need unit tests for libraries too.
* The graphical debugger is a work in progress. Right now, it can display
  disassembly and that's it.

 [1]: http://www.dosbox.com/
 [2]: http://boxerapp.com/
 [3]: http://www.winehq.org/
 [4]: http://developer.apple.com/legacy/mac/library/documentation/mac/pdf/MacOS_RT_Architectures.pdf
 [5]: http://dolphin-emulator.com/
 [6]: http://stackoverflow.com/questions/13517396/how-can-i-ask-mac-os-to-allocate-memory-in-a-specific-address-range