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

#ifndef NAV_FILE_H
#define NAV_FILE_H
#ifdef _WIN32
#pragma once
#endif

#undef min
#undef max

#include <list>
#include <vector>
#include <algorithm>

#include <fcntl.h>
#include <sys/stat.h>
#include <assert.h>

#ifndef _WIN32

#include <unistd.h>

#endif // _WIN32

// The 'place directory' is used to save and load places from
// nav files in a size-efficient manner that also allows for the 
// order of the place ID's to change without invalidating the
// nav files.
//
// The place directory is stored in the nav file as a list of 
// place name strings.  Each nav area then contains an index
// into that directory, or zero if no place has been assigned to 
// that area.

/* <4ecb57> ../game_shared/bot/nav_file.cpp:54 */
class PlaceDirectory
{
public:
	typedef unsigned short EntryType;

	void Reset(void);
	bool IsKnown(Place place) const;		// return true if this place is already in the directory
	EntryType GetEntry(Place place) const;		// return the directory entry corresponding to this Place (0 = no entry)
	void AddPlace(Place place);			// add the place to the directory if not already known
	Place EntryToPlace(EntryType entry) const;	// given an entry, return the Place
	void Save(int fd);				// store the directory
	void Load(SteamFile *file);			// load the directory

private:
	std::vector<Place> m_directory;
};

#ifdef HOOK_GAMEDLL
#define placeDirectory (*pplaceDirectory)
#endif // HOOK_GAMEDLL

extern PlaceDirectory placeDirectory;

NOBODY char *GetBspFilename(const char *navFilename);
NOBODY void COM_FixSlashes(char *pname);
NOBODY bool SaveNavigationMap(const char *filename);
NOBODY void LoadLocationFile(const char *filename);
NOBODY void SanityCheckNavigationMap(const char *mapName);
NOBODY NavErrorType LoadNavigationMap(void);

extern void (*pLoadNavigationMap)(void);

#endif // NAV_FILE_H
