# ReGameDLL_CS [![GitHub release (by tag)](https://img.shields.io/github/downloads/s1lentq/ReGameDLL_CS/latest/total)](https://github.com/s1lentq/ReGameDLL_CS/releases/latest) ![GitHub all releases](https://img.shields.io/github/downloads/s1lentq/ReGameDLL_CS/total) [![Percentage of issues still open](http://isitmaintained.com/badge/open/s1lentq/ReGameDLL_CS.svg)](http://isitmaintained.com/project/s1lentq/ReGameDLL_CS "Percentage of issues still open") [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) <img align="right" src="https://cloud.githubusercontent.com/assets/5860435/20008568/b3623150-a2d3-11e6-85f3-0d6571045fc9.png" alt="Counter-Strike 1.6 GameDLL" />
逆向工程开发的游戏动态库 (mp.dll / Counter-Strike)

## 项目简介
Regamedll_CS是通过对HLDS（版本6153beta）原版库进行逆向工程的成果，利用了嵌入在Linux版HLDS（cs.so ）中的DWARF调试信息.

## 项目目标
* 提供比官方版更稳定的Counter-Strike游戏版本，并为模组和插件扩展API接口

## 如何使用
ReGameDLL_CS完全兼容Valve官方的CS1.6/CZero模组，只需下载二进制文件替换原版mp.dll/cs.so 即可

## 下载
* [正式发布版](https://github.com/s1lentq/ReGameDLL_CS/releases)
* [开发预览版](https://github.com/s1lentq/ReGameDLL_CS/actions/workflows/build.yml)

<b>警告!</b> 由于使用不同编译器构建，ReGameDLL_CS与原版HLDS不兼容二进制.
这意味着依赖二进制代码分析的插件（如Orpheu）可能无法正常工作.

## 如何使用测试版
<pre>ReGameDLL_CS包含官方Counter-Strike最新更改的测试版本.</pre>
* 在HLDS命令行添加 `-beta` 参数.

## 命令
| 命令                                | 命令释义                                        |
| :---------------------------------- | :---------------------------------------------- |
| game version                        | 显示GameDLL构建版本、日期和URL. |
| endround                            | 参数:<br/>`T` 强制恐怖分子获胜. <br/>`CT` 强制反恐精英获胜<br/> 无参数则平局结束回合. |
| swapteams                           | 交换队伍并重启对局（默认延迟1秒）.<br/> 参数: <br/>`0` - 不重启直接交换. <br/> `>0.001` - 重启延迟秒数.|
| give                                | 获取武器命令.<br/> 参数:<br/><weapon_name><br/>示例:<br/>`give weapon_ak47`<br/>`give weapon_usp`<br/><br/>注意：需开启 `sv_cheats 1`. |
| impulse 255                         | 获取所有武器.<br/><br/>注意：需开启 `sv_cheats 1`.|
| impulse 200                         | 开启带加速的穿墙模式.<br/><br/>注意：需开启 `sv_cheats 1`. |

## 配置参数（CVars） - 具体详见dist\game.cfg
<details>
<summary>点击展开</summary>

| 参数                               |  默认值 | 最小值 | 最大值   |          参数释义                              |
| :--------------------------------- | :-----: | :----: | :------: | :--------------------------------------------- |
| mp_freeforall                      | 0       | 0   | 1            | The style of gameplay where there aren't any teams (FFA mode)<br/>`0` disabled <br/>`1` enabled |
| mp_autoteambalance                 | 1       | 0   | 2            | Auto balancing of teams.<br/>`0` disabled <br/>`1` on after next round<br/>`2` on next round |
| mp_buytime                         | 1.5     | 0.0 | -            | Designate the desired amount of buy time for each round. (in minutes)<br />`-1` means no time limit<br />`0` disable buy |
| mp_maxmoney                        | 16000   | 0   | `999999`     | The maximum allowable amount of money in the game |
| mp_round_infinite                  | 0       | 0   | 1            | Flags for fine grained control (choose as many as needed)<br/>`0` disabled<br/>`1` enabled<br/><br/>or flags<br/>`a` block round time round end check<br/>`b` block needed players round end check<br/>`c` block VIP assassination/success round end check<br/>`d` block prison escape round end check<br/>`e` block bomb round end check<br/>`f` block team extermination round end check<br/>`g` block hostage rescue round end check<br/>`h` block VIP assassination/success round time end check<br/>`i` block prison escape round time end check<br/>`j` block bomb round time end check<br/>`k` block hostage rescue round time end check<br/><br/>`Example setting:` "ae" blocks round time and bomb round end checks |
| mp_roundover                       | 0       | 0   | 3            | The round by expired time will be over, if on a map it does not have the scenario of the game.<br/>`0` disabled<br/>`1` end of the round with a draw<br/>`2` round end with Terrorists win<br/>`3` round end with Counter-Terrorists win |
| mp_round_restart_delay             | 5       | -   | -            | Number of seconds to delay before restarting a round after a win. |
| mp_hegrenade_penetration           | 0       | 0   | 1            | Disable grenade damage through walls.<br/>`0` disabled<br/>`1` enabled |
| mp_nadedrops                       | 0       | 0   | 2            | Drop a grenade after player death.<br/>`0` disabled<br/>`1` drop first available grenade<br/>`2` drop all grenades |
| mp_weapondrop                      | 1       | 0   | 3            | Drop player weapon after death.<br/>`0` do not drop weapons after death<br/>`1` drop best/heaviest weapon after death<br/>`2` drop active weapon after death<br/>`3` drop all weapons after death (primary and secondary) |
| mp_ammodrop                        | 1       | 0   | 2            | Drop ammo on weapon boxes on death or manual drop.<br/>`0` always keep ammo on player<br/>`1` drop all ammo only after death<br/>`2` drop all ammo whenever player drops a weapon |
| mp_roundrespawn_time               | 20      | 0   | -            | Player cannot respawn until next round if more than N seconds has elapsed since the beginning round.<br />`-1` means no time limit<br /> |
| mp_auto_reload_weapons             | 0       | 0   | 1            | Automatically reload each weapon on player spawn.<br/>`0` disabled<br/>`1` enabled |
| mp_refill_bpammo_weapons           | 0       | 0   | 2            | Refill amount of backpack ammo up to the max.<br/>`0` disabled<br/>`1` refill backpack ammo on player spawn<br/>`2` refill backpack ammo on player spawn and on the purchase of the item |
| mp_infinite_ammo                   | 0       | 0   | 2            | Sets the mode infinite ammo for weapons.<br/>`0` disabled<br/>`1` weapon clip infinite<br/>`2` weapon bpammo infinite (This means for reloading) |
| mp_infinite_grenades               | 0       | 0   | 1            | Enable infinite grenades.<br/>`0` disabled<br/>`1` grenades infinite |
| mp_auto_join_team                  | 0       | 0   | 1            | Automatically joins the team.<br/>`0` disabled<br/>`1` enable (Use in conjunction with the cvar humans_join_team any/CT/T) |
| mp_max_teamkills                   | 3       | 0   | -            | Maximum number of allowed teamkills before autokick. Used when enabled mp_autokick. |
| mp_fragsleft                       | -       | -   | -            | Is the number of frags left, if you have set mp_fraglimit. You just type mp_fragsleft in server console, and it tells you the number of frags left depending of mp_fraglimit. |
| mp_fraglimit                       | 0       | 0   | -            | If set to something other than 0, when anybody’s scored reaches mp_fraglimit the server changes map.<br />`0` means no limit |
| mp_timeleft                        | -       | -   | -            | Is the number of time left before the map changes, if you have set mp_timelimit. You just type mp_timeleft in server console, and it tells you the number of time left depending of mp_timelimit. |
| mp_timelimit                       | 0       | -   | -            | Period between map rotations.<br />`0` means no limit |
| mp_forcerespawn                    | 0       | 0   | -            | Players will automatically respawn when killed.<br/>`0` disabled<br/>`>0.00001` time delay to respawn |
| mp_hostage_hurtable                | 1       | 0   | 1            | The hostages can take damage.<br/>`0` disabled<br/>`1` from any team<br/>`2` only from `CT`<br/>`3` only from `T` |
| mp_show_radioicon                  | 1       | 0   | 1            | Show radio icon.<br/>`0` disabled<br/>`1` enabled |
| mp_show_scenarioicon               | 0       | 0   | 1            | Show scenario icon in HUD such as count of alive hostages or ticking bomb.<br/>`0` disabled<br/>`1` enabled |
| mp_old_bomb_defused_sound          | 1       | 0   | 1            | Play "Bomb has been defused" sound instead of "Counter-Terrorists win" when bomb was defused<br/>`0` disabled<br/>`1` enabled |
| showtriggers                       | 0       | 0   | 1            | Debug cvar shows triggers. |
| sv_alltalk                         | 0       | 0   | 5            | When players can hear each other ([further explanation](../../wiki/sv_alltalk)).<br/>`0` dead don't hear alive<br/>`1` no restrictions<br/>`2` teammates hear each other<br/>`3` Same as 2, but spectators hear everybody<br/>`4` alive hear alive, dead hear dead and alive.<br/>`5` alive hear alive teammates, dead hear dead and alive.
| bot_deathmatch                     | 0       | 0   | 1            | Sets the mode for the zBot.<br/>`0` disabled<br/>`1` enable mode Deathmatch and not allow to do the scenario |
| bot_quota_mode                     | normal  | -   | -            | Determines the type of quota.<br/>`normal` default behaviour<br/>`fill` the server will adjust bots to keep `N` players in the game, where `N` is bot_quota<br/>`match` the server will maintain a `1:N` ratio of humans to bots, where `N` is bot_quota |
| bot_join_delay                     | 0       | -   | -            | Prevents bots from joining the server for this many seconds after a map change. |
| bot_freeze                         | 0       | 0   | 1            | Prevents bots on your server from moving.<br/>`0` disabled<br/>`1` enabled |
| mp_item_staytime                   | 300     | -   | -            | Time to remove item that have been dropped from the players. |
| mp_legacy_bombtarget_touch         | 1       | 0   | 1            | Legacy func_bomb_target touch. New one is more strict. <br/>`0` New behavior<br/>`1` Legacy behavior|
| mp_respawn_immunitytime            | 0       | 0   | -            | Specifies the players defense time after respawn. (in seconds).<br/>`0` disabled<br/>`>0.00001` time delay to remove protection |
| mp_respawn_immunity_effects        | 1       | 0   | 1            | Enable effects on player spawn protection.<br/>`0` disabled<br/>`1` enable (Use in conjunction with the cvar mp_respawn_immunitytime) |
| mp_respawn_immunity_force_unset    | 1       | 0   | 2            | Force unset spawn protection if the player doing any action.<br/>`0` disabled<br/>`1` when moving and attacking<br/>`2` only when attacking |
| mp_kill_filled_spawn               | 1       | 0   | 1            | Kill the player in filled spawn before spawning some one else (Prevents players stucking in each other).<br />Only disable this if you have semiclip or other plugins that prevents stucking.<br/>`0` disabled<br/>`1` enabled |
| mp_allow_point_servercommand       | 0       | 0   | 1            | Allow use of point_servercommand entities in map.<br/>`0` disallow<br/>`1` allow<br/>`NOTE`: Potentially dangerous for untrusted maps. |
| mp_hullbounds_sets                 | 1       | 0   | 1            | Sets mins/maxs hull bounds for the player.<br/>`0` disabled<br/>`1` enabled |
| mp_unduck_method                   | 0       | 0   | 1            | Don't unduck if ducking isn't finished yet.<br/>`0` disabled<br/>`1` enabled<br/>`NOTE`: This also prevents double duck. |
| mp_scoreboard_showhealth           | 3       | -1  | 5            | Show `HP` field into a scoreboard.<br/>`-1` disabled<br/>`0` don't send any update for `HP` field to any clients<br/>`1` show only Terrorist `HP` field to all clients<br/>`2` show only CT `HP` field to all clients<br/>`3` show `HP` field to teammates<br/>`4` show `HP` field to all clients<br/>`5` show `HP` field to teammates and spectators |
| mp_scoreboard_showmoney            | 3       | -1  | 5            | Show `Money` field into a scoreboard.<br/>`-1` disabled<br/>`0` don't send any update for `Money` field to any clients<br/>`1` show only Terrorist `Money` field to all clients<br/>`2` show only CT `Money` field to all clients<br/>`3` show `Money` field to teammates<br/>`4` show `Money` field to all clients<br/>`5` show `Money` field to teammates and spectators |
| mp_scoreboard_showdefkit           | 1       | 0   | 1            | Show `D. Kit` field into a scoreboard for teammates.<br/>`0` disabled<br/>`1` enabled<br/>`NOTE`: If you don't want to show `D. Kit` field for dead enemies then disable this CVar or configure mp_forcecamera |
| ff_damage_reduction_bullets        | 0.35    | 0.0 | 1.0          | How much to reduce damage done to teammates when shot.<br/> Range is from `0` - `1` (with 1 being damage equal to what is done to an enemy) |
| ff_damage_reduction_grenade        | 0.25    | 0.0 | 1.0          | How much to reduce damage done to teammates by a thrown grenade.<br/> Range is from `0` - `1` (with 1 being damage equal to what is done to an enemy) |
| ff_damage_reduction_grenade_self   | 1.0     | 0.0 | 1.0          | How much to damage a player does to himself with his own grenade.<br/> Range is from `0` - `1` (with 1 being damage equal to what is done to an enemy) |
| ff_damage_reduction_other          | 0.35    | 0.0 | 1.0          | How much to reduce damage done to teammates by things other than bullets and grenades.<br/> Range is from `0` - `1` (with 1 being damage equal to what is done to an enemy) |
| mp_afk_bomb_drop_time              | 0       | 5.0 | -            | Player that have never moved sience they last move will drop the bomb after this amount of time. (in seconds).<br/>`0` disabled<br/>`>5.0` delay to drop |
| mp_radio_timeout                   | 1.5     | 0.0 | -            | Delay between player Radio messages. (in seconds).<br/>`0` disable delay |
| mp_radio_maxinround                | 60      | -   | -            | Maximum Radio messages count for player per round.<br/>`0` disable radio messages |
| mp_buy_anywhere                    | 0       | 0   | 3            | When set, players can buy anywhere, not only in buyzones.<br/> `0` disabled.<br/>`1` both teams <br/>`2` only Terrorists team <br/>`3` only CT team |
| mp_t_default_grenades              | ""        | "" | -           | The default grenades that the Ts will spawn with. |
| mp_t_give_player_knife             | 1         | 0  | 1           | Whether Terrorist player spawn with knife. |
| mp_t_default_weapons_primary       | ""        | "" | -           | The default primary (rifle) weapon that the Ts will spawn with. |
| mp_t_default_weapons_secondary     | "glock18" | "" | -           | The default secondary (pistol) weapon that the Ts will spawn with. |
| mp_ct_default_grenades             | ""        | "" | -           | The default grenades that the CTs will spawn with. |
| mp_ct_give_player_knife            | 1         | 0  | 1           | Whether Counter-Terrorist player spawn with knife. |
| mp_ct_default_weapons_primary      | ""        | "" | -           | The default primary (rifle) weapon that the CTs will spawn with. |
| mp_ct_default_weapons_secondary    | "usp"     | "" | -           | The default secondary (pistol) weapon that the CTs will spawn with. |
| mp_default_weapons_random          | 0       | 0   | 1            | Randomize default weapons (if there are multiple).<br/> `0` disabled<br/>`1` enabled |
| mp_give_player_c4                  | 1       | 0   | 1            | Whether this map should spawn a C4 bomb for a player or not.<br/> `0` disabled<br/>`1` enabled |
| mp_weapons_allow_map_placed        | 1       | 0   | 1            | When set, map weapons (located on the floor by map) will be shown.<br/> `0` hide all map weapons.<br/>`1` enabled<br/>`NOTE`: Effect will work after round restart. |
| mp_free_armor                      | 0       | 0   | 2            | Give free armor on player spawn.<br/>`0` disabled <br/>`1` Give Kevlar <br/>`2` Give Kevlar + Helmet |
| mp_team_flash                      | 1       | -1  | 1            | Sets the behaviour for Flashbangs on teammates.<br/>`-1` Don't affect teammates neither flash owner <br/>`0` Don't affect teammates <br/>`1` Affects teammates |
| mp_fadetoblack                     | 0       | 0   | 2            | Observer's screen will fade to black on kill event or permanent.<br/> `0` No fade.<br/>`1` Fade to black and won't be able to watch anybody.<br/>`2` fade to black only on kill moment. |
| mp_falldamage                      | 1       | 0   | 1            | Damage from falling.<br/>`0` disabled <br/>`1` enabled |
| sv_allchat                         | 1       | 0   | 2            | Players can receive all other players text chat, team restrictions apply<br/>`0` disabled <br/>`1` enabled <br/> `2` enabled, but only dead player can see spectator's message|
| sv_autobunnyhopping                | 0       | 0   | 1            | Players automatically re-jump while holding jump button.<br/>`0` disabled <br/>`1` enabled |
| sv_enablebunnyhopping              | 0       | 0   | 1            | Allow player speed to exceed maximum running speed.<br/>`0` disabled <br/>`1` enabled |
| mp_plant_c4_anywhere               | 0       | 0   | 1            | When set, players can plant anywhere, not only in bombsites.<br/>`0` disabled <br/>`1` enabled |
| mp_give_c4_frags                   | 3       | -   | -            | How many bonuses (frags) will get the player who defused or exploded the bomb. |
| mp_hostages_rescued_ratio          | 1.0     | 0.0 | 1.0          | Ratio of hostages rescued to win the round. |
| mp_legacy_vehicle_block            | 1       | 0   | 1            | Legacy func_vehicle behavior when blocked by another entity.<br/>`0` New behavior <br/>`1` Legacy behavior |
| mp_dying_time                      | 3.0     | 0.0 | -            | Time for switch to free observing after death.<br/>`0` - disable spectating around death.<br/>`>0.00001` - time delay to start spectate.<br/>`NOTE`: The countdown starts when the player’s death animation is finished. |
| mp_deathmsg_flags                  | abc     | 0   | -            | Sets a flags for extra information in the player's death message.<br/>`0` disabled<br/>`a` position where the victim died<br/>`b` index of the assistant who helped the attacker kill the victim<br/>`c` rarity classification bits, e.g., `blinkill`, `noscope`, `penetrated`, etc. |
| mp_assist_damage_threshold         | 40      | 0   | 100          | Sets the percentage of damage needed to score an assist. |
| mp_freezetime_duck                 | 1       | 0   | 1            | Allow players to duck during freezetime.<br/> `0` disabled<br/>`1` enabled |
| mp_freezetime_jump                 | 1       | 0   | 1            | Allow players to jump during freezetime.<br/> `0` disabled<br/>`1` enabled |
| mp_defuser_allocation              | 0       | 0   | 2            | Give defuser on player spawn.<br/> `0` disabled<br/>`1` Random players. <br/>`2` All players. |
| mp_location_area_info              | 0       | 0   | 3            | Enable location area info.<br/> `0` disabled<br/>`1` show location below HUD radar.<br/>`2` show location in HUD chat. `NOT RECOMMENDED!` [:speech_balloon:](## "Not all client builds are compatible")<br/>`3` both displayed. `NOT RECOMMENDED!` [:speech_balloon:](## "Not all client builds are compatible")<br/><br/>`NOTE`: Navigation `maps/.nav` file required and should contain place names<br/>`NOTE`: If option `2` or `3` is enabled, be sure to enable `mp_chat_loc_fallback 1` |
| mp_item_respawn_time               | 30      | 0.0 | -            | The respawn time for items (such as health packs, armor, etc.). |
| mp_weapon_respawn_time             | 20      | 0.0 | -            | The respawn time for weapons. |
| mp_ammo_respawn_time               | 20      | 0.0 | -            | The respawn time for ammunition. |
| mp_vote_flags                      | km      | 0   | -            | Vote systems enabled in server.<br/>`0` voting disabled<br/>`k` votekick enabled via `vote` command<br/>`m` votemap enabled via `votemap` command |
| mp_votemap_min_time                | 180     | 0.0 | -            | Minimum seconds that must elapse on map before `votemap` command can be used. |
| mp_flymove_method                  | 0       | 0   | 1            | Set the method used for flymove calculations.<br/> `0` default method<br/>`1` alternative method (more accurate) |
| mp_stamina_restore_rate            | 0       | 0.0 | -            | Framerate (FPS), that used as reference when restoring stamina (fuser2) after jump. |
| mp_logkills                        | 1       | 0   | 1            | Log kills.<br/>`0` disabled <br/>`1` enabled |
| mp_jump_height                     | 45      | 0.0 | -            | Player jump height. |
| bot_excellent_morale               | 0       | 0   | 1            | Bots always have great morale regardless of defeat or victory. |
| mp_randomspawn                     | 0       | 0   | 1            | Random player spawns<br/>`0` disabled <br/>`1` enabled<br/>`NOTE`: Navigation `maps/.nav` file required |
| mp_playerid_showhealth             | 1       | 0   | 2            | Player ID display mode.<br/>`0` don't show health<br/>`1` show health for teammates only (default CS behaviour)<br/>`2` show health for all players |
| mp_playerid_field                  | 3       | 0   | 3            | Player ID field display mode.<br/>`0` don't show additional information<br/>`1` show team name<br/>`2` show health percentage<br/>`3` show both team name and health percentage |
| mp_show_c4_defkit                  | 0       | 0   | 1            | Enable ReGameDLL scoreboard bug fix(Dead players could see the bomb or defuse kit).<br/> `0` Can see C4 and KIT<br/>`1` Cannot see C4 and KIT|
</details>

## zBot机器人安装指南
* 解压压缩包的所有文件 [archive](regamedll/extra/zBot/bot_profiles.zip?raw=true)
* 在`cstrike/game_init.cfg`中设置 `bot_enable 1`  (如无此文件请创建文件)

## CS:CZ人质AI安装指南
* 解压压缩包的所有文件 [archive](regamedll/extra/HostageImprov/host_improv.zip?raw=true)
* 在`cstrike/game_init.cfg`中设置 `hostage_ai_enable 1` (如无此文件请创建文件)

## 构建说明
### 环境要求
构建ReGameDLL_CS需要满足以下软件要求:

#### Windows环境
<pre>
Visual Studio 2015 (C++14标准) 或更高版本
</pre>

#### Linux环境
<pre>
git >= 1.8.5
cmake >= 3.10
GCC >= 4.9.2 (可选)
ICC >= 15.0.1 20141023 (可选)
LLVM (Clang) >= 6.0 (可选)
</pre>

### 构建方法

#### Windows环境
使用Visual Studio打开 `msvc/ReGameDLL.sln` 选择 `Release` 或 `Debug` 配置

#### Linux环境

* 使用构建脚本 `build.sh --compiler=[gcc] --jobs=[N] -D[option]=[ON or OFF]` (不带方括号)

<pre>
-c=|--compiler=[icc|gcc|clang]  - 选择用于构建的C/C++编译器
-j=|--jobs=[N]                  - 指定并行运行的任务（命令）数量（可加快构建速度）

<sub>定义参数 (-D)</sub>
DEBUG                           - 启用调试模式
USE_STATIC_LIBSTDC              - 启用静态链接 libstdc++
</pre>

* ICC          <pre>./build.sh --compiler=intel</pre>
* LLVM (Clang) <pre>./build.sh --compiler=clang</pre>
* GCC          <pre>./build.sh --compiler=gcc</pre>

##### 检查构建环境（Debian/Ubuntu系统）

<details>
<summary>点击展开</summary>

<ul>
<li>
安装必备软件包
<pre>
sudo dpkg --add-architecture i386
sudo apt-get update
sudo apt-get install -y gcc-multilib g++-multilib
sudo apt-get install -y build-essential
sudo apt-get install -y libc6-dev libc6-dev-i386
</pre>
</li>

<li>
选择C/C++编译器安装方案
<pre>
1) sudo apt-get install -y gcc g++
2) sudo apt-get install -y clang
</pre>
</li>
</ul>

</details>

### 致谢
感谢[ReHLDS](https://github.com/dreamstalker/rehlds)项目( ReGameDLL_CS基于ReHLDS开发 )

## 如何对项目提供支持
只需在您的游戏服务器上安装并反馈遇到的问题.<br />
也欢迎提交合并请求 :shipit:
