/*
*
*    This program is free software; you can redistribute it and/or modify it
*    under the terms of the GNU General Public License as published by the
*    Free Software Foundation; either version 2 of the License, or (at
*    your option) any later version.
*
*    This program is distributed in the hope that it will be useful, but
*    WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not, write to the Free Software Foundation,
*    Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*    In addition, as a special exception, the author gives permission to
*    link the code of this program with the Half-Life Game Engine ("HL
*    Engine") and Modified Game Libraries ("MODs") developed by Valve,
*    L.L.C ("Valve").  You must obey the GNU General Public License in all
*    respects for all of the code used other than the HL Engine and MODs
*    from Valve.  If you modify this file, you may extend this exception
*    to your version of the file, but you are not obligated to do so.  If
*    you do not wish to do so, delete this exception statement from your
*    version.
*
*/

#ifndef COMMON_H
#define COMMON_H
#ifdef _WIN32
#pragma once
#endif

#include "maintypes.h"
#include "bspfile.h"
#include "FileSystem.h"
#include "info.h"

// Don't allow overflow
#define SIZEBUF_CHECK_OVERFLOW		0
#define SIZEBUF_ALLOW_OVERFLOW		BIT(0)
#define SIZEBUF_OVERFLOWED		BIT(1)

/* <6ae> ../common/common.h:82 */
typedef struct sizebuf_s
{
	const char *buffername;
	uint16_t flags;
	byte *data;
	int maxsize;
	int cursize;
} sizebuf_t;

/* <270aa> ../common/common.h:297 */
typedef struct downloadtime_s
{
	qboolean bUsed;
	float fTime;
	int nBytesRemaining;
} downloadtime_t;

/* <19fa2> ../common/common.h:303 */
typedef struct incomingtransfer_s
{
	qboolean doneregistering;
	int percent;
	qboolean downloadrequested;
	downloadtime_t rgStats[8];
	int nCurStat;
	int nTotalSize;
	int nTotalToTransfer;
	int nRemainingToTransfer;
	float fLastStatusUpdate;
	qboolean custom;
} incomingtransfer_t;

#ifndef _WIN32
#define _strlwr(p) for (int i = 0; p[i] != 0; i++) p[i] = tolower(p[i]);
#endif // _WIN32

inline double M_sqrt(int value) {
	return sqrt(value);
}

inline float M_sqrt(float value) {
	return _mm_cvtss_f32(_mm_sqrt_ss(_mm_load_ss(&value)));
}

inline double M_sqrt(double value) {
	double ret;
	auto v = _mm_load_sd(&value);
	_mm_store_sd(&ret, _mm_sqrt_sd(v, v));
	return ret;
}

#define printf2 _printf2
#define chatf _print_chat

#define Q_isspace isspace
#define Q_isalnum isalnum
#define Q_isalpha isalpha

#define Q_malloc malloc
#define Q_calloc calloc
#define Q_alloca alloca
#define Q_free free

#define Q_close _close
#define Q_write _write
#define Q_memset memset
#define Q_memcpy memcpy
#define Q_strlen strlen
#define Q_memcmp memcmp
#define Q_strcpy strcpy
#define Q_strncpy strncpy
#define Q_strrchr strrchr
#define Q_strcat strcat
#define Q_strncat strncat
#define Q_strcmp strcmp
#define Q_strncmp strncmp
//#define Q_strcasecmp _stricmp		// Use Q_stricmp
//#define Q_strncasecmp _strnicmp	// Use Q_strnicmp
#define Q_sscanf sscanf
#define Q_strdup _strdup
#define Q_stricmp _stricmp
#define Q_strnicmp _strnicmp
#define Q_strstr strstr
#define Q_strchr strchr
#define Q_strrchr strrchr
#define Q_strlwr _strlwr
#define Q_sprintf sprintf
#define Q_snprintf _snprintf
#define Q_atoi atoi
#define Q_atof atof
#define Q_toupper toupper
#define Q_memmove memmove
//#define Q_strtoull strtoull
//#define Q_FileNameCmp FileNameCmp
#define Q_vsnprintf _vsnprintf
#define Q_vsnwprintf _vsnwprintf
#define Q_abs abs
#define Q_fabs fabs
#define Q_tan tan
#define Q_atan atan
#define Q_atan2 atan2
#define Q_acos acos
#define Q_cos cos
#define Q_sin sin
#define Q_sqrt sqrt
#define Q_pow pow
#define Q_fmod fmod
#define Q_fopen fopen
#define Q_fprintf fprintf
#define Q_fclose fclose

#ifdef REGAMEDLL_FIXES
#undef Q_sqrt
#define Q_sqrt M_sqrt
#endif

#endif // COMMON_H
