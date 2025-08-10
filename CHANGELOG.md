# [ReGameDLL_CS](https://github.com/rehlds/ReGameDLL_CS) Changelog

## [`5.28.0.756`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.28.0.756) - 2025-03-27

### Added
* New ConVar: `mp_defuser_allocation` by @wopox1337 in https://github.com/rehlds/ReGameDLL_CS/pull/908
* Add trigger_teleport landmark by @khanghugo in https://github.com/rehlds/ReGameDLL_CS/pull/952
* New ConVars: `mp_item_respawn_time`, `mp_weapon_respawn_time`, `mp_ammo_respawn_time` by @wopox1337 in https://github.com/rehlds/ReGameDLL_CS/pull/983
* New ConVars: `mp_vote_flags`, `mp_votemap_min_time` by @dystopm in https://github.com/rehlds/ReGameDLL_CS/pull/990
* Add `Escape` Scenario for Bot AI with Dynamic Behavior by @Vaqtincha in https://github.com/rehlds/ReGameDLL_CS/pull/1012
* add desc to readme by @Vaqtincha in https://github.com/rehlds/ReGameDLL_CS/pull/1014

### Changed
* Support for secondary ammo and extra EF_ flags by @Rafflesian in https://github.com/rehlds/ReGameDLL_CS/pull/934
* don't send radio message to teammate (if freeforall 1) by @Vaqtincha in https://github.com/rehlds/ReGameDLL_CS/pull/958
* Implement `game_round_end` and `game_round_freeze_end` triggers by @overl4y in https://github.com/rehlds/ReGameDLL_CS/pull/949
* API: KickBack function extension by @dystopm in https://github.com/rehlds/ReGameDLL_CS/pull/980
* Cache ObjectCaps call inside PlayerUse by @dystopm in https://github.com/rehlds/ReGameDLL_CS/pull/991
* Reset bot morale on new match(game) by @Vaqtincha in https://github.com/rehlds/ReGameDLL_CS/pull/1025
* @Rafflesian made their first contribution in https://github.com/rehlds/ReGameDLL_CS/pull/934
* @khanghugo made their first contribution in https://github.com/rehlds/ReGameDLL_CS/pull/952
**Full Changelog**: https://github.com/rehlds/ReGameDLL_CS/compare/5.26.0.668...5.28.0.756

### Fixed
* Fix excessive punchangle when getting shield shot by @dystopm in https://github.com/rehlds/ReGameDLL_CS/pull/919
* FIX: `trigger_multiple` restart by @overl4y in https://github.com/rehlds/ReGameDLL_CS/pull/935
* Fix ApplyMultiDamage duplicated call on MultiDamage routine by @dystopm in https://github.com/rehlds/ReGameDLL_CS/pull/946
* Fix `SendDeathMessage` kill rarity flags and transform to VFUNC by @FEDERICOMB96 in https://github.com/rehlds/ReGameDLL_CS/pull/943
* FIX: `NavArea::ComputeApproachAreas()` hang during `*.nav` file generation by @wopox1337 in https://github.com/rehlds/ReGameDLL_CS/pull/913
* Fix bot_kill command by @Vaqtincha in https://github.com/rehlds/ReGameDLL_CS/pull/974
* Fix: `ammo`/`weapons` respawn behavior by @wopox1337 in https://github.com/rehlds/ReGameDLL_CS/pull/982
* Fix Shotguns reload flag not getting reset on weapon changing by @dystopm in https://github.com/rehlds/ReGameDLL_CS/pull/993
* FIX: ConVar `mp_kill_filled_spawn`  by @Vaqtincha in https://github.com/rehlds/ReGameDLL_CS/pull/1011
* CI Workflow Refactor and Fixes by @wopox1337 in https://github.com/rehlds/ReGameDLL_CS/pull/1016

### API
* API: Implement `RemoveAllItems` hook by @Javekson in https://github.com/rehlds/ReGameDLL_CS/pull/960

### Internal
* client.cpp: Use macros for pfnPrecacheEvent by @Nord1cWarr1or in https://github.com/rehlds/ReGameDLL_CS/pull/1019


## [`5.26.0.668`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.26.0.668) - 2023-12-31
### Added
* New CVar: `mp_team_flash` by @aleeperezz16 in https://github.com/s1lentq/ReGameDLL_CS/pull/693
* Add an extended player's DeathMsg message by @s1lentq in https://github.com/s1lentq/ReGameDLL_CS/pull/858
* New CVars: `mp_freezetime_duck` and `mp_freezetime_jump`  by @FEDERICOMB96 in https://github.com/s1lentq/ReGameDLL_CS/pull/886
* Add member m_iGibDamageThreshold to control GIB damage threshold by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/904

### Changed
* `mp_fadetoblack` fade timings now depends from `mp_dying_time` CVar by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/845
* `API`: CSPlayerWeapon integration + new members and functions by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/850
* `API`: CSPlayer new members (physics related) by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/851
* Ensure m_pDriver assignation on func_vehicle only by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/853
* Refactored RemovePlayerItemEx and Extended DestroyItem in CBasePlayerItem by @Javekson in https://github.com/s1lentq/ReGameDLL_CS/pull/864
* `API`: CSPlayer methods enhancement by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/862
* SG_Detonate: make event realible by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/875
* Updated the GiveC4 to return a player pointer by @Javekson in https://github.com/s1lentq/ReGameDLL_CS/pull/876
* Small defuser refactory by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/871
* Observer_SetMode: Use Observer_IsValidPlayer function inside by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/872
* DropPlayerItem: Ensure HasPrimary flag assignation on successful weapon removal by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/866
* Added updating more game info to the player who started recording the demo by @s1lentq in https://github.com/s1lentq/ReGameDLL_CS/pull/881
* Use CSEntity member to hold last inflictor from TakeDamage by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/896
* Changed the order of setting pev->body for the correct value in SetBo… by @Javekson in https://github.com/s1lentq/ReGameDLL_CS/pull/893
* Avoid intro camera switching when only 1 trigger_camera available by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/873
* Tiny API code clean by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/897
* Allow null player pointer in CreateWeaponBox by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/899
* Update studio.h constants by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/898
* Initialize m_pevLastInflictor to nullptr to avoid garbage memory by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/901
* @Javekson made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/857
* @Mythlogic made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/894
**Full Changelog**: https://github.com/s1lentq/ReGameDLL_CS/compare/5.22.0.593...5.25.0.627

### Fixed
* Various defuser fixes and code refactory by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/848
* Fixed crash sometimes occurring while map analyzing for zbot navigation by @s1lentq in https://github.com/s1lentq/ReGameDLL_CS/pull/844
* Fixed of m_lastDamageAmount  recording during armor calculation by @Javekson in https://github.com/s1lentq/ReGameDLL_CS/pull/857
* Fix: Grenade weaponbox not deploying on unarmed player by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/847
* `FIX`: Reloading animation bug while holding weapon with altered Maxclip by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/861
* Ammo type hardcode fix by @Vaqtincha in https://github.com/s1lentq/ReGameDLL_CS/pull/882
* Fixed grenades disappearing when speed exceeds 2000 fixed units ignoring sv_maxvelocity by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/888

### API
* `API`: Implement `PM_LadderMove` hook by @ShadowsAdi in https://github.com/s1lentq/ReGameDLL_CS/pull/740
* `API`: Added new API funcs (6) and new Hookchains (21) by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/849
* Implement PlayerDeathThink hook by @fl0werD in https://github.com/s1lentq/ReGameDLL_CS/pull/885
* Implements Observer_Think Hook by @Mythlogic in https://github.com/s1lentq/ReGameDLL_CS/pull/894

### Internal
* Adjust gib's velocity limit according to sv_maxvelocity by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/846


## [`5.22.0.593`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.22.0.593) - 2023-07-11
### Added
* Add FreeGameRules hook, api util functions, player api functions by @fl0werD in https://github.com/s1lentq/ReGameDLL_CS/pull/808
* Add new trace flags by @justgo97 in https://github.com/s1lentq/ReGameDLL_CS/pull/813
* Add Visual Studio 2022 (17.0) Platform Toolset by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/820
* New CVars: `mp_weapondrop` and `mp_ammodrop` and fixes by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/840
* add FTRACE_KNIFE flag by @justgo97 in https://github.com/s1lentq/ReGameDLL_CS/pull/817

### Changed
* Missing friendlyfire after previous  commit by @UnrealKaraulov in https://github.com/s1lentq/ReGameDLL_CS/pull/805
* Weaponbox ammopack hardcode by @Vaqtincha in https://github.com/s1lentq/ReGameDLL_CS/pull/533
* Disable BotPrecache whether game is CS 1.6 by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/839
* Make Knife back stab multiplier customizable by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/834
* Little code cleaning: g_vecAttackDir by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/831
* @deprale made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/815
* @dystopm made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/839
**Full Changelog**: https://github.com/s1lentq/ReGameDLL_CS/compare/5.21.0.576...5.21.0.593

### Fixed
* Fix incorrect 3rd camera player death animations when frozen. by @deprale in https://github.com/s1lentq/ReGameDLL_CS/pull/815
* Grenade weaponbox ammo pickup fix by @Vaqtincha in https://github.com/s1lentq/ReGameDLL_CS/pull/669
* `CZero`: Fix broken Career Tasks by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/836
* Fix: Glock18 and Famas undesired ammo decreasing on burst mode by @dystopm in https://github.com/s1lentq/ReGameDLL_CS/pull/832
* fix: `bot_profile_db` CVar use by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/827

## [`5.21.0.576`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.21.0.576) - 2023-03-11
### Added
* Add an argument to `swapteams` command by @ShadowsAdi in https://github.com/s1lentq/ReGameDLL_CS/pull/739
* New CVar: `mp_give_c4_frags` by @JulioBarker in https://github.com/s1lentq/ReGameDLL_CS/pull/776
* New CVar: `mp_hostages_rescued_ratio` by @fl0werD in https://github.com/s1lentq/ReGameDLL_CS/pull/786

### Changed
* Correcting code style and config by @Vaqtincha in https://github.com/s1lentq/ReGameDLL_CS/pull/783
* Update func_vehicle for multiplayer by @UnrealKaraulov in https://github.com/s1lentq/ReGameDLL_CS/pull/792
* Implement `game_round_start` & `game_entity_restart` triggers by @ShadowsAdi in https://github.com/s1lentq/ReGameDLL_CS/pull/754
* @ShadowsAdi made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/739
* @JulioBarker made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/776
* @UnrealKaraulov made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/792
* @RauliTop made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/748
**Full Changelog**: https://github.com/s1lentq/ReGameDLL_CS/compare/5.21.0.547...5.21.0.575

### Fixed
* fix: update scoreboard attributes on defuser pickup by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/770
* fix: Reset immunity effects always by @Vaqtincha in https://github.com/s1lentq/ReGameDLL_CS/pull/788
* little code fixes by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/798
* Fix: `TimeBasedDamage` Paralyze typo by @RauliTop in https://github.com/s1lentq/ReGameDLL_CS/pull/748
* FIX: Unexpected behavior with `mp_forcerespawn` by @FEDERICOMB96 in https://github.com/s1lentq/ReGameDLL_CS/pull/653
* Fix: 'fast fire glitch' at AUG/SG552 by @RauliTop in https://github.com/s1lentq/ReGameDLL_CS/pull/734
* **Revert** (fix): New entity `trigger_bomb_reset` by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/796

### Internal
* Update CI by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/787
* CI: `ubuntu-latest` -> `ubuntu-20.04` by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/799
* CI: Keep the `ICC` build for releases only by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/800

## [`5.21.0.575`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.21.0.575) - 2022-12-18
> [!WARNING]
> @wopox1337: This is not a stable release! It is not recommended for use.

### Added
* Add an argument to `swapteams` command by @ShadowsAdi in https://github.com/s1lentq/ReGameDLL_CS/pull/739
* New CVar: `mp_give_c4_frags` by @JulioBarker in https://github.com/s1lentq/ReGameDLL_CS/pull/776
* New CVar: `mp_hostages_rescued_ratio` by @fl0werD in https://github.com/s1lentq/ReGameDLL_CS/pull/786

### Changed
* Correcting code style and config by @Vaqtincha in https://github.com/s1lentq/ReGameDLL_CS/pull/783
* Update func_vehicle for multiplayer by @UnrealKaraulov in https://github.com/s1lentq/ReGameDLL_CS/pull/792
* Implement `game_round_start` & `game_entity_restart` triggers by @ShadowsAdi in https://github.com/s1lentq/ReGameDLL_CS/pull/754
* New entity `trigger_bomb_reset` by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/796
* @ShadowsAdi made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/739
* @JulioBarker made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/776
* @UnrealKaraulov made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/792
* @RauliTop made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/748
**Full Changelog**: https://github.com/s1lentq/ReGameDLL_CS/compare/5.21.0.547...5.21.0.575

### Fixed
* fix: update scoreboard attributes on defuser pickup by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/770
* fix: Reset immunity effects always by @Vaqtincha in https://github.com/s1lentq/ReGameDLL_CS/pull/788
* little code fixes by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/798
* Fix: `TimeBasedDamage` Paralyze typo by @RauliTop in https://github.com/s1lentq/ReGameDLL_CS/pull/748
* FIX: Unexpected behavior with `mp_forcerespawn` by @FEDERICOMB96 in https://github.com/s1lentq/ReGameDLL_CS/pull/653
* Fix: 'fast fire glitch' at AUG/SG552 by @RauliTop in https://github.com/s1lentq/ReGameDLL_CS/pull/734

### Internal
* Update CI by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/787
* CI: `ubuntu-latest` -> `ubuntu-20.04` by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/799
* CI: Keep the `ICC` build for releases only by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/800


## [`5.21.0.556`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.21.0.556) - 2022-07-22
### Changed
* update WeaponBuyAliasInfo by @Vaqtincha in https://github.com/s1lentq/ReGameDLL_CS/pull/729
* Clamp moving entities' sounds volume by @etojuice in https://github.com/s1lentq/ReGameDLL_CS/pull/751
* @UnkwUsr made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/714
* @SmileyAG made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/747
**Full Changelog**: https://github.com/s1lentq/ReGameDLL_CS/compare/5.21.0.546...5.21.0.556

### Fixed
* fix observer crosshair bug by @Nord1cWarr1or in https://github.com/s1lentq/ReGameDLL_CS/pull/672
* g3sg1 animation duration fix by @Vaqtincha in https://github.com/s1lentq/ReGameDLL_CS/pull/670
* `RemoveSpawnProtection()` little fix by @aleeperezz16 in https://github.com/s1lentq/ReGameDLL_CS/pull/695
* Fix player_weaponstrip by @Vaqtincha in https://github.com/s1lentq/ReGameDLL_CS/pull/735

### Internal
* README.md: Note about `impulse 255` command by @UnkwUsr in https://github.com/s1lentq/ReGameDLL_CS/pull/714
* Added spawnflags for keep player angles & velocity in trigger_teleport by @SmileyAG in https://github.com/s1lentq/ReGameDLL_CS/pull/747


## [`5.21.0.547`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.21.0.547) - 2022-07-22
### Changed
* update WeaponBuyAliasInfo by @Vaqtincha in https://github.com/rehlds/ReGameDLL_CS/pull/729
* Clamp moving entities' sounds volume by @etojuice in https://github.com/rehlds/ReGameDLL_CS/pull/751
* @UnkwUsr made their first contribution in https://github.com/rehlds/ReGameDLL_CS/pull/714
* @SmileyAG made their first contribution in https://github.com/rehlds/ReGameDLL_CS/pull/747
**Full Changelog**: https://github.com/rehlds/ReGameDLL_CS/compare/5.21.0.546...5.21.0.547

### Fixed
* fix observer crosshair bug by @Nord1cWarr1or in https://github.com/rehlds/ReGameDLL_CS/pull/672
* g3sg1 animation duration fix by @Vaqtincha in https://github.com/rehlds/ReGameDLL_CS/pull/670
* `RemoveSpawnProtection()` little fix by @aleeperezz16 in https://github.com/rehlds/ReGameDLL_CS/pull/695
* Fix player_weaponstrip by @Vaqtincha in https://github.com/rehlds/ReGameDLL_CS/pull/735

### Internal
* README.md: Note about `impulse 255` command by @UnkwUsr in https://github.com/rehlds/ReGameDLL_CS/pull/714
* Added spawnflags for keep player angles & velocity in trigger_teleport by @SmileyAG in https://github.com/rehlds/ReGameDLL_CS/pull/747


## [`5.21.0.546`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.21.0.546) - 2021-12-28
### Added
* New CVar: `mp_plant_c4_anywhere` by @aleeperezz16 in https://github.com/s1lentq/ReGameDLL_CS/pull/692

### Changed
* update score status constants by @Nord1cWarr1or in https://github.com/s1lentq/ReGameDLL_CS/pull/674
* Reset `m_flNextFollowTime` before trying to find next target after previous target death by @etojuice in https://github.com/s1lentq/ReGameDLL_CS/pull/712
* @Nord1cWarr1or made their first contribution in https://github.com/s1lentq/ReGameDLL_CS/pull/674
**Full Changelog**: https://github.com/s1lentq/ReGameDLL_CS/compare/5.21.0.540...5.21.0.546

### Fixed
* CItemAirBox: Fix flight to the moon by @StevenKal in https://github.com/s1lentq/ReGameDLL_CS/pull/697

## [`5.21.0.540`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.21.0.540) - 2021-10-25
### Added
* New CVars: `sv_autobunnyhopping` and `sv_enablebunnyhopping` by @aleeperezz16 in https://github.com/s1lentq/ReGameDLL_CS/pull/686

### Changed
* Disable thread-safe initialization for static local variables by @jeefo in https://github.com/s1lentq/ReGameDLL_CS/pull/673
* Update player counts by @etojuice in https://github.com/s1lentq/ReGameDLL_CS/pull/684
**Full Changelog**: https://github.com/s1lentq/ReGameDLL_CS/compare/5.21.0.534...5.21.0.540

### Fixed
* Fix `m_flAccuracy` calculation by @wopox1337 in https://github.com/s1lentq/ReGameDLL_CS/pull/677
* `mp_free_armor` small fix by @aleeperezz16 in https://github.com/s1lentq/ReGameDLL_CS/pull/685

# [ReGameDLL_CS](https://github.com/rehlds/ReGameDLL_CS) Changelog

## [`5.21.0.534`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.21.0.534) - 2021-09-21
### Fixed
- "use accuracy from last bullet fired earlier" glitch @Vaqtincha ([#662](https://github.com/rehlds/ReGameDLL_CS/pull/662))
- Various bot issues @Vaqtincha ([#659](https://github.com/rehlds/ReGameDLL_CS/pull/659))

### Added
- New CVar `sv_allchat` @wopox1337 ([#665](https://github.com/rehlds/ReGameDLL_CS/pull/665))

### API
- Implemented `CBasePlayer::Observer_SetMode()` hook @lopol2010 ([#663](https://github.com/rehlds/ReGameDLL_CS/pull/663))
- Implemented player `Pain`, `DeathSound` and `JoiningThink` hooks @fl0werD ([#607](https://github.com/rehlds/ReGameDLL_CS/pull/607))
- Implemented `CBasePlayer::Observer_FindNextPlayer()` hook @francoromaniello ([#667](https://github.com/rehlds/ReGameDLL_CS/pull/667))
- Implemented `CGib::SpawnHeadGib()` and `CGib::SpawnRandomGibs()` @FEDERICOMB96 ([#650](https://github.com/rehlds/ReGameDLL_CS/pull/650))
- Implemented `CCSEntity::FireBuckshots()` @FEDERICOMB96 ([#651](https://github.com/rehlds/ReGameDLL_CS/pull/651))

**Full Changelog**: https://github.com/s1lentq/ReGameDLL_CS/compare/5.20.0.525...5.21.0.534

## [`5.20.0.525`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.20.0.525) - 2021-07-25
### Added
- New type `sv_alltalk 5` ([#644](https://github.com/rehlds/ReGameDLL_CS/pull/644))
- New CVar `mp_free_armor` ([#609](https://github.com/rehlds/ReGameDLL_CS/pull/609))
- `give` cmd documentation in readme ([#649](https://github.com/rehlds/ReGameDLL_CS/pull/649))

### Changed
- Allow observe for dying player with `EF_NODRAW` effect ([#647](https://github.com/rehlds/ReGameDLL_CS/pull/647))
  * Observer_IsValidTarget: checks refactoring

### API
- Implemented `CBasePlayer::HasTimePassedSinceDeath()` for `m_fDeadTime` ([#648](https://github.com/rehlds/ReGameDLL_CS/pull/648))

## [`5.20.0.516`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.20.0.516) - 2021-06-15
### Fixed
- Crash in UTIL_AreHostagesImprov ([#626](https://github.com/rehlds/ReGameDLL_CS/pull/626))
- First shot weapon_sg550 issue ([#624](https://github.com/rehlds/ReGameDLL_CS/pull/624))
- Forcerespawn behavior ([#623](https://github.com/rehlds/ReGameDLL_CS/pull/623))
  * Dead players now respawn after enabling mp_forcerespawn
  * Uses timer instead of instant spawn

### Added
- New feature "strict touch" for func_bomb_target ([#636](https://github.com/rehlds/ReGameDLL_CS/pull/636))
- Enhanced "player_weaponstrip" entity ([#634](https://github.com/rehlds/ReGameDLL_CS/pull/634))
- Weapon flag ITEM_FLAG_NOFIREUNDERWATER ([#628](https://github.com/rehlds/ReGameDLL_CS/pull/628))
- New flag SF_PLAYEREQUIP_REMOVEWEAPONS for game_player_equip ([#618](https://github.com/rehlds/ReGameDLL_CS/pull/618))
- Bots can now switch weapons underwater ([#631](https://github.com/rehlds/ReGameDLL_CS/pull/631))
- New value (2) for CVar 'mp_respawn_immunity_force_unset' ([#621](https://github.com/rehlds/ReGameDLL_CS/pull/621))

### Changed
- FGD updates ([#632](https://github.com/rehlds/ReGameDLL_CS/pull/632))
  * game_player_equip fixes
  * enhanced cycler/cycler_sprite
- Added lost spawnflags SF_DOOR_ROTATE_Z, SF_DOOR_ROTATE_X for func_rot_button ([#637](https://github.com/rehlds/ReGameDLL_CS/pull/637))

## [`5.20.0.505`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.20.0.505) - 2021-04-17
### Fixed
- Flag 'k' for `mp_round_infinite` ([#540](https://github.com/rehlds/ReGameDLL_CS/pull/540))

## [`5.20.0.498`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.20.0.498) - 2021-04-13
### Changed
- Enhanced CVar `mp_roundover`
- Updated `README.md`
- Updated `C++ Intel Compiler` version from `17.0` to `19.0`

## [`5.20.0.496`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.20.0.496) - 2021-04-12
### Changed
- Renamed CMD `mp_swapteams`

### Removed
- Unused CVar `mp_mirrordamage`

### Fixed
- Various refactoring and checks ([#540](https://github.com/rehlds/ReGameDLL_CS/pull/540))

## [`5.20.0.492`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.20.0.492) - 2021-01-04
### Changed
- `CHalfLifeMultiplay::SwapAllPlayers` now ignores HLTV

## [`5.19.0.486`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.19.0.486) - 2020-12-05
### Added
- Newest feature for `_cl_autowepswitch` ([#568](https://github.com/rehlds/ReGameDLL_CS/pull/568))

## [`5.19.0.485`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.19.0.485) - 2020-12-02
### Fixed
- Compatibility with `rg_hint_message` ([#583](https://github.com/rehlds/ReGameDLL_CS/pull/583))
  * Fixes issue when reapi native `rg_hint_message` tried to access a non-existent pointer in `CHintMessage::Send`

## [`5.19.0.484`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.19.0.484) - 2020-12-02
### Fixed
- Reset client `m_signals` on fullupdate ([#588](https://github.com/rehlds/ReGameDLL_CS/pull/588))

## [`5.18.0.482`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.482) - 2020-11-28
### Fixed
- Reset observer's `m_flNextFollowTime` before finding next target if previous target disconnected ([#584](https://github.com/rehlds/ReGameDLL_CS/pull/584))

## [`5.18.0.481`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.481) - 2020-11-28
### API
- Added `CBaseEntity::Fire<Bullets[3]|Buckshots>` hooks ([#587](https://github.com/rehlds/ReGameDLL_CS/pull/587))

## [`5.18.0.480`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.480) - 2020-11-21
### Fixed
- Memory leak with hintmessage

## [`5.18.0.479`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.479) - 2020-11-13
### Fixed
- Crash caused by `ReloadMapCycleFile` function ([#576](https://github.com/rehlds/ReGameDLL_CS/pull/576))

## [`5.18.0.475`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.475) - 2020-10-26
### Changed
- Reverted `mp_refill_bpammo_weapons 3`

## [`5.18.0.474`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.474) - 2020-07-16
### Fixed
- Client body not disappearing after reconnect

## [`5.18.0.473`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.473) - 2020-07-03
### Fixed
- Crash when func_breakable signals for `CCSBot::OnEvent`

## [`5.18.0.472`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.472) - 2020-06-25
### Fixed
- Don't call HasRestrictItem with type touch when item is being bought

## [`5.18.0.470`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.470) - 2020-06-17
### Added
- New CVars for default weapons ([#470](https://github.com/rehlds/ReGameDLL_CS/pull/470))

## [`5.18.0.469`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.469) - 2020-06-13
### Added
- More flags for round time expired to CVar `mp_round_infinite`

## [`5.18.0.468`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.468) - 2020-06-10
### Fixed
- Various bot fixes ([#544](https://github.com/rehlds/ReGameDLL_CS/pull/544))

## [`5.18.0.467`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.18.0.467) - 2020-06-10
### Fixed
- Additional bot fixes ([#544](https://github.com/rehlds/ReGameDLL_CS/pull/544))
- Flood message "All bot profiles at this difficulty level are in use." in console

## [`5.17.0.466`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.17.0.466) - 2020-05-27
### API
- Implemented `CGib` hooks ([#536](https://github.com/rehlds/ReGameDLL_CS/pull/536))
- Moved code from `basemonster.cpp` to `gib.cpp`
- Linked entity to class (hookable by HamSandwich amxx module)

## [`5.16.0.465`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.16.0.465) - 2020-05-27
### Fixed
- Player reset zoom & speed behavior ([#541](https://github.com/rehlds/ReGameDLL_CS/pull/541))
  * `RemoveAllItems` now resets (updates) player speed
  * `RemoveAllItems` resets player zoom
  * `RemovePlayerItem` resets player zoom & speed
  * `CFuncTank->StartControl` fully resets zoom

## [`5.16.0.460`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.16.0.460) - 2020-05-02
### API
- Added `m_bCanShootOverride` member ([#527](https://github.com/rehlds/ReGameDLL_CS/pull/527))
  * Allows overriding `m_bCanShoot` (e.g., enabling fire during freeze time)

## [`5.15.0.459`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.15.0.459) - 2020-05-02
### Fixed
- Format buffer size in `UTIL_dtosX` functions ([#528](https://github.com/rehlds/ReGameDLL_CS/pull/528))

## [`5.15.0.457`](https://github.com/rehlds/ReGameDLL_CS/releases/tag/5.15.0.457) - 2020-03-27
### API
- Added weaponbox hook ([#521](https://github.com/rehlds/ReGameDLL_CS/pull/521))

-------------------------------

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
