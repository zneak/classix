/* $VER: ppc_disasm.h V1.4 (29.08.2001)
 *
 * Disassembler module for the PowerPC microprocessor family
 * Copyright (c) 1998-2001  Frank Wille
 *
 * ppc_disasm.c is freeware and may be freely redistributed as long as
 * no modifications are made and nothing is charged for it.
 * Non-commercial usage is allowed without any restrictions.
 * EVERY PRODUCT OR PROGRAM DERIVED DIRECTLY FROM MY SOURCE MAY NOT BE
 * SOLD COMMERCIALLY WITHOUT PERMISSION FROM THE AUTHOR.
 *
 *
 * v1.4  (29.08.2001) phx
 *       AltiVec support.
 * v0.1  (23.05.1998) phx
 *       First version, which implements all PowerPC instructions.
 * v0.0  (09.05.1998) phx
 *       File created.
 */

// Félix Cloutier, 2012-11-02
// I believe Frank Wille made this program available in the goal
// that it will be useful and used for non-commercial purposes.
// With that in mind, I allowed myself to make some slight modifications
// *some* sections of the program, WITH THE ONLY GOAL of reversing the
// adverse effects of aging. The algorithm was not modified. The program
// was not made more powerful. It was merely adapted to this brave new
// world I threw it into.
// All the changes are clearly marked with lines starting by "// Félix Cloutier",
// with the original code commented out.
// I'm so sorry, Mr. Wille. I really did not want to write a new disassembler
// for my open-source project. I hope this reflects the spirit of your licence,
// since it doesn't follow it to the letter.

#ifndef PPC_DISASM_H
#define PPC_DISASM_H


/* version/revision */
#define PPCDISASM_VER 1
#define PPCDISASM_REV 4


/* typedefs */
typedef unsigned int ppc_word;
#ifndef NULL
#define NULL (0L)
#endif


// Félix Cloutier, 2012-11-02
// Adapted to work in an environment where endianness macros are already defined
/* endianess */
#if TARGET_RT_BIG_ENDIAN
# define BIGENDIAN
#else
# define LITTLEENDIAN
#endif

/* BEGIN old code
#if macintosh
#define BIGENDIAN
#endif

#if !defined(BIGENDIAN) && !defined(LITTLEENDIAN)
#error Define either BIGENDIAN or LITTLEENDIAN!
#define BIGENDIAN
#endif
   END old code */

/* general defines */
#define PPCIDXMASK      0xfc000000
#define PPCIDX2MASK     0x000007fe
#define PPCDMASK        0x03e00000
#define PPCAMASK        0x001f0000
#define PPCBMASK        0x0000f800
#define PPCCMASK        0x000007c0
#define PPCMMASK        0x0000003e
#define PPCCRDMASK      0x03800000
#define PPCCRAMASK      0x001c0000
#define PPCLMASK        0x00600000
#define PPCOE           0x00000400
#define PPCVRC          0x00000400
#define PPCDST          0x02000000
#define PPCSTRM         0x00600000

#define PPCIDXSH        26
#define PPCDSH          21
#define PPCASH          16
#define PPCBSH          11
#define PPCCSH          6
#define PPCMSH          1
#define PPCCRDSH        23
#define PPCCRASH        18
#define PPCLSH          21
#define PPCIDX2SH       1

#define PPCGETIDX(x)    (((x)&PPCIDXMASK)>>PPCIDXSH)
#define PPCGETD(x)      (((x)&PPCDMASK)>>PPCDSH)
#define PPCGETA(x)      (((x)&PPCAMASK)>>PPCASH)
#define PPCGETB(x)      (((x)&PPCBMASK)>>PPCBSH)
#define PPCGETC(x)      (((x)&PPCCMASK)>>PPCCSH)
#define PPCGETM(x)      (((x)&PPCMMASK)>>PPCMSH)
#define PPCGETCRD(x)    (((x)&PPCCRDMASK)>>PPCCRDSH)
#define PPCGETCRA(x)    (((x)&PPCCRAMASK)>>PPCCRASH)
#define PPCGETL(x)      (((x)&PPCLMASK)>>PPCLSH)
#define PPCGETIDX2(x)   (((x)&PPCIDX2MASK)>>PPCIDX2SH)
#define PPCGETSTRM(x)   (((x)&PPCSTRM)>>PPCDSH)


/* Disassembler structure, the interface to the application */

struct DisasmPara_PPC {
  ppc_word *instr;              /* pointer to instruction to disassemble */
  ppc_word *iaddr;              /* instr.addr., usually the same as instr */
  char *opcode;                 /* buffer for opcode, min. 10 chars. */
  char *operands;               /* operand buffer, min. 24 chars. */
/* changed by disassembler: */
  unsigned char type;           /* type of instruction, see below */
  unsigned char flags;          /* additional flags */
  unsigned short sreg;          /* register in load/store instructions */
  ppc_word displacement;        /* branch- or load/store displacement */
};

#define PPCINSTR_OTHER      0   /* no additional info for other instr. */
#define PPCINSTR_BRANCH     1   /* branch dest. = PC+displacement */
#define PPCINSTR_LDST       2   /* load/store instruction: displ(sreg) */
#define PPCINSTR_IMM        3   /* 16-bit immediate val. in displacement */

#define PPCF_ILLEGAL   (1<<0)   /* illegal PowerPC instruction */
#define PPCF_UNSIGNED  (1<<1)   /* unsigned immediate instruction */
#define PPCF_SUPER     (1<<2)   /* supervisor level instruction */
#define PPCF_64        (1<<3)   /* 64-bit only instruction */
#define PPCF_ALTIVEC   (1<<4)   /* AltiVec instruction */


/* ppc_disasm.o prototypes */
#ifndef PPC_DISASM_C
extern ppc_word *PPC_Disassemble(struct DisasmPara_PPC *);
#endif

#endif