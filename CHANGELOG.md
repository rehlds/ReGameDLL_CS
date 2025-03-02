# [ReGameDLL_CS](https://github.com/rehlds/ReGameDLL_CS) Changelog

---


---

> [!CAUTION]
>
> This versions and changelogs were brought only for historical purposes from [DevCS Thread](https://dev-cs.ru/resources/67/updates) and not avalible at github.
>





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
