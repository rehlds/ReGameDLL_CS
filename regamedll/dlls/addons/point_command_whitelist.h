/*
*
*   This program is free software; you can redistribute it and/or modify it
*   under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or (at
*   your option) any later version.
*
*/

#pragma once

//-----------------------------------------------------------------------------
// Whitelist of commands allowed for point_servercommand / point_clientcommand.
// By default only harmless gameplay cvars are allowed.
// Any command not in the list is blocked and written to the log.
// Additional commands can be allowed via the mp_point_servercommand_whitelist cvar.
//-----------------------------------------------------------------------------
static const char *g_allowedServerCommands[] =
{
	// safe gameplay settings that maps commonly change
	"mp_roundtime",
	"mp_freezetime",
	"mp_buytime",
	"mp_c4timer",
	"sv_gravity",
	"sv_friction",
	"sv_stepsize",
	"sv_maxspeed",
	"sv_stopspeed",
	"sv_accelerate",
	"sv_airaccelerate",
	"sv_wateraccelerate",
	"sv_waterfriction",
	nullptr
};

//-----------------------------------------------------------------------------
// Check for dangerous characters in a command argument (injection protection).
// Returns true if the string contains characters that allow command chaining
// or argument injection.
//-----------------------------------------------------------------------------
inline bool CommandContainsDangerousChars(const char *cmd)
{
	if (!cmd)
		return true;

	for (; *cmd; ++cmd)
	{
		const char c = *cmd;
		if (c == ';' || c == '|' || c == '&' || c == '`' || c == '$' ||
			c == '<' || c == '>' || c == '(' || c == ')' || c == '{' || c == '}' ||
			c == '!' || c == '\n' || c == '\r')
		{
			return true;
		}
	}

	return false;
}

//-----------------------------------------------------------------------------
// Case-insensitive check of a command name against the built-in whitelist.
//-----------------------------------------------------------------------------
inline bool IsBuiltinCommandAllowed(const char *cmdName)
{
	if (!cmdName || cmdName[0] == '\0')
		return false;

	for (int i = 0; g_allowedServerCommands[i] != nullptr; ++i)
	{
		if (Q_stricmp(cmdName, g_allowedServerCommands[i]) == 0)
			return true;
	}

	return false;
}
