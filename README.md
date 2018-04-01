# ReGameDLL_CS [![Build Status](http://teamcity.rehlds.org/app/rest/builds/buildType:(id:ReGameDLLCs_Publish)/statusIcon)](http://teamcity.rehlds.org/viewType.html?buildTypeId=ReGameDLLCs_Publish&guest=1) [![Download](http://rehlds.org/version/regamedll.svg)](http://teamcity.rehlds.org/guestAuth/downloadArtifacts.html?buildTypeId=ReGameDLL_Publish&buildId=lastSuccessful) [![Percentage of issues still open](http://isitmaintained.com/badge/open/s1lentq/ReGameDLL_CS.svg)](http://isitmaintained.com/project/s1lentq/ReGameDLL_CS "Percentage of issues still open") [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) <img align="right" src="https://cloud.githubusercontent.com/assets/5860435/20008568/b3623150-a2d3-11e6-85f3-0d6571045fc9.png" alt="Counter-Strike 1.6 GameDLL" />
Reverse-engineered gamedll (mp.dll / Counter-Strike)

## What is this?
Regamedll_CS is a result of reverse engineering of original library mod HLDS (build 6153beta) using DWARF debug info embedded into linux version of HLDS, cs.so

## Goals of the project
* Provide more stable (than official) version of Counter-Strike game with extended API for mods and plugins

## How can use it?
ReGameDLL_CS is fully compatible with official mod CS 1.6 / CZero by Valve. All you have to do is to download binaries and replace original mp.dll/cs.so

Compiled binaries are available here: [link](http://nexus.rehlds.org/nexus/content/repositories/regamedll-dev/regamedll/regamedll/)

Archive's bin directory contains 2 subdirectories, 'bugfixed' and 'pure'
* 'pure' version is designed to work exactly as official mod CS
* 'bugfixed' version contains some fixes and improvements

<b>Warning!</b> ReGameDLL_CS is not binary compatible with original hlds since it's compiled with compilers other than ones used for original mod CS. This means that plugins that do binary code analysis (Orpheu for example) probably will not work with ReGameDLL_CS.

## Configuration (cvars)
| CVar                          | Default | Min | Max          | Description                                    |
| :---------------------------- | :-----: | :-: | :----------: | :--------------------------------------------- |
| mp_freeforall                 | 0       | 0   | 1            | The style of gameplay where there aren't any teams (FFA mode)<br/>`0` disabled <br/>`1` enabled |
| mp_autoteambalance            | 1       | 0   | 2            | Auto balancing of teams.<br/>`0` disabled <br/>`1` on after next round<br/>`2` on next round |
| mp_buytime                    | 1.5     | 0.0 | -            | Designate the desired amount of buy time for each round. (in minutes)<br />`-1` means no time limit<br />`0` disable buy |
| mp_maxmoney                   | 16000   | 0   | `0x7FFFFFFF` | The maximum allowable amount of money in the game |
| mp_round_infinite             | 0       | 0   | 1            | Flags for fine grained control (choose as many as needed)<br/>`0` disabled<br/>`1` enabled<br/><br/>or flags<br/>`a` block round time round end check<br/>`b` block needed players round end check<br/>`c` block VIP assassination/success round end check<br/>`d` block prison escape round end check<br/>`e` block bomb round end check<br/>`f` block team extermination round end check<br/>`g` block hostage rescue round end check<br/><br/>`Example setting:` "ae" blocks round time and bomb round end checks |
| mp_roundover                  | 0       | -   | -            | The round by expired time will be over, if on a map it does not have the scenario of the game.<br/>`0` disabled<br/>`1` enabled |
| mp_round_restart_delay        | 5       | -   | -            | Number of seconds to delay before restarting a round after a win. |
| mp_hegrenade_penetration      | 0       | 0   | 1            | Disable grenade damage through walls.<br/>`0` disabled<br/>`1` enabled |
| mp_nadedrops                  | 0       | 0   | 2            | Drop a grenade after player death.<br/>`0` disabled<br/>`1` drop one the grenade<br/>`2` drop an everyone grenades |
| mp_roundrespawn_time          | 20      | 0   | -            | Player cannot respawn until next round if more than N seconds has elapsed since the beginning round |
| mp_auto_reload_weapons        | 0       | 0   | 1            | Automatically reload each weapon on player spawn.<br/>`0` disabled<br/>`1` enabled |
| mp_refill_bpammo_weapons      | 0       | 0   | 3            | Refill amount of backpack ammo up to the max.<br/>`0` disabled<br/>`1` refill backpack ammo on player spawn<br/>`2` refill backpack ammo on player spawn and on the purchase of the item<br/>`3` refill backpack ammo on each weapon reload |
| mp_auto_join_team             | 0       | 0   | 1            | Automatically joins the team.<br/>`0` disabled<br/>`1` enable (Use in conjunction with the cvar humans_join_team any/CT/T) |
| mp_max_teamkills              | 3       | 0   | -            | Maximum number of allowed teamkills before autokick. Used when enabled mp_autokick. |
| mp_fragsleft                  | -       | -   | -            | Is the number of frags left, if you have set mp_fraglimit. You just type mp_fragsleft in server console, and it tells you the number of frags left depending of mp_fraglimit. |
| mp_fraglimit                  | 0       | 0   | -            | If set to something other than 0, when anybody’s scored reaches mp_fraglimit the server changes map.<br />`0` means no limit |
| mp_timeleft                   | -       | -   | -            | Is the number of time left before the map changes, if you have set mp_timelimit. You just type mp_timeleft in server console, and it tells you the number of time left depending of mp_timelimit. |
| mp_timelimit                  | 0       | -   | -            | Period between map rotations.<br />`0` means no limit |
| mp_forcerespawn               | 0       | 0   | -            | Players will automatically respawn when killed.<br/>`0` disabled<br/>`>0.00001` time delay to respawn |
| mp_hostage_hurtable           | 1       | 0   | 1            | The hostages can take damage.<br/>`0` disabled<br/>`1` from any team<br/>`2` only from `CT`<br/>`3` only from `T` |
| mp_show_radioicon             | 1       | 0   | 1            | Show radio icon.<br/>`0` disabled<br/>`1` enabled |
| mp_old_bomb_defused_sound     | 1       | 0   | 1            | Play "Bomb has been defused" sound instead of "Counter-Terrorists win" when bomb was defused<br/>`0` disabled<br/>`1` enabled |
| showtriggers                  | 0       | 0   | 1            | Debug cvar shows triggers. |
| sv_alltalk                    | 0       | 0   | 4            | When players can hear each other ([further explanation](../../wiki/sv_alltalk)).<br/>`0` dead don't hear alive<br/>`1` no restrictions<br/>`2` teammates hear each other<br/>`3` Same as 2, but spectators hear everybody<br/>`4` alive hear alive, dead hear dead and alive.
| bot_deathmatch                | 0       | 0   | 1            | Set's the mode for the zBot.<br/>`0` disabled<br/>`1` enable mode Deathmatch and not allow to do the scenario |
| bot_quota_mode                | normal  | -   | -            | Determines the type of quota.<br/>`normal` default behaviour<br/>`fill` the server will adjust bots to keep `N` players in the game, where `N` is bot_quota |
| mp_item_staytime              | 300     | -   | -            | Time to remove item that have been dropped from the players. |
| mp_legacy_bombtarget_touch    | 1       | 0   | 1            | Legacy func_bomb_target touch. New one is more strict. <br/>`0` New behavior<br/>`1` Legacy behavior|
| mp_respawn_immunitytime       | 0       | 0   | -            | Specifies the players defense time after respawn. (in seconds).<br/>`0` disabled<br/>`>0.00001` time delay to remove protection |

## How to install zBot for CS 1.6?
* Extract all the files from an [archive](regamedll/extra/zBot/bot_profiles.zip?raw=true)
* Enter `-bots` option at the command line HLDS

## Build instructions
There are several software requirements for building Regamedll_CS:
<ol>
<li>Java Development Kit (JDK) 7+ (http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html)</li>
<li>For Windows: Visual Studio 2015 and later</li>
<li>For Linux: Intel C++ Compiler 15 and later</li>
</ol>

### Checking requirements
#### JDK version
Windows<pre>&gt; %JAVA_HOME%\bin\javac -version
javac 1.8.0_25
</pre>

Linux
<pre>$ javac -version
javac 1.7.0_65
</pre>

#### Visual Studio
Help -> About

#### ICC
<pre>$ icc --version
icc (ICC) 15.0.1 20141023
</pre>

### Building
On Windows:
<pre>gradlew --max-workers=1 clean buildRelease</pre>
* For faster building without unit tests use this:exclamation:
<pre>gradlew --max-workers=1 clean buildFixes</pre>

On Linux:
<pre>./gradlew --max-workers=1 clean buildRelease</pre>

* For faster building without unit tests use this:exclamation:
<pre>./gradlew --max-workers=1 clean buildFixes</pre>

Compiled binaries will be placed in the build/binaries/ directory

### Credits
Thanks to the project [ReHLDS](https://github.com/dreamstalker/rehlds) ( ReGameDLL_CS was created on the basis of ReHLDS )

## How can I help the project?
Just install it on your game server and report problems you faced.<br />
Merge requests are also welcome :shipit:
