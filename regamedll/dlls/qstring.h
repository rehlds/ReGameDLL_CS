/*
*
*   This program is free software; you can redistribute it and/or modify it
*   under the terms of the GNU General Public License as published by the
*   Free Software Foundation; either version 2 of the License, or (at
*   your option) any later version.
*
*   This program is distributed in the hope that it will be useful, but
*   WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*   General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software Foundation,
*   Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*   In addition, as a special exception, the author gives permission to
*   link the code of this program with the Half-Life Game Engine ("HL
*   Engine") and Modified Game Libraries ("MODs") developed by Valve,
*   L.L.C ("Valve").  You must obey the GNU General Public License in all
*   respects for all of the code used other than the HL Engine and MODs
*   from Valve.  If you modify this file, you may extend this exception
*   to your version of the file, but you are not obligated to do so.  If
*   you do not wish to do so, delete this exception statement from your
*   version.
*
*/

#pragma once

#define QSTRING_DEFINE

// Quake string (helper class)
class QString final
{
public:
#if XASH_64BIT
	using qstring_t = int;
#else
	using qstring_t = unsigned int;
#endif

	QString();
	QString(qstring_t string);

	bool IsNull() const;
	bool IsNullOrEmpty() const;

	// Copy the array
	QString &operator=(const QString &other);

	bool operator==(qstring_t string) const;
	bool operator==(const QString &s) const;
	bool operator==(const char *pszString) const;

	operator const char *() const;
	operator qstring_t() const;
	const char *str() const;

private:
	qstring_t m_string;
};

constexpr QString::qstring_t iStringNull = {0};

#ifdef USE_QSTRING
#define string_t QString
#endif

#include "const.h"
#include "edict.h"
#include "eiface.h"
#include "enginecallback.h"

extern globalvars_t *gpGlobals;

#define STRING(offset)   ((const char *)(gpGlobals->pStringBase + (QString::qstring_t)(offset)))
#if XASH_64BIT
// Xash3D FWGS in 64-bit mode has internal string pool which allows mods to continue use 32-bit string_t
inline int MAKE_STRING(const char *str)
{
	ptrdiff_t diff = str - STRING(0);
	if (diff >= INT_MIN && diff <= INT_MAX)
		return (int)diff;

	return ALLOC_STRING(str);
}
#else
#define MAKE_STRING(str) ((QString::qstring_t)(str) - (QString::qstring_t)(STRING(0)))
#endif

// Inlines
inline QString::QString(): m_string(iStringNull) {}
inline QString::QString(qstring_t string): m_string(string) {}

inline bool QString::IsNull() const
{
	return m_string == iStringNull;
}

inline bool QString::IsNullOrEmpty() const
{
	return IsNull() || (&gpGlobals->pStringBase[m_string])[0] == '\0';
}

inline QString &QString::operator=(const QString &other)
{
	m_string = other.m_string;
	return (*this);
}

inline bool QString::operator==(qstring_t string) const
{
	return m_string == string;
}

inline bool QString::operator==(const QString &s) const
{
	return m_string == s.m_string;
}

inline bool QString::operator==(const char *pszString) const
{
	return Q_strcmp(&gpGlobals->pStringBase[m_string], pszString) == 0;
}

inline const char *QString::str() const
{
	return &gpGlobals->pStringBase[m_string];
}

inline QString::operator const char *() const
{
	return str();
}

inline QString::operator qstring_t() const
{
	return m_string;
}
