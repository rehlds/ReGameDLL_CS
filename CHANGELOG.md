# [ReGameDLL_CS](https://github.com/rehlds/ReGameDLL_CS) Changelog


> [!CAUTION]
>
> This versions and changelogs were brought only for historical purposes from [DevCS Thread](https://dev-cs.ru/resources/67/updates) and not avalible at github.
>

## `5.14.0.453` - 2020-02-14

### Added
- Enhanced CCSPlayerItem::GetItemInfo

### Changed
- Bump minor API version

### Fixed
- None

## `5.13.0.451` - 2020-02-07

### Added
- None

### Changed
- None

### Fixed
- build.gradle: Fix missing brace
- Fixed some compiler warnings
- Fixed appversion.sh when the path may contain spaces

## `5.13.0.447` - 2020-01-16

### Added
- Implemented CVar mp_scoreboard_showdefkit
- ZBot: Implemented cvar bot_freeze

### Changed
- CVar mp_fadetoblack enhancement (close #463) (#471)
- Update README.md
- func_mortar_field: Use explosion instead of a flash

### Fixed
- C4: Fixed a bug when a player died by explosive targets triggered by the main bomb
- USP: Fixed jitter effect when playing an animation of adding a silencer

## `5.13.0.439` - 2020-01-15

### Added
- None

### Changed
- None

### Fixed
- DefaultDeploy fix allocation string issue for 3rd-party
- Fix hitsounds on vehicles
- [CZERO] Fix count hostages ("ScenarioIcon" message)
- func_breakable: Remove m_iszSpawnObject on restart round

## `5.13.0.434` - 2019-12-28

### Added
- None

### Changed
- None

### Fixed
- Fix bug with radio commands (#480)

## `5.13.0.433` - 2019-12-25

### Added
- None

### Changed
- Ignorerad command small optimization

### Fixed
- Typo fix

## `5.13.0.431` - 2019-12-20

### Added
- None

### Changed
- None

### Fixed
- Fix voice API bug (#469)

## `5.13.0.430` - 2019-12-17

### Added
- New CVar mp_give_player_c4

### Changed
- Move some new features to REGAMEDLL_ADD
- Move beta features to release stage

### Fixed
- None

## `5.13.0.427` - 2019-12-14

### Added
- Add API to set if player can hear another player

### Changed
- None

### Fixed
- None

## `5.12.0.426` - 2019-12-13

### Added
- None

### Changed
- None

### Fixed
- Spelling mistake on naming fix

## `5.12.0.425` - 2019-11-09

### Added
- Implement RG_CBasePlayer_DropIdlePlayer hook (#444)

### Changed
- None

### Fixed
- None

## `5.12.0.424` - 2019-10-30

### Added
- Add new console command: mp_swapteams
- New CVar mp_weapons_allow_map_placed

### Changed
- Bots: safe check for DoorActivator
- Implement RG_CBasePlayerWeapon_CanDeploy & CBasePlayerWeapon_DefaultDeploy hooks

### Fixed
- Fix CBasePlayerWeapon_CanDeploy hook for grenades
- Fix CBasePlayer::CanDeploy

## `5.11.0.420` - 2019-10-12

### Added
- None

### Changed
- Refactoring (#418)
  - Remove unused cheat impulses
  - Disable flashlight on kill
  - Remove unused entities (from HL)
  - Code style fixes

### Fixed
- nadedrop fixes
- Close equipmenu (VGUIMenus) when the player left the purchase area
- Hostage "far use" fix
- Reset player basevelocity on spawn
- Weapon HUD fixes

## `5.11.0.418` - 2019-09-29

### Added
- None

### Changed
- Introduce end-of-line normalization
- Minor refactoring

### Fixed
- Don't respawn if m_flRespawnPending isn't set
- Ignore submodules for detecting local changes

## `5.11.0.417` - 2019-09-23

### Added
- Add "give" client cheat command (e.g., give weapon_ak47) like in CS:GO

### Changed
- Added gitattributes and updated editorconfig files

### Fixed
- CGrenade::Use: Fixed spam sound on defuse start if player is in the air
- Autobuy/Rebuy fixes
- Invisible shield fix
- Fix typo
- Fix newlines

## `5.11.0.405` - 2019-09-18

### Added
- Add CVar mp_show_scenarioicon

### Changed
- Grenade::Use: Move #C4_Defuse_Must_Be_On_Ground to the beginning of defusing

### Fixed
- None

## `5.11.0.403` - 2019-09-17

### Added
- None

### Changed
- None

### Fixed
- Fix func_healthcharger & func_recharge bug
- Fix entity leak
- item_airbox: Little optimizations
- CCSPlayer::RemoveShield: Enhanced
- CCSPlayer::GiveNamedItemEx: Drop weapon_elite when getting weapon_shield

## `5.11.0.401` - 2019-09-14

### Added
- Add prevent jump flag to iuser3 data

### Changed
- None

### Fixed
- None

## `5.11.0.400` - 2019-09-11

### Added
- None

### Changed
- Enhanced behavior of armoury_entity with czbot, don't pick up if forbidden by cvars
- Minor refactoring

### Fixed
- armoury_entity: Don't pick up dual elites if the player carries a shield

## `5.11.0.398` - 2019-09-08

### Added
- None

### Changed
- None

### Fixed
- mp_infinite_ammo 1: Fixed grenade throw

## `5.11.0.397` - 2019-09-04

### Added
- Implemented cvar mp_unduck_method

### Changed
- build.gradle: Remove extralib stdc++
- pm_shared.cpp: Minor refactoring

### Fixed
- None

## `5.11.0.394` - 2019-08-30

### Added
- Implement RG_CBasePlayer_UseEmpty hook
- Add force visibility effect

### Changed
- Update const.h and SDK

### Fixed
- Disconnected players func_tank fix
- Fix potential memory leak for CRenderFxManager

## `5.9.0.387` - 2019-08-28

### Added
- Implemented cvar mp_infinite_grenades

### Changed
- Reworked cvar mp_infinite_ammo, not including grenades
- Update README.md

### Fixed
- QuaternionSlerp: Fix GCC issue & minor refactoring
- Unittest-win: Fixed demo failed
- Missing initialization for member m_iWeaponInfiniteIds

## `5.9.0.379` - 2019-08-16

### Added
- Implemented cheat command impulse 255

### Changed
- None

### Fixed
- Fix C4 defuse glitch (#383)
- Fix potential memory leak for CRenderFxManager
- RadiusFlash: Fixed eyes position

## `5.9.0.369` - 2019-08-11

### Added
- None

### Changed
- Allow immediately change name for proxy
- Make restartable for func_healthcharger and func_recharge entities

### Fixed
- Fix bug related to field "dmdelay" not working properly

## `5.9.0.367` - 2019-08-08

### Added
- None

### Changed
- None

### Fixed
- Fix VIP mechanic

## `5.9.0.366` - 2019-07-30

### Added
- New CVar mp_buy_anywhere

### Changed
- Radio enhancement cvars

### Fixed
- Fix CVar's register

## `5.9.0.363` - 2019-07-17

### Added
- None

### Changed
- None

### Fixed
- Fix dead players kick for idle

## `5.9.0.362` - 2019-06-25

### Added
- Added new cvar bot_join_delay

### Changed
- Enhanced bot_quota_mode
- Reworked bot_quota_mode and removed bot_quota_match cvar

### Fixed
- Minor refactoring
- Print reason kick and added reason message for kick

## `5.9.0.355` - 2019-06-13

### Added
- None

### Changed
- None

### Fixed
- Some minor changes
- UTIL_HumansInGame: Ignore HLTV

## `5.9.0.353` - 2019-06-08

### Added
- None

### Changed
- Minor refactoring CBasePlayer::TakeDamage

### Fixed
- Fix cvar ff_damage_reduction_grenade: don't reduce damage to enemies
- Fix README.md
- Enhanced point_servercommand, point_clientcommand: Added reset of cvar values on remove an entity or change level

## `5.9.0.349` - 2019-06-08

### Added
- Add CVar: mp_afk_bomb_drop_time

### Changed
- None

### Fixed
- None

## `5.9.0.345` - 2019-06-06

### Added
- Added API hook CBasePlayer::HintMessageEx
- Added cvars:
  - mp_scoreboard_showhealth
  - mp_scoreboard_showmoney
  - ff_damage_reduction_bullets
  - ff_damage_reduction_grenade
  - ff_damage_reduction_grenade_self
  - ff_damage_reduction_other

### Changed
- Changed default values for cvars:
  - ff_damage_reduction_other
  - ff_damage_reduction_grenade
- Updated latest changes from ValveSoftware/halflife.

### Fixed
- Fixed fail tests.
- Fixed some GCC warnings.
- Fixed work of cvar bot_chatter "radio" (zbots now correctly send radio commands to chat).
- Fixed potential memory leaks in CUtlVector.

## `5.7.0.330` - 2019-04-23

### Added
- None

### Changed
- Reduced allowable money limit (HUD can't draw more than 999k).

### Fixed
- None

## `5.7.0.329` - 2019-04-17

### Added
- Added cvar mp_hullbounds_sets (0/1).

### Changed
- None

### Fixed
- None

## `5.7.0.328` - 2019-04-17

### Added
- None

### Changed
- None

### Fixed
- Fixed player's velocity on pushable use.

## `5.7.0.327` - 2019-04-09

### Added
- Added cvar mp_allow_point_servercommand to disable point_servercommand entities.

### Changed
- None

### Fixed
- Fixed potential abuse of point_servercommand entities.

## `5.7.0.325` - 2019-04-08

### Added
- None

### Changed
- None

### Fixed
- Fixed buffer overflow.

## `5.7.0.324` - 2019-04-07

### Added
- Implemented point entities:
  - point_clientcommand
  - point_servercommand

### Changed
- None

### Fixed
- None

## `5.7.0.323` - 2019-03-07

### Added
- None

### Changed
- None

### Fixed
- Fixed dead player inclination.

## `5.7.0.322` - 2019-01-13

### Added
- Added base damage for M3 and XM1014.

### Changed
- None

### Fixed
- Fixed m_flBaseDamageSil.

## `5.7.0.321` - 2019-01-07

### Added
- None

### Changed
- Changed int type of variable to bool.

### Fixed
- Some minor fixes.

## `5.7.0.320` - 2019-01-07

### Added
- Added m_flBaseDamage member.

### Changed
- None

### Fixed
- None

## `5.7.0.319` - 2018-12-23

### Added
- Added iuser3 flag PLAYER_PREVENT_CLIMB.

### Changed
- None

### Fixed
- None

## `5.7.0.318` - 2018-10-31

### Added
- None

### Changed
- Enhanced "endround" command.
- Updated bot vision:
  - Bots can't see invisible enemies.
  - Bots ignore enemies with flag FL_NOTARGET.

### Fixed
- None

## `5.7.0.316` - 2018-10-27

### Added
- Added cvar mp_kill_filled_spawn.

### Changed
- None

### Fixed
- Fixed players getting stuck in spawn.

## `5.7.0.314` - 2018-10-06

### Added
- None

### Changed
- None

### Fixed
- Resolved issue #307.

## `5.7.0.313` - 2018-09-10

### Added
- None

### Changed
- None

### Fixed
- Fixed third-party bots joining teams based on humans_join_team cvar.

## `5.7.0.312` - 2018-05-31

### Added
- None

### Changed
- Enhanced mp_respawn_immunitytime.

### Fixed
- Refused support for CS 1.8.2 hacks (use CS 1.8.3).

## `5.7.0.310` - 2018-05-27

### Added
- Added new point-entity trigger_random.

### Changed
- Reworked publish process.
- Cosmetic changes.

### Fixed
- Fixed circular dependency on GCC 7.3.
- Fixed compiling with MSVC and ICC.

## `5.7.0.302` - 2018-05-22

### Added
- Added GCC toolchain support.

### Changed
- Cosmetic changes.

### Fixed
- Fixed ASM inline for GCC.
- Fixed compiling with MSVC.

## `5.7.0.301` - 2018-04-14

### Added
- Added hook check penetration.

### Changed
- None

### Fixed
- Crash fix.

## `5.7.0.298` - 2018-04-02

### Added
- None

### Changed
- None

### Fixed
- Fixed bug where mp_fraglimit is less than zero.
- Fixed C4 disappearance on inclined surfaces with Valve HLDS.

## `5.7.0.295` - 2018-04-02

### Changed
- Update API minor version

## `5.6.0.294` - 2018-02-18

### Added
- Spawn protection API and cvar (`mp_respawn_immunitytime`)
![mp_respawn_immunitytime](/.github/media/36073848-14aeec46-0f48-11e8-9958-78affecf46012131.gif "mp_respawn_immunitytime")

### Changed
- `CS Interface` Update: Add Remov`ePlayerItemEx

## `5.5.0.291` - 2018-02-09

### Changed
- `gradle.properties`: Bump minor version
- Reset entity on start round for `env_spark`, `env_laser`, `env_beam`
- Move `sv_alltalk 1.0` to `CanPlayerHearPlayer`
- Remove height check
- Adjust bomb angles for righthanded users

### Fixed
- Fixed spectator check, small refactoring

## `5.5.0.286` - 2018-01-28

### Changed
- `ReGameDLL API`: Implemented hookchain's `CSGameRules::CanPlayerHearPlayer, CBasePlayer::SwitchTeam, CBasePlayer::CanSwitchTeam, CBasePlayer::ThrowGrenade, CWeaponBox::SetModel, CGrenade::DefuseBombStart, CGrenade::DefuseBombEnd, CGrenade::ExplodeHeGrenade, CGrenade::ExplodeFlashbang, CGrenade::ExplodeSmokeGrenade, CGrenade::ExplodeBomb, ThrowHeGrenade, ThrowFlashbang, ThrowSmokeGrenade, PlantBomb`

## `5.3.0.284` - 2018-01-21

[![Watch the video](/.github/media/preview-yt-2018-01-21.jpg)](https://www.youtube.com/watch?v=h4_-9lVCoKk
)

### Added
- Added `cvar` for old bomb defuse sound
- Added `mp_legacy_bombtarget_touch` cvar
- Enabled `mp_legacy_bombtarget_touch` by default, typo fix

### Changed
- Revert `NEXT_DEFUSE_TIME`
- Updated `README.md`

## `5.3.0.280` - 2018-01-08

### Fixed
- Fixed some things related
  - `CGameText`: add safe-checks to avoid crash on some maps

## `5.3.0.279` - 2017-12-25

### Changed
- Prevent spam in console if `bot_quota` is more than spawn points, so decreases bot_`quota every time if create bot fails

### Fixed
- Fixed a bug after killing `czbot` by headshot, angles turn at `180 degrees`

## `5.3.0.275` - 2017-12-11

### Fixed
- Prevent crash when caller triggered itself lot of times.

## `5.3.0.275` - 2017-12-03

### Changed
- Moved reg cvar `sv_alltalk`, `voice_serverdebug` into `GameDLLInit`

## `5.3.0.274` - 2017-12-03

### Fixed
- Fix reset `CRotDoor::Restart`

## `5.3.0.273` - 2017-11-27

### Added
- Features: added bits for iuser3 for prevent duck like HL

### Changed
- Refactoring

### Fixed
- Fixed wrong calc duck fraction
- Fixed CSSDK in extra
