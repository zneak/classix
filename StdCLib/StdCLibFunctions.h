//
// StdCLibFunctions.h
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

#ifndef Classix_StdCLibFunctions_h
#define Classix_StdCLibFunctions_h

#include "MachineState.h"

extern "C"
{
	using PPCVM::MachineState;
	struct StdCLibGlobals;

	void StdCLib___abort(StdCLibGlobals* globals, MachineState* state);
	void StdCLib___assertprint(StdCLibGlobals* globals, MachineState* state);
	void StdCLib___DebugMallocHeap(StdCLibGlobals* globals, MachineState* state);
	void StdCLib___GetTrapType(StdCLibGlobals* globals, MachineState* state);
	void StdCLib___growFileTable(StdCLibGlobals* globals, MachineState* state);
	void StdCLib___NumToolboxTraps(StdCLibGlobals* globals, MachineState* state);
	void StdCLib___RestoreInitialCFragWorld(StdCLibGlobals* globals, MachineState* state);
	void StdCLib___RevertCFragWorld(StdCLibGlobals* globals, MachineState* state);
	void StdCLib___setjmp(StdCLibGlobals* globals, MachineState* state);
	void StdCLib___vec_longjmp(StdCLibGlobals* globals, MachineState* state);
	void StdCLib___vec_setjmp(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__addDevHandler(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__badPtr(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__Bogus(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__BreakPoint(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__bufsync(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__c2pstrcpy(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__coClose(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__coExit(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__coFAccess(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__coIoctl(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__coRead(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__coreIOExit(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__coWrite(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__cvt(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__DoExitProcs(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__doprnt(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__doscan(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__exit(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__faccess(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__filbuf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__findiop(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__flsbuf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__fsClose(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__fsFAccess(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__fsIoctl(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__fsRead(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__FSSpec2Path(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__fsWrite(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__GetAliasInfo(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__getDevHandler(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__getIOPort(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__memchr(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__memcpy(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__ResolveFileAlias(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__rmemcpy(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__RTExit(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__RTInit(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__SA_DeletePtr(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__SA_GetPID(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__SA_SetPtrSize(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__syClose(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__syFAccess(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__syIoctl(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__syRead(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__syWrite(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__uerror(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__wrtchk(StdCLibGlobals* globals, MachineState* state);
	void StdCLib__xflsbuf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_abort(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_abs(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_access(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_asctime(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_atexit(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_atof(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_atoi(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_atol(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_atoll(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_binhex(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_bsearch(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_calloc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_clearerr(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_clock(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_close(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ConvertTheString(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_creat(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ctime(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_difftime(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_div(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_dup(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ecvt(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_exit(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_faccess(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fclose(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fcntl(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fcvt(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fdopen(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_feof(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ferror(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fflush(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fgetc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fgetpos(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fgets(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fopen(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fprintf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fputc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fputs(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fread(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_free(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_freopen(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fscanf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fseek(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fsetfileinfo(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fsetpos(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_FSMakeFSSpec_Long(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_FSp_creat(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_FSp_faccess(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_FSp_fopen(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_FSp_freopen(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_FSp_fsetfileinfo(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_FSp_open(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_FSp_remove(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_FSp_rename(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_FSp_unlink(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_FSSpec2Path_Long(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ftell(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_fwrite(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_getc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_getchar(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_getenv(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_getIDstring(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_getpid(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_gets(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_getw(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_gmtime(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_IEResolvePath(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ioctl(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_isalnum(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_isalpha(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_isascii(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_iscntrl(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_isdigit(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_isgraph(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_islower(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_isprint(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ispunct(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_isspace(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_isupper(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_isxdigit(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_labs(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ldiv(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_llabs(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_lldiv(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_localeconv(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_localtime(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_longjmp(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_lseek(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_MakeResolvedFSSpec(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_MakeResolvedFSSpec_Long(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_MakeResolvedPath(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_MakeResolvedPath_Long(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_MakeTheLocaleString(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_malloc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_mblen(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_mbstowcs(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_mbtowc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_memccpy(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_memchr(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_memcmp(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_memcpy(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_memmove(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_memset(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_mktemp(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_mktime(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_open(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ParseTheLocaleString(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_perror(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLpos(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrcat(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrchr(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrcmp(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrcpy(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrlen(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrncat(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrncmp(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrncpy(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrpbrk(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrrchr(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrspn(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_PLstrstr(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_printf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_putc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_putchar(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_puts(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_putw(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_qsort(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_raise(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_rand(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_read(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_realloc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_remove(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_rename(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ResolveFolderAliases(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ResolveFolderAliases_Long(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ResolvePath(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ResolvePath_Long(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_rewind(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_scanf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_setbuf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_setenv(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_setlocale(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_setvbuf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_signal(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_sprintf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_srand(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_sscanf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strcat(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strchr(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strcmp(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strcoll(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strcpy(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strcspn(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strerror(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strftime(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strlen(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strncat(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strncmp(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strncpy(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strpbrk(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strrchr(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strspn(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strstr(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strtod(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strtok(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strtol(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strtoll(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strtoul(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strtoull(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_strxfrm(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_system(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_time(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_tmpfile(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_tmpnam(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_toascii(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_tolower(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_toupper(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_TrapAvailable(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_ungetc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_unlink(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_vec_calloc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_vec_free(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_vec_malloc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_vec_realloc(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_vfprintf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_vprintf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_vsprintf(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_wcstombs(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_wctomb(StdCLibGlobals* globals, MachineState* state);
	void StdCLib_write(StdCLibGlobals* globals, MachineState* state);
}

#endif
