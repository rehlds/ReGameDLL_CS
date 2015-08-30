#include "precompiled.h"

#define DEFINE_WEAPON(m_wpnid, m_cost, m_slotnum, m_acost)\
	{ m_wpnid, m_cost, 3, m_slotnum, m_acost }

/*
* Globals initialization
*/
#ifndef HOOK_GAMEDLL

int giPrecacheGrunt = 0;
int gmsgFlashlight = 0;
int gmsgFlashBattery = 0;
int gmsgResetHUD = 0;
int gmsgInitHUD = 0;
int gmsgViewMode = 0;
int gmsgShowGameTitle = 0;
int gmsgCurWeapon = 0;
int gmsgHealth = 0;
int gmsgDamage = 0;
int gmsgBattery = 0;
int gmsgTrain = 0;
int gmsgLogo = 0;
int gmsgWeaponList = 0;
int gmsgAmmoX = 0;
int gmsgDeathMsg = 0;
int gmsgScoreAttrib = 0;
int gmsgScoreInfo = 0;
int gmsgTeamInfo = 0;
int gmsgTeamScore = 0;
int gmsgGameMode = 0;
int gmsgMOTD = 0;
int gmsgServerName = 0;
int gmsgAmmoPickup = 0;
int gmsgItemPickup = 0;
int gmsgHideWeapon = 0;
int gmsgSayText = 0;
int gmsgTextMsg = 0;
int gmsgSetFOV = 0;
int gmsgShowMenu = 0;
int gmsgSendAudio = 0;
int gmsgRoundTime = 0;
int gmsgMoney = 0;
int gmsgBlinkAcct = 0;
int gmsgArmorType = 0;
int gmsgStatusValue = 0;
int gmsgStatusText = 0;
int gmsgStatusIcon = 0;
int gmsgBarTime = 0;
int gmsgReloadSound = 0;
int gmsgCrosshair = 0;
int gmsgNVGToggle = 0;
int gmsgRadar = 0;
int gmsgSpectator = 0;
int gmsgVGUIMenu = 0;
int gmsgCZCareer = 0;
int gmsgCZCareerHUD = 0;
int gmsgTaskTime = 0;
int gmsgTutorText = 0;
int gmsgTutorLine = 0;
int gmsgShadowIdx = 0;
int gmsgTutorState = 0;
int gmsgTutorClose = 0;
int gmsgAllowSpec = 0;
int gmsgBombDrop = 0;
int gmsgBombPickup = 0;
int gmsgHostagePos = 0;
int gmsgHostageK = 0;
int gmsgGeigerRange = 0;
int gmsgSendCorpse = 0;
int gmsgHLTV = 0;
int gmsgSpecHealth = 0;
int gmsgForceCam = 0;
int gmsgADStop = 0;
int gmsgReceiveW = 0;
int gmsgScenarioIcon = 0;
int gmsgBotVoice = 0;
int gmsgBuyClose = 0;
int gmsgItemStatus = 0;
int gmsgLocation = 0;
int gmsgSpecHealth2 = 0;
int gmsgBarTime2 = 0;
int gmsgBotProgress = 0;
int gmsgBrass = 0;
int gmsgFog = 0;
int gmsgShowTimer = 0;

BOOL gInitHUD = TRUE;
cvar_t *sv_aim = NULL;

TYPEDESCRIPTION CRevertSaved::m_SaveData[] =
{
	DEFINE_FIELD(CRevertSaved, m_messageTime, FIELD_FLOAT),
	DEFINE_FIELD(CRevertSaved, m_loadTime, FIELD_FLOAT),
};

TYPEDESCRIPTION CBasePlayer::m_playerSaveData[] =
{
	DEFINE_FIELD(CBasePlayer, m_flFlashLightTime, FIELD_TIME),
	DEFINE_FIELD(CBasePlayer, m_iFlashBattery, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_afButtonLast, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_afButtonPressed, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_afButtonReleased, FIELD_INTEGER),
	DEFINE_ARRAY(CBasePlayer, m_rgItems, FIELD_INTEGER, MAX_ITEMS),
	DEFINE_FIELD(CBasePlayer, m_afPhysicsFlags, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_flTimeStepSound, FIELD_TIME),
	DEFINE_FIELD(CBasePlayer, m_flTimeWeaponIdle, FIELD_TIME),
	DEFINE_FIELD(CBasePlayer, m_flSwimTime, FIELD_TIME),
	DEFINE_FIELD(CBasePlayer, m_flDuckTime, FIELD_TIME),
	DEFINE_FIELD(CBasePlayer, m_flWallJumpTime, FIELD_TIME),
	DEFINE_FIELD(CBasePlayer, m_flSuitUpdate, FIELD_TIME),
	DEFINE_ARRAY(CBasePlayer, m_rgSuitPlayList, FIELD_INTEGER, CSUITPLAYLIST),
	DEFINE_FIELD(CBasePlayer, m_iSuitPlayNext, FIELD_INTEGER),
	DEFINE_ARRAY(CBasePlayer, m_rgiSuitNoRepeat, FIELD_INTEGER, CSUITNOREPEAT),
	DEFINE_ARRAY(CBasePlayer, m_rgflSuitNoRepeatTime, FIELD_TIME, CSUITNOREPEAT),
	DEFINE_FIELD(CBasePlayer, m_lastDamageAmount, FIELD_INTEGER),
	DEFINE_ARRAY(CBasePlayer, m_rgpPlayerItems, FIELD_CLASSPTR, MAX_ITEM_TYPES),
	DEFINE_FIELD(CBasePlayer, m_pActiveItem, FIELD_CLASSPTR),
	DEFINE_FIELD(CBasePlayer, m_pLastItem, FIELD_CLASSPTR),
	DEFINE_ARRAY(CBasePlayer, m_rgAmmo, FIELD_INTEGER, MAX_AMMO_SLOTS),
	DEFINE_FIELD(CBasePlayer, m_idrowndmg, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_idrownrestored, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_tSneaking, FIELD_TIME),
	DEFINE_FIELD(CBasePlayer, m_iTrain, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_bitsHUDDamage, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_flFallVelocity, FIELD_FLOAT),
	DEFINE_FIELD(CBasePlayer, m_iTargetVolume, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_iWeaponVolume, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_iExtraSoundTypes, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_iWeaponFlash, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_fLongJump, FIELD_BOOLEAN),
	DEFINE_FIELD(CBasePlayer, m_fInitHUD, FIELD_BOOLEAN),
	DEFINE_FIELD(CBasePlayer, m_tbdPrev, FIELD_TIME),
	DEFINE_FIELD(CBasePlayer, m_pTank, FIELD_EHANDLE),
	DEFINE_FIELD(CBasePlayer, m_iHideHUD, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_iFOV, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_flDisplayHistory, FIELD_INTEGER),
	DEFINE_FIELD(CBasePlayer, m_iJoiningState, FIELD_INTEGER),
};

WeaponStruct g_weaponStruct[ MAX_WEAPONS ] =
{
	{ 0, 0, 0, 0, 0 },

	{ WEAPON_P228,		P228_PRICE,		TERRORIST|CT,		AUTOBUYCLASS_SECONDARY,	AMMO_357SIG_PRICE },
	{ WEAPON_SCOUT,		SCOUT_PRICE,		TERRORIST|CT,		AUTOBUYCLASS_PRIMARY,	AMMO_762MM_PRICE },
	{ WEAPON_XM1014,	XM1014_PRICE,		TERRORIST|CT,		AUTOBUYCLASS_PRIMARY,	AMMO_BUCKSHOT_PRICE },
	{ WEAPON_MAC10,		MAC10_PRICE,		CT,			AUTOBUYCLASS_PRIMARY,	AMMO_45ACP_PRICE },
	{ WEAPON_AUG,		AUG_PRICE,		TERRORIST,		AUTOBUYCLASS_PRIMARY,	AMMO_556MM_PRICE },
	{ WEAPON_ELITE,		ELITE_PRICE,		CT,			AUTOBUYCLASS_SECONDARY,	AMMO_9MM_PRICE },
	{ WEAPON_FIVESEVEN,	FIVESEVEN_PRICE,	TERRORIST|CT,		AUTOBUYCLASS_SECONDARY,	AMMO_57MM_PRICE },
	{ WEAPON_UMP45,		UMP45_PRICE,		TERRORIST,		AUTOBUYCLASS_PRIMARY,	AMMO_45ACP_PRICE },
	{ WEAPON_SG550,		SG550_PRICE,		TERRORIST,		AUTOBUYCLASS_PRIMARY,	AMMO_556MM_PRICE },
	{ WEAPON_USP,		USP_PRICE,		TERRORIST|CT,		AUTOBUYCLASS_SECONDARY,	AMMO_45ACP_PRICE },
	{ WEAPON_GLOCK18,	GLOCK18_PRICE,		TERRORIST|CT,		AUTOBUYCLASS_SECONDARY,	AMMO_9MM_PRICE },
	{ WEAPON_MP5N,		MP5NAVY_PRICE,		TERRORIST|CT,		AUTOBUYCLASS_PRIMARY,	AMMO_9MM_PRICE },
	{ WEAPON_AWP,		AWP_PRICE,		TERRORIST|CT,		AUTOBUYCLASS_PRIMARY,	AMMO_338MAG_PRICE },
	{ WEAPON_M249,		M249_PRICE,		TERRORIST|CT,		AUTOBUYCLASS_PRIMARY,	AMMO_556MM_PRICE },
	{ WEAPON_M3,		M3_PRICE,		TERRORIST|CT,		AUTOBUYCLASS_PRIMARY,	AMMO_BUCKSHOT_PRICE },
	{ WEAPON_M4A1,		M4A1_PRICE,		TERRORIST,		AUTOBUYCLASS_PRIMARY,	AMMO_556MM_PRICE },
	{ WEAPON_TMP,		TMP_PRICE,		TERRORIST,		AUTOBUYCLASS_PRIMARY,	AMMO_9MM_PRICE },
	{ WEAPON_G3SG1,		G3SG1_PRICE,		CT,			AUTOBUYCLASS_PRIMARY,	AMMO_762MM_PRICE },
	{ WEAPON_DEAGLE,	DEAGLE_PRICE,		TERRORIST|CT,		AUTOBUYCLASS_SECONDARY,	AMMO_50AE_PRICE },
	{ WEAPON_SG552,		SG552_PRICE,		CT,			AUTOBUYCLASS_PRIMARY,	AMMO_556MM_PRICE },
	{ WEAPON_AK47,		AK47_PRICE,		CT,			AUTOBUYCLASS_PRIMARY,	AMMO_762MM_PRICE },
	{ WEAPON_P90,		P90_PRICE,		TERRORIST|CT,		AUTOBUYCLASS_PRIMARY,	AMMO_57MM_PRICE },
	{ WEAPON_FAMAS,		FAMAS_PRICE,		TERRORIST,		AUTOBUYCLASS_PRIMARY,	AMMO_556MM_PRICE },
	{ WEAPON_GALIL,		GALIL_PRICE,		CT,			AUTOBUYCLASS_PRIMARY,	AMMO_556MM_PRICE },
				// TODO: this have bug, the cost of galil $2000, but not $2250

	{ WEAPON_SHIELDGUN,	SHIELDGUN_PRICE,	TERRORIST,		AUTOBUYCLASS_PRIMARY,	0 },

	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }
};

char *CDeadHEV::m_szPoses[] =
{
	"deadback",
	"deadsitting",
	"deadstomach",
	"deadtable"
};

#else //HOOK_GAMEDLL

int giPrecacheGrunt;
int gmsgWeapPickup;
int gmsgHudText;
int gmsgHudTextArgs;
int gmsgShake;
int gmsgFade;
int gmsgFlashlight;
int gmsgFlashBattery;
int gmsgResetHUD;
int gmsgInitHUD;
int gmsgViewMode;
int gmsgShowGameTitle;
int gmsgCurWeapon;
int gmsgHealth;
int gmsgDamage;
int gmsgBattery;
int gmsgTrain;
int gmsgLogo;
int gmsgWeaponList;
int gmsgAmmoX;
int gmsgDeathMsg;
int gmsgScoreAttrib;
int gmsgScoreInfo;
int gmsgTeamInfo;
int gmsgTeamScore;
int gmsgGameMode;
int gmsgMOTD;
int gmsgServerName;
int gmsgAmmoPickup;
int gmsgItemPickup;
int gmsgHideWeapon;
int gmsgSayText;
int gmsgTextMsg;
int gmsgSetFOV;
int gmsgShowMenu;
int gmsgSendAudio;
int gmsgRoundTime;
int gmsgMoney;
int gmsgBlinkAcct;
int gmsgArmorType;
int gmsgStatusValue;
int gmsgStatusText;
int gmsgStatusIcon;
int gmsgBarTime;
int gmsgReloadSound;
int gmsgCrosshair;
int gmsgNVGToggle;
int gmsgRadar;
int gmsgSpectator;
int gmsgVGUIMenu;
int gmsgCZCareer;
int gmsgCZCareerHUD;
int gmsgTaskTime;
int gmsgTutorText;
int gmsgTutorLine;
int gmsgShadowIdx;
int gmsgTutorState;
int gmsgTutorClose;
int gmsgAllowSpec;
int gmsgBombDrop;
int gmsgBombPickup;
int gmsgHostagePos;
int gmsgHostageK;
int gmsgGeigerRange;
int gmsgSendCorpse;
int gmsgHLTV;
int gmsgSpecHealth;
int gmsgForceCam;
int gmsgADStop;
int gmsgReceiveW;
int gmsgScenarioIcon;
int gmsgBotVoice;
int gmsgBuyClose;
int gmsgItemStatus;
int gmsgLocation;
int gmsgSpecHealth2;
int gmsgBarTime2;
int gmsgBotProgress;
int gmsgBrass;
int gmsgFog;
int gmsgShowTimer;

BOOL gInitHUD;
cvar_t *sv_aim;

TYPEDESCRIPTION (*CRevertSaved::pm_SaveData)[2];
TYPEDESCRIPTION (*CBasePlayer::pm_playerSaveData)[40];
WeaponStruct g_weaponStruct[ MAX_WEAPONS ];
char *(*CDeadHEV::pm_szPoses)[4];

#endif //HOOK_GAMEDLL

//int giPrecacheGrunt;
int gEvilImpulse101;
char g_szMapBriefingText[512];

entvars_t *g_pevLastInflictor;
CBaseEntity *g_pLastSpawn;
CBaseEntity *g_pLastCTSpawn;
CBaseEntity *g_pLastTerroristSpawn;

/* <14e3fc> ../cstrike/dlls/player.cpp:5868 */
struct ZombieSpawn
{
	CBaseEntity *entity;
	CountdownTimer useableTimer;

};/* size: 12, cachelines: 1, members: 2 */

ZombieSpawn zombieSpawn[256];
int zombieSpawnCount;

/* <15353b> ../cstrike/dlls/player.cpp:282 */
void LinkUserMessages(void)
{
	if (gmsgCurWeapon)
		return;

	gmsgCurWeapon = REG_USER_MSG("CurWeapon", 3);
	gmsgGeigerRange = REG_USER_MSG("Geiger", 1);
	gmsgFlashlight = REG_USER_MSG("Flashlight", 2);
	gmsgFlashBattery = REG_USER_MSG("FlashBat", 1);
	gmsgHealth = REG_USER_MSG("Health", 1);
	gmsgDamage = REG_USER_MSG("Damage", 12);
	gmsgBattery = REG_USER_MSG("Battery", 2);
	gmsgTrain = REG_USER_MSG("Train", 1);
	gmsgHudText = REG_USER_MSG("HudTextPro", -1);
	REG_USER_MSG("HudText", -1);
	gmsgSayText = REG_USER_MSG("SayText", -1);
	gmsgTextMsg = REG_USER_MSG("TextMsg", -1);
	gmsgWeaponList = REG_USER_MSG("WeaponList", -1);
	gmsgResetHUD = REG_USER_MSG("ResetHUD", 0);
	gmsgInitHUD = REG_USER_MSG("InitHUD", 0);
	gmsgViewMode = REG_USER_MSG("ViewMode", 0);
	gmsgShowGameTitle = REG_USER_MSG("GameTitle", 1);
	gmsgDeathMsg = REG_USER_MSG("DeathMsg", -1);
	gmsgScoreAttrib = REG_USER_MSG("ScoreAttrib", 2);
	gmsgScoreInfo = REG_USER_MSG("ScoreInfo", 9);
	gmsgTeamInfo = REG_USER_MSG("TeamInfo", -1);
	gmsgTeamScore = REG_USER_MSG("TeamScore", -1);
	gmsgGameMode = REG_USER_MSG("GameMode", 1);
	gmsgMOTD = REG_USER_MSG("MOTD", -1);
	gmsgServerName = REG_USER_MSG("ServerName", -1);
	gmsgAmmoPickup = REG_USER_MSG("AmmoPickup", 2);
	gmsgWeapPickup = REG_USER_MSG("WeapPickup", 1);
	gmsgItemPickup = REG_USER_MSG("ItemPickup", -1);
	gmsgHideWeapon = REG_USER_MSG("HideWeapon", 1);
	gmsgSetFOV = REG_USER_MSG("SetFOV", 1);
	gmsgShowMenu = REG_USER_MSG("ShowMenu", -1);
	gmsgShake = REG_USER_MSG("ScreenShake", 6);
	gmsgFade = REG_USER_MSG("ScreenFade", 10);
	gmsgAmmoX = REG_USER_MSG("AmmoX", 2);
	gmsgSendAudio = REG_USER_MSG("SendAudio", -1);
	gmsgRoundTime = REG_USER_MSG("RoundTime", 2);
	gmsgMoney = REG_USER_MSG("Money", 5);
	gmsgArmorType = REG_USER_MSG("ArmorType", 1);
	gmsgBlinkAcct = REG_USER_MSG("BlinkAcct", 1);
	gmsgStatusValue = REG_USER_MSG("StatusValue", -1);
	gmsgStatusText = REG_USER_MSG("StatusText", -1);
	gmsgStatusIcon = REG_USER_MSG("StatusIcon", -1);
	gmsgBarTime = REG_USER_MSG("BarTime", 2);
	gmsgReloadSound = REG_USER_MSG("ReloadSound", 2);
	gmsgCrosshair = REG_USER_MSG("Crosshair", 1);
	gmsgNVGToggle = REG_USER_MSG("NVGToggle", 1);
	gmsgRadar = REG_USER_MSG("Radar", 7);
	gmsgSpectator = REG_USER_MSG("Spectator", 2);
	gmsgVGUIMenu = REG_USER_MSG("VGUIMenu", -1);
	gmsgTutorText = REG_USER_MSG("TutorText", -1);
	gmsgTutorLine = REG_USER_MSG("TutorLine", -1);
	gmsgTutorState = REG_USER_MSG("TutorState", -1);
	gmsgTutorClose = REG_USER_MSG("TutorClose", -1);
	gmsgAllowSpec = REG_USER_MSG("AllowSpec", 1);
	gmsgBombDrop = REG_USER_MSG("BombDrop", 7);
	gmsgBombPickup = REG_USER_MSG("BombPickup", 0);
	gmsgSendCorpse = REG_USER_MSG("ClCorpse", -1);
	gmsgHostagePos = REG_USER_MSG("HostagePos", 8);
	gmsgHostageK = REG_USER_MSG("HostageK", 1);
	gmsgHLTV = REG_USER_MSG("HLTV", 2);
	gmsgSpecHealth = REG_USER_MSG("SpecHealth", 1);
	gmsgForceCam = REG_USER_MSG("ForceCam", 3);
	gmsgADStop = REG_USER_MSG("ADStop", 0);
	gmsgReceiveW = REG_USER_MSG("ReceiveW", 1);
	gmsgCZCareer = REG_USER_MSG("CZCareer", -1);
	gmsgCZCareerHUD = REG_USER_MSG("CZCareerHUD", -1);
	gmsgShadowIdx = REG_USER_MSG("ShadowIdx", 4);
	gmsgTaskTime = REG_USER_MSG("TaskTime", 4);
	gmsgScenarioIcon = REG_USER_MSG("Scenario", -1);
	gmsgBotVoice = REG_USER_MSG("BotVoice", 2);
	gmsgBuyClose = REG_USER_MSG("BuyClose", 0);
	gmsgSpecHealth2 = REG_USER_MSG("SpecHealth2", 2);
	gmsgBarTime2 = REG_USER_MSG("BarTime2", 4);
	gmsgItemStatus = REG_USER_MSG("ItemStatus", 1);
	gmsgLocation = REG_USER_MSG("Location", -1);
	gmsgBotProgress = REG_USER_MSG("BotProgress", -1);
	gmsgBrass = REG_USER_MSG("Brass", -1);
	gmsgFog = REG_USER_MSG("Fog", 7);
	gmsgShowTimer = REG_USER_MSG("ShowTimer", 0);
	gmsgHudTextArgs = REG_USER_MSG("HudTextArgs", -1);
}

/* <1535a5> ../cstrike/dlls/player.cpp:380 */
void WriteSigonMessages(void)
{
	for (int i = 0; i < MAX_WEAPONS; i++)
	{
		ItemInfo &II = IMPLEMENT_ARRAY_CLASS(CBasePlayerItem, ItemInfoArray)[i];

		if (!II.iId)
			continue;

		const char *pszName;
		if (!II.pszName)
			pszName = "Empty";
		else
			pszName = II.pszName;

		MESSAGE_BEGIN(MSG_INIT, gmsgWeaponList);
			WRITE_STRING(pszName);
			WRITE_BYTE(CBasePlayer::GetAmmoIndex(II.pszAmmo1));
			WRITE_BYTE(II.iMaxAmmo1);
			WRITE_BYTE(CBasePlayer::GetAmmoIndex(II.pszAmmo2));
			WRITE_BYTE(II.iMaxAmmo2);
			WRITE_BYTE(II.iSlot);
			WRITE_BYTE(II.iPosition);
			WRITE_BYTE(II.iId);
			WRITE_BYTE(II.iFlags);
		MESSAGE_END();
	}
}

/* <15f281> ../cstrike/dlls/player.cpp:425 */
LINK_ENTITY_TO_CLASS(player, CBasePlayer);

/* <1536a9> ../cstrike/dlls/player.cpp:429 */
void SendItemStatus(CBasePlayer *pPlayer)
{
	int itemStatus = 0;
	if (pPlayer->m_bHasNightVision)
		itemStatus |= ITEM_STATUS_NIGHTVISION;

	if (pPlayer->m_bHasDefuser)
		itemStatus |= ITEM_STATUS_DEFUSER;

	MESSAGE_BEGIN(MSG_ONE, gmsgItemStatus, NULL, pPlayer->pev);
		WRITE_BYTE(itemStatus);
	MESSAGE_END();
}

/* <150ed5> ../cstrike/dlls/player.cpp:438 */
const char *GetCSModelName(int item_id)
{
	const char *modelName = NULL;
	switch (item_id)
	{
	case WEAPON_P228:		modelName = "models/w_p228.mdl"; break;
	case WEAPON_SCOUT:		modelName = "models/w_scout.mdl"; break;
	case WEAPON_HEGRENADE:		modelName = "models/w_hegrenade.mdl"; break;
	case WEAPON_XM1014:		modelName = "models/w_xm1014.mdl"; break;
 	case WEAPON_C4:			modelName = "models/w_backpack.mdl"; break;
	case WEAPON_MAC10:		modelName = "models/w_mac10.mdl"; break;
	case WEAPON_AUG:		modelName = "models/w_aug.mdl"; break;
	case WEAPON_SMOKEGRENADE:	modelName = "models/w_smokegrenade.mdl"; break;
	case WEAPON_ELITE:		modelName = "models/w_elite.mdl"; break;
	case WEAPON_FIVESEVEN:		modelName = "models/w_fiveseven.mdl"; break;
	case WEAPON_UMP45:		modelName = "models/w_ump45.mdl"; break;
	case WEAPON_SG550:		modelName = "models/w_sg550.mdl"; break;
	case WEAPON_GALIL:		modelName = "models/w_galil.mdl"; break;
	case WEAPON_FAMAS:		modelName = "models/w_famas.mdl"; break;
	case WEAPON_USP:		modelName = "models/w_usp.mdl"; break;
	case WEAPON_GLOCK18:		modelName = "models/w_glock18.mdl"; break;
	case WEAPON_AWP:		modelName = "models/w_awp.mdl"; break;
	case WEAPON_MP5N:		modelName = "models/w_mp5.mdl"; break;
	case WEAPON_M249:		modelName = "models/w_m249.mdl"; break;
	case WEAPON_M3:			modelName = "models/w_m3.mdl"; break;
	case WEAPON_M4A1:		modelName = "models/w_m4a1.mdl"; break;
	case WEAPON_TMP:		modelName = "models/w_tmp.mdl"; break;
	case WEAPON_G3SG1:		modelName = "models/w_g3sg1.mdl"; break;
	case WEAPON_FLASHBANG:		modelName = "models/w_flashbang.mdl"; break;
	case WEAPON_DEAGLE:		modelName = "models/w_deagle.mdl"; break;
	case WEAPON_SG552:		modelName = "models/w_sg552.mdl"; break;
	case WEAPON_AK47:		modelName = "models/w_ak47.mdl"; break;
	case WEAPON_KNIFE:		modelName = "models/w_knife.mdl"; break;
	case WEAPON_P90:		modelName = "models/w_p90.mdl"; break;
	case WEAPON_SHIELDGUN:		modelName = "models/w_shield.mdl"; break;
	default:
		ALERT(at_console, "CBasePlayer::PackDeadPlayerItems(): Unhandled item- not creating weaponbox\n");
	}

	return modelName;
}

/* <153737> ../cstrike/dlls/player.cpp:572 */
void CBasePlayer::SetPlayerModel(BOOL HasC4)
{
	char *infobuffer = GET_INFO_BUFFER(edict());
	char *model;

	if (m_iTeam == CT)
	{		
		switch (m_iModelName)
		{
		case MODEL_URBAN:
			model = "urban";
			break;
		case MODEL_GSG9:
			model = "gsg9";
			break;
		case MODEL_GIGN:
			model = "gign";
			break;
		case MODEL_SAS:
			model = "sas";
			break;
		case MODEL_VIP:
			model = "vip";
			break;
		case MODEL_SPETSNAZ:
			if (UTIL_IsGame("czero"))
			{
				model = "spetsnaz";
				break;
			}
		default:
		{
			if (IsBot())
			{
				model = (char *)TheBotProfiles->GetCustomSkinModelname(m_iModelName);
				if (!model)
					model = "urban";
			}
			else
				model = "urban";

			break;
		}
		}
	}
	else if (m_iTeam == TERRORIST)
	{
		switch (m_iModelName)
		{
		case MODEL_TERROR:
			model = "terror";
			break;
		case MODEL_LEET:
			model = "leet";
			break;
		case MODEL_ARCTIC:
			model = "arctic";
			break;
		case MODEL_GUERILLA:
			model = "guerilla";
			break;
		case MODEL_MILITIA:
			if (UTIL_IsGame("czero"))
			{
				model = "militia";
				break;
			}
		default:
		{
			if (IsBot())
			{
				model = (char *)TheBotProfiles->GetCustomSkinModelname(m_iModelName);
				if (!model)
					model = "terror";
			}
			else
				model = "terror";

			break;
		}
		}
	}
	else
		model = "urban";

	if (Q_strcmp(GET_KEY_VALUE(infobuffer, "model"), model))
	{
		SET_CLIENT_KEY_VALUE(entindex(), infobuffer, "model", model);
	}
}

/* <15f129> ../cstrike/dlls/player.cpp:659 */
NOXREF CBasePlayer *CBasePlayer::GetNextRadioRecipient(CBasePlayer *pStartPlayer)
{
	CBaseEntity *pEntity = (CBaseEntity *)pStartPlayer;
	while ((pEntity = UTIL_FindEntityByClassname(pEntity, "player")) != NULL)
	{
		if (FNullEnt(pEntity->edict()))
			break;

		BOOL bSend = FALSE;
		CBasePlayer *pPlayer = GetClassPtr((CBasePlayer *)pEntity->pev);

		if (pEntity->IsPlayer())
		{
			if (pEntity->IsDormant())
				continue;

			if (pPlayer && pPlayer->m_iTeam == m_iTeam)
				bSend = TRUE;
		}
		else if (pPlayer)
		{
			int iSpecMode = IsObserver();

			if (iSpecMode != OBS_CHASE_LOCKED && iSpecMode != OBS_CHASE_FREE && iSpecMode != OBS_IN_EYE)
				continue;

			if (!FNullEnt(m_hObserverTarget))
				continue;

			CBasePlayer *pTarget = (CBasePlayer *)CBaseEntity::Instance(pPlayer->m_hObserverTarget->pev);

			if (pTarget && pTarget->m_iTeam == m_iTeam)
			{
				bSend = TRUE;
			}
		}

		if (bSend)
		{
			return pPlayer;
		}
	}

	return NULL;
}

/* <15edd2> ../cstrike/dlls/player.cpp:705 */
void CBasePlayer::Radio(const char *msg_id, const char *msg_verbose, short pitch, bool showIcon)
{
	if (!IsPlayer())
		return;

	if (pev->deadflag != DEAD_NO && !IsBot())
		return;

	CBaseEntity *pEntity = NULL;
	while ((pEntity = UTIL_FindEntityByClassname(pEntity, "player")) != NULL)
	{
		if (FNullEnt(pEntity->edict()))
			break;
		
		BOOL bSend = FALSE;
		CBasePlayer *pPlayer = GetClassPtr((CBasePlayer *)pEntity->pev);

		if (pEntity->IsPlayer())
		{
			if (pEntity->IsDormant())
				continue;

			if (pEntity && pPlayer->m_iTeam == m_iTeam)
				bSend = TRUE;
		}
		else if (pEntity)
		{
			int iSpecMode = IsObserver();

			if (iSpecMode != OBS_CHASE_LOCKED && iSpecMode != OBS_CHASE_FREE && iSpecMode != OBS_IN_EYE)
				continue;

			if (!FNullEnt(m_hObserverTarget))
				continue;

			CBasePlayer *pTarget = (CBasePlayer *)CBaseEntity::Instance(pPlayer->m_hObserverTarget->pev);

			if (pTarget && pTarget->m_iTeam == m_iTeam)
				bSend = TRUE;
		}

		if (!bSend || pPlayer->m_bIgnoreRadio)
			continue;

		MESSAGE_BEGIN(MSG_ONE, gmsgSendAudio, NULL, pEntity->pev);
			WRITE_BYTE(ENTINDEX(edict()));
			WRITE_STRING(msg_id);
			WRITE_SHORT(pitch);
		MESSAGE_END();

		if (msg_verbose)	
		{
			// search the place name where is located the player
			const char *placeName = NULL;
			Place playerPlace = TheNavAreaGrid.GetPlace( &pev->origin );
			const BotPhraseList *placeList = TheBotPhrases->GetPlaceList();

			for (BotPhraseList::const_iterator iter = placeList->begin(); iter != placeList->end(); ++iter)
			{
				if ((*iter)->GetID() == playerPlace)
				{
					placeName = (*iter)->GetName();
					break;
				}
			}

			if (placeName != NULL)
				ClientPrint(pEntity->pev, HUD_PRINTRADIO, NumAsString(entindex()), "#Game_radio_location", STRING(pev->netname), placeName, msg_verbose);
			else
				ClientPrint(pEntity->pev, HUD_PRINTRADIO, NumAsString(entindex()), "#Game_radio", STRING(pev->netname), msg_verbose);
		}

		if (showIcon)
		{
			MESSAGE_BEGIN(MSG_ONE, SVC_TEMPENTITY, NULL, pEntity->pev);
				WRITE_BYTE(TE_PLAYERATTACHMENT);
				WRITE_BYTE(ENTINDEX(edict()));
				WRITE_COORD(35); // vertical offset
				WRITE_SHORT(g_sModelIndexRadio); // model index
				WRITE_SHORT(15); // life
			MESSAGE_END();
		}
	}
}

/* <1537f3> ../cstrike/dlls/player.cpp:812 */
void CBasePlayer::SmartRadio(void)
{
	;
}

/* <15381b> ../cstrike/dlls/player.cpp:816 */
void CBasePlayer::Pain(int m_LastHitGroup, bool HasArmour)
{
	int temp = RANDOM_LONG(0, 2);

	if (m_LastHitGroup == HITGROUP_HEAD)
	{
		if (m_iKevlar == ARMOR_TYPE_HELMET)
		{
			EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/bhit_helmet-1.wav", VOL_NORM, ATTN_NORM);
			return;
		}

		switch (temp)
		{
		case 0: EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/headshot1.wav", VOL_NORM, ATTN_NORM); break;
		case 1: EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/headshot2.wav", VOL_NORM, ATTN_NORM); break;
		default: EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/headshot3.wav", VOL_NORM, ATTN_NORM); break;
		}
	}
	else
	{
		if (m_LastHitGroup != HITGROUP_LEFTLEG && m_LastHitGroup != HITGROUP_RIGHTLEG)
		{
			if (HasArmour)
			{
				EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/bhit_kevlar-1.wav", VOL_NORM, ATTN_NORM);
				return;
			}
		}

		switch (temp)
		{
		case 0: EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/bhit_flesh-1.wav", VOL_NORM, ATTN_NORM); break;
		case 1: EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/bhit_flesh-2.wav", VOL_NORM, ATTN_NORM); break;
		default: EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/bhit_flesh-3.wav", VOL_NORM, ATTN_NORM); break;
		}
	}
}

/* <153b48> ../cstrike/dlls/player.cpp:864 */
Vector VecVelocityForDamage(float flDamage)
{
	Vector vec(RANDOM_FLOAT(-100, 100), RANDOM_FLOAT(-100, 100), RANDOM_FLOAT(200, 300));

	if (flDamage > -50.0f)
		vec = vec * 0.7f;
	else if (flDamage > -200.0f)
		vec = vec * 2.0f;
	else
		vec = vec * 10.0f;

	return vec;
}

/* <14edfb> ../cstrike/dlls/player.cpp:878 */
int TrainSpeed(int iSpeed, int iMax)
{
	float fMax;
	float fSpeed;
	int iRet = 0;

	fMax = (float)iMax;
	fSpeed = iSpeed / fMax;

	if (iSpeed < 0)
		iRet = TRAIN_BACK;
	else if (iSpeed == 0)
		iRet = TRAIN_NEUTRAL;
	else if (fSpeed < 0.33)
		iRet = TRAIN_SLOW;
	else if (fSpeed < 0.66)
		iRet = TRAIN_MEDIUM;
	else
		iRet = TRAIN_FAST;

	return iRet;
}

/* <153c8e> ../cstrike/dlls/player.cpp:902 */
void CBasePlayer::DeathSound(void)
{
	switch (RANDOM_LONG(1, 4))
	{
	case 1: EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/die1.wav", VOL_NORM, ATTN_NORM); break;
	case 2: EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/die2.wav", VOL_NORM, ATTN_NORM); break;
	case 3: EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/die3.wav", VOL_NORM, ATTN_NORM); break;
	case 4: EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/death6.wav", VOL_NORM, ATTN_NORM); break;
	}
}

/* <151213> ../cstrike/dlls/player.cpp:937 */
int CBasePlayer::__MAKE_VHOOK(TakeHealth)(float flHealth, int bitsDamageType)
{
	return CBaseMonster::TakeHealth(flHealth, bitsDamageType);
}

/* <150f1c> ../cstrike/dlls/player.cpp:943 */
Vector CBasePlayer::__MAKE_VHOOK(GetGunPosition)(void)
{
	return pev->origin + pev->view_ofs;
}

/* <15412b> ../cstrike/dlls/player.cpp:953 */
bool CBasePlayer::IsHittingShield(Vector &vecDirection, TraceResult *ptr)
{
	if ((m_pActiveItem && m_pActiveItem->m_iId == WEAPON_C4) || !HasShield())
		return false;

	if (ptr->iHitgroup == HITGROUP_SHIELD)
		 return true;

	if (m_bShieldDrawn)
		UTIL_MakeVectors(pev->angles);

	return false;
}

/* <152b58> ../cstrike/dlls/player.cpp:989 */
void CBasePlayer::__MAKE_VHOOK(TraceAttack)(entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType)
{
	bool bShouldBleed = true;
	bool bShouldSpark = false;
	bool bHitShield = IsHittingShield(vecDir, ptr);
	CBasePlayer *pAttacker = (CBasePlayer *)CBasePlayer::Instance(pevAttacker);

	if (CVAR_GET_FLOAT("mp_friendlyfire") == 0 && m_iTeam == pAttacker->m_iTeam)
		bShouldBleed = false;

	if (pev->takedamage == DAMAGE_NO)
		return;

	m_LastHitGroup = ptr->iHitgroup;
	if (bHitShield)
	{
		flDamage = 0;

		if (RANDOM_LONG(0, 1))
			EMIT_SOUND(ENT(pev), CHAN_VOICE, "weapons/ric_metal-1.wav", VOL_NORM, ATTN_NORM);
		else
			EMIT_SOUND(ENT(pev), CHAN_VOICE, "weapons/ric_metal-2.wav", VOL_NORM, ATTN_NORM);

		UTIL_Sparks(ptr->vecEndPos);

		pev->punchangle.x = flDamage * RANDOM_FLOAT(-0.15, 0.15);
		pev->punchangle.z = flDamage * RANDOM_FLOAT(-0.15, 0.15);

		if (pev->punchangle.x < 4)
			pev->punchangle.x = -4;

		if (pev->punchangle.z < -5)
			pev->punchangle.z = -5;

		else if (pev->punchangle.z > 5)
			pev->punchangle.z = 5;
	}
	else
	{
		switch (ptr->iHitgroup)
		{
			case HITGROUP_GENERIC:
				break;

			case HITGROUP_HEAD:
			{
				if (m_iKevlar == ARMOR_TYPE_HELMET)
				{
					bShouldBleed = false;
					bShouldSpark = true;
				}

				flDamage *= 4;
				if (bShouldBleed)
				{
					pev->punchangle.x = flDamage * -0.5;

					if (pev->punchangle.x < -12)
						pev->punchangle.x = -12;

					pev->punchangle.z = flDamage * RANDOM_FLOAT(-1, 1);

					if (pev->punchangle.z < -9)
						pev->punchangle.z = -9;

					else if (pev->punchangle.z > 9)
						pev->punchangle.z = 9;
				}
				break;
			}
			case HITGROUP_CHEST:
			{
				flDamage *= 1;

				if (m_iKevlar != ARMOR_TYPE_EMPTY)
					bShouldBleed = false;

				else if (bShouldBleed)
				{
					pev->punchangle.x = flDamage * -0.1;

					if (pev->punchangle.x < -4)
						pev->punchangle.x = -4;
				}
				break;
			}
			case HITGROUP_STOMACH:
			{
				flDamage = flDamage * 1.25;

				if (m_iKevlar != ARMOR_TYPE_EMPTY)
					bShouldBleed = false;

				else if (bShouldBleed)
				{
					pev->punchangle.x = flDamage * -0.1;

					if (pev->punchangle.x < -4)
						pev->punchangle.x = -4;
				}
				break;
			}
			case HITGROUP_LEFTARM:
			case HITGROUP_RIGHTARM:
			{
				if (m_iKevlar != ARMOR_TYPE_EMPTY)
					bShouldBleed = false;

				break;
			}
			case HITGROUP_LEFTLEG:
			case HITGROUP_RIGHTLEG:
			{
				flDamage *= 0.75;
				break;
			}
		}
	}

	if (bShouldBleed)
	{
		BloodSplat(ptr->vecEndPos, vecDir, ptr->iHitgroup, flDamage * 5);
		SpawnBlood(ptr->vecEndPos, BloodColor(), flDamage);
		TraceBleed(flDamage, vecDir, ptr, bitsDamageType);
	}
	else if (ptr->iHitgroup == HITGROUP_HEAD && bShouldSpark == true)
	{
		MESSAGE_BEGIN(MSG_PVS, SVC_TEMPENTITY, ptr->vecEndPos);
			WRITE_BYTE(TE_STREAK_SPLASH);
			WRITE_COORD(ptr->vecEndPos.x);
			WRITE_COORD(ptr->vecEndPos.y);
			WRITE_COORD(ptr->vecEndPos.z);
			WRITE_COORD(ptr->vecPlaneNormal.x);
			WRITE_COORD(ptr->vecPlaneNormal.y);
			WRITE_COORD(ptr->vecPlaneNormal.z);
			WRITE_BYTE(5); // color
			WRITE_SHORT(22); // count
			WRITE_SHORT(25); // base speed
			WRITE_SHORT(65); // ramdon velocity
		MESSAGE_END();
	}

	AddMultiDamage(pevAttacker, this, flDamage, bitsDamageType);
}

/* <1541c2> ../cstrike/dlls/player.cpp:1171 */
const char *GetWeaponName(entvars_t *pevInflictor, entvars_t *pKiller)
{
	const char *killer_weapon_name = "world";

	if (pKiller->flags & FL_CLIENT)
	{
		//int killer_index = ENTINDEX(ENT(pKiller)); unused!

		if (pevInflictor)
		{
			if (pevInflictor == pKiller)
			{
				CBasePlayer *pAttacker = (CBasePlayer *)CBaseEntity::Instance(pKiller);

				if (pAttacker)
				{
					if (pAttacker->m_pActiveItem)
						killer_weapon_name = pAttacker->m_pActiveItem->pszName();
				}
			}
			else
				killer_weapon_name = STRING(pevInflictor->classname);
		}
	}
	else
		killer_weapon_name = STRING(pevInflictor->classname);

	if (!Q_strncmp(killer_weapon_name, "weapon_", 7))
		killer_weapon_name += 7;

	else if (!Q_strncmp(killer_weapon_name, "monster_", 8))
		killer_weapon_name += 8;

	else if (Q_strncmp(killer_weapon_name, "func_", 5))
		killer_weapon_name += 5;

	return killer_weapon_name;
}

/* <14e061> ../cstrike/dlls/player.cpp:1214 */
void LogAttack(CBasePlayer *pAttacker, CBasePlayer *pVictim, int teamAttack, int healthHit, int armorHit, int newHealth, int newArmor, const char *killer_weapon_name)
{
	int detail = logdetail.value;

	if (!detail)
		return;

	if (!pAttacker || !pVictim)
		return;

	if ((teamAttack && (detail & LOG_TEAMMATEATTACK)) || (!teamAttack && (detail & LOG_ENEMYATTACK)))
	{
		UTIL_LogPrintf
		(
			"\"%s<%i><%s><%s>\" attacked \"%s<%i><%s><%s>\" with \"%s\" (damage \"%d\") (damage_armor \"%d\") (health \"%d\") (armor \"%d\")\n",
			STRING(pAttacker->pev->netname),
			GETPLAYERUSERID(pAttacker->edict()),
			GETPLAYERAUTHID(pAttacker->edict()),
			GetTeam(pAttacker->m_iTeam),
			STRING(pVictim->pev->netname),
			GETPLAYERUSERID(pVictim->edict()),
			GETPLAYERAUTHID(pVictim->edict()),
			GetTeam(pVictim->m_iTeam),
			killer_weapon_name,
			healthHit,
			armorHit,
			newHealth,
			newArmor
		);
	}
}

// Take some damage.  
// NOTE: each call to TakeDamage with bitsDamageType set to a time-based damage
// type will cause the damage time countdown to be reset.  Thus the ongoing effects of poison, radiation
// etc are implemented with subsequent calls to TakeDamage using DMG_GENERIC.

/* <15dff9> ../cstrike/dlls/player.cpp:1241 */
int CBasePlayer::__MAKE_VHOOK(TakeDamage)(entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType)
{
	int fTookDamage;
	float flRatio = ARMOR_RATIO;
	float flBonus = ARMOR_BONUS;
	//float flHealthPrev = pev->health;
	int iGunType = 0;
	float flShieldRatio = 0;
	int teamAttack = FALSE;
	int armorHit = 0;
	CBasePlayer *pAttack = NULL;
	CBaseEntity *pAttacker = NULL;
	//CBaseEntity *attacker = NULL; // unused

	if (bitsDamageType & (DMG_EXPLOSION | DMG_BLAST | DMG_FALL))
		m_LastHitGroup = HITGROUP_GENERIC;

	else if (m_LastHitGroup == HITGROUP_SHIELD && (bitsDamageType & DMG_BULLET))
		return 0;

	if (HasShield())
		flShieldRatio = 0.2;

	if (m_bIsVIP)
		flRatio *= 0.5;

	if (bitsDamageType & (DMG_EXPLOSION | DMG_BLAST))
	{
		if (!IsAlive())
		{
			return 0;
		}

		if (bitsDamageType & DMG_EXPLOSION)
		{
			CBaseEntity *temp = GetClassPtr((CBaseEntity *)pevInflictor);

			if (!Q_strcmp(STRING(temp->pev->classname), "grenade"))
			{
				CGrenade *pGrenade = GetClassPtr((CGrenade *)pevInflictor);

				if (CVAR_GET_FLOAT("mp_friendlyfire"))
				{
					if (pGrenade->m_iTeam == m_iTeam)
						teamAttack = TRUE;

					pAttack = reinterpret_cast<CBasePlayer *>(CBasePlayer::Instance(pevAttacker));
				}
				else if (pGrenade->m_iTeam == m_iTeam && (&edict()->v != pevAttacker))
				{
					return 0;
				}
			}
		}

		if (!FNullEnt(ENT(pevInflictor)))
			m_vBlastVector = pev->origin - pevInflictor->origin;

		if (pev->armorvalue != 0.0f && IsArmored(m_LastHitGroup))
		{
			float_precision flNew = flRatio * flDamage;
			float_precision flArmor = (flDamage - flNew) * flBonus;

			// Does this use more armor than we have?
			if (flArmor > pev->armorvalue)
			{
				flNew = flDamage - pev->armorvalue;
				armorHit = flArmor;
				pev->armorvalue = 0;
			}
			else
			{
				int oldValue = pev->armorvalue;

				if (flArmor < 0.0)
					flArmor = 1.0;

				pev->armorvalue -= flArmor;
				armorHit = oldValue - pev->armorvalue;
			}

			flDamage = flNew;

			if (pev->armorvalue <= 0.0)
				m_iKevlar = ARMOR_TYPE_EMPTY;

			Pain(m_LastHitGroup, true);
		}
		else
			Pain(m_LastHitGroup, false);

		m_lastDamageAmount = flDamage;

		if (pev->health > flDamage)
		{
			SetAnimation(PLAYER_FLINCH);
			Pain(m_LastHitGroup, false);
		}
		else
		{
			if (bitsDamageType & DMG_BLAST)
				m_bKilledByBomb = true;

			else if (bitsDamageType & DMG_EXPLOSION)
				m_bKilledByGrenade = true;
		}

		LogAttack(pAttack, this, teamAttack, (int)flDamage, armorHit, pev->health - flDamage, pev->armorvalue, GetWeaponName(pevInflictor, pevAttacker));
		fTookDamage = CBaseMonster::TakeDamage(pevInflictor, pevAttacker, (int)flDamage, bitsDamageType);

		if (fTookDamage > 0)
		{
			CHalfLifeMultiplay *mp = g_pGameRules;

			if (TheBots)
				TheBots->OnEvent(EVENT_PLAYER_TOOK_DAMAGE, this, pAttack);

			if (mp->IsCareer())
			{
				for (int i = 1; i <= gpGlobals->maxClients; i++)
				{
					CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );

					if (!pPlayer)
						continue;

					bool killedByHumanPlayer = (!pPlayer->IsBot() && pPlayer->pev == pevAttacker && pPlayer->m_iTeam != m_iTeam);

					if (killedByHumanPlayer)
					{
						TheCareerTasks->HandleEnemyInjury(GetWeaponName(pevInflictor, pevAttacker), pPlayer->HasShield(), pPlayer);
					}
				}
			}
		}

		{
			// reset damage time countdown for each type of time based damage player just sustained
			for (int i = 0; i < CDMG_TIMEBASED; i++)
			{
				if (bitsDamageType & (DMG_PARALYZE << i))
					m_rgbTimeBasedDamage[i] = 0;
			}
		}

		// tell director about it
		MESSAGE_BEGIN(MSG_SPEC, SVC_DIRECTOR);
			WRITE_BYTE(9);			// command length in bytes
			WRITE_BYTE(DRC_CMD_EVENT);	// take damage event
			WRITE_SHORT(ENTINDEX(edict()));		// index number of primary entity
			WRITE_SHORT(ENTINDEX(ENT(pevInflictor))); // index number of secondary entity
			WRITE_LONG(5);			// eventflags (priority and flags)
		MESSAGE_END();

		MESSAGE_BEGIN(MSG_SPEC, gmsgHLTV);
			WRITE_BYTE(ENTINDEX(edict()));
			WRITE_BYTE((int)_max(pev->health, 0) | DRC_FLAG_FACEPLAYER);
		MESSAGE_END();

		for (int i = 1; i <= gpGlobals->maxClients; i++)
		{
			CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex(i);

			if (!pPlayer || pPlayer->m_hObserverTarget != this)
				continue;

			MESSAGE_BEGIN(MSG_ONE, gmsgSpecHealth, NULL, pPlayer->edict());
				WRITE_BYTE((int)_max(pev->health, 0));
			MESSAGE_END();
		}

		return fTookDamage;
	}

	pAttacker = CBaseEntity::Instance(pevAttacker);

	if (!g_pGameRules->FPlayerCanTakeDamage(this, pAttacker) && Q_strcmp("grenade", STRING(pevInflictor->classname)))
	{
		// Refuse the damage
		return 0;
	}

	if (bitsDamageType & DMG_BLAST && g_pGameRules->IsMultiplayer())
	{
		// blasts damage armor more.
		flBonus *= 2;
	}

	// Already dead
	if (!IsAlive())
		return 0;

	pAttacker = GetClassPtr((CBaseEntity *)pevAttacker);

	if (pAttacker->IsPlayer())
	{
		pAttack = GetClassPtr((CBasePlayer *)pevAttacker);

		if (pAttack != this && pAttack->m_iTeam == m_iTeam)
		{
			// TODO: this->m_flDisplayHistory!!
			if (!(m_flDisplayHistory & DHF_FRIEND_INJURED))
			{
				m_flDisplayHistory |= DHF_FRIEND_INJURED;
				pAttack->HintMessage("#Hint_try_not_to_injure_teammates");
			}

			teamAttack = TRUE;
			if (gpGlobals->time > pAttack->m_flLastAttackedTeammate + 0.6)
			{
				CBaseEntity *pBasePlayer = NULL;
				while ((pBasePlayer = UTIL_FindEntityByClassname(pBasePlayer, "player")) != NULL)
				{
					if (FNullEnt(pBasePlayer->edict()))
						break;

					CBasePlayer *basePlayer = GetClassPtr((CBasePlayer *)pBasePlayer->pev);

					if (basePlayer->m_iTeam == m_iTeam)
					{
						ClientPrint(basePlayer->pev, HUD_PRINTTALK, "#Game_teammate_attack", STRING(pAttack->pev->netname));
					}
				}

				pAttack->m_flLastAttackedTeammate = gpGlobals->time;
			}
		}

		if (pAttack->m_iTeam == m_iTeam)
			flDamage *= 0.35;

		iGunType = pAttack->m_pActiveItem->m_iId;

		if (pAttack->m_pActiveItem)
		{
			flRatio += flShieldRatio;
			switch (iGunType)
			{
			case WEAPON_AUG:
			case WEAPON_M4A1:	flRatio *= 1.4; break;
			case WEAPON_AWP:	flRatio *= 1.95; break;
			case WEAPON_G3SG1:	flRatio *= 1.65; break;
			case WEAPON_SG550:	flRatio *= 1.45; break;
			case WEAPON_M249:	flRatio *= 1.5; break;
			case WEAPON_ELITE:	flRatio *= 1.05; break;
			case WEAPON_DEAGLE:	flRatio *= 1.5; break;
			case WEAPON_GLOCK18:	flRatio *= 1.05; break;
			case WEAPON_FIVESEVEN:
			case WEAPON_P90:	flRatio *= 1.5; break;
			case WEAPON_MAC10:	flRatio *= 0.95; break;
			case WEAPON_P228:	flRatio *= 1.25; break;
			case WEAPON_SCOUT:
			case WEAPON_KNIFE:	flRatio *= 1.7; break;
			case WEAPON_FAMAS:
			case WEAPON_SG552:	flRatio *= 1.4; break;
			case WEAPON_GALIL:
			case WEAPON_AK47:	flRatio *= 1.55; break;
			}
		}

		if (!ShouldDoLargeFlinch(m_LastHitGroup, iGunType))
		{
			m_flVelocityModifier = 0.5f;

			if (m_LastHitGroup == HITGROUP_HEAD)
				m_bHighDamage = (flDamage > 60);
			else
				m_bHighDamage = (flDamage > 20);

			SetAnimation(PLAYER_FLINCH);
		}
		else
		{
			if (pev->velocity.Length() < 300)
			{
				Vector attack_velocity = (pev->origin - pAttack->pev->origin).Normalize() * 170;
				pev->velocity = pev->velocity + attack_velocity;

				m_flVelocityModifier = 0.65f;
			}
			SetAnimation(PLAYER_LARGE_FLINCH);
		}
	}

	// keep track of amount of damage last sustained
	m_lastDamageAmount = flDamage;

	// Armor
	// armor doesn't protect against fall or drown damage!
	if (pev->armorvalue != 0.0f && !(bitsDamageType & (DMG_DROWN | DMG_FALL)) && IsArmored(m_LastHitGroup))
	{
		float_precision flNew = flRatio * flDamage;
		float_precision flArmor = (flDamage - flNew) * flBonus;

		// Does this use more armor than we have?
		if (flArmor > pev->armorvalue)
		{
			armorHit = flArmor;
			flArmor = pev->armorvalue;
			flArmor *= (1 / flBonus);
			flNew = flDamage - flArmor;
			pev->armorvalue = 0;
		}
		else
		{
			int oldValue = pev->armorvalue;

			if (flArmor < 0.0)
				flArmor = 1.0;

			pev->armorvalue -= flArmor;
			armorHit = oldValue - pev->armorvalue;
		}

		flDamage = flNew;

		if (pev->armorvalue <= 0.0f)
			m_iKevlar = ARMOR_TYPE_EMPTY;

		Pain(m_LastHitGroup, true);
	}
	else
		Pain(m_LastHitGroup, false);

	LogAttack(pAttack, this, teamAttack, flDamage, armorHit, pev->health - flDamage, pev->armorvalue, GetWeaponName(pevInflictor, pevAttacker));

	// this cast to INT is critical!!! If a player ends up with 0.5 health, the engine will get that
	// as an int (zero) and think the player is dead! (this will incite a clientside screentilt, etc)
	fTookDamage = CBaseMonster::TakeDamage(pevInflictor, pevAttacker, (int)flDamage, bitsDamageType);

	if (fTookDamage > 0)
	{
		CHalfLifeMultiplay *mp = g_pGameRules;

		if (TheBots)
		{
			TheBots->OnEvent(EVENT_PLAYER_TOOK_DAMAGE, this, pAttack);
		}

		if (mp->IsCareer())
		{
			for (int i = 1; i <= gpGlobals->maxClients; i++)
			{
				CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );

				if (!pPlayer)
					continue;

				bool killedByHumanPlayer = (!pPlayer->IsBot() && pPlayer->pev == pevAttacker && pPlayer->m_iTeam != m_iTeam);

				if (killedByHumanPlayer)
				{
					TheCareerTasks->HandleEnemyInjury(GetWeaponName(pevInflictor, pevAttacker), pPlayer->HasShield(), pPlayer);
				}
			}
		}
	}

	{
		// reset damage time countdown for each type of time based damage player just sustained
		for (int i = 0; i < CDMG_TIMEBASED; i++)
		{
			if (bitsDamageType & (DMG_PARALYZE << i))
				m_rgbTimeBasedDamage[i] = 0;
		}
	}

	// tell director about it
	MESSAGE_BEGIN(MSG_SPEC, SVC_DIRECTOR);
		WRITE_BYTE(9);			// command length in bytes
		WRITE_BYTE(DRC_CMD_EVENT);	// take damage event
		WRITE_SHORT(ENTINDEX(edict()));		// index number of primary entity
		WRITE_SHORT(ENTINDEX(ENT(pevInflictor)));	// index number of secondary entity
		WRITE_LONG(5);			// eventflags (priority and flags)
	MESSAGE_END();

	MESSAGE_BEGIN(MSG_SPEC, gmsgHLTV);
		WRITE_BYTE(ENTINDEX(edict()));
		WRITE_BYTE((int)_max(pev->health, 0) | DRC_FLAG_FACEPLAYER);
	MESSAGE_END();

	for (int i = 1; i <= gpGlobals->maxClients; i++)
	{
		CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );

		if (!pPlayer)
			continue;

		if (pPlayer->m_hObserverTarget == this)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgSpecHealth, NULL, pPlayer->edict());
				WRITE_BYTE((int)_max(pev->health, 0));
			MESSAGE_END();
		}
	}

	// Save this so we can report it to the client
	m_bitsHUDDamage = -1;

	// make sure the damage bits get resent
	m_bitsDamageType |= bitsDamageType;

	return fTookDamage;
}

/* <1516a0> ../cstrike/dlls/player.cpp:1706 */
void packPlayerItem(CBasePlayer *pPlayer, CBasePlayerItem *pItem, bool packAmmo)
{
	if (pItem)
	{
		const char *modelName = GetCSModelName(pItem->m_iId);
		if (modelName)
		{
			CWeaponBox *pWeaponBox = (CWeaponBox *)CBaseEntity::Create("weaponbox", pPlayer->pev->origin, pPlayer->pev->angles, ENT(pPlayer->pev));

			pWeaponBox->pev->angles.x = 0;
			pWeaponBox->pev->angles.z = 0;

			pWeaponBox->pev->velocity = pPlayer->pev->velocity * 0.75;

			pWeaponBox->SetThink(&CWeaponBox::Kill);
			pWeaponBox->pev->nextthink = gpGlobals->time + 300;
			pWeaponBox->PackWeapon(pItem);

			if (packAmmo)
			{
				pWeaponBox->PackAmmo(MAKE_STRING(IMPLEMENT_ARRAY_CLASS(CBasePlayerItem, ItemInfoArray)[ pItem->m_iId ].pszAmmo1), pPlayer->m_rgAmmo[pItem->PrimaryAmmoIndex()]);
			}
			SET_MODEL(ENT(pWeaponBox->pev), modelName);
		}
	}
}

/* <15f739> ../cstrike/dlls/player.cpp:1756 */
void CBasePlayer::PackDeadPlayerItems(void)
{
	bool bPackGun = (g_pGameRules->DeadPlayerWeapons(this) != GR_PLR_DROP_GUN_NO);
	bool bPackAmmo = (g_pGameRules->DeadPlayerAmmo(this) != GR_PLR_DROP_AMMO_NO);

	if (bPackGun)
	{
		bool bShieldDropped = false;
		if (HasShield())
		{
			DropShield();
			bShieldDropped = true;
		}

		int nBestWeight = 0;
		CBasePlayerItem *pBestItem = NULL;

		for (int n = 0; n < MAX_ITEM_TYPES; n++)
		{
			CBasePlayerItem *pPlayerItem = m_rgpPlayerItems[ n ];

			while (pPlayerItem != NULL)
			{
				ItemInfo info;
				if (pPlayerItem->iItemSlot() < KNIFE_SLOT && !bShieldDropped)
				{
					if (pPlayerItem->GetItemInfo(&info))
					{
						if (info.iWeight > nBestWeight)
						{
							nBestWeight = info.iWeight;
							pBestItem = pPlayerItem;
						}
					}
				}
				else if (pPlayerItem->iItemSlot() == GRENADE_SLOT && UTIL_IsGame("czero"))
					packPlayerItem(this, pPlayerItem, true);

				pPlayerItem = pPlayerItem->m_pNext;
			}
		}
		packPlayerItem(this, pBestItem, bPackAmmo);
	}
	RemoveAllItems(TRUE);
}

/* <15f710> ../cstrike/dlls/player.cpp:1829 */
void CBasePlayer::GiveDefaultItems(void)
{
	RemoveAllItems(FALSE);
	m_bHasPrimary = false;

	switch (m_iTeam)
	{
	case CT:
		GiveNamedItem("weapon_knife");
		GiveNamedItem("weapon_usp");
		GiveAmmo(m_bIsVIP ? 12 : 24, "45acp", MAX_AMMO_45ACP);

		break;
	case TERRORIST:
		GiveNamedItem("weapon_knife");
		GiveNamedItem("weapon_glock18");
		GiveAmmo(40, "9mm", MAX_AMMO_9MM);

		break;
	}
}

/* <15f406> ../cstrike/dlls/player.cpp:1871 */
void CBasePlayer::RemoveAllItems(BOOL removeSuit)
{
	BOOL bKillProgBar = false;
	int i;

	if (m_bHasDefuser)
	{
		m_bHasDefuser = false;
		pev->body = 0;

		MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, pev);
			WRITE_BYTE(STATUSICON_HIDE);
			WRITE_STRING("defuser");
		MESSAGE_END();

		SendItemStatus(this);
		bKillProgBar = true;
	}

	if (m_bHasC4)
	{
		m_bHasC4 = false;
		pev->body = 0;

		MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, pev);
			WRITE_BYTE(STATUSICON_HIDE);
			WRITE_STRING("c4");
		MESSAGE_END();

		bKillProgBar = true;
	}

	RemoveShield();

	if (bKillProgBar)
		SetProgressBarTime(0);

	if (m_pActiveItem)
	{
		ResetAutoaim();

		m_pActiveItem->Holster();
		m_pActiveItem = NULL;
	}
	m_pLastItem = NULL;

	for (i = 0; i < MAX_ITEM_TYPES; i++)
	{
		m_pActiveItem = m_rgpPlayerItems[i];

		while (m_pActiveItem)
		{
			CBasePlayerItem *pPendingItem = m_pActiveItem->m_pNext;

			m_pActiveItem->Drop();
			m_pActiveItem = pPendingItem;
		}

		m_rgpPlayerItems[i] = NULL;
	}

	m_pActiveItem = NULL;
	m_bHasPrimary = NULL;

	pev->viewmodel = 0;
	pev->weaponmodel = 0;

	if (removeSuit)
		pev->weapons = 0;
	else
		pev->weapons &= ~WEAPON_ALLWEAPONS;

	for (i = 0; i < MAX_AMMO_SLOTS; i++)
		m_rgAmmo[i] = 0;

	UpdateClientData();

	MESSAGE_BEGIN(MSG_ONE, gmsgCurWeapon, NULL, pev);
		WRITE_BYTE(0);
		WRITE_BYTE(0);
		WRITE_BYTE(0);
	MESSAGE_END();
}

/* <15436c> ../cstrike/dlls/player.cpp:1962 */
void CBasePlayer::SetBombIcon(BOOL bFlash)
{
	if (m_bHasC4)
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, pev);
			WRITE_BYTE(bFlash ? STATUSICON_FLASH : STATUSICON_SHOW);
			WRITE_STRING("c4");
			WRITE_BYTE(0);
			WRITE_BYTE(160);
			WRITE_BYTE(0);
		MESSAGE_END();
	}
	else
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, pev);
			WRITE_BYTE(STATUSICON_HIDE);
			WRITE_STRING("c4");
		MESSAGE_END();
	}

	SetScoreboardAttributes();
}

/* <15f2ab> ../cstrike/dlls/player.cpp:1985 */
void CBasePlayer::SetProgressBarTime(int time)
{
	if (time)
	{
		m_progressStart = gpGlobals->time;
		m_progressEnd = time + gpGlobals->time;
	}
	else
	{
		m_progressStart = 0;
		m_progressEnd = 0;
	}

	MESSAGE_BEGIN(MSG_ONE, gmsgBarTime, NULL, pev);
		WRITE_SHORT(time);
	MESSAGE_END();

	CBaseEntity *pPlayer = NULL;
	int myIndex = entindex();

	while ((pPlayer = UTIL_FindEntityByClassname(pPlayer, "player")) != NULL)
	{
		if (FNullEnt(pPlayer->edict()))
			break;

		CBasePlayer *player = GetClassPtr((CBasePlayer *)pPlayer->pev);

		if (player->IsObserver() == OBS_IN_EYE && player->pev->iuser2 == myIndex)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgBarTime, NULL, player->pev);
				WRITE_SHORT(time);
			MESSAGE_END();
		}
	}
}

/* <15dcb4> ../cstrike/dlls/player.cpp:2027 */
void CBasePlayer::SetProgressBarTime2(int time, float timeElapsed)
{
	if (time)
	{
		m_progressStart = gpGlobals->time - timeElapsed;
		m_progressEnd = time + gpGlobals->time - timeElapsed;
	}
	else
	{
		timeElapsed = 0;
		m_progressStart = 0;
		m_progressEnd = 0;
	}

	short iTimeElapsed = (timeElapsed * 100.0 / (m_progressEnd - m_progressStart));

	MESSAGE_BEGIN(MSG_ONE, gmsgBarTime2, NULL, pev);
		WRITE_SHORT(time);
		WRITE_SHORT(iTimeElapsed);
	MESSAGE_END();

	CBaseEntity *pPlayer = NULL;
	int myIndex = entindex();

	while ((pPlayer = UTIL_FindEntityByClassname(pPlayer, "player")) != NULL)
	{
		if (FNullEnt(pPlayer->edict()))
			break;

		CBasePlayer *player = GetClassPtr((CBasePlayer *)pPlayer->pev);

		if (player->IsObserver() == OBS_IN_EYE && player->pev->iuser2 == myIndex)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgBarTime, NULL, player->pev);
				WRITE_SHORT(time);
				WRITE_SHORT(iTimeElapsed);
			MESSAGE_END();
		}
	}
}

/* <14e0e9> ../cstrike/dlls/player.cpp:2073 */
void BuyZoneIcon_Set(CBasePlayer *player)
{
	MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, player->pev);
		WRITE_BYTE(STATUSICON_SHOW);
		WRITE_STRING("buyzone");
		WRITE_BYTE(0);
		WRITE_BYTE(160);
		WRITE_BYTE(0);
	MESSAGE_END();
}

/* <14e106> ../cstrike/dlls/player.cpp:2086 */
void BuyZoneIcon_Clear(CBasePlayer *player)
{
	MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, player->pev);
		WRITE_BYTE(STATUSICON_HIDE);
		WRITE_STRING("buyzone");
	MESSAGE_END();

	if (player->m_iMenu >= Menu_Buy)
	{
		if (player->m_iMenu <= Menu_BuyItem)
		{
			CLIENT_COMMAND(ENT(player->pev), "slot10\n");
		}
		else if (player->m_iMenu == Menu_ClientBuy)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgBuyClose, NULL, player->pev);
			MESSAGE_END();
		}
	}
}

/* <14e62c> ../cstrike/dlls/player.cpp:2115 */
void BombTargetFlash_Set(CBasePlayer *player)
{
	if (player->m_bHasC4 && !(player->m_flDisplayHistory & DHF_IN_TARGET_ZONE))
	{
		player->m_flDisplayHistory |= DHF_IN_TARGET_ZONE;
		player->HintMessage("#Hint_you_are_in_targetzone", TRUE); // TODO: send also for dead the players?
	}
	player->SetBombIcon(TRUE);
}

/* <14e649> ../cstrike/dlls/player.cpp:2129 */
void BombTargetFlash_Clear(CBasePlayer *player)
{
	player->SetBombIcon(FALSE);
}

/* <158292> ../cstrike/dlls/player.cpp:2136 */
void RescueZoneIcon_Set(CBasePlayer *player)
{
	MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, player->pev);
		WRITE_BYTE(STATUSICON_SHOW);
		WRITE_STRING("rescue");
		WRITE_BYTE(0);
		WRITE_BYTE(160);
		WRITE_BYTE(0);
	MESSAGE_END();

	if (player->m_iTeam == CT && !(player->m_flDisplayHistory & DHF_IN_RESCUE_ZONE))
	{
		player->m_flDisplayHistory |= DHF_IN_RESCUE_ZONE;
		player->HintMessage("#Hint_hostage_rescue_zone", TRUE); // TODO: send also for dead the players?
	}
}

/* <14e666> ../cstrike/dlls/player.cpp:2156 */
void RescueZoneIcon_Clear(CBasePlayer *player)
{
	MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, player->pev);
		WRITE_BYTE(STATUSICON_HIDE);
		WRITE_STRING("rescue");
	MESSAGE_END();

	if (player->m_iMenu >= Menu_Buy)
	{
		if (player->m_iMenu <= Menu_BuyItem)
		{
			CLIENT_COMMAND(ENT(player->pev), "slot10\n");
		}
		else if (player->m_iMenu == Menu_ClientBuy)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgBuyClose, NULL, player->pev);
			MESSAGE_END();
		}
	}
}

/* <1582af> ../cstrike/dlls/player.cpp:2185 */
void EscapeZoneIcon_Set(CBasePlayer *player)
{
	MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, player->pev);
		WRITE_BYTE(STATUSICON_SHOW);
		WRITE_STRING("escape");
		WRITE_BYTE(0);
		WRITE_BYTE(160);
		WRITE_BYTE(0);
	MESSAGE_END();

	if (player->m_iTeam == CT)
	{
		if (!(player->m_flDisplayHistory & DHF_IN_ESCAPE_ZONE))
		{
			player->m_flDisplayHistory |= DHF_IN_ESCAPE_ZONE;
			player->HintMessage("#Hint_terrorist_escape_zone");
		}
	}
}

/* <14e683> ../cstrike/dlls/player.cpp:2203 */
void EscapeZoneIcon_Clear(CBasePlayer *player)
{
	MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, player->pev);
		WRITE_BYTE(STATUSICON_HIDE);
		WRITE_STRING("escape");
	MESSAGE_END();

	if (player->m_iMenu >= Menu_Buy)
	{
		if (player->m_iMenu <= Menu_BuyItem)
		{
			CLIENT_COMMAND(player->edict(), "slot10\n");
		}
		else if (player->m_iMenu == Menu_ClientBuy)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgBuyClose, NULL, player->pev);
			MESSAGE_END();
		}
	}
}

/* <1582cc> ../cstrike/dlls/player.cpp:2231 */
void VIP_SafetyZoneIcon_Set(CBasePlayer *player)
{
	MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, player->pev);
		WRITE_BYTE(STATUSICON_SHOW);
		WRITE_STRING("vipsafety");
		WRITE_BYTE(0);
		WRITE_BYTE(160);
		WRITE_BYTE(0);
	MESSAGE_END();
	
	if (!(player->m_flDisplayHistory & DHF_IN_VIPSAFETY_ZONE))
	{
		if (player->m_iTeam == CT)
		{
			player->m_flDisplayHistory |= DHF_IN_VIPSAFETY_ZONE;
			player->HintMessage("#Hint_ct_vip_zone", TRUE);
		}
		else if (player->m_iTeam == TERRORIST)
		{
			player->m_flDisplayHistory |= DHF_IN_VIPSAFETY_ZONE;
			player->HintMessage("#Hint_terrorist_vip_zone", TRUE);
		}
	}
}

/* <14e6a0> ../cstrike/dlls/player.cpp:2255 */
void VIP_SafetyZoneIcon_Clear(CBasePlayer *player)
{
	MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, player->pev);
		WRITE_BYTE(STATUSICON_HIDE);
		WRITE_STRING("vipsafety");
	MESSAGE_END();

	if (player->m_iMenu >= Menu_Buy)
	{
		if (player->m_iMenu <= Menu_BuyItem)
		{
			CLIENT_COMMAND(player->edict(), "slot10\n");
		}
		else if (player->m_iMenu == Menu_ClientBuy)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgBuyClose, NULL, player->pev);
			MESSAGE_END();
		}
	}
}

/* <154417> ../cstrike/dlls/player.cpp:2282 */
void CBasePlayer::SendFOV(int fov)
{
	pev->fov = (float_precision)fov;
	m_iClientFOV = fov;
	m_iFOV = fov;

	MESSAGE_BEGIN(MSG_ONE, gmsgSetFOV, NULL, pev);
		WRITE_BYTE(fov);
	MESSAGE_END();
}

/* <160a1a> ../cstrike/dlls/player.cpp:2300 */
void CBasePlayer::__MAKE_VHOOK(Killed)(entvars_t *pevAttacker, int iGib)
{
	m_canSwitchObserverModes = false;

	if (m_LastHitGroup == HITGROUP_HEAD)
		m_bHeadshotKilled = true;

	CBaseEntity *pAttackerEntity = CBaseEntity::Instance(pevAttacker);

	TheBots->OnEvent(EVENT_PLAYER_DIED, this, pAttackerEntity);

	if (g_pGameRules->IsCareer())
	{
		bool killerHasShield = false;
		bool wasBlind = false;

		if (!IsBot())
		{
			TheCareerTasks->HandleEvent(EVENT_DIE, NULL, this);
		}
		TheCareerTasks->HandleDeath(m_iTeam, this);

		if (!m_bKilledByBomb)
		{
			CBasePlayer *pAttacker = (CBasePlayer *)CBaseEntity::Instance(pevAttacker);

			if (pAttacker->HasShield())
				killerHasShield = true;

			CCSBot *pBot = reinterpret_cast<CCSBot *>(this);
			if (pBot->IsBot() && pBot->IsBlind())
			{
				wasBlind = true;
			}

			for (int i = 1; i <= gpGlobals->maxClients; i++)
			{
				CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex(i);

				if (!pPlayer)
					continue;

				bool killedByHumanPlayer = (!pPlayer->IsBot() && pPlayer->pev == pevAttacker && pPlayer->m_iTeam != m_iTeam);

				if (killedByHumanPlayer)
				{
					TheCareerTasks->HandleEnemyKill(wasBlind, GetWeaponName(g_pevLastInflictor, pevAttacker), m_bHeadshotKilled, killerHasShield, this, pPlayer);
				}
			}
		}
	}

	if (!m_bKilledByBomb)
	{
		g_pGameRules->PlayerKilled(this, pevAttacker, g_pevLastInflictor);
	}

	MESSAGE_BEGIN(MSG_ONE, gmsgNVGToggle, NULL, pev);
		WRITE_BYTE(0);
	MESSAGE_END();

	m_bNightVisionOn = false;

	for (int i = 1; i <= gpGlobals->maxClients; ++i)
	{
		CBasePlayer *pObserver = (CBasePlayer *)UTIL_PlayerByIndex(i);

		if (!pObserver)
			continue;

		if (pObserver->IsObservingPlayer(this))
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgNVGToggle, NULL, pObserver->pev);
				WRITE_BYTE(0);
			MESSAGE_END();

			pObserver->m_bNightVisionOn = false;
		}
	}

	if (m_pTank != NULL)
	{
		m_pTank->Use(this, this, USE_OFF, 0);
		m_pTank = NULL;
	}

	CSound *pSound = CSoundEnt::SoundPointerForIndex(CSoundEnt::ClientSoundIndex(edict()));

	if (pSound)
	{
		pSound->Reset();
	}

	SetAnimation(PLAYER_DIE);

	if (m_pActiveItem && m_pActiveItem->m_pPlayer)
	{
		switch (m_pActiveItem->m_iId)
		{
		case WEAPON_HEGRENADE:
		{
			CHEGrenade *pHEGrenade = (CHEGrenade *)m_pActiveItem;
			if ((pev->button & IN_ATTACK) && m_rgAmmo[ pHEGrenade->m_iPrimaryAmmoType ])
			{
				CGrenade::ShootTimed2(pev, (pev->origin + pev->view_ofs), pev->angles, 1.5, m_iTeam, pHEGrenade->m_usCreateExplosion);
			}
			break;
		}
		case WEAPON_FLASHBANG:
		{
			if ((pev->button & IN_ATTACK) && m_rgAmmo[ ((CBasePlayerWeapon *)m_pActiveItem)->m_iPrimaryAmmoType ])
			{
				CGrenade::ShootTimed(pev, (pev->origin + pev->view_ofs), pev->angles, 1.5);
			}
			break;
		}
		case WEAPON_SMOKEGRENADE:
		{
			CSmokeGrenade *pSmoke = (CSmokeGrenade *)m_pActiveItem;
			if ((pev->button & IN_ATTACK) && m_rgAmmo[ pSmoke->m_iPrimaryAmmoType ])
			{
				CGrenade::ShootSmokeGrenade(pev, (pev->origin + pev->view_ofs), pev->angles, 1.5, pSmoke->m_usCreateSmoke);
			}
			break;
		}
		default:
			break;
		}
	}

	pev->modelindex = m_modelIndexPlayer;
	pev->deadflag = DEAD_DYING;
	pev->movetype = MOVETYPE_TOSS;
	pev->takedamage = DAMAGE_NO;

	pev->gamestate = 1;
	m_bShieldDrawn = false;

	pev->flags &= ~FL_ONGROUND;
	
	if (fadetoblack.value == 0.0)
	{
		pev->iuser1 = OBS_CHASE_FREE;
		pev->iuser2 = ENTINDEX(edict());
		pev->iuser3 = ENTINDEX(ENT(pevAttacker));

		m_hObserverTarget = UTIL_PlayerByIndex(pev->iuser3);

		MESSAGE_BEGIN(MSG_ONE, gmsgADStop, NULL, pev);
		MESSAGE_END();
	}
	else
		UTIL_ScreenFade(this, Vector(0, 0, 0), 3, 3, 255, (FFADE_OUT | FFADE_STAYOUT));

	SetScoreboardAttributes();

	if (m_iThrowDirection)
	{
		switch (m_iThrowDirection)
		{
		case THROW_FORWARD:
		{
			UTIL_MakeVectors(pev->angles);

			pev->velocity = gpGlobals->v_forward * RANDOM_FLOAT(100, 200);
			pev->velocity.z = RANDOM_FLOAT(50, 100);

			break;
		}
		case THROW_BACKWARD:
		{
			UTIL_MakeVectors(pev->angles);

			pev->velocity = gpGlobals->v_forward * RANDOM_FLOAT(-100, -200);
			pev->velocity.z = RANDOM_FLOAT(50, 100);

			break;
		}
		case THROW_HITVEL:
		{
			if (FClassnameIs(pevAttacker, "player"))
			{
				UTIL_MakeVectors(pevAttacker->angles);

				pev->velocity = gpGlobals->v_forward * RANDOM_FLOAT(200, 300);
				pev->velocity.z = RANDOM_FLOAT(200, 300);
			}

			break;
		}
		case THROW_BOMB:
		{
			pev->velocity = m_vBlastVector * (1 / m_vBlastVector.Length()) * (2300 - m_vBlastVector.Length()) * 0.25;
			pev->velocity.z = (2300 - m_vBlastVector.Length()) / 2.75;

			break;
		}
		case THROW_GRENADE:
		{
			pev->velocity = m_vBlastVector * (1 / m_vBlastVector.Length()) * (500 - m_vBlastVector.Length());
			pev->velocity.z = (350 - m_vBlastVector.Length()) * 1.5;

			break;
		}
		case THROW_HITVEL_MINUS_AIRVEL:
		{
			if (FClassnameIs(pevAttacker, "player"))
			{
				UTIL_MakeVectors(pevAttacker->angles);
				pev->velocity = gpGlobals->v_forward * RANDOM_FLOAT(200, 300);
			}

			break;
		}
		default:
			break;
		}

		pev->angles.y = UTIL_VecToAngles(-pev->velocity).y;
		pev->v_angle.y = pev->angles.y;

		m_iThrowDirection = THROW_NONE;
	}

	SetSuitUpdate(NULL, FALSE, 0);
	m_iClientHealth = 0;

	MESSAGE_BEGIN(MSG_ONE, gmsgHealth, NULL, pev);
		WRITE_BYTE(m_iClientHealth);
	MESSAGE_END();

	MESSAGE_BEGIN(MSG_ONE, gmsgCurWeapon, NULL, pev);
		WRITE_BYTE(0);
		WRITE_BYTE(0xFF);
		WRITE_BYTE(0xFF);
	MESSAGE_END();

	SendFOV(0);

	g_pGameRules->CheckWinConditions();
	m_bNotKilled = false;

	if (m_bHasC4)
	{
		DropPlayerItem("weapon_c4");
		SetProgressBarTime(0);
	}
	else if (m_bHasDefuser)
	{
		m_bHasDefuser = false;
		pev->body = 0;

		GiveNamedItem("item_thighpack");

		MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, pev);
			WRITE_BYTE(STATUSICON_HIDE);
			WRITE_STRING("defuser");
		MESSAGE_END();

		SendItemStatus(this);
	}

	if (m_bIsDefusing)
	{
		SetProgressBarTime(0);
	}

	m_bIsDefusing = false;

	BuyZoneIcon_Clear(this);

	SetThink(&CBasePlayer::PlayerDeathThink);
	pev->nextthink = gpGlobals->time + 0.1;
	pev->solid = SOLID_NOT;

	if (m_bPunishedForTK)
	{
		m_bPunishedForTK = false;
		HintMessage("#Hint_cannot_play_because_tk", TRUE, TRUE);
	}

	if ((pev->health < -9000 && iGib != GIB_NEVER) || iGib == GIB_ALWAYS)
	{
		pev->solid = SOLID_NOT;
		GibMonster();
		pev->effects |= EF_NODRAW;

		g_pGameRules->CheckWinConditions();

		return;
	}

	DeathSound();

	pev->angles.x = 0;
	pev->angles.z = 0;

	if (!(m_flDisplayHistory & DHF_SPEC_DUCK))
	{
		HintMessage("#Spec_Duck", TRUE, TRUE);
		m_flDisplayHistory |= DHF_SPEC_DUCK;
	}
}

/* <154478> ../cstrike/dlls/player.cpp:2625 */
BOOL CBasePlayer::IsBombGuy(void)
{
	if (!g_pGameRules->IsMultiplayer())
		return FALSE;

	return m_bHasC4;
}

/* <1544a1> ../cstrike/dlls/player.cpp:2636 */
void CBasePlayer::SetAnimation(PLAYER_ANIM playerAnim)
{
	int animDesired;
	float speed;
	char szAnim[64];
	int hopSeq;
	int leapSeq;

	if (!pev->modelindex)
		return;

	if ((playerAnim == PLAYER_FLINCH || playerAnim == PLAYER_LARGE_FLINCH) && HasShield())
		return;

	if (playerAnim != PLAYER_FLINCH && playerAnim != PLAYER_LARGE_FLINCH && m_flFlinchTime > gpGlobals->time && pev->health > 0.0f)
		return;

	speed = pev->velocity.Length2D();

	if (pev->flags & FL_FROZEN)
	{
		speed = 0;
		playerAnim = PLAYER_IDLE;
	}

	hopSeq = LookupActivity(ACT_HOP);
	leapSeq = LookupActivity(ACT_LEAP);

	switch (playerAnim)
	{
		case PLAYER_JUMP:
		{
			if (m_Activity == ACT_SWIM || m_Activity == ACT_DIESIMPLE || m_Activity == ACT_HOVER)
				m_IdealActivity = m_Activity;
			else
			{
				m_IdealActivity = ACT_HOP;
				TheBots->OnEvent(EVENT_PLAYER_JUMPED, this);
			}
			break;
		}
		case PLAYER_SUPERJUMP:
		{
			if (m_Activity == ACT_SWIM || m_Activity == ACT_DIESIMPLE || m_Activity == ACT_HOVER)
				m_IdealActivity = m_Activity;
			else
				m_IdealActivity = ACT_LEAP;
			break;
		}
		case PLAYER_DIE:
		{
			m_IdealActivity = ACT_DIESIMPLE;
			DeathSound();
			break;
		}
		case PLAYER_ATTACK1:
		{
			if (m_Activity == ACT_SWIM || m_Activity == ACT_DIESIMPLE || m_Activity == ACT_HOVER)
				m_IdealActivity = m_Activity;
			else
			{
				m_IdealActivity = ACT_RANGE_ATTACK1;
				TheBots->OnEvent(EVENT_WEAPON_FIRED, this);
			}
			break;
		}
		case PLAYER_ATTACK2:
		{
			if (m_Activity == ACT_SWIM || m_Activity == ACT_DIESIMPLE || m_Activity == ACT_HOVER)
				m_IdealActivity = m_Activity;
			else
			{
				m_IdealActivity = ACT_RANGE_ATTACK2;
				TheBots->OnEvent(EVENT_WEAPON_FIRED, this);
			}
			break;
		}
		case PLAYER_RELOAD:
		{
			if (m_Activity == ACT_SWIM || m_Activity == ACT_DIESIMPLE || m_Activity == ACT_HOVER)
				m_IdealActivity = m_Activity;
			else
			{
				m_IdealActivity = ACT_RELOAD;
				TheBots->OnEvent(EVENT_WEAPON_RELOADED, this);
			}
			break;
		}
		case PLAYER_IDLE:
		case PLAYER_WALK:
		{
			if (pev->flags & FL_ONGROUND || (m_Activity != ACT_HOP && m_Activity != ACT_LEAP))
			{
				if (pev->waterlevel <= 1)
					m_IdealActivity = ACT_WALK;

				else if (speed == 0.0f)
					m_IdealActivity = ACT_HOVER;

				else
					m_IdealActivity = ACT_SWIM;
			}
			else
				m_IdealActivity = m_Activity;
			break;
		}
		case PLAYER_HOLDBOMB:
			m_IdealActivity = ACT_HOLDBOMB;
			break;
		case PLAYER_FLINCH:
			m_IdealActivity = ACT_FLINCH;
			break;
		case PLAYER_LARGE_FLINCH:
			m_IdealActivity = ACT_LARGE_FLINCH;
			break;
		default:
			break;
	}
	switch (m_IdealActivity)
	{
		case ACT_HOP:
		case ACT_LEAP:
		{
			if (m_Activity == m_IdealActivity)
				return;

			switch (m_Activity)
			{
			case ACT_RANGE_ATTACK1:	Q_strcpy(szAnim, "ref_shoot_"); break;
			case ACT_RANGE_ATTACK2:	Q_strcpy(szAnim, "ref_shoot2_"); break;
			case ACT_RELOAD:	Q_strcpy(szAnim, "ref_reload_"); break;
			default:		Q_strcpy(szAnim, "ref_aim_"); break;
			}

			Q_strcat(szAnim, m_szAnimExtention);
			animDesired = LookupSequence(szAnim);
			if (animDesired == -1)
				animDesired = 0;

			if (pev->sequence != animDesired || !m_fSequenceLoops)
				pev->frame = 0;

			if (!m_fSequenceLoops)
				pev->effects |= EF_NOINTERP;

			if (m_IdealActivity == ACT_LEAP)
				pev->gaitsequence = LookupActivity(ACT_LEAP);
			else
				pev->gaitsequence = LookupActivity(ACT_HOP);

			m_Activity = m_IdealActivity;
			break;
		}
		case ACT_RANGE_ATTACK1:
		{
			m_flLastFired = gpGlobals->time;

			if (pev->flags & FL_DUCKING)
				Q_strcpy(szAnim, "crouch_shoot_");
			else
				Q_strcpy(szAnim, "ref_shoot_");

			Q_strcat(szAnim, m_szAnimExtention);
			animDesired = LookupSequence(szAnim);
			if (animDesired == -1)
				animDesired = 0;

			pev->sequence = animDesired;
			pev->frame = 0;

			ResetSequenceInfo();
			m_Activity = m_IdealActivity;
			break;
		}
		case ACT_RANGE_ATTACK2:
		{
			m_flLastFired = gpGlobals->time;

			if (pev->flags & FL_DUCKING)
				Q_strcpy(szAnim, "crouch_shoot2_");
			else
				Q_strcpy(szAnim, "ref_shoot2_");

			Q_strcat(szAnim, m_szAnimExtention);
			animDesired = LookupSequence(szAnim);
			if (animDesired == -1)
				animDesired = 0;

			pev->sequence = animDesired;
			pev->frame = 0;

			ResetSequenceInfo();
			m_Activity = m_IdealActivity;
			break;
		}
		case ACT_RELOAD:
		{
			if (pev->flags & FL_DUCKING)
				Q_strcpy(szAnim, "crouch_reload_");
			else
				Q_strcpy(szAnim, "ref_reload_");

			Q_strcat(szAnim, m_szAnimExtention);
			animDesired = LookupSequence(szAnim);
			if (animDesired == -1)
				animDesired = 0;

			if (pev->sequence != animDesired || !m_fSequenceLoops)
				pev->frame = 0;

			if (!m_fSequenceLoops)
				pev->effects |= EF_NOINTERP;

			m_Activity = m_IdealActivity;
			break;
		}
		case ACT_HOLDBOMB:
		{
			if (pev->flags & FL_DUCKING)
				Q_strcpy(szAnim, "crouch_aim_");
			else
				Q_strcpy(szAnim, "ref_aim_");

			Q_strcat(szAnim, m_szAnimExtention);
			animDesired = LookupSequence(szAnim);
			if (animDesired == -1)
				animDesired = 0;

			m_Activity = m_IdealActivity;
			break;
		}
		case ACT_WALK:
		{
			if ((m_Activity != ACT_RANGE_ATTACK1 || m_fSequenceFinished)
				&& (m_Activity != ACT_RANGE_ATTACK2 || m_fSequenceFinished)
				&& (m_Activity != ACT_FLINCH || m_fSequenceFinished)
				&& (m_Activity != ACT_LARGE_FLINCH || m_fSequenceFinished)
				&& (m_Activity != ACT_RELOAD || m_fSequenceFinished))
			{
				if (speed <= 135.0f || m_flLastFired + 4.0 >= gpGlobals->time)
				{
					if (pev->flags & FL_DUCKING)
						Q_strcpy(szAnim, "crouch_aim_");
					else
						Q_strcpy(szAnim, "ref_aim_");

					Q_strcat(szAnim, m_szAnimExtention);
					animDesired = LookupSequence(szAnim);
					if (animDesired == -1)
						animDesired = 0;

					m_Activity = ACT_WALK;
				}
				else
				{
					Q_strcpy(szAnim, "run_");
					Q_strcat(szAnim, m_szAnimExtention);
					animDesired = LookupSequence(szAnim);
					if (animDesired == -1)
					{
						if (pev->flags & FL_DUCKING)
							Q_strcpy(szAnim, "crouch_aim_");
						else
							Q_strcpy(szAnim, "ref_aim_");

						Q_strcat(szAnim, m_szAnimExtention);
						animDesired = LookupSequence(szAnim);
						if (animDesired == -1)
							animDesired = 0;

						m_Activity = ACT_RUN;
						pev->gaitsequence = LookupActivity(ACT_RUN);
					}
					else
					{
						m_Activity = ACT_RUN;
						pev->gaitsequence = animDesired;
					}
					if (m_Activity == ACT_RUN)
					{
						//TODO: maybe away used variable 'speed'?
						//if (speed > 150.0f)
						if (pev->velocity.Length2D() > 150.0f)
							TheBots->OnEvent(EVENT_PLAYER_FOOTSTEP, this);
					}
				}
			}
			else
				animDesired = pev->sequence;

			if (speed > 135.0f)
				pev->gaitsequence = LookupActivity(ACT_RUN);
			else
				pev->gaitsequence = LookupActivity(ACT_WALK);
			break;
		}
		case ACT_FLINCH:
		case ACT_LARGE_FLINCH:
		{
			m_Activity = m_IdealActivity;

#ifndef REGAMEDLL_FIXES
			// TODO: why? this condition was checked!
			if ((playerAnim == PLAYER_FLINCH || playerAnim == PLAYER_LARGE_FLINCH) && HasShield())
				return;
#endif // REGAMEDLL_FIXES

			switch (m_LastHitGroup)
			{
				case HITGROUP_GENERIC:
				{
					if (RANDOM_LONG(0, 1))
						animDesired = LookupSequence("head_flinch");
					else
						animDesired = LookupSequence("gut_flinch");
					break;
				}
				case HITGROUP_HEAD:
				case HITGROUP_CHEST:
					animDesired = LookupSequence("head_flinch");
					break;
				case HITGROUP_SHIELD:
					animDesired = 0;
					break;
				default:
					animDesired = LookupSequence("gut_flinch");
					break;
			}

			if (animDesired == -1)
				animDesired = 0;

			break;
		}
		case ACT_DIESIMPLE:
		{
			if (m_Activity == m_IdealActivity)
				return;

			m_Activity = m_IdealActivity;
			m_flDeathThrowTime = 0;
			m_iThrowDirection = THROW_NONE;

			switch (m_LastHitGroup)
			{
				case HITGROUP_GENERIC:
				{
					switch (RANDOM_LONG(0, 8))
					{
					case 0:
						animDesired = LookupActivity(ACT_DIE_HEADSHOT);
						m_iThrowDirection = THROW_BACKWARD;
						break;
					case 1:
						animDesired = LookupActivity(ACT_DIE_GUTSHOT);
						break;
					case 2:
						animDesired = LookupActivity(ACT_DIE_BACKSHOT);
						m_iThrowDirection = THROW_HITVEL;
						break;
					case 3:
						animDesired = LookupActivity(ACT_DIESIMPLE);
						break;
					case 4:
						animDesired = LookupActivity(ACT_DIEBACKWARD);
						m_iThrowDirection = THROW_HITVEL;
						break;
					case 5:
						animDesired = LookupActivity(ACT_DIEFORWARD);
						m_iThrowDirection = THROW_FORWARD;
						break;
					case 6:
						animDesired = LookupActivity(ACT_DIE_CHESTSHOT);
						break;
					case 7:
						animDesired = LookupActivity(ACT_DIE_GUTSHOT);
						break;
					case 8:
						animDesired = LookupActivity(ACT_DIE_HEADSHOT);
						break;
					default:
						break;
					}
					break;
				}
				case HITGROUP_HEAD:
				{
					int random = RANDOM_LONG(0, 8);
					m_bHeadshotKilled = true;

					if (m_bHighDamage)
						++random;

					switch (random)
					{
					case 1:
					case 2:
						m_iThrowDirection = THROW_BACKWARD;
						break;
					case 3:
					case 4:
						m_iThrowDirection = THROW_FORWARD;
						break;
					case 5:
					case 6:
						m_iThrowDirection = THROW_HITVEL;
						break;
					default:
						m_iThrowDirection = THROW_NONE;
						break;
					}

					animDesired = LookupActivity(ACT_DIE_HEADSHOT);
					break;
				}
				case HITGROUP_CHEST:
					animDesired = LookupActivity(ACT_DIE_CHESTSHOT);
					break;
				case HITGROUP_STOMACH:
					animDesired = LookupActivity(ACT_DIE_GUTSHOT);
					break;
				case HITGROUP_LEFTARM:
					animDesired = LookupSequence("left");
					break;
				case HITGROUP_RIGHTARM:
				{
					m_iThrowDirection = RANDOM_LONG(0, 1) ? THROW_HITVEL : THROW_HITVEL_MINUS_AIRVEL;
					animDesired = LookupSequence("right");
					break;
				}
				default:
				{
					animDesired = LookupActivity(ACT_DIESIMPLE);
					break;
				}
			}
			if (pev->flags & FL_DUCKING)
			{
				animDesired = LookupSequence("crouch_die");
				m_iThrowDirection = THROW_BACKWARD;
			}
			else if (m_bKilledByBomb || m_bKilledByGrenade)
			{
				UTIL_MakeVectors(pev->angles);

				if (DotProduct(gpGlobals->v_forward, m_vBlastVector) > 0.0f)
					animDesired = LookupSequence("left");

				else
				{
					if (RANDOM_LONG(0, 1))
						animDesired = LookupSequence("crouch_die");
					else
						animDesired = LookupActivity(ACT_DIE_HEADSHOT);
				}

				if (m_bKilledByBomb)
					m_iThrowDirection = THROW_BOMB;

				else if (m_bKilledByGrenade)
					m_iThrowDirection = THROW_GRENADE;
			}

			if (animDesired == -1)
				animDesired = 0;

			if (pev->sequence != animDesired)
			{
				pev->gaitsequence = 0;
				pev->sequence = animDesired;
				pev->frame = 0.0f;
				ResetSequenceInfo();
			}
			return;
		}
		default:
		{
			if (m_Activity == m_IdealActivity)
				return;

			m_Activity = m_IdealActivity;
			animDesired = LookupActivity(m_IdealActivity);

			if (pev->sequence != animDesired)
			{
				pev->gaitsequence = 0;
				pev->sequence = animDesired;
				pev->frame = 0;

				ResetSequenceInfo();
			}
			return;
		}
	}

	if (pev->gaitsequence != hopSeq && pev->gaitsequence != leapSeq)
	{
		if (pev->flags & FL_DUCKING)
		{
			if (speed != 0.0f)
				pev->gaitsequence = LookupActivity(ACT_CROUCH);
			else
				pev->gaitsequence = LookupActivity(ACT_CROUCHIDLE);
		}
		else
		{
			if (speed > 135.0f)
			{
				if (m_flLastFired + 4.0f < gpGlobals->time)
				{
					if (m_Activity != ACT_FLINCH && m_Activity != ACT_LARGE_FLINCH)
					{
						Q_strcpy(szAnim, "run_");
						Q_strcat(szAnim, m_szAnimExtention);

						animDesired = LookupSequence(szAnim);
						if (animDesired == -1)
						{
							if (pev->flags & FL_DUCKING)
								Q_strcpy(szAnim, "crouch_aim_");
							else
								Q_strcpy(szAnim, "ref_aim_");

							Q_strcat(szAnim, m_szAnimExtention);
							animDesired = LookupSequence(szAnim);
						}
						else
							pev->gaitsequence = animDesired;

						m_Activity = ACT_RUN;
					}
				}
				pev->gaitsequence = LookupActivity(ACT_RUN);
			}
			else
			{
				if (speed > 0.0f)
					pev->gaitsequence = LookupActivity(ACT_WALK);
				else
					pev->gaitsequence = LookupActivity(ACT_IDLE);
			}
		}
	}
	if (pev->sequence != animDesired)
	{
		pev->sequence = animDesired;
		pev->frame = 0;

		ResetSequenceInfo();
	}
}

/* <1544f4> ../cstrike/dlls/player.cpp:3264 */
void CBasePlayer::WaterMove(void)
{
	int air;

	if (pev->movetype == MOVETYPE_NOCLIP || pev->movetype == MOVETYPE_NONE)
		return;

	if (pev->health < 0.0f)
		return;

	// waterlevel 0 - not in water
	// waterlevel 1 - feet in water
	// waterlevel 2 - waist in water
	// waterlevel 3 - head in water

	if (pev->waterlevel != 3)
	{
		// not underwater

		// play 'up for air' sound
		if (pev->air_finished < gpGlobals->time)
			EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/pl_wade1.wav", VOL_NORM, ATTN_NORM);

		else if (pev->air_finished < gpGlobals->time + 9)
			EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/pl_wade2.wav", VOL_NORM, ATTN_NORM);

		pev->air_finished = gpGlobals->time + AIRTIME;
		pev->dmg = 2;

		// if we took drowning damage, give it back slowly
		if (m_idrowndmg > m_idrownrestored)
		{
			// set drowning damage bit.  hack - dmg_drownrecover actually
			// makes the time based damage code 'give back' health over time.
			// make sure counter is cleared so we start count correctly.

			// NOTE: this actually causes the count to continue restarting
			// until all drowning damage is healed.
			m_rgbTimeBasedDamage[ itbd_DrownRecover ] = 0;
			m_bitsDamageType |= DMG_DROWNRECOVER;
			m_bitsDamageType &= ~DMG_DROWN;

		}
	}
	else
	{
		// fully under water
		// stop restoring damage while underwater
		m_rgbTimeBasedDamage[ itbd_DrownRecover ] = 0;
		m_bitsDamageType &= ~DMG_DROWNRECOVER;
		
		// drown!
		if (gpGlobals->time > pev->air_finished)
		{
			if (gpGlobals->time > pev->pain_finished)
			{
				// take drowning damage
				pev->dmg += 1;

				if (pev->dmg > 5)
					pev->dmg = 5;

				TakeDamage(VARS(eoNullEntity), VARS(eoNullEntity), pev->dmg, DMG_DROWN);
				pev->pain_finished = gpGlobals->time + 1;

				// track drowning damage, give it back when
				// player finally takes a breath
				m_idrowndmg += pev->dmg;
			}
		}
		else
			m_bitsDamageType &= ~(DMG_DROWNRECOVER | DMG_DROWN);
	}

	if (!pev->waterlevel)
	{
		if (pev->flags & FL_INWATER)
			pev->flags &= ~FL_INWATER;

		return;
	}

	// make bubbles
	air = (int)(pev->air_finished - gpGlobals->time);

	if (!RANDOM_LONG(0, 0x1f) && RANDOM_LONG(0, AIRTIME - 1) >= air)
	{
		switch (RANDOM_LONG(0, 3))
		{
		case 0: EMIT_SOUND(ENT(pev), CHAN_BODY, "player/pl_swim1.wav", 0.8, ATTN_NORM); break;
		case 1: EMIT_SOUND(ENT(pev), CHAN_BODY, "player/pl_swim2.wav", 0.8, ATTN_NORM); break;
		case 2: EMIT_SOUND(ENT(pev), CHAN_BODY, "player/pl_swim3.wav", 0.8, ATTN_NORM); break;
		case 3: EMIT_SOUND(ENT(pev), CHAN_BODY, "player/pl_swim4.wav", 0.8, ATTN_NORM); break;
		}
	}

	if (pev->watertype == CONTENT_LAVA)		// do damage
	{
		if (pev->dmgtime < gpGlobals->time)
			TakeDamage(VARS(eoNullEntity), VARS(eoNullEntity), pev->waterlevel * 10, DMG_BURN);
	}
	else if (pev->watertype == CONTENT_SLIME)	// do damage
	{
		pev->dmgtime = gpGlobals->time + 1;
		TakeDamage(VARS(eoNullEntity), VARS(eoNullEntity), pev->waterlevel * 4, DMG_ACID);
	}
	if (!(pev->flags & FL_INWATER))
	{
		pev->flags |= FL_INWATER;
		pev->dmgtime = 0;
	}
}

/* <15493f> ../cstrike/dlls/player.cpp:3380 */
BOOL CBasePlayer::IsOnLadder(void)
{
	return pev->movetype == MOVETYPE_FLY;
}

/* <160720> ../cstrike/dlls/player.cpp:3387 */
NOXREF void CBasePlayer::ThrowWeapon(char *pszItemName)
{
	for (int i = 0; i < MAX_WEAPON_SLOTS; i++)
	{
		CBasePlayerItem *pWeapon = m_rgpPlayerItems[i];

		while (pWeapon != NULL)
		{
			if (!Q_strcmp(pszItemName, STRING(pWeapon->pev->classname)))
			{
				DropPlayerItem(pszItemName);
				return;
			}

			pWeapon = pWeapon->m_pNext;
		}
	}
}

/* <154967> ../cstrike/dlls/player.cpp:3424 */
LINK_ENTITY_TO_CLASS(weapon_shield, CWShield);

/* <151962> ../cstrike/dlls/player.cpp:3426 */
void CWShield::__MAKE_VHOOK(Spawn)(void)
{
	pev->movetype = MOVETYPE_TOSS;
	pev->solid = SOLID_TRIGGER;

	UTIL_SetSize(pev, g_vecZero, g_vecZero);
	SET_MODEL(ENT(pev), "models/w_shield.mdl");
}

/* <152e95> ../cstrike/dlls/player.cpp:3436 */
void CWShield::__MAKE_VHOOK(Touch)(CBaseEntity *pOther)
{
	if (!pOther->IsPlayer())
		return;

	CBasePlayer *pPlayer = (CBasePlayer *)pOther;

	if (pPlayer->pev->deadflag != DEAD_NO)
		return;

	if (m_hEntToIgnoreTouchesFrom != NULL && pPlayer == (CBasePlayer *)((CBaseEntity *)m_hEntToIgnoreTouchesFrom))
	{
		if (m_flTimeToIgnoreTouches > gpGlobals->time)
			return;

		m_hEntToIgnoreTouchesFrom = NULL;
	}

	if (!pPlayer->m_bHasPrimary)
	{
		if (pPlayer->m_rgpPlayerItems[ PISTOL_SLOT ] != NULL && pPlayer->m_rgpPlayerItems[ PISTOL_SLOT ]->m_iId == WEAPON_ELITE)
			return;

		if (pPlayer->m_pActiveItem)
		{
			if (!pPlayer->m_pActiveItem->CanHolster())
				return;
		}

		if (!pPlayer->m_bIsVIP)
		{
			pPlayer->GiveShield();

			EMIT_SOUND(edict(), CHAN_ITEM, "items/gunpickup2.wav", VOL_NORM, ATTN_NORM);
			UTIL_Remove(this);

			pev->nextthink = gpGlobals->time + 0.1;
		}
	}
}

/* <154a43> ../cstrike/dlls/player.cpp:3480 */
void CBasePlayer::GiveShield(bool bDeploy)
{
	m_bOwnsShield = true;
	m_bHasPrimary = true;

	if (m_pActiveItem != NULL)
	{
		CBasePlayerWeapon *pWeapon = (CBasePlayerWeapon *)m_pActiveItem;

		if (bDeploy)
		{
			if (m_rgAmmo[ pWeapon->m_iPrimaryAmmoType ] > 0)
				pWeapon->Holster();

			if (!pWeapon->Deploy())
				pWeapon->RetireWeapon();
		}
	}

	pev->gamestate = 0;
}

/* <154a70> ../cstrike/dlls/player.cpp:3504 */
void CBasePlayer::RemoveShield(void)
{
	if (HasShield())
	{
		m_bOwnsShield = false;
		m_bHasPrimary = false;
		m_bShieldDrawn = false;
		pev->gamestate = 1;

		UpdateShieldCrosshair(true);
	}
}

/* <154ad5> ../cstrike/dlls/player.cpp:3521 */
void CBasePlayer::DropShield(bool bDeploy)
{
	if (!HasShield())
		return;

	if (m_pActiveItem && !m_pActiveItem->CanHolster())
		return;

	if (m_pActiveItem)
	{
		CBasePlayerWeapon *pWeapon = (CBasePlayerWeapon *)m_pActiveItem;

		if (pWeapon->m_iId == WEAPON_HEGRENADE || pWeapon->m_iId == WEAPON_FLASHBANG || pWeapon->m_iId == WEAPON_SMOKEGRENADE)
		{
			if (m_rgAmmo[ pWeapon->m_iPrimaryAmmoType ] <= 0)
				g_pGameRules->GetNextBestWeapon(this, pWeapon);
		}
	}

	if (m_pActiveItem)
	{
		CBasePlayerWeapon *pWeapon = (CBasePlayerWeapon *)m_pActiveItem;

		if (pWeapon->m_flStartThrow != 0)
			m_pActiveItem->Holster();
	}

	if (IsReloading())
	{
		CBasePlayerWeapon *pWeapon = (CBasePlayerWeapon *)m_pActiveItem;

		pWeapon->m_fInReload = FALSE;
		m_flNextAttack = 0;
	}

	if (IsProtectedByShield() && m_pActiveItem)
		((CBasePlayerWeapon *)m_pActiveItem)->SecondaryAttack();

	m_bShieldDrawn = false;

	RemoveShield();

	if (m_pActiveItem && bDeploy)
		m_pActiveItem->Deploy();

	UTIL_MakeVectors(pev->angles);

	CWShield *pShield = (CWShield *)CBaseEntity::Create("weapon_shield", pev->origin + gpGlobals->v_forward * 10, pev->angles, edict());

	pShield->pev->angles.x = 0;
	pShield->pev->angles.z = 0;

	pShield->pev->velocity = gpGlobals->v_forward * 400;

	pShield->SetThink(&CBaseEntity::SUB_Remove);
	pShield->pev->nextthink = gpGlobals->time + 300;

	pShield->SetCantBePickedUpByUser(this, 2.0);
}

/* <154b15> ../cstrike/dlls/player.cpp:3588 */
bool CBasePlayer::HasShield(void)
{
	return m_bOwnsShield;
}

/* <1615d2> ../cstrike/dlls/player.cpp:3593 */
NOXREF void CBasePlayer::ThrowPrimary(void)
{
	ThrowWeapon("weapon_m249");
	ThrowWeapon("weapon_g3sg1");
	ThrowWeapon("weapon_sg550");
	ThrowWeapon("weapon_awp");
	ThrowWeapon("weapon_mp5navy");
	ThrowWeapon("weapon_tmp");
	ThrowWeapon("weapon_p90");
	ThrowWeapon("weapon_ump45");
	ThrowWeapon("weapon_m4a1");
	ThrowWeapon("weapon_m3");
	ThrowWeapon("weapon_sg552");
	ThrowWeapon("weapon_scout");
	ThrowWeapon("weapon_galil");
	ThrowWeapon("weapon_famas");

	DropShield();
}

/* <154b6d> ../cstrike/dlls/player.cpp:3624 */
void CBasePlayer::AddAccount(int amount, bool bTrackChange)
{
	m_iAccount += amount;

	if (m_iAccount < 0)
		m_iAccount = 0;

	else if (m_iAccount > 16000)
		m_iAccount = 16000;

	MESSAGE_BEGIN(MSG_ONE, gmsgMoney, NULL, pev);
		WRITE_LONG(m_iAccount);
		WRITE_BYTE(bTrackChange);
	MESSAGE_END();
}

/* <154bf8> ../cstrike/dlls/player.cpp:3640 */
void CBasePlayer::ResetMenu(void)
{
	MESSAGE_BEGIN(MSG_ONE, gmsgShowMenu, NULL, pev);
		WRITE_SHORT(0);
		WRITE_CHAR(0);
		WRITE_BYTE(0);
		WRITE_STRING("");
	MESSAGE_END();

#ifdef REGAMEDLL_FIXES
	m_iMenu = Menu_OFF;
#endif // REGAMEDLL_FIXES

}

/* <154c50> ../cstrike/dlls/player.cpp:3651 */
void CBasePlayer::SyncRoundTimer(void)
{
	float tmRemaining;
	CHalfLifeMultiplay *mp = g_pGameRules;

	if (mp->IsMultiplayer())
		tmRemaining = mp->TimeRemaining();
	else
		tmRemaining = 0;

	if (tmRemaining < 0)
		tmRemaining = 0;

	MESSAGE_BEGIN(MSG_ONE, gmsgRoundTime, NULL, pev);
		WRITE_SHORT((int)tmRemaining);
	MESSAGE_END();

	if (!mp->IsMultiplayer())
		return;

	if (mp->IsFreezePeriod() && TheTutor != NULL && !IsObserver())
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgBlinkAcct, NULL, pev);
			WRITE_BYTE(MONEY_BLINK_AMOUNT);
		MESSAGE_END();
	}

	if (mp->IsCareer())
	{
		int remaining = 0;
		bool shouldCountDown = false;
		int fadeOutDelay = 0;

		if (tmRemaining != 0.0f)
		{
			remaining = TheCareerTasks->GetTaskTime() - (gpGlobals->time - mp->m_fRoundCount);
		}

		if (remaining < 0)
			remaining = 0;

		if (mp->IsFreezePeriod())
			remaining = -1;

		if (TheCareerTasks->GetFinishedTaskTime())
			remaining = -TheCareerTasks->GetFinishedTaskTime();

		if (!mp->IsFreezePeriod() && !TheCareerTasks->GetFinishedTaskTime())
		{
			shouldCountDown = true;
		}
		if (!mp->IsFreezePeriod())
		{
			if (TheCareerTasks->GetFinishedTaskTime() || (TheCareerTasks->GetTaskTime() <= TheCareerTasks->GetRoundElapsedTime()))
			{
				fadeOutDelay = 3;
			}
		}

		if (!TheCareerTasks->GetFinishedTaskTime() || TheCareerTasks->GetFinishedTaskRound() == mp->m_iTotalRoundsPlayed)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgTaskTime, NULL, pev);
				WRITE_SHORT(remaining);		// remaining of time, -1 the timer is disappears
				WRITE_BYTE(shouldCountDown);	// timer counts down
				WRITE_BYTE(fadeOutDelay); // fade in time, hide HUD timer after the expiration time
			MESSAGE_END();
		}
	}
}

/* <154db6> ../cstrike/dlls/player.cpp:3711 */
void CBasePlayer::RemoveLevelText(void)
{
	ResetMenu();
}

void ShowMenu2(CBasePlayer *pPlayer, int bitsValidSlots, int nDisplayTime, int fNeedMore, char *pszText)
{
	MESSAGE_BEGIN(MSG_ONE, gmsgShowMenu, NULL, pPlayer->pev);
		WRITE_SHORT(bitsValidSlots);
		WRITE_CHAR(nDisplayTime);
		WRITE_BYTE(fNeedMore);
		WRITE_STRING(pszText);
	MESSAGE_END();
}

/* <154e29> ../cstrike/dlls/player.cpp:3721 */
void WINAPI_HOOK CBasePlayer::MenuPrint(const char *msg)
{
	const char *msg_portion = msg;
	char sbuf[MAX_BUFFER_MENU_BRIEFING + 1];

	while (Q_strlen(msg_portion) >= MAX_BUFFER_MENU_BRIEFING)
	{
		Q_strncpy(sbuf, msg_portion, MAX_BUFFER_MENU_BRIEFING);
		sbuf[ MAX_BUFFER_MENU_BRIEFING ] = '\0';
		msg_portion += MAX_BUFFER_MENU_BRIEFING;

		MESSAGE_BEGIN(MSG_ONE, gmsgShowMenu, NULL, pev);
			WRITE_SHORT(0xFFFF);
			WRITE_CHAR(-1);
			WRITE_BYTE(1);	// multipart
			WRITE_STRING(sbuf);
		MESSAGE_END();
	}

	MESSAGE_BEGIN(MSG_ONE, gmsgShowMenu, NULL, pev);
		WRITE_SHORT(0xFFFF);
		WRITE_CHAR(-1);
		WRITE_BYTE(0);	// multipart
		WRITE_STRING(msg_portion);
	MESSAGE_END();
}

/* <154f3d> ../cstrike/dlls/player.cpp:3753 */
void CBasePlayer::MakeVIP(void)
{
	pev->body = 0;
	m_iModelName = MODEL_VIP;

	SET_CLIENT_KEY_VALUE(entindex(), GET_INFO_BUFFER(edict()), "model", "vip");
	UTIL_LogPrintf("\"%s<%i><%s><CT>\" triggered \"Became_VIP\"\n", STRING(pev->netname), GETPLAYERUSERID(edict()), GETPLAYERAUTHID(edict()));

	m_iTeam = CT;
	m_bIsVIP = true;
	m_bNotKilled = false;

	g_pGameRules->m_pVIP = this;
	g_pGameRules->m_iConsecutiveVIP = 1;
}

/* <154fe5> ../cstrike/dlls/player.cpp:3785 */
void CBasePlayer::JoiningThink(void)
{
	switch (m_iJoiningState)
	{
		case JOINED:
		{
			return;
		}
		case SHOWLTEXT:
		{
			ResetMenu();
			m_iJoiningState = SHOWTEAMSELECT;

			MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, pev);
				WRITE_BYTE(STATUSICON_HIDE);
				WRITE_STRING("defuser");
			MESSAGE_END();

			m_bHasDefuser = false;
			m_fLastMovement = gpGlobals->time;
			m_bMissionBriefing = false;

			SendItemStatus(this);
			break;
		}
		case READINGLTEXT:
		{
			if (m_afButtonPressed & (IN_ATTACK | IN_ATTACK2 | IN_JUMP))
			{
				m_afButtonPressed &= ~(IN_ATTACK | IN_ATTACK2 | IN_JUMP);

				RemoveLevelText();
				m_iJoiningState = SHOWTEAMSELECT;
			}

			break;
		}
		case GETINTOGAME:
		{
			CHalfLifeMultiplay *mp = g_pGameRules;

			m_bNotKilled = false;
			m_iIgnoreGlobalChat = IGNOREMSG_NONE;

			m_iTeamKills = 0;
			m_iFOV = DEFAULT_FOV;

			Q_memset(&m_rebuyStruct, 0, sizeof(m_rebuyStruct));

			m_bIsInRebuy = false;
			m_bJustConnected = false;
			m_fLastMovement = gpGlobals->time;

			ResetMaxSpeed();
			m_iJoiningState = JOINED;

			if (mp->m_bMapHasEscapeZone && m_iTeam == CT)
			{
				m_iAccount = 0;
				CheckStartMoney();
				AddAccount(startmoney.value);
			}

			if (mp->FPlayerCanRespawn(this))
			{
				Spawn();

				mp->CheckWinConditions();

				if (!mp->m_fTeamCount && mp->m_bMapHasBombTarget && !mp->IsThereABomber() && !mp->IsThereABomb())
				{
					mp->GiveC4();
				}
				if (m_iTeam == TERRORIST)
				{
					mp->m_iNumEscapers++;
				}
			}
			else
			{
				pev->deadflag = DEAD_RESPAWNABLE;

				if (pev->classname)
				{
					RemoveEntityHashValue(pev, STRING(pev->classname), CLASSNAME);
				}

				MAKE_STRING_CLASS("player", pev);
				AddEntityHashValue(pev, STRING(pev->classname), CLASSNAME);
				
				pev->flags &= (FL_PROXY | FL_FAKECLIENT);
				pev->flags |= (FL_SPECTATOR | FL_CLIENT);

				edict_t *pentSpawnSpot = mp->GetPlayerSpawnSpot(this);
				StartObserver(pev->origin, VARS(pentSpawnSpot)->angles);

				mp->CheckWinConditions();

				MESSAGE_BEGIN(MSG_ALL, gmsgTeamInfo);
					WRITE_BYTE(entindex());
					switch (m_iTeam)
					{
					case CT:
						WRITE_STRING("CT");
						break;
					case TERRORIST:
						WRITE_STRING("TERRORIST");
						break;
					case SPECTATOR:
						WRITE_STRING("SPECTATOR");
						break;
					default:
						WRITE_STRING("UNASSIGNED");
						break;
					}
				MESSAGE_END();

				MESSAGE_BEGIN(MSG_ALL, gmsgLocation);
					WRITE_BYTE(entindex());
					WRITE_STRING("");
				MESSAGE_END();

				MESSAGE_BEGIN(MSG_ALL, gmsgScoreInfo);
					WRITE_BYTE(ENTINDEX(edict()));
					WRITE_SHORT((int)pev->frags);
					WRITE_SHORT(m_iDeaths);
					WRITE_SHORT(0);
					WRITE_SHORT(m_iTeam);
				MESSAGE_END();
				
				if (!(m_flDisplayHistory & DHF_SPEC_DUCK))
				{
					HintMessage("#Spec_Duck", TRUE, TRUE);
					m_flDisplayHistory |= DHF_SPEC_DUCK;
				}
			}

			return;
		}
	}

	if (m_pIntroCamera && gpGlobals->time >= m_fIntroCamTime)
	{
		m_pIntroCamera = UTIL_FindEntityByClassname(m_pIntroCamera, "trigger_camera");

		if (!m_pIntroCamera)
		{
			m_pIntroCamera = UTIL_FindEntityByClassname(NULL, "trigger_camera");
		}

		CBaseEntity *Target = UTIL_FindEntityByTargetname(NULL, STRING(m_pIntroCamera->pev->target));

		if (Target)
		{
			Vector CamAngles = UTIL_VecToAngles((Target->pev->origin - m_pIntroCamera->pev->origin).Normalize());

			CamAngles.x = -CamAngles.x;
			UTIL_SetOrigin(pev, m_pIntroCamera->pev->origin);

			pev->angles = CamAngles;
			pev->v_angle = pev->angles;

			pev->velocity = g_vecZero;
			pev->punchangle = g_vecZero;

			pev->fixangle = 1;
			pev->view_ofs = g_vecZero;
			m_fIntroCamTime = gpGlobals->time + 6;
		}
		else
			m_pIntroCamera = NULL;
	}
}

/* <16076f> ../cstrike/dlls/player.cpp:3952 */
void CBasePlayer::Disappear(void)
{
	if (m_pTank != NULL)
	{
		m_pTank->Use(this, this, USE_OFF, 0);
		m_pTank = NULL;
	}

	CSound *pSound = CSoundEnt::SoundPointerForIndex(CSoundEnt::ClientSoundIndex(edict()));

	if (pSound)
	{
		pSound->Reset();
	}

	m_fSequenceFinished = TRUE;
	pev->modelindex = m_modelIndexPlayer;
	pev->view_ofs = Vector(0, 0, -8);
	pev->deadflag = DEAD_DYING;
	pev->solid = SOLID_NOT;
	pev->flags &= ~FL_ONGROUND;

	SetSuitUpdate(NULL, FALSE, 0);

	m_iClientHealth = 0;
	MESSAGE_BEGIN(MSG_ONE, gmsgHealth, NULL, pev);
		WRITE_BYTE(m_iClientHealth);
	MESSAGE_END();

	MESSAGE_BEGIN(MSG_ONE, gmsgCurWeapon, NULL, pev);
		WRITE_BYTE(0);
		WRITE_BYTE(0xFF);
		WRITE_BYTE(0xFF);
	MESSAGE_END();

	SendFOV(0);

	g_pGameRules->CheckWinConditions();
	m_bNotKilled = false;

	if (m_bHasC4)
	{
		DropPlayerItem("weapon_c4");
		SetProgressBarTime(0);
	}
	else if (m_bHasDefuser)
	{
		m_bHasDefuser = false;
		pev->body = 0;
		GiveNamedItem("item_thighpack");

		MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, pev);
			WRITE_BYTE(STATUSICON_HIDE);
			WRITE_STRING("defuser");
		MESSAGE_END();

		SendItemStatus(this);
		SetProgressBarTime(0);
	}

	BuyZoneIcon_Clear(this);

	SetThink(&CBasePlayer::PlayerDeathThink);
	pev->nextthink = gpGlobals->time + 0.1f;

	pev->angles.x = 0;
	pev->angles.z = 0;
}

/* <15f83d> ../cstrike/dlls/player.cpp:4039 */
void CBasePlayer::PlayerDeathThink(void)
{
	if (m_iJoiningState != JOINED)
		return;

	if (pev->flags & FL_ONGROUND)
	{
		float flForward = pev->velocity.Length() - 20;
		
		if (flForward <= 0)
			pev->velocity = g_vecZero;
		else
			pev->velocity = flForward * pev->velocity.Normalize();
	}

	if (HasWeapons())
	{
		// we drop the guns here because weapons that have an area effect and can kill their user
		// will sometimes crash coming back from CBasePlayer::Killed() if they kill their owner because the
		// player class sometimes is freed. It's safer to manipulate the weapons once we know
		// we aren't calling into any of their code anymore through the player pointer.
		PackDeadPlayerItems();
	}

	if (pev->modelindex && !m_fSequenceFinished && pev->deadflag == DEAD_DYING)
	{
		StudioFrameAdvance();
		return;
	}

	// once we're done animating our death and we're on the ground, we want to set movetype to None so our dead body won't do collisions and stuff anymore
	// this prevents a bug where the dead body would go to a player's head if he walked over it while the dead player was clicking their button to respawn
	if (pev->movetype != MOVETYPE_NONE && (pev->flags & FL_ONGROUND))
		pev->movetype = MOVETYPE_NONE;

	if (pev->deadflag == DEAD_DYING)
	{
		m_fDeadTime = gpGlobals->time;
		pev->deadflag = DEAD_DEAD;
	}

	StopAnimation();
	pev->effects |= EF_NOINTERP;

	BOOL fAnyButtonDown = (pev->button & ~IN_SCORE);

	// if the player has been dead for one second longer than allowed by forcerespawn, 
	// forcerespawn isn't on. Send the player off to an intermission camera until they 
	// choose to respawn.
	if (g_pGameRules->IsMultiplayer())
	{
		if (gpGlobals->time > m_fDeadTime + 3.0 && !(m_afPhysicsFlags & PFLAG_OBSERVER))
		{
			SpawnClientSideCorpse();
			StartDeathCam(); // go to dead camera.
		}
	}

	// wait for all buttons released
	if (pev->deadflag == DEAD_DEAD && m_iTeam != UNASSIGNED && m_iTeam != SPECTATOR)
	{
		if (fAnyButtonDown)
			return;

		if (g_pGameRules->FPlayerCanRespawn(this))
		{
			pev->deadflag = DEAD_RESPAWNABLE;

			if (g_pGameRules->IsMultiplayer())
				g_pGameRules->CheckWinConditions();
		}

		pev->nextthink = gpGlobals->time + 0.1;
	}
	else if (pev->deadflag == DEAD_RESPAWNABLE)
	{
		respawn(pev, FALSE);
		pev->button = 0;
		pev->nextthink = -1;
	}
}

/* <153042> ../cstrike/dlls/player.cpp:4134 */
void CBasePlayer::__MAKE_VHOOK(RoundRespawn)(void)
{
	m_canSwitchObserverModes = true;

	if (m_bJustKilledTeammate && CVAR_GET_FLOAT("mp_tkpunish"))
	{
		m_bJustKilledTeammate = false;
#ifndef REGAMEDLL_FIXES
		// TODO: wtf?
		CLIENT_COMMAND(edict(), "kill\n");
#else
		if (pev->health > 0.0f)
		{
			ClientKill(ENT(pev));
		}
#endif // REGAMEDLL_FIXES
		m_bPunishedForTK = true;
	}
	if (m_iMenu != Menu_ChooseAppearance)
	{
		respawn(pev);

		pev->button = 0;
		pev->nextthink = -1;
	}

	if (m_pActiveItem)
	{
		if (m_pActiveItem->iItemSlot() == GRENADE_SLOT)
		{
			SwitchWeapon(m_pActiveItem);
		}
	}

	m_lastLocation[0] = '\0';
}

/* <155577> ../cstrike/dlls/player.cpp:4172 */
void CBasePlayer::StartDeathCam(void)
{
	if (pev->view_ofs == g_vecZero)
	{
		// don't accept subsequent attempts to StartDeathCam()
		return;
	}

	StartObserver(pev->origin, pev->angles);

	if (TheBots)
	{
		TheBots->OnEvent(EVENT_DEATH_CAMERA_START, this);
	}
}

/* <155616> ../cstrike/dlls/player.cpp:4190 */
void CBasePlayer::StartObserver(Vector vecPosition, Vector vecViewAngle)
{	
	// clear any clientside entities attached to this player
	MESSAGE_BEGIN(MSG_PAS, SVC_TEMPENTITY, pev->origin);
		WRITE_BYTE(TE_KILLPLAYERATTACHMENTS);
		WRITE_BYTE(entindex());
	MESSAGE_END();

	// Holster weapon immediately, to allow it to cleanup
	if (m_pActiveItem)
		m_pActiveItem->Holster();

	if (m_pTank)
	{
		m_pTank->Use(this, this);
		m_pTank = NULL;
	}

	// clear out the suit message cache so we don't keep chattering
	SetSuitUpdate();

	// Tell Ammo Hud that the player is dead
	MESSAGE_BEGIN(MSG_ONE, gmsgCurWeapon, NULL, pev);
		WRITE_BYTE(0);
		WRITE_BYTE(0xFF);
		WRITE_BYTE(0xFF);
	MESSAGE_END();

	// reset FOV
	SendFOV(0);

	// Setup flags
	m_iHideHUD = (HIDEHUD_WEAPONS | HIDEHUD_HEALTH);
	m_afPhysicsFlags |= PFLAG_OBSERVER;

	pev->effects = EF_NODRAW;
	pev->view_ofs = g_vecZero;

	pev->angles = pev->v_angle = vecViewAngle;

	pev->fixangle = 1;
	pev->solid = SOLID_NOT;

	pev->takedamage = DAMAGE_NO;
	pev->movetype = MOVETYPE_NONE;

	// Move them to the new position
	UTIL_SetOrigin(pev, vecPosition);

	m_afPhysicsFlags &= ~PFLAG_DUCKING;
	pev->flags &= ~FL_DUCKING;
	pev->health = 1;

	m_iObserverC4State = 0;
	m_bObserverHasDefuser = false;

	m_iObserverWeapon = 0;
	m_flNextObserverInput = 0;

	pev->iuser1 = OBS_NONE;

	static int iFirstTime = 1;
	CHalfLifeMultiplay *mp = g_pGameRules;

	if (iFirstTime && mp && mp->IsCareer() && !IsBot())
	{
		Observer_SetMode(OBS_CHASE_LOCKED);
		CLIENT_COMMAND(edict(), "spec_autodirector_internal 1\n");
		iFirstTime = 0;
	}
	else
		Observer_SetMode(m_iObserverLastMode);

	ResetMaxSpeed();

	// Tell all clients this player is now a spectator
	MESSAGE_BEGIN(MSG_ALL, gmsgSpectator);
		WRITE_BYTE(entindex());
		WRITE_BYTE(1);
	MESSAGE_END();
}

/* <14d785> ../cstrike/dlls/player.cpp:4272 */
bool CanSeeUseable(CBasePlayer *me, CBaseEntity *entity)
{
	TraceResult result;
	Vector eye = me->pev->origin + me->pev->view_ofs;

	if (FClassnameIs(entity->pev, "hostage_entity"))
	{
		Vector chest	= entity->pev->origin + Vector(0, 0, 36);
		Vector head	= entity->pev->origin + Vector(0, 0, 72 * 0.9);
		Vector knees	= entity->pev->origin + Vector(0, 0, 18);

		UTIL_TraceLine(eye, chest, ignore_monsters, ignore_glass, me->edict(), &result);
		if (result.flFraction < 1.0f)
		{
			UTIL_TraceLine(eye, head, ignore_monsters, ignore_glass, entity->edict(), &result);
			if (result.flFraction < 1.0f)
			{
				UTIL_TraceLine(eye, knees, ignore_monsters, ignore_glass, entity->edict(), &result);
				if (result.flFraction < 1.0f)
				{
					return false;
				}
			}
		}
	}

	return true;
}

/* <155815> ../cstrike/dlls/player.cpp:4307 */
void CBasePlayer::PlayerUse(void)
{
	// Was use pressed or released?
	if (!((pev->button | m_afButtonPressed | m_afButtonReleased) & IN_USE))
		return;

	// Hit Use on a train?
	if (m_afButtonPressed & IN_USE)
	{
		if (m_pTank != NULL)
		{
			// Stop controlling the tank
			// TODO: Send HUD Update
			m_pTank->Use(this, this, USE_OFF, 0);
			m_pTank = NULL;
			return;
		}

		if (m_afPhysicsFlags & PFLAG_ONTRAIN)
		{
			m_iTrain = (TRAIN_NEW | TRAIN_OFF);
			m_afPhysicsFlags &= ~PFLAG_ONTRAIN;

			CBaseEntity *pTrain = Instance(pev->groundentity);
			if (pTrain && pTrain->Classify() == CLASS_VEHICLE)
			{
				((CFuncVehicle *)pTrain)->m_pDriver = NULL;
			}
			return;
		}
		else
		{
			// Start controlling the train!
			CBaseEntity *pTrain = Instance(pev->groundentity);

			if (pTrain && !(pev->button & IN_JUMP) && (pev->flags & FL_ONGROUND) && (pTrain->ObjectCaps() & FCAP_DIRECTIONAL_USE) && pTrain->OnControls(pev))
			{
				m_afPhysicsFlags |= PFLAG_ONTRAIN;

				m_iTrain = TrainSpeed(pTrain->pev->speed, pTrain->pev->impulse);
				m_iTrain |= TRAIN_NEW;

				if (pTrain->Classify() == CLASS_VEHICLE)
				{
					EMIT_SOUND(ENT(pev), CHAN_ITEM, "plats/vehicle_ignition.wav", 0.8, ATTN_NORM);
					((CFuncVehicle *)pTrain)->m_pDriver = this;
				}
				else
					EMIT_SOUND(ENT(pev), CHAN_ITEM, "plats/train_use1.wav", 0.8, ATTN_NORM);

				return;
			}
		}
	}

	bool useNewHostages = !TheNavAreaList.empty();
	CBaseEntity *pObject = NULL;
	CBaseEntity *pClosest = NULL;
	Vector vecLOS;
	float flMaxDot = VIEW_FIELD_NARROW;
	float flDot;

	// so we know which way we are facing
	UTIL_MakeVectors(pev->v_angle);

	if (useNewHostages)
	{
		TraceResult result;
		const float useHostageRange = 1000.0f;

		Vector vecStart = pev->origin + pev->view_ofs;
		Vector vecEnd = vecStart + gpGlobals->v_forward * useHostageRange;

		UTIL_TraceLine(vecStart, vecEnd, dont_ignore_monsters, edict(), &result);

		if (result.flFraction < 1.0f)
		{
			CBaseEntity *hit = Instance(result.pHit);
			if (hit != NULL && FClassnameIs(hit->pev, "hostage_entity") && CanSeeUseable(this, hit))
				pClosest = hit;
		}

		if (!pClosest)
		{
			while ((pObject = UTIL_FindEntityInSphere(pObject, pev->origin, useHostageRange)) != NULL)
			{
				if (!FClassnameIs(pObject->pev, "hostage_entity"))
					continue;

				vecLOS = VecBModelOrigin(pObject->pev) - vecStart;
				vecLOS.NormalizeInPlace();

				flDot = DotProduct(vecLOS, gpGlobals->v_forward);

				if (flDot > flMaxDot && CanSeeUseable(this, pObject))
				{
					pClosest = pObject;
					flMaxDot = flDot;
				}
			}
		}
	}

	if (!pClosest)
	{
		while ((pObject = UTIL_FindEntityInSphere(pObject, pev->origin, PLAYER_SEARCH_RADIUS)) != NULL)
		{
			if (pObject->ObjectCaps() & (FCAP_IMPULSE_USE | FCAP_CONTINUOUS_USE | FCAP_ONOFF_USE))
			{
				// !!!PERFORMANCE- should this check be done on a per case basis AFTER we've determined that
				// this object is actually usable? This dot is being done for every object within PLAYER_SEARCH_RADIUS
				// when player hits the use key. How many objects can be in that area, anyway? (sjb)
				vecLOS = (VecBModelOrigin(pObject->pev) - (pev->origin + pev->view_ofs));
				vecLOS.NormalizeInPlace();

				flDot = DotProduct(vecLOS, gpGlobals->v_forward);

				// only if the item is in front of the user
				if (flDot > flMaxDot)
				{
					flMaxDot = flDot;
					pClosest = pObject;
				}
			}
		}
	}

	pObject = pClosest;

	// Found an object
	if (pObject != NULL)
	{
		if (!useNewHostages || CanSeeUseable(this, pObject))
		{
			int caps = pObject->ObjectCaps();

			if (m_afButtonPressed & IN_USE)
				EMIT_SOUND(ENT(pev), CHAN_ITEM, "common/wpn_select.wav", 0.4, ATTN_NORM);
	
			if (((pev->button & IN_USE) && (caps & FCAP_CONTINUOUS_USE))
				|| ((m_afButtonPressed & IN_USE) && (caps & (FCAP_IMPULSE_USE | FCAP_ONOFF_USE))))
			{
				if (caps & FCAP_CONTINUOUS_USE)
					m_afPhysicsFlags |= PFLAG_USING;

				pObject->Use(this, this, USE_SET, 1);
			}
			// UNDONE: Send different USE codes for ON/OFF.  Cache last ONOFF_USE object to send 'off' if you turn away
			// BUGBUG This is an "off" use
			else if ((m_afButtonReleased & IN_USE) && (pObject->ObjectCaps() & FCAP_ONOFF_USE))
			{
				pObject->Use(this, this, USE_SET, 0);
			}
		}
	}
	else
	{
		if (m_afButtonPressed & IN_USE)
			EMIT_SOUND(ENT(pev), CHAN_ITEM, "common/wpn_denyselect.wav", 0.4, ATTN_NORM);
	}
}

/* <155f41> ../cstrike/dlls/player.cpp:4486 */
void CBasePlayer::HostageUsed(void)
{
	if (m_flDisplayHistory & DHF_HOSTAGE_USED)
		return;

	if (m_iTeam == TERRORIST)
		HintMessage("#Hint_use_hostage_to_stop_him");

	else if (m_iTeam == CT)
		HintMessage("#Hint_lead_hostage_to_rescue_point");

	m_flDisplayHistory |= DHF_HOSTAGE_USED;
}

/* <153f69> ../cstrike/dlls/player.cpp:4507 */
void CBasePlayer::__MAKE_VHOOK(Jump)(void)
{
	if (pev->flags & FL_WATERJUMP)
		return;

	if (pev->waterlevel >= 2)
	{
		return;
	}

	// jump velocity is sqrt( height * gravity * 2)
	// If this isn't the first frame pressing the jump button, break out.
	if (!(m_afButtonPressed & IN_JUMP))
	{
		// don't pogo stick
		return;
	}

	if (!(pev->flags & FL_ONGROUND) || pev->groundentity == NULL)
		return;

	// many features in this function use v_forward, so makevectors now.
	UTIL_MakeVectors(pev->angles);
	SetAnimation(PLAYER_JUMP);

	if ((pev->flags & FL_DUCKING) || (m_afPhysicsFlags & PFLAG_DUCKING))
	{
		if (m_fLongJump && (pev->button & IN_DUCK) && (gpGlobals->time - m_flDuckTime < 1.0f) && pev->velocity.Length() > 50)
		{
			SetAnimation(PLAYER_SUPERJUMP);
		}
	}

	// If you're standing on a conveyor, add it's velocity to yours (for momentum)
	entvars_t *pevGround = VARS(pev->groundentity);
	if (pevGround)
	{
		if (pevGround->flags & FL_CONVEYOR)
		{
			pev->velocity = pev->velocity + pev->basevelocity;
		}

		if (FClassnameIs(pevGround, "func_tracktrain")
			|| FClassnameIs(pevGround, "func_train")
			|| FClassnameIs(pevGround, "func_vehicle"))
		{
			pev->velocity = pevGround->velocity + pev->velocity;
		}
	}
}

// This is a glorious hack to find free space when you've crouched into some solid space
// Our crouching collisions do not work correctly for some reason and this is easier
// than fixing the problem :(

/* <155fe2> ../cstrike/dlls/player.cpp:4565 */
NOXREF void FixPlayerCrouchStuck(edict_t *pPlayer)
{
	TraceResult trace;

	// Move up as many as 18 pixels if the player is stuck.
	for (int i = 0; i < 18; i++)
	{
		UTIL_TraceHull(pPlayer->v.origin, pPlayer->v.origin, dont_ignore_monsters, head_hull, pPlayer, &trace);

		if (trace.fStartSolid)
			pPlayer->v.origin.z ++;
		else
			break;
	}
}

/* <153ef5> ../cstrike/dlls/player.cpp:4580 */
void CBasePlayer::__MAKE_VHOOK(Duck)(void)
{
	if (pev->button & IN_DUCK)
		SetAnimation(PLAYER_WALK);
}

/* <150f8f> ../cstrike/dlls/player.cpp:4591 */
int CBasePlayer::__MAKE_VHOOK(Classify)(void)
{
	return CLASS_PLAYER;
}

/* <150fb7> ../cstrike/dlls/player.cpp:4597 */
void CBasePlayer::__MAKE_VHOOK(AddPoints)(int score, BOOL bAllowNegativeScore)
{
	if (score < 0 && !bAllowNegativeScore)
	{
		if (pev->frags < 0)
			return;

		if (-score > pev->frags)
			score = -pev->frags;
	}

	pev->frags += score;

	MESSAGE_BEGIN(MSG_BROADCAST, gmsgScoreInfo);
		WRITE_BYTE(ENTINDEX(edict()));
		WRITE_SHORT((int)pev->frags);
		WRITE_SHORT(m_iDeaths);
		WRITE_SHORT(0);
		WRITE_SHORT(m_iTeam);
	MESSAGE_END();
}

/* <15125b> ../cstrike/dlls/player.cpp:4626 */
void CBasePlayer::__MAKE_VHOOK(AddPointsToTeam)(int score, BOOL bAllowNegativeScore)
{
	int index = entindex();

	for (int i = 1; i <= gpGlobals->maxClients; i++)
	{
		CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex(i);

		if (pPlayer && i != index)
		{
			if (g_pGameRules->PlayerRelationship(this, pPlayer) == GR_TEAMMATE)
				pPlayer->AddPoints(score, bAllowNegativeScore);
		}
	}
}

/* <156047> ../cstrike/dlls/player.cpp:4645 */
bool CBasePlayer::CanPlayerBuy(bool display)
{
	CHalfLifeMultiplay *mp = g_pGameRules;
	int buyTime;

	if (!mp->IsMultiplayer())
	{
		return CHalfLifeTraining::PlayerCanBuy(this);
	}

	if (pev->deadflag != DEAD_NO || !(m_signals.GetState() & SIGNAL_BUY))
	{
		return false;
	}

	buyTime = (int)(CVAR_GET_FLOAT("mp_buytime") * 60);
	if (buyTime < 15)
	{
		buyTime = 15;
		CVAR_SET_FLOAT("mp_buytime", 1 / (60 / 15));
	}

	if (gpGlobals->time - mp->m_fRoundCount > buyTime)
	{
		if (display)
		{
			ClientPrint(pev, HUD_PRINTCENTER, "#Cant_buy", UTIL_dtos1(buyTime));
		}
		return false;
	}
	if (m_bIsVIP)
	{
		if (display)
		{
			ClientPrint(pev, HUD_PRINTCENTER, "#VIP_cant_buy");
		}
		return false;
	}
	if (mp->m_bCTCantBuy && m_iTeam == CT)
	{
		if (display)
		{
			ClientPrint(pev, HUD_PRINTCENTER, "#CT_cant_buy");
		}
		return false;
	}
	if (mp->m_bTCantBuy && m_iTeam == TERRORIST)
	{
		if (display)
		{
			ClientPrint(pev, HUD_PRINTCENTER, "#Terrorist_cant_buy");
		}
		return false;
	}

	return true;
}

/* <15f9ac> ../cstrike/dlls/player.cpp:4717 */
void CBasePlayer::__MAKE_VHOOK(PreThink)(void)
{
	int buttonsChanged = (pev->button ^ m_afButtonLast);

	if (pev->button != m_afButtonLast)
		m_fLastMovement = gpGlobals->time;

	m_afButtonPressed = (buttonsChanged & pev->button); // The changed ones still down are "pressed"
	m_afButtonReleased = (buttonsChanged & (~pev->button)); // The ones not down are "released"

	m_hintMessageQueue.Update(this);
	g_pGameRules->PlayerThink(this);

	if (g_fGameOver)
	{
		return;
	}

	if (m_iJoiningState != JOINED)
	{
		JoiningThink();
	}

	if (m_bMissionBriefing)
	{
		if (m_afButtonPressed & (IN_ATTACK | IN_ATTACK2))
		{
			m_afButtonPressed &= ~(IN_ATTACK | IN_ATTACK2);
			RemoveLevelText();
			m_bMissionBriefing = false;
		}
	}

	UTIL_MakeVectors(pev->v_angle);
	ItemPreFrame();
	WaterMove();

	if (pev->flags & FL_ONGROUND)
	{
		if (m_flVelocityModifier < 1.0f)
		{
			float_precision modvel = m_flVelocityModifier + 0.01;

			m_flVelocityModifier = modvel;
			pev->velocity = pev->velocity * modvel;
		}

		if (m_flVelocityModifier > 1.0f)
			m_flVelocityModifier = 1;
	}

	if (m_flIdleCheckTime <= (double)gpGlobals->time || m_flIdleCheckTime == 0.0f)
	{
		m_flIdleCheckTime = gpGlobals->time + 5.0;

		double v25 = gpGlobals->time - m_fLastMovement;

		if (v25 > g_pGameRules->m_fMaxIdlePeriod)
		{
			if (!IsBot() && CVAR_GET_FLOAT("mp_autokick") != 0.0f)
			{
				UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Game_idle_kick\" (auto)\n",
					STRING(pev->netname),
					GETPLAYERUSERID(edict()),
					GETPLAYERAUTHID(edict()),
					GetTeam(m_iTeam));

				UTIL_ClientPrintAll(HUD_PRINTCONSOLE, "#Game_idle_kick", STRING(pev->netname));
				SERVER_COMMAND(UTIL_VarArgs("kick \"%s\"\n", STRING(pev->netname)));
				m_fLastMovement = gpGlobals->time;
			}
		}
	}

	if (g_pGameRules && g_pGameRules->FAllowFlashlight())
		m_iHideHUD &= ~HIDEHUD_FLASHLIGHT;
	else
		m_iHideHUD |= HIDEHUD_FLASHLIGHT;

	// JOHN: checks if new client data (for HUD and view control) needs to be sent to the client
	UpdateClientData();
	CheckTimeBasedDamage();
	CheckSuitUpdate();

	// So the correct flags get sent to client asap.
	if (m_afPhysicsFlags & PFLAG_ONTRAIN)
		pev->flags |= FL_ONTRAIN;
	else
		pev->flags &= ~FL_ONTRAIN;

	// Observer Button Handling
	if (IsObserver() && (m_afPhysicsFlags & PFLAG_OBSERVER))
	{
		Observer_HandleButtons();
		Observer_CheckTarget();
		Observer_CheckProperties();
		return;
	}

	if (pev->deadflag >= DEAD_DYING && pev->deadflag != DEAD_RESPAWNABLE)
	{
		PlayerDeathThink();
		return;
	}

	CBaseEntity *pGroundEntity = Instance(pev->groundentity);

	if (pGroundEntity && pGroundEntity->Classify() == CLASS_VEHICLE)
		pev->iuser4 = 1;
	else
		pev->iuser4 = 0;

	// Train speed control
	if (m_afPhysicsFlags & PFLAG_ONTRAIN)
	{
		CBaseEntity *pTrain = Instance(pev->groundentity);
		float vel;

		if (!pTrain)
		{
			TraceResult trainTrace;
			// Maybe this is on the other side of a level transition
			UTIL_TraceLine(pev->origin, pev->origin + Vector(0, 0, -38), ignore_monsters, ENT(pev), &trainTrace);

			// HACKHACK - Just look for the func_tracktrain classname
			if (trainTrace.flFraction != 1.0f && trainTrace.pHit)
				pTrain = Instance(trainTrace.pHit);

			if (!pTrain || !(pTrain->ObjectCaps() & FCAP_DIRECTIONAL_USE) || !pTrain->OnControls(pev))
			{
				m_iTrain = (TRAIN_NEW | TRAIN_OFF);
				m_afPhysicsFlags &= ~PFLAG_ONTRAIN;

				((CFuncVehicle *)pTrain)->m_pDriver = NULL;
				return;
			}
		}
		else if (!(pev->flags & FL_ONGROUND) || (pTrain->pev->spawnflags & SF_TRACKTRAIN_NOCONTROL))
		{
			// Turn off the train if you jump, strafe, or the train controls go dead
			m_iTrain = (TRAIN_NEW | TRAIN_OFF);
			m_afPhysicsFlags &= ~PFLAG_ONTRAIN;

			((CFuncVehicle *)pTrain)->m_pDriver = NULL;
			return;
		}

		pev->velocity = g_vecZero;
		vel = 0;

		if (pTrain->Classify() == CLASS_VEHICLE)
		{
			if (pev->button & IN_FORWARD)
			{
				vel = 1;
				pTrain->Use(this, this, USE_SET, vel);
			}

			if (pev->button & IN_BACK)
			{
				vel = -1;
				pTrain->Use(this, this, USE_SET, vel);
			}

			if (pev->button & IN_MOVELEFT)
			{
				vel = 20;
				pTrain->Use(this, this, USE_SET, vel);
			}
			if (pev->button & IN_MOVERIGHT)
			{
				vel = 30;
				pTrain->Use(this, this, USE_SET, vel);
			}
		}
		else
		{
			if (m_afButtonPressed & IN_FORWARD)
			{
				vel = 1;
				pTrain->Use(this, this, USE_SET, vel);
			}
			else if (m_afButtonPressed & IN_BACK)
			{
				vel = -1;
				pTrain->Use(this, this, USE_SET, vel);
			}
		}

		if (vel)
		{
			m_iTrain = TrainSpeed(pTrain->pev->speed, pTrain->pev->impulse);
			m_iTrain |= (TRAIN_ACTIVE | TRAIN_NEW);
		}
	}
	else if (m_iTrain & TRAIN_ACTIVE)
	{
		// turn off train
		m_iTrain = TRAIN_NEW;
	}

	if (pev->button & IN_JUMP)
	{
		// If on a ladder, jump off the ladder
		// else Jump
		Jump();
	}

	// If trying to duck, already ducked, or in the process of ducking
	if ((pev->button & IN_DUCK) || (pev->flags & FL_DUCKING) || (m_afPhysicsFlags & PFLAG_DUCKING))
	{
		Duck();
	}

	if (!(pev->flags & FL_ONGROUND))
	{
		m_flFallVelocity = -pev->velocity.z;
	}

	// Clear out ladder pointer
	m_hEnemy = NULL;

	if (m_afPhysicsFlags & PFLAG_ONBARNACLE)
	{
		pev->velocity = g_vecZero;
	}

	if (!(m_flDisplayHistory & DHF_ROUND_STARTED) && CanPlayerBuy())
	{
		HintMessage("#Hint_press_buy_to_purchase");
		m_flDisplayHistory |= DHF_ROUND_STARTED;
	}

	UpdateLocation();
}

// If player is taking time based damage, continue doing damage to player -
// this simulates the effect of being poisoned, gassed, dosed with radiation etc -
// anything that continues to do damage even after the initial contact stops.
// Update all time based damage counters, and shut off any that are done.

// The m_bitsDamageType bit MUST be set if any damage is to be taken.
// This routine will detect the initial on value of the m_bitsDamageType
// and init the appropriate counter.  Only processes damage every second.

/* <156096> ../cstrike/dlls/player.cpp:5146 */
void CBasePlayer::CheckTimeBasedDamage(void)
{
	int i;
	BYTE bDuration = 0;
	//static float gtbdPrev = 0.0;
	
	if (!(m_bitsDamageType & DMG_TIMEBASED))
		return;

	if (abs((int64_t)(gpGlobals->time - m_tbdPrev)) < 2.0f)
		return;

	m_tbdPrev = gpGlobals->time;
	
	for (i = 0; i < CDMG_TIMEBASED; i++)
	{
		if (m_bitsDamageType & (DMG_PARALYZE << i))
		{
			switch (i)
			{
			case itbd_Paralyze:
				// UNDONE - flag movement as half-speed
				bDuration = PARALYZE_DURATION;
				break;
			case itbd_NerveGas:
				bDuration = NERVEGAS_DURATION;
				break;
			case itbd_Poison:
			{
				TakeDamage(pev, pev, POISON_DAMAGE, DMG_GENERIC);
				bDuration = POISON_DURATION;
				break;
			}
			case itbd_DrownRecover:
			{
				if (m_idrowndmg > m_idrownrestored)
				{
					int idif = _min(m_idrowndmg - m_idrownrestored, 10);
					TakeHealth(idif, DMG_GENERIC);
					m_idrownrestored += idif;
				}

				bDuration = 4;
				break;
			}
			case itbd_Radiation:
				bDuration = RADIATION_DURATION;
				break;
			case itbd_Acid:
				bDuration = ACID_DURATION;
				break;
			case itbd_SlowBurn:
				bDuration = SLOWBURN_DURATION;
				break;
			case itbd_SlowFreeze:
				bDuration = SLOWFREEZE_DURATION;
				break;
			default:
				bDuration = 0;
				break;
			}

			if (m_rgbTimeBasedDamage[i])
			{
				// use up an antitoxin on poison or nervegas after a few seconds of damage
				if ((i == itbd_NerveGas && m_rgbTimeBasedDamage[i] < NERVEGAS_DURATION) || (i == itbd_Poison && m_rgbTimeBasedDamage[i] < POISON_DURATION))
				{
					if (m_rgItems[ ITEM_ANTIDOTE ])
					{
						m_rgbTimeBasedDamage[i] = 0;
						m_rgItems[ ITEM_ANTIDOTE ]--;
						SetSuitUpdate("!HEV_HEAL4", FALSE, SUIT_REPEAT_OK);
					}
				}

				// decrement damage duration, detect when done.
				if (!m_rgbTimeBasedDamage[i] || --m_rgbTimeBasedDamage[i] == 0)
				{
					m_rgbTimeBasedDamage[i] = 0;
					// if we're done, clear damage bits
					m_bitsDamageType &= ~(DMG_PARALYZE << i);
				}
			}
			else
				// first time taking this damage type - init damage duration
				m_rgbTimeBasedDamage[i] = bDuration;
		}
	}
}

/* <156112> ../cstrike/dlls/player.cpp:5312 */
void CBasePlayer::UpdateGeigerCounter(void)
{
	if (gpGlobals->time < m_flgeigerDelay)
		return;

	m_flgeigerDelay = gpGlobals->time + 0.25;
	BYTE range = (byte)(m_flgeigerRange * 0.25);

	if (range != m_igeigerRangePrev)
	{
		m_igeigerRangePrev = range;

		MESSAGE_BEGIN(MSG_ONE, gmsgGeigerRange, NULL, pev);
			WRITE_BYTE(range);
		MESSAGE_END();
	}

	if (!RANDOM_LONG(0, 3))
		m_flgeigerRange = 1000.0;
}

/* <156189> ../cstrike/dlls/player.cpp:5352 */
void CBasePlayer::CheckSuitUpdate(void)
{
	int i;
	int isentence = 0;
	int isearch = m_iSuitPlayNext;

	// Ignore suit updates if no suit
	if (!(pev->weapons & (1 << WEAPON_SUIT)))
		return;

	// if in range of radiation source, ping geiger counter
	UpdateGeigerCounter();

	if (g_pGameRules->IsMultiplayer())
	{
		// don't bother updating HEV voice in multiplayer.
		return;
	}

	if (gpGlobals->time >= m_flSuitUpdate && m_flSuitUpdate > 0)
	{
		// play a sentence off of the end of the queue
		for (i = 0; i < CSUITPLAYLIST; i++)
		{
			if (isentence = m_rgSuitPlayList[ isearch ])
				break;

			if (++isearch == CSUITPLAYLIST)
				isearch = 0;
		}

		if (isentence)
		{
			m_rgSuitPlayList[ isearch ] = 0;

			if (isentence > 0)
			{
				// play sentence number

				char sentence[CBSENTENCENAME_MAX + 1];
				Q_strcpy(sentence, "!");
				Q_strcat(sentence, gszallsentencenames[isentence]);
				EMIT_SOUND_SUIT(ENT(pev), sentence);
			}
			else
			{
				// play sentence group
				EMIT_GROUPID_SUIT(ENT(pev), -isentence);
			}
			m_flSuitUpdate = gpGlobals->time + SUITUPDATETIME;
		}
		else
			// queue is empty, don't check
			m_flSuitUpdate = 0;
	}
}

/* <156201> ../cstrike/dlls/player.cpp:5414 */
void CBasePlayer::SetSuitUpdate(char *name, int fgroup, int iNoRepeatTime)
{
	;
}

/* <15623f> ../cstrike/dlls/player.cpp:5519 */
void CBasePlayer::CheckPowerups(entvars_t *pev)
{
	if (pev->health > 0.0f)
		pev->modelindex = m_modelIndexPlayer;
}

/* <15626b> ../cstrike/dlls/player.cpp:5531 */
void CBasePlayer::SetNewPlayerModel(const char *modelName)
{
	SET_MODEL(edict(), modelName);
	m_modelIndexPlayer = pev->modelindex;
}

// UpdatePlayerSound - updates the position of the player's
// reserved sound slot in the sound list.

/* <1562a4> ../cstrike/dlls/player.cpp:5543 */
void CBasePlayer::UpdatePlayerSound(void)
{
	int iBodyVolume;
	int iVolume;
	CSound *pSound;

	pSound = CSoundEnt::SoundPointerForIndex(CSoundEnt::ClientSoundIndex(edict()));

	if (!pSound)
	{
		ALERT(at_console, "Client lost reserved sound!\n");
		return;
	}

	pSound->m_iType = bits_SOUND_NONE;

	// now calculate the best target volume for the sound. If the player's weapon
	// is louder than his body/movement, use the weapon volume, else, use the body volume.

	if (pev->flags & FL_ONGROUND)
	{
		iBodyVolume = pev->velocity.Length();

		// clamp the noise that can be made by the body, in case a push trigger,
		// weapon recoil, or anything shoves the player abnormally fast.
		if (iBodyVolume> 512)
		{
			iBodyVolume = 512;
		}
	}
	else
	{
		iBodyVolume = 0;
	}

	if (pev->button & IN_JUMP)
	{
		iBodyVolume += 100;
	}

	// convert player move speed and actions into sound audible by monsters.
	if (m_iWeaponVolume > iBodyVolume)
	{
		m_iTargetVolume = m_iWeaponVolume;

		// OR in the bits for COMBAT sound if the weapon is being louder than the player.
		pSound->m_iType |= bits_SOUND_COMBAT;
	}
	else
	{
		m_iTargetVolume = iBodyVolume;
	}

	// decay weapon volume over time so bits_SOUND_COMBAT stays set for a while
	m_iWeaponVolume -= 250 * gpGlobals->frametime;

	// if target volume is greater than the player sound's current volume, we paste the new volume in
	// immediately. If target is less than the current volume, current volume is not set immediately to the
	// lower volume, rather works itself towards target volume over time. This gives monsters a much better chance
	// to hear a sound, especially if they don't listen every frame.
	iVolume = pSound->m_iVolume;

	if (m_iTargetVolume > iVolume)
	{
		iVolume = m_iTargetVolume;
	}
	else if (iVolume > m_iTargetVolume)
	{
		iVolume -= 250 * gpGlobals->frametime;

		if (iVolume < m_iTargetVolume)
			iVolume = 0;
	}

	if (m_fNoPlayerSound)
	{
		// debugging flag, lets players move around and shoot without monsters hearing.
		iVolume = 0;
	}

	if (gpGlobals->time > m_flStopExtraSoundTime)
	{
		// since the extra sound that a weapon emits only lasts for one client frame, we keep that sound around for a server frame or two
		// after actual emission to make sure it gets heard.
		m_iExtraSoundTypes = 0;
	}

	if (pSound)
	{
		pSound->m_vecOrigin = pev->origin;
		pSound->m_iVolume = iVolume;
		pSound->m_iType |= (bits_SOUND_PLAYER | m_iExtraSoundTypes);
	}

	// keep track of virtual muzzle flash
	m_iWeaponFlash -= 256 * gpGlobals->frametime;

	if (m_iWeaponFlash < 0)
		m_iWeaponFlash = 0;

	UTIL_MakeVectors(pev->angles);
	gpGlobals->v_forward.z = 0;
}

/* <15a182> ../cstrike/dlls/player.cpp:5667 */
void CBasePlayer::__MAKE_VHOOK(PostThink)(void)
{
	// intermission or finale
	if (g_fGameOver)
		goto pt_end;

	if (!IsAlive())
		goto pt_end;

	// Handle Tank controlling
	if (m_pTank != NULL)
	{
		// if they've moved too far from the gun,  or selected a weapon, unuse the gun
		if (m_pTank->OnControls(pev) && !pev->weaponmodel)
		{
			// try fire the gun
			m_pTank->Use(this, this, USE_SET, 2);
		}
		else
		{
			// they've moved off the platform
			m_pTank->Use(this, this, USE_OFF, 0);
			m_pTank = NULL;
		}		
	}

	// do weapon stuff
	ItemPostFrame();

	// check to see if player landed hard enough to make a sound
	// falling farther than half of the maximum safe distance, but not as far a max safe distance will
	// play a bootscrape sound, and no damage will be inflicted. Fallling a distance shorter than half
	// of maximum safe distance will make no sound. Falling farther than max safe distance will play a
	// fallpain sound, and damage will be inflicted based on how far the player fell
	if ((pev->flags & FL_ONGROUND) && pev->health > 0.0f && m_flFallVelocity >= PLAYER_FALL_PUNCH_THRESHHOLD)
	{
		if (pev->watertype != CONTENT_WATER)
		{
			// after this point, we start doing damage
			if (m_flFallVelocity > PLAYER_MAX_SAFE_FALL_SPEED)
			{
				float flFallDamage = g_pGameRules->FlPlayerFallDamage(this);

				//splat
				if (flFallDamage > pev->health)
				{
					// note: play on item channel because we play footstep landing on body channel
					EMIT_SOUND(ENT(pev), CHAN_ITEM, "common/bodysplat.wav", VOL_NORM, ATTN_NORM);
				}
				if (flFallDamage > 0)
				{
					m_LastHitGroup = HITGROUP_GENERIC;
					TakeDamage(VARS(eoNullEntity), VARS(eoNullEntity), flFallDamage, DMG_FALL);
					pev->punchangle.x = 0;
					TheBots->OnEvent(EVENT_PLAYER_LANDED_FROM_HEIGHT, this);
				}
			}
		}

		if (IsAlive())
		{
			SetAnimation(PLAYER_WALK);
		}
	}

	if (pev->flags & FL_ONGROUND)
	{
		if (m_flFallVelocity > 64.0f && !g_pGameRules->IsMultiplayer())
		{
			CSoundEnt::InsertSound(bits_SOUND_PLAYER, pev->origin, m_flFallVelocity, 0.2);
		}
		m_flFallVelocity = 0;
	}

	// select the proper animation for the player character
	if (IsAlive())
	{
		if (pev->velocity.x || pev->velocity.y)
		{
			if (((pev->velocity.x || pev->velocity.y) && (pev->flags & FL_ONGROUND)) || pev->waterlevel > 1)
				SetAnimation(PLAYER_WALK);
		}
		else if (pev->gaitsequence != ACT_FLY)
			SetAnimation(PLAYER_IDLE);
	}

	StudioFrameAdvance();
	CheckPowerups(pev);
	UpdatePlayerSound();

pt_end:
#ifdef CLIENT_WEAPONS
	// Decay timers on weapons
	// go through all of the weapons and make a list of the ones to pack
	for (int i = 0; i < MAX_ITEM_TYPES; i++)
	{
		if (m_rgpPlayerItems[i])
		{
			CBasePlayerItem *pPlayerItem = m_rgpPlayerItems[i];

			while (pPlayerItem != NULL)
			{
				CBasePlayerWeapon *gun = (CBasePlayerWeapon *)pPlayerItem->GetWeaponPtr();

				if (gun && gun->UseDecrement())
				{
					gun->m_flNextPrimaryAttack = _max(gun->m_flNextPrimaryAttack - gpGlobals->frametime, -1.0);
					gun->m_flNextSecondaryAttack = _max(gun->m_flNextSecondaryAttack - gpGlobals->frametime, -0.001);

					if (gun->m_flTimeWeaponIdle != 1000.0f)
					{
						gun->m_flTimeWeaponIdle = _max(gun->m_flTimeWeaponIdle - gpGlobals->frametime, -0.001);
					}
				}

				pPlayerItem = pPlayerItem->m_pNext;
			}
		}
	}

	m_flNextAttack -= gpGlobals->frametime;

	if (m_flNextAttack < -0.001)
		m_flNextAttack = -0.001;
#endif // CLIENT_WEAPONS

	// Track button info so we can detect 'pressed' and 'released' buttons next frame
	m_afButtonLast = pev->button;
	m_iGaitsequence = pev->gaitsequence;

	StudioProcessGait();
}

/* <14e39d> ../cstrike/dlls/player.cpp:5837 */
BOOL IsSpawnPointValid(CBaseEntity *pPlayer, CBaseEntity *pSpot)
{
	CBaseEntity *ent = NULL;

	if (!pSpot->IsTriggered(pPlayer))
		return FALSE;

	while ((ent = UTIL_FindEntityInSphere(ent, pSpot->pev->origin, 64)) != NULL)
	{
		if (ent->IsPlayer() && ent != pPlayer)
			return FALSE;
	}

	return TRUE;
}

/* <1563a8> ../cstrike/dlls/player.cpp:5879 */
NOXREF void InitZombieSpawns(void)
{
	CBaseEntity *spot = NULL;

	g_pSelectedZombieSpawn = NULL;
	zombieSpawnCount = 0;

	while ((spot = UTIL_FindEntityByClassname(spot, "info_player_start")) != NULL)
	{
		if (spot->pev->origin != Vector(0, 0, 0))
		{
			zombieSpawn[ zombieSpawnCount ].entity = spot;
			zombieSpawn[ zombieSpawnCount ].useableTimer.Invalidate();

			zombieSpawnCount++;
		}
	}
}

/* <14e440> ../cstrike/dlls/player.cpp:5906 */
NOXREF CBaseEntity *FindZombieSpawn(CBaseEntity *player, bool forceSpawn)
{
	return NULL;
}

/* <15645f> ../cstrike/dlls/player.cpp:6060 */
edict_t *EntSelectSpawnPoint(CBaseEntity *pPlayer)
{
	CBaseEntity *pSpot;
	edict_t *player = pPlayer->edict();

	// choose a info_player_deathmatch point
	if (g_pGameRules->IsCoOp())
	{
		pSpot = UTIL_FindEntityByClassname(g_pLastSpawn, "info_player_coop");

		if (!FNullEnt(pSpot))
			goto ReturnSpot;

		pSpot = UTIL_FindEntityByClassname(g_pLastSpawn, "info_player_start");

		if (!FNullEnt(pSpot))
			goto ReturnSpot;
	}
	else if (g_pGameRules->IsDeathmatch() && ((CBasePlayer *)pPlayer)->m_bIsVIP)
	{
		pSpot = UTIL_FindEntityByClassname(NULL, "info_vip_start");

		if (!FNullEnt(pSpot))
			goto ReturnSpot;

		goto CTSpawn;
	}
	else if (g_pGameRules->IsDeathmatch() && ((CBasePlayer *)pPlayer)->m_iTeam == CT)
	{
CTSpawn:
		pSpot = UTIL_FindEntityByClassname(g_pLastCTSpawn, "info_player_start");

		// skip over the null point
		if (FNullEnt(pSpot))
			pSpot = UTIL_FindEntityByClassname(pSpot, "info_player_start");

		CBaseEntity *pFirstSpot = pSpot;

		do
		{
			if (pSpot)
			{
				// check if pSpot is valid
				if (IsSpawnPointValid(pPlayer, pSpot))
				{
					if (pSpot->pev->origin == Vector(0, 0, 0))
					{
						pSpot = UTIL_FindEntityByClassname(pSpot, "info_player_start");
						continue;
					}

					// if so, go to pSpot
					goto ReturnSpot;
				}
			}

			// increment pSpot
			pSpot = UTIL_FindEntityByClassname(pSpot, "info_player_start");
		}
		// loop if we're not back to the start
		while (pSpot != pFirstSpot);

		// we haven't found a place to spawn yet,  so kill any guy at the first spawn point and spawn there
		if (!FNullEnt(pSpot))
		{
			CBaseEntity *ent = NULL;
			while ((ent = UTIL_FindEntityInSphere(ent, pSpot->pev->origin, 64)) != NULL)
			{
				// if ent is a client, kill em (unless they are ourselves)
				if (ent->IsPlayer() && ent->edict() != player)
					ent->TakeDamage(VARS(INDEXENT(0)), VARS(INDEXENT(0)), 200, DMG_GENERIC);
			}
			goto ReturnSpot;
		}
	}
	else if (g_pGameRules->IsDeathmatch() && ((CBasePlayer *)pPlayer)->m_iTeam == TERRORIST)
	{
		pSpot = UTIL_FindEntityByClassname(g_pLastTerroristSpawn, "info_player_deathmatch");

		// skip over the null point
		if (FNullEnt(pSpot))
			pSpot = UTIL_FindEntityByClassname(pSpot, "info_player_deathmatch");

		CBaseEntity *pFirstSpot = pSpot;

		do
		{
			if (pSpot)
			{
				// check if pSpot is valid
				if (IsSpawnPointValid(pPlayer, pSpot))
				{
					if (pSpot->pev->origin == Vector(0, 0, 0))
					{
						pSpot = UTIL_FindEntityByClassname(pSpot, "info_player_deathmatch");
						continue;
					}

					// if so, go to pSpot
					goto ReturnSpot;
				}
			}

			// increment pSpot
			pSpot = UTIL_FindEntityByClassname(pSpot, "info_player_deathmatch");
		}
		// loop if we're not back to the start
		while (pSpot != pFirstSpot);

		// we haven't found a place to spawn yet,  so kill any guy at the first spawn point and spawn there
		if (!FNullEnt(pSpot))
		{
			CBaseEntity *ent = NULL;
			while ((ent = UTIL_FindEntityInSphere(ent, pSpot->pev->origin, 64)) != NULL)
			{
				// if ent is a client, kill em (unless they are ourselves)
				if (ent->IsPlayer() && ent->edict() != player)
					ent->TakeDamage(VARS(INDEXENT(0)), VARS(INDEXENT(0)), 200, DMG_GENERIC);
			}
			goto ReturnSpot;
		}
	}

	// If startspot is set, (re)spawn there.
	if (FStringNull(gpGlobals->startspot) || !Q_strlen(STRING(gpGlobals->startspot)))
	{
		pSpot = UTIL_FindEntityByClassname(NULL, "info_player_deathmatch");

		if (!FNullEnt(pSpot))
			goto ReturnSpot;
	}
	else
	{
		pSpot = UTIL_FindEntityByTargetname(NULL, STRING(gpGlobals->startspot));

		if (!FNullEnt(pSpot))
			goto ReturnSpot;
	}

ReturnSpot:
	if (FNullEnt(pSpot))
	{
		ALERT(at_error, "PutClientInServer: no info_player_start on level");
		return INDEXENT(0);
	}

	if (((CBasePlayer *)pPlayer)->m_iTeam == TERRORIST)
		g_pLastTerroristSpawn = pSpot;
	else
		g_pLastCTSpawn = pSpot;

	return pSpot->edict();
}

/* <15331b> ../cstrike/dlls/player.cpp:6237 */
void SetScoreAttrib(CBasePlayer *dest, CBasePlayer *src)
{
	int state = 0;
	if (src->pev->deadflag != DEAD_NO)
		state |= SCORE_STATUS_DEAD;

	if (src->m_bHasC4)
		state |= SCORE_STATUS_BOMB;

	if (src->m_bIsVIP)
		state |= SCORE_STATUS_VIP;

	if (gmsgScoreAttrib)
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgScoreAttrib, NULL, dest->pev);
			WRITE_BYTE(src->entindex());
			WRITE_BYTE(state);
		MESSAGE_END();
	}
}

/* <15fdba> ../cstrike/dlls/player.cpp:6264 */
void CBasePlayer::__MAKE_VHOOK(Spawn)(void)
{
	int i;

	m_iGaitsequence = 0;

	m_flGaitframe = 0;
	m_flGaityaw = 0;
	m_flGaitMovement = 0;
	m_prevgaitorigin = Vector(0, 0, 0);
	m_progressStart = 0;
	m_progressEnd = 0;

	if (pev->classname)
	{
		RemoveEntityHashValue(pev, STRING(pev->classname), CLASSNAME);
	}

	MAKE_STRING_CLASS("player", pev);
	AddEntityHashValue(pev, STRING(pev->classname), CLASSNAME);

	pev->health = 100;

	if (!m_bNotKilled)
	{
		pev->armorvalue = 0;
		m_iKevlar = ARMOR_TYPE_EMPTY;
	}

	pev->maxspeed = 1000;
	pev->takedamage = DAMAGE_AIM;
	pev->solid = SOLID_SLIDEBOX;
	pev->movetype = MOVETYPE_WALK;
	pev->max_health = pev->health;
	
	pev->flags &= FL_PROXY;
	pev->flags |= FL_CLIENT;
	pev->air_finished = gpGlobals->time + 12;
	pev->dmg = 2;
	pev->effects = 0;
	pev->deadflag = DEAD_NO;
	pev->dmg_take = 0;
	pev->dmg_save = 0;

	m_bitsHUDDamage = -1;
	m_bitsDamageType = 0;
	m_afPhysicsFlags = 0;
	m_fLongJump = FALSE;
	m_iClientFOV = 0;
	m_pentCurBombTarget = NULL;

	if (m_bOwnsShield)
		pev->gamestate = 0;
	else
		pev->gamestate = 1;

	ResetStamina();
	pev->friction = 1;
	pev->gravity = 1;

	SET_PHYSICS_KEY_VALUE(edict(), "slj", "0");
	SET_PHYSICS_KEY_VALUE(edict(), "hl", "1");
	m_hintMessageQueue.Reset();

	m_flVelocityModifier = 1;
	m_iLastZoom = DEFAULT_FOV;
	m_flLastTalk = 0;
	m_flIdleCheckTime = 0;
	m_flRadioTime = 0;
	m_iRadioMessages = 60;
	m_bHasC4 = false;
	m_bKilledByBomb = false;
	m_bKilledByGrenade = false;
	m_flDisplayHistory &= ~DHM_ROUND_CLEAR;
	m_tmHandleSignals = 0;
	m_fCamSwitch = 0;
	m_iChaseTarget = 1;
	m_bEscaped = false;
	m_tmNextRadarUpdate = gpGlobals->time;
	m_vLastOrigin = Vector(0, 0, 0);
	m_iCurrentKickVote = 0;
	m_flNextVoteTime = 0;
	m_bJustKilledTeammate = false;

	SET_VIEW(ENT(pev), ENT(pev));

	m_hObserverTarget = NULL;
	pev->iuser1 = 0;
	pev->iuser2 = 0;
	pev->iuser3 = 0;

	m_flLastFired = -15;
	m_bHeadshotKilled = false;
	m_bReceivesNoMoneyNextRound = false;
	m_bShieldDrawn = false;

	m_blindUntilTime = 0;
	m_blindStartTime = 0;
	m_blindHoldTime = 0;
	m_blindFadeTime = 0;
	m_blindAlpha = 0;

	m_canSwitchObserverModes = true;
	m_lastLocation[0] = '\0';
	
	m_bitsDamageType &= ~(DMG_DROWN | DMG_DROWNRECOVER);
	m_rgbTimeBasedDamage[ itbd_DrownRecover ] = 0;
	m_idrowndmg = 0;
	m_idrownrestored = 0;

	if (m_iObserverC4State)
	{
		m_iObserverC4State = 0;

		MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, pev);
			WRITE_BYTE(STATUSICON_HIDE);
			WRITE_STRING("c4");
		MESSAGE_END();
	}

	if (m_bObserverHasDefuser)
	{
		m_bObserverHasDefuser = false;

		MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, pev);
			WRITE_BYTE(STATUSICON_HIDE);
			WRITE_STRING("defuser");
		MESSAGE_END();
	}

	MESSAGE_BEGIN(MSG_ONE, SVC_ROOMTYPE, NULL, pev);
		WRITE_SHORT((int)CVAR_GET_FLOAT("room_type"));
	MESSAGE_END();

	if (g_pGameRules->IsFreezePeriod())
		m_bCanShoot = false;
	else
		m_bCanShoot = true;

	m_iNumSpawns++;
	InitStatusBar();

	for (i = 0; i < MAX_RECENT_PATH; i++)
		m_vRecentPath[ i ] = Vector(0, 0, 0);

	if (m_pActiveItem != NULL && !pev->viewmodel)
	{
		switch (m_pActiveItem->m_iId)
		{
		case WEAPON_AWP:
			pev->viewmodel = MAKE_STRING("models/v_awp.mdl");
			break;
		case WEAPON_G3SG1:
			pev->viewmodel = MAKE_STRING("models/v_g3sg1.mdl");
			break;
		case WEAPON_SCOUT:
			pev->viewmodel = MAKE_STRING("models/v_scout.mdl");
			break;
		case WEAPON_SG550:
			pev->viewmodel = MAKE_STRING("models/v_sg550.mdl");
			break;
		}
	}

	m_iFOV = DEFAULT_FOV;
	m_flNextDecalTime = 0;
	m_flTimeStepSound = 0;
	m_iStepLeft = 0;
	m_flFieldOfView = 0.5;
	m_bloodColor = BLOOD_COLOR_RED;
	m_flNextAttack = 0;
	m_flgeigerDelay = gpGlobals->time + 2;

	StartSneaking();

	m_iFlashBattery = 99;
	m_flFlashLightTime = 1;

	if (m_bHasDefuser)
		pev->body = 1;
	else
		pev->body = 0;

	if (m_bMissionBriefing)
	{
		RemoveLevelText();
		m_bMissionBriefing = false;
	}

	m_flFallVelocity = 0;

	if (!g_skipCareerInitialSpawn)
	{
		g_pGameRules->GetPlayerSpawnSpot(this);
	}

	if (!pev->modelindex)
	{
		SET_MODEL(ENT(pev), "models/player.mdl");
		m_modelIndexPlayer = pev->modelindex;
	}

	pev->sequence = LookupActivity(ACT_IDLE);

	if (pev->flags & FL_DUCKING)
		UTIL_SetSize(pev, VEC_DUCK_HULL_MIN, VEC_DUCK_HULL_MAX);
	else
		UTIL_SetSize(pev, VEC_HULL_MIN, VEC_HULL_MAX);

	pev->view_ofs = VEC_VIEW;
	Precache();

	m_HackedGunPos = Vector(0, 32, 0);

	if (m_iPlayerSound == SOUNDLIST_EMPTY)
	{
		ALERT(at_console, "Couldn't alloc player sound slot!\n");
	}
	
	m_iHideHUD &= ~(HIDEHUD_WEAPONS | HIDEHUD_HEALTH | HIDEHUD_TIMER | HIDEHUD_MONEY);
	m_fNoPlayerSound = FALSE;
	m_pLastItem = NULL;
	m_fWeapon = FALSE;
	m_pClientActiveItem = NULL;
	m_iClientBattery = -1;
	m_fInitHUD = TRUE;

	if (!m_bNotKilled)
	{
		m_iClientHideHUD = -1;

		for (i = 0; i < MAX_AMMO_SLOTS; i++)
			m_rgAmmo[i] = 0;

		m_bHasPrimary = false;
		m_bHasNightVision = false;

		SendItemStatus(this);
	}
	else
	{
		for (i = 0; i < MAX_AMMO_SLOTS; i++)
			m_rgAmmoLast[i] = -1;
	}

	MESSAGE_BEGIN(MSG_ONE, gmsgNVGToggle, NULL, pev);
		WRITE_BYTE(0);
	MESSAGE_END();

	m_bNightVisionOn = false;

	for (i = 1; i <= gpGlobals->maxClients; i++)
	{
		CBasePlayer *pObserver = (CBasePlayer *)UTIL_PlayerByIndex(i);

		if (pObserver && pObserver->IsObservingPlayer(this))
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgNVGToggle, NULL, pObserver->pev);
				WRITE_BYTE(0);
			MESSAGE_END();

			pObserver->m_bNightVisionOn = false;
		}
	}

	m_lastx = 0;
	m_lasty = 0;

	g_pGameRules->PlayerSpawn(this);

	m_bNotKilled = true;
	m_bIsDefusing = false;

	SetProgressBarTime(0);
	ResetMaxSpeed();

	UTIL_SetOrigin(pev, pev->origin);

	if (m_bIsVIP)
	{
		m_iKevlar = ARMOR_TYPE_HELMET;
		pev->armorvalue = 200;
		HintMessage("#Hint_you_are_the_vip", TRUE, TRUE);
	}

	SetScoreboardAttributes();

	MESSAGE_BEGIN(MSG_ALL, gmsgTeamInfo);
	WRITE_BYTE(entindex());
	switch (m_iTeam)
	{
	case CT:
		WRITE_STRING("CT");
		break;
	case TERRORIST:
		WRITE_STRING("TERRORIST");
		break;
	case SPECTATOR:
		WRITE_STRING("SPECTATOR");
		break;
	default:
		WRITE_STRING("UNASSIGNED");
		break;
	}
	MESSAGE_END();

	UpdateLocation(true);

	MESSAGE_BEGIN(MSG_ALL, gmsgScoreInfo);
		WRITE_BYTE(ENTINDEX(edict()));
		WRITE_SHORT((int)pev->frags);
		WRITE_SHORT(m_iDeaths);
		WRITE_SHORT(0);
		WRITE_SHORT(m_iTeam);
	MESSAGE_END();

	if (m_bHasChangedName)
	{
		char *infobuffer = GET_INFO_BUFFER(edict());

		if (!FStrEq(m_szNewName, GET_KEY_VALUE(infobuffer, "name")))
		{
			SET_CLIENT_KEY_VALUE(entindex(), infobuffer, "name", m_szNewName);
		}

		m_bHasChangedName = false;
		m_szNewName[0] = '\0';
	}

	UTIL_ScreenFade(this, Vector(0, 0, 0), 0.001);
	SyncRoundTimer();

	if (TheBots)
	{
		TheBots->OnEvent(EVENT_PLAYER_SPAWNED, this);
	}

	m_allowAutoFollowTime = false;

	sv_aim = CVAR_GET_POINTER("sv_aim");

	for (i = 0; i < ARRAYSIZE(m_flLastCommandTime); i++)
		m_flLastCommandTime[i] = -1;
}

/* <153555> ../cstrike/dlls/player.cpp:6620 */
void CBasePlayer::__MAKE_VHOOK(Precache)(void)
{
	// in the event that the player JUST spawned, and the level node graph
	// was loaded, fix all of the node graph pointers before the game starts.

	// !!!BUGBUG - now that we have multiplayer, this needs to be moved!
	if (WorldGraph.m_fGraphPresent && !WorldGraph.m_fGraphPointersSet)
	{
		if (!WorldGraph.FSetGraphPointers())
		{
			ALERT(at_console, "**Graph pointers were not set!\n");
		}
		else
		{
			ALERT(at_console, "**Graph Pointers Set!\n");
		}
	}

	// SOUNDS / MODELS ARE PRECACHED in ClientPrecache() (game specific)
	// because they need to precache before any clients have connected

	// init geiger counter vars during spawn and each time
	// we cross a level transition

	m_flgeigerRange = 1000;
	m_igeigerRangePrev = 1000;
	m_bitsDamageType = 0;
	m_bitsHUDDamage = -1;
	m_iClientBattery = -1;
	m_iTrain = TRAIN_NEW;

	// Make sure any necessary user messages have been registered
	LinkUserMessages();

	// won't update for 1/2 a second
	m_iUpdateTime = 5;

	if (gInitHUD)
		m_fInitHUD = TRUE;
}

/* <151a77> ../cstrike/dlls/player.cpp:6671 */
int CBasePlayer::__MAKE_VHOOK(Save)(CSave &save)
{
	if (!CBaseMonster::Save(save))
		return 0;

	return save.WriteFields("PLAYER", this, IMPLEMENT_ARRAY_CLASS(CBasePlayer, m_playerSaveData), ARRAYSIZE(IMPLEMENT_ARRAY_CLASS(CBasePlayer, m_playerSaveData)));
}

/* <153355> ../cstrike/dlls/player.cpp:6685 */
void CBasePlayer::SetScoreboardAttributes(CBasePlayer *destination)
{
	if (destination != NULL)
	{
		SetScoreAttrib(destination, this);
		return;
	}

	for (int i = 1; i <= gpGlobals->maxClients; i++)
	{
		CBasePlayer *player = (CBasePlayer *)UTIL_PlayerByIndex(i);

		if (player && !FNullEnt(player->edict()))
			SetScoreboardAttributes(player);
	}
}

/* <156e88> ../cstrike/dlls/player.cpp:6712 */
NOXREF void CBasePlayer::RenewItems(void)
{
	;
}

/* <156b9b> ../cstrike/dlls/player.cpp:6718 */
int CBasePlayer::__MAKE_VHOOK(Restore)(CRestore &restore)
{
	if (!CBaseMonster::Restore(restore))
		return 0;
	
	int status = restore.ReadFields("PLAYER", this, IMPLEMENT_ARRAY_CLASS(CBasePlayer, m_playerSaveData), ARRAYSIZE(IMPLEMENT_ARRAY_CLASS(CBasePlayer, m_playerSaveData)));
	SAVERESTOREDATA *pSaveData = (SAVERESTOREDATA *)gpGlobals->pSaveData;

	if (!pSaveData->fUseLandmark)
	{
		ALERT(at_console, "No Landmark:%s\n", pSaveData->szLandmarkName);

		edict_t *pentSpawnSpot = EntSelectSpawnPoint(this);

		pev->origin = VARS(pentSpawnSpot)->origin + Vector(0, 0, 1);
		pev->angles = VARS(pentSpawnSpot)->angles;
	}

	pev->v_angle.z = 0;
	pev->angles = pev->v_angle;
	pev->fixangle = 1;

	m_bloodColor = BLOOD_COLOR_RED;
	m_modelIndexPlayer = pev->modelindex;
	
	if (pev->flags & FL_DUCKING)
		UTIL_SetSize(pev, VEC_DUCK_HULL_MIN, VEC_DUCK_HULL_MAX);
	else
		UTIL_SetSize(pev, VEC_HULL_MIN, VEC_HULL_MAX);
	
	m_flDisplayHistory &= ~DHM_CONNECT_CLEAR;
	SetScoreboardAttributes();

	return status;
}

/* <156eab> ../cstrike/dlls/player.cpp:6771 */
void CBasePlayer::Reset(void)
{
	pev->frags = 0;
	m_iDeaths = 0;
	m_iAccount = 0;

	MESSAGE_BEGIN(MSG_ONE, gmsgMoney, NULL, pev);
		WRITE_LONG(m_iAccount);
		WRITE_BYTE(0);
	MESSAGE_END();

	m_bNotKilled = false;

	RemoveShield();
	CheckStartMoney();
	AddAccount(startmoney.value);

	MESSAGE_BEGIN(MSG_ALL, gmsgScoreInfo);
		WRITE_BYTE(ENTINDEX(edict()));
		WRITE_SHORT(0);
		WRITE_SHORT(0);
		WRITE_SHORT(0);
		WRITE_SHORT(m_iTeam);
	MESSAGE_END();
}

/* <157066> ../cstrike/dlls/player.cpp:6794 */
NOXREF void CBasePlayer::SelectNextItem(int iItem)
{
	CBasePlayerItem *pItem = m_rgpPlayerItems[ iItem ];

	if (!pItem)
	{
		return;
	}

	if (pItem == m_pActiveItem)
	{
		pItem = m_pActiveItem->m_pNext;

		if (!pItem)
		{
			return;
		}

		CBasePlayerItem *pLast = pItem;

		while (pLast->m_pNext != NULL)
			pLast = pLast->m_pNext;

		pLast->m_pNext = m_pActiveItem;
		m_pActiveItem->m_pNext = NULL;
		m_rgpPlayerItems[ iItem ] = pItem;
	}

	ResetAutoaim();

	if (m_pActiveItem)
	{
		m_pActiveItem->Holster();
	}

	if (HasShield())
	{
		CBasePlayerWeapon *pWeapon = (CBasePlayerWeapon *)m_pActiveItem;
		pWeapon->m_iWeaponState &= ~WPNSTATE_SHIELD_DRAWN;
		m_bShieldDrawn = false;
	}

	m_pLastItem = m_pActiveItem;
	m_pActiveItem = pItem;

	if (m_pActiveItem)
	{
		UpdateShieldCrosshair(true);

		m_pActiveItem->Deploy();
		m_pActiveItem->UpdateItemInfo();

		ResetMaxSpeed();
	}
}

/* <15714a> ../cstrike/dlls/player.cpp:6851 */
void CBasePlayer::SelectItem(const char *pstr)
{
	if (!pstr)
	{
		return;
	}

	CBasePlayerItem *pItem = NULL;

	for (int i = 0; i < MAX_ITEM_TYPES; i++)
	{
		pItem = m_rgpPlayerItems[ i ];

		if (pItem != NULL)
		{
			while (pItem != NULL)
			{
				if (FClassnameIs(pItem->pev, pstr))
					break;

				pItem = pItem->m_pNext;
			}

			if (pItem)
			{
				break;
			}
		}
	}

	if (!pItem || pItem == m_pActiveItem)
	{
		return;
	}

	ResetAutoaim();

	// FIX, this needs to queue them up and delay
	if (m_pActiveItem)
	{
		m_pActiveItem->Holster();
	}

	m_pLastItem = m_pActiveItem;
	m_pActiveItem = pItem;

	if (m_pActiveItem)
	{
		CBasePlayerWeapon *pWeapon = (CBasePlayerWeapon *)m_pActiveItem;
		pWeapon->m_iWeaponState &= ~WPNSTATE_SHIELD_DRAWN;

		m_bShieldDrawn = false;
		UpdateShieldCrosshair(true);

		m_pActiveItem->Deploy();
		m_pActiveItem->UpdateItemInfo();

		ResetMaxSpeed();
	}
}

/* <157268> ../cstrike/dlls/player.cpp:6909 */
void CBasePlayer::SelectLastItem(void)
{
	if (m_pActiveItem && !m_pActiveItem->CanHolster())
		return;

	if (!m_pLastItem || m_pLastItem == m_pActiveItem)
	{
		for (int i = 1; i < MAX_ITEMS; i++)
		{
			CBasePlayerItem *pItem = m_rgpPlayerItems[i];
			if (pItem && pItem != m_pActiveItem)
			{
				m_pLastItem = pItem;
				break;
			}
		}
	}

	if (!m_pLastItem || m_pLastItem == m_pActiveItem)
		return;

	ResetAutoaim();

	if (m_pActiveItem)
		m_pActiveItem->Holster();

	if (HasShield())
	{
		CBasePlayerWeapon *pWeapon = (CBasePlayerWeapon *)m_pActiveItem;

		if (m_pActiveItem)
			pWeapon->m_iWeaponState &= ~WPNSTATE_SHIELD_DRAWN;

		m_bShieldDrawn = false;
	}

	CBasePlayerItem *pTemp = m_pActiveItem;

	m_pActiveItem = m_pLastItem;
	m_pLastItem = pTemp;

	m_pActiveItem->Deploy();
	m_pActiveItem->UpdateItemInfo();

	UpdateShieldCrosshair(true);

	ResetMaxSpeed();
}

// HasWeapons - do I have any weapons at all?

/* <15733a> ../cstrike/dlls/player.cpp:6967 */
BOOL CBasePlayer::HasWeapons(void)
{
	for (int i = 0; i < MAX_ITEM_TYPES; i++)
	{
		if (m_rgpPlayerItems[i])
			return TRUE;
	}
	return FALSE;
}

/* <157372> ../cstrike/dlls/player.cpp:6982 */
NOXREF void CBasePlayer::SelectPrevItem(int iItem)
{
	;
}

/* <15106c> ../cstrike/dlls/player.cpp:6987 */
const char *CBasePlayer::__MAKE_VHOOK(TeamID)(void)
{
	// Not fully connected yet
	if (pev == NULL)
		return "";

	// return their team name
	return m_szTeamName;
}

/* <1573aa> ../cstrike/dlls/player.cpp:7010 */
void CSprayCan::Spawn(entvars_t *pevOwner)
{
	pev->origin = pevOwner->origin + Vector(0, 0, 32);
	pev->angles = pevOwner->v_angle;
	pev->owner = ENT(pevOwner);
	pev->frame = 0;

	pev->nextthink = gpGlobals->time + 0.1;
	EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/sprayer.wav", VOL_NORM, ATTN_NORM);
}

/* <151815> ../cstrike/dlls/player.cpp:7021 */
void CSprayCan::__MAKE_VHOOK(Think)(void)
{
	TraceResult tr;
	int playernum;
	int nFrames;
	CBasePlayer *pPlayer;

	pPlayer = (CBasePlayer *)GET_PRIVATE(pev->owner);

	if (pPlayer)
		nFrames = pPlayer->GetCustomDecalFrames();
	else
		nFrames = -1;

	playernum = ENTINDEX(pev->owner);

	UTIL_MakeVectors(pev->angles);
	UTIL_TraceLine(pev->origin, pev->origin + gpGlobals->v_forward * 128, ignore_monsters, pev->owner, &tr);

	// No customization present.
	if (nFrames == -1)
	{
		UTIL_DecalTrace(&tr, DECAL_LAMBDA6);
		UTIL_Remove(this);
	}
	else
	{
		UTIL_PlayerDecalTrace(&tr, playernum, pev->frame, TRUE);

		// Just painted last custom frame.
		if (pev->frame++ >= (nFrames - 1))
			UTIL_Remove(this);
	}

	pev->nextthink = gpGlobals->time + 0.1;
}

/* <157481> ../cstrike/dlls/player.cpp:7064 */
void CBloodSplat::Spawn(entvars_t *pevOwner)
{
	pev->origin = pevOwner->origin + Vector(0, 0, 32);
	pev->angles = pevOwner->v_angle;
	pev->owner = ENT(pevOwner);

	SetThink(&CBloodSplat::Spray);
	pev->nextthink = gpGlobals->time + 0.1;
}

/* <151758> ../cstrike/dlls/player.cpp:7074 */
void CBloodSplat::Spray(void)
{
	TraceResult tr;
	if (g_Language != LANGUAGE_GERMAN)
	{
		UTIL_MakeVectors(pev->angles);
		UTIL_TraceLine(pev->origin, pev->origin + gpGlobals->v_forward * 128, ignore_monsters, pev->owner, &tr);
		UTIL_BloodDecalTrace(&tr, BLOOD_COLOR_RED);
	}

	SetThink(&CBloodSplat::SUB_Remove);
	pev->nextthink = gpGlobals->time + 0.1;
}

/* <1574d3> ../cstrike/dlls/player.cpp:7093 */
void CBasePlayer::GiveNamedItem(const char *pszName)
{
	string_t istr = MAKE_STRING(pszName);
	edict_t *pent = CREATE_NAMED_ENTITY(istr);
	
	if (FNullEnt(pent))
	{
		ALERT(at_console, "NULL Ent in GiveNamedItem!\n");
		return;
	}

	VARS(pent)->origin = pev->origin;
	pent->v.spawnflags |= SF_NORESPAWN;

	DispatchSpawn(pent);
	DispatchTouch(pent, ENT(pev));
}

/* <157568> ../cstrike/dlls/player.cpp:7114 */
CBaseEntity *FindEntityForward(CBaseEntity *pMe)
{
	TraceResult tr;

	UTIL_MakeVectors(pMe->pev->v_angle);
	UTIL_TraceLine(pMe->pev->origin + pMe->pev->view_ofs, pMe->pev->origin + pMe->pev->view_ofs + gpGlobals->v_forward * 8192, dont_ignore_monsters, pMe->edict(), &tr);

	if (tr.flFraction != 1.0 && !FNullEnt(tr.pHit))
	{
		CBaseEntity *pHit = CBaseEntity::Instance(tr.pHit);
		return pHit;
	}
	return NULL;
}

/* <15777b> ../cstrike/dlls/player.cpp:7129 */
BOOL CBasePlayer::FlashlightIsOn(void)
{
	return pev->effects & EF_DIMLIGHT;
}

/* <15779e> ../cstrike/dlls/player.cpp:7135 */
void CBasePlayer::FlashlightTurnOn(void)
{
	if (!g_pGameRules->FAllowFlashlight())
		return;

	if (pev->weapons & (1 << WEAPON_SUIT))
	{
		EMIT_SOUND(ENT(pev), CHAN_ITEM, "items/flashlight1.wav", VOL_NORM, ATTN_NORM);

		pev->effects |= EF_DIMLIGHT;

		MESSAGE_BEGIN(MSG_ONE, gmsgFlashlight, NULL, pev);
			WRITE_BYTE(1);
			WRITE_BYTE(m_iFlashBattery);
		MESSAGE_END();

		m_flFlashLightTime = gpGlobals->time + FLASH_DRAIN_TIME;
	}
}

/* <157816> ../cstrike/dlls/player.cpp:7157 */
void CBasePlayer::FlashlightTurnOff(void)
{
	EMIT_SOUND(ENT(pev), CHAN_ITEM, "items/flashlight1.wav", VOL_NORM, ATTN_NORM);

	pev->effects &= ~EF_DIMLIGHT;
	MESSAGE_BEGIN(MSG_ONE, gmsgFlashlight, NULL, pev);
		WRITE_BYTE(0);
		WRITE_BYTE(m_iFlashBattery);
	MESSAGE_END();

	m_flFlashLightTime = gpGlobals->time + FLASH_CHARGE_TIME;
}

/* <158ae7> ../cstrike/dlls/player.cpp:7179 */
void CBasePlayer::ForceClientDllUpdate(void)
{
	m_iClientHealth = -1;
	m_iClientBattery = -1;
	m_fWeapon = FALSE;
	m_fInitHUD = TRUE;
	m_iTrain |= TRAIN_NEW;

	UpdateClientData();
	HandleSignals();
}

/* <157f8d> ../cstrike/dlls/player.cpp:7202 */
void CBasePlayer::__MAKE_VHOOK(ImpulseCommands)(void)
{
	TraceResult tr;

	// Handle use events
	PlayerUse();

	int iImpulse = pev->impulse;

	switch (iImpulse)
	{
		case 99:
		{
			int iOn;

			if (!gmsgLogo)
			{
				iOn = 1;
				gmsgLogo = REG_USER_MSG("Logo", 1);
			}
			else
				iOn = 0;

			assert(gmsgLogo > 0);

			MESSAGE_BEGIN(MSG_ONE, gmsgLogo, NULL, pev);
				WRITE_BYTE(iOn);
			MESSAGE_END();

			if (!iOn)
				gmsgLogo = 0;

			break;
		}
		case 100:
		{
			// temporary flashlight for level designers
			if (FlashlightIsOn())
				FlashlightTurnOff();
			else
				FlashlightTurnOn();

			break;
		}
		case 201:
		{
			// paint decal
			if (gpGlobals->time < m_flNextDecalTime)
			{
				// too early!
				break;
			}

			UTIL_MakeVectors(pev->v_angle);
			UTIL_TraceLine(pev->origin + pev->view_ofs, pev->origin + pev->view_ofs + gpGlobals->v_forward * 128, ignore_monsters, edict(), &tr);

			if (tr.flFraction != 1.0f)
			{
				// line hit something, so paint a decal
				m_flNextDecalTime = gpGlobals->time + CVAR_GET_FLOAT("decalfrequency");
				CSprayCan *pCan = GetClassPtr((CSprayCan *)NULL);
				pCan->Spawn(pev);
			}
			break;
		}
		default:
			// check all of the cheat impulse commands now
			CheatImpulseCommands(iImpulse);
	}

	pev->impulse = 0;
}

/* <15786e> ../cstrike/dlls/player.cpp:7280 */
void CBasePlayer::CheatImpulseCommands(int iImpulse)
{
	if (!g_flWeaponCheat)
		return;

	CBaseEntity *pEntity;
	TraceResult tr;

	switch (iImpulse)
	{
		case 76:
			if (!giPrecacheGrunt)
			{
				giPrecacheGrunt = 1;
				ALERT(at_console, "You must now restart to use Grunt-o-matic.\n");
			}
			else
			{
				UTIL_MakeVectors(Vector(0, pev->v_angle.y, 0));
				Create("monster_human_grunt", pev->origin + gpGlobals->v_forward * 128, pev->angles);
			}
			break;
		case 101:
			gEvilImpulse101 = TRUE;
			AddAccount(16000);
			ALERT(at_console, "Crediting %s with $16000\n", STRING(pev->netname));
			break;
		case 102:
			CGib::SpawnRandomGibs(pev, 1, 1);
			break;
		case 103:
		{
			// What the hell are you doing?
			pEntity = FindEntityForward(this);

			if (pEntity)
			{
				CBaseMonster *pMonster = pEntity->MyMonsterPointer();

				if (pMonster)
					pMonster->ReportAIState();
			}
			break;
		}
		case 104:
			// Dump all of the global state varaibles (and global entity names)
			gGlobalState.DumpGlobals();
			break;
		case 105:
		{
			// player makes no sound for monsters to hear.
			if (m_fNoPlayerSound)
			{
				ALERT(at_console, "Player is audible\n");
				m_fNoPlayerSound = FALSE;
			}
			else
			{
				ALERT(at_console, "Player is silent\n");
				m_fNoPlayerSound = TRUE;
			}
			break;
		}
		case 106:
		{
			// Give me the classname and targetname of this entity.
			pEntity = FindEntityForward(this);

			if (pEntity)
			{
				ALERT(at_console, "Classname: %s", STRING(pEntity->pev->classname));

				if (!FStringNull(pEntity->pev->targetname))
					ALERT(at_console, " - Targetname: %s\n", STRING(pEntity->pev->targetname));
				else
					ALERT(at_console, " - TargetName: No Targetname\n");

				ALERT(at_console, "Model: %s\n", STRING(pEntity->pev->model));

				if (pEntity->pev->globalname)
					ALERT(at_console, "Globalname: %s\n", STRING(pEntity->pev->globalname));
			}
			break;
		}
		case 107:
		{
			TraceResult tr;
			edict_t *pWorld = INDEXENT(0);

			Vector start = pev->origin + pev->view_ofs;
			Vector end = start + gpGlobals->v_forward * 1024;
			UTIL_TraceLine(start, end, ignore_monsters, edict(), &tr);

			if (tr.pHit)
				pWorld = tr.pHit;

			const char *pszTextureName = TRACE_TEXTURE(pWorld, start, end);

			if (pszTextureName)
				ALERT(at_console, "Texture: %s\n", pszTextureName);

			break;
		}
		case 195:
			// show shortest paths for entire level to nearest node
			Create("node_viewer_fly", pev->origin, pev->angles);
			break;
		case 196:
			// show shortest paths for entire level to nearest node
			Create("node_viewer_large", pev->origin, pev->angles);
			break;
		case 197:
			// show shortest paths for entire level to nearest node
			Create("node_viewer_human", pev->origin, pev->angles);
			break;
		case 199:
			// show nearest node and all connections
			ALERT(at_console, "%d\n", WorldGraph.FindNearestNode(pev->origin, bits_NODE_LAND));
			WorldGraph.ShowNodeConnections(WorldGraph.FindNearestNode(pev->origin, bits_NODE_LAND));
			break;
		case 202:
		{
			// Random blood splatter
			UTIL_MakeVectors(pev->v_angle);
			UTIL_TraceLine(pev->origin + pev->view_ofs, pev->origin + pev->view_ofs + gpGlobals->v_forward * 128, ignore_monsters, edict(), &tr);

			if (tr.flFraction != 1.0f)
			{
				// line hit something, so paint a decal
				CBloodSplat *pBlood = GetClassPtr((CBloodSplat *)NULL);
				pBlood->Spawn(pev);
			}
			break;
		}
		case 203:
		{
			// remove creature.
			pEntity = FindEntityForward(this);

			if (pEntity && pEntity->pev->takedamage != DAMAGE_NO)
			{
				pEntity->SetThink(&CBaseEntity::SUB_Remove);
			}
			break;
		}
		case 204:
		{
			TraceResult tr;
			Vector dir = Vector(0, 0, 1);

			UTIL_BloodDrips(pev->origin, dir, BLOOD_COLOR_RED, 2000);

			for (int r = 1; r < 4; r++)
			{
				float bloodRange = r * 50.0f;

				for (int i = 0; i < 50; i++)
				{
					dir.x = RANDOM_FLOAT(-1, 1);
					dir.y = RANDOM_FLOAT(-1, 1);
					dir.z = RANDOM_FLOAT(-1, 1);

					if (dir.x || dir.y || dir.z)
						dir.NormalizeInPlace();
					else
						dir.z = -1.0f;
					
					UTIL_TraceLine(EyePosition(), EyePosition() + dir * bloodRange, ignore_monsters, pev->pContainingEntity, &tr);

					if (tr.flFraction < 1.0f)
						UTIL_BloodDecalTrace(&tr, BLOOD_COLOR_RED);
				}
			}
			break;
		}
	}
}

/* <158256> ../cstrike/dlls/player.cpp:7474 */
void OLD_CheckBuyZone(CBasePlayer *player)
{
	const char *pszSpawnClass = NULL;

	if (player->m_iTeam == TERRORIST)
		pszSpawnClass = "info_player_deathmatch";

	else if (player->m_iTeam == CT)
		pszSpawnClass = "info_player_start";

	if (pszSpawnClass != NULL)
	{
		CBaseEntity *pSpot = NULL;
		while ((pSpot = UTIL_FindEntityByClassname(pSpot, pszSpawnClass)) != NULL)
		{
			if ((pSpot->pev->origin - player->pev->origin).Length() < 200.0f)
				player->m_signals.Signal(SIGNAL_BUY);
		}
	}
}

/* <14e5a9> ../cstrike/dlls/player.cpp:7514 */
void OLD_CheckBombTarget(CBasePlayer *player)
{
	CBaseEntity *pSpot = NULL;
	while ((pSpot = UTIL_FindEntityByClassname(pSpot, "info_bomb_target")) != NULL)
	{
		if ((pSpot->pev->origin - player->pev->origin).Length() <= 256.0f)
			player->m_signals.Signal(SIGNAL_BOMB);
	}
}

/* <14e5d5> ../cstrike/dlls/player.cpp:7532 */
void OLD_CheckRescueZone(CBasePlayer *player)
{
	CBaseEntity *pSpot = NULL;
	while ((pSpot = UTIL_FindEntityByClassname(pSpot, "info_hostage_rescue")) != NULL)
	{
		if ((pSpot->pev->origin - player->pev->origin).Length() <= 256.0f)
			player->m_signals.Signal(SIGNAL_RESCUE);
	}
}

/* <1582e9> ../cstrike/dlls/player.cpp:7553 */
void CBasePlayer::HandleSignals(void)
{
	CHalfLifeMultiplay *mp = g_pGameRules;

	if (mp->IsMultiplayer())
	{
		if (!mp->m_bMapHasBuyZone)
			OLD_CheckBuyZone(this);

		if (!mp->m_bMapHasBombZone)
			OLD_CheckBombTarget(this);

		if (!mp->m_bMapHasRescueZone)
			OLD_CheckRescueZone(this);
	}

	int state = m_signals.GetSignal();
	int changed = m_signals.GetState() ^ state;

	m_signals.Update();

	if (changed & SIGNAL_BUY)
	{
		if (state & SIGNAL_BUY)
			BuyZoneIcon_Set(this);
		else
			BuyZoneIcon_Clear(this);
	}
	if (changed & SIGNAL_BOMB)
	{
		if (state & SIGNAL_BOMB)
			BombTargetFlash_Set(this);
		else
			BombTargetFlash_Clear(this);
	}
	if (changed & SIGNAL_RESCUE)
	{
		if (state & SIGNAL_RESCUE)
			RescueZoneIcon_Set(this);
		else
			RescueZoneIcon_Clear(this);
	}
	if (changed & SIGNAL_ESCAPE)
	{
		if (state & SIGNAL_ESCAPE)
			EscapeZoneIcon_Set(this);
		else
			EscapeZoneIcon_Clear(this);
	}
	if (changed & SIGNAL_VIPSAFETY)
	{
		if (state & SIGNAL_VIPSAFETY)
			VIP_SafetyZoneIcon_Set(this);
		else
			VIP_SafetyZoneIcon_Clear(this);
	}
}

// Add a weapon to the player (Item == Weapon == Selectable Object)

/* <15325f> ../cstrike/dlls/player.cpp:7625 */
BOOL CBasePlayer::__MAKE_VHOOK(AddPlayerItem)(CBasePlayerItem *pItem)
{
	CBasePlayerItem *pInsert = m_rgpPlayerItems[ pItem->iItemSlot() ];
	while (pInsert != NULL)
	{
		if (FClassnameIs(pInsert->pev, STRING(pItem->pev->classname)))
		{
			if (pItem->AddDuplicate(pInsert))
			{
				g_pGameRules->PlayerGotWeapon(this, pItem);
				pItem->CheckRespawn();

				// ugly hack to update clip w/o an update clip message
				pItem->UpdateItemInfo();

				if (m_pActiveItem)
					m_pActiveItem->UpdateItemInfo();

				pItem->Kill();
			}
			else if (gEvilImpulse101)
				pItem->Kill();

			return FALSE;
		}

		pInsert = pInsert->m_pNext;
	}
	if (pItem->AddToPlayer(this))
	{
		g_pGameRules->PlayerGotWeapon(this, pItem);

		if (pItem->iItemSlot() == PRIMARY_WEAPON_SLOT)
			m_bHasPrimary = true;

		pItem->CheckRespawn();
		pItem->m_pNext = m_rgpPlayerItems[ pItem->iItemSlot() ];
		m_rgpPlayerItems[ pItem->iItemSlot() ] = pItem;

		if (HasShield())
			pev->gamestate = 0;

		// should we switch to this item?
		if (g_pGameRules->FShouldSwitchWeapon(this, pItem))
		{
			if (!m_bShieldDrawn)
			{
				SwitchWeapon(pItem);
			}
		}

		return TRUE;
	}
	else if (gEvilImpulse101)
	{
		pItem->Kill();
	}

	return FALSE;
}

/* <1534bd> ../cstrike/dlls/player.cpp:7692 */
BOOL CBasePlayer::__MAKE_VHOOK(RemovePlayerItem)(CBasePlayerItem *pItem)
{
	if (m_pActiveItem == pItem)
	{
		ResetAutoaim();
		pItem->pev->nextthink = 0;

		pItem->SetThink(NULL);
		m_pActiveItem = NULL;

		pev->viewmodel = 0;
		pev->weaponmodel = 0;
	}
	else if (m_pLastItem == pItem)
		m_pLastItem = NULL;

	CBasePlayerItem *pPrev = m_rgpPlayerItems[pItem->iItemSlot()];
	if (pPrev == pItem)
	{
		m_rgpPlayerItems[pItem->iItemSlot()] = pItem->m_pNext;
		return TRUE;
	}

	while (pPrev && pPrev->m_pNext != pItem)
		pPrev = pPrev->m_pNext;

	if (pPrev)
	{
		pPrev->m_pNext = pItem->m_pNext;
		return TRUE;
	}
	return FALSE;
}

// Returns the unique ID for the ammo, or -1 if error

/* <15997b> ../cstrike/dlls/player.cpp:7731 */
int CBasePlayer::__MAKE_VHOOK(GiveAmmo)(int iCount, char *szName, int iMax)
{
	if (pev->flags & FL_SPECTATOR)
		return -1;

	if (!szName)
	{
		// no ammo.
		return -1;
	}

	if (!g_pGameRules->CanHaveAmmo(this, szName, iMax))
	{
		// game rules say I can't have any more of this ammo type.
		return -1;
	}

	int i = GetAmmoIndex( szName );

	if (i < 0 || i >= MAX_AMMO_SLOTS)
		return -1;

	int iAdd = _min(iCount, iMax - m_rgAmmo[i]);
	if (iAdd < 1)
		return i;

	m_rgAmmo[i] += iAdd;

	// make sure the ammo messages have been linked first
	if (gmsgAmmoPickup)
	{
		// Send the message that ammo has been picked up
		MESSAGE_BEGIN(MSG_ONE, gmsgAmmoPickup, NULL, pev);
			WRITE_BYTE(GetAmmoIndex(szName)); // ammo ID
			WRITE_BYTE(iAdd); // amount
		MESSAGE_END();
	}
	TabulateAmmo();

	return i;
}

// Called every frame by the player PreThink

/* <158b10> ../cstrike/dlls/player.cpp:7784 */
void CBasePlayer::ItemPreFrame(void)
{
#ifdef CLIENT_WEAPONS
	if (m_flNextAttack > 0)
		return;
#else
	if (gpGlobals->time < m_flNextAttack)
		return;
#endif // CLIENT_WEAPONS

	if (!m_pActiveItem)
		return;

	m_pActiveItem->ItemPreFrame();
}

// Called every frame by the player PostThink

/* <158b33> ../cstrike/dlls/player.cpp:7805 */
void CBasePlayer::ItemPostFrame(void)
{
	static int fInSelect = FALSE;

	// check if the player is using a tank
	if (m_pTank != NULL)
		return;

	if (m_pActiveItem != NULL)
	{
		if (HasShield() && IsReloading())
		{
			if (pev->button & IN_ATTACK2)
				m_flNextAttack = 0;
		}
	}

#ifdef CLIENT_WEAPONS
	if (m_flNextAttack > 0)
#else
	if (gpGlobals->time < m_flNextAttack)
#endif // CLIENT_WEAPONS
		return;

	ImpulseCommands();

	if (m_pActiveItem != NULL)
		m_pActiveItem->ItemPostFrame();
}

/* <158b71> ../cstrike/dlls/player.cpp:7834 */
int CBasePlayer::AmmoInventory(int iAmmoIndex)
{
	if (iAmmoIndex == -1)
		return -1;

	return m_rgAmmo[iAmmoIndex];
}

/* <158b9d> ../cstrike/dlls/player.cpp:7844 */
int CBasePlayer::GetAmmoIndex(const char *psz)
{
	if (!psz)
		return -1;

	for (int i = 1; i < MAX_AMMO_SLOTS; i++)
	{
		if (!IMPLEMENT_ARRAY_CLASS(CBasePlayerItem, AmmoInfoArray)[ i ].pszName)
			continue;

		if (!Q_stricmp(psz, IMPLEMENT_ARRAY_CLASS(CBasePlayerItem, AmmoInfoArray)[ i ].pszName))
			return i;
	}
	return -1;
}

/* <158bf7> ../cstrike/dlls/player.cpp:7865 */
void CBasePlayer::SendAmmoUpdate(void)
{
	for (int i = 0; i < MAX_AMMO_SLOTS; i++)
	{
		if (m_rgAmmo[i] != m_rgAmmoLast[i])
		{
			m_rgAmmoLast[i] = m_rgAmmo[i];

			// send "Ammo" update message
			MESSAGE_BEGIN(MSG_ONE, gmsgAmmoX, NULL, pev);
				WRITE_BYTE(i);
				WRITE_BYTE( _max( _min( m_rgAmmo[i], 254 ), 0 ) ); // clamp the value to one byte
			MESSAGE_END();
		}
	}
}

/* <158d4b> ../cstrike/dlls/player.cpp:7885 */
void CBasePlayer::SendHostagePos(void)
{
	CBaseEntity *pHostage = NULL;

	while ((pHostage = UTIL_FindEntityByClassname(pHostage, "hostage_entity")) != NULL)
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgHostagePos, NULL, pev);
			WRITE_BYTE(1);
			WRITE_BYTE(((CHostage *)pHostage)->m_iHostageIndex);
			WRITE_COORD(pHostage->pev->origin.x);
			WRITE_COORD(pHostage->pev->origin.y);
			WRITE_COORD(pHostage->pev->origin.z);
		MESSAGE_END();
	}

	SendHostageIcons();
}

/* <158c66> ../cstrike/dlls/player.cpp:7908 */
void CBasePlayer::SendHostageIcons(void)
{
	CBaseEntity *pHostage = NULL;
	int numHostages = 0;
	char buf[16];

	if (!UTIL_IsGame("czero"))
		return;

	while ((pHostage = UTIL_FindEntityByClassname(pHostage, "hostage_entity")) != NULL)
	{
		if (pHostage && pHostage->pev->deadflag == DEAD_NO)
			numHostages++;
	}

	if (numHostages > 4)
		numHostages = 4;

	Q_snprintf(buf, ARRAYSIZE(buf), "hostage%d", numHostages);

	if (numHostages)
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgScenarioIcon, NULL, pev);
			WRITE_BYTE(1);
			WRITE_STRING(buf);
			WRITE_BYTE(0);
		MESSAGE_END();
	}
	else
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgScenarioIcon, NULL, pev);
			WRITE_BYTE(0);
		MESSAGE_END();
	}
}

/* <158dc6> ../cstrike/dlls/player.cpp:7949 */
void CBasePlayer::SendWeatherInfo(void)
{
	CBaseEntity *pPoint = UTIL_FindEntityByClassname(NULL, "env_rain");
	CBaseEntity *pPoint2 = UTIL_FindEntityByClassname(NULL, "func_rain");

	if (pPoint != NULL || pPoint2 != NULL)
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgReceiveW, NULL, pev);
			WRITE_BYTE(1);
		MESSAGE_END();
	}
	else
	{
		pPoint = UTIL_FindEntityByClassname(NULL, "env_snow");
		pPoint2 = UTIL_FindEntityByClassname(NULL, "func_snow");

		if (pPoint != NULL || pPoint2 != NULL)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgReceiveW, NULL, pev);
				WRITE_BYTE(2);
			MESSAGE_END();
		}
	}
}

// resends any changed player HUD info to the client.
// Called every frame by PlayerPreThink
// Also called at start of demo recording and playback by
// ForceClientDllUpdate to ensure the demo gets messages
// reflecting all of the HUD state info.

/* <159d3c> ../cstrike/dlls/player.cpp:7963 */
void CBasePlayer::__MAKE_VHOOK(UpdateClientData)(void)
{
	if (m_fInitHUD)
	{
		m_fInitHUD = FALSE;
		gInitHUD = FALSE;
		m_signals.Update();

		MESSAGE_BEGIN(MSG_ONE, gmsgResetHUD, NULL, pev);
		MESSAGE_END();

		if (!m_fGameHUDInitialized)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgInitHUD, NULL, pev);
			MESSAGE_END();

			CBaseEntity *pEntity = UTIL_FindEntityByClassname(NULL, "env_fog");

			if (pEntity)
			{
				CClientFog *pFog = (CClientFog *)pEntity;

				int r = pFog->pev->rendercolor[0];
				int g = pFog->pev->rendercolor[1];
				int b = pFog->pev->rendercolor[2];

				if (r > 255)
					r = 255;

				else if (r < 0)
					r = 0;

				if (g > 255)
					g = 255;

				else if (g < 0)
					g = 0;

				if (b > 255)
					b = 255;

				else if (b < 0)
					b = 0;

				union
				{
					float f;
					char b[4];

				} density;

				density.f = pFog->m_fDensity;

				MESSAGE_BEGIN(MSG_ONE, gmsgFog, NULL, pev);
					WRITE_BYTE(r);
					WRITE_BYTE(g);
					WRITE_BYTE(b);
					WRITE_BYTE(density.b[0]);
					WRITE_BYTE(density.b[1]);
					WRITE_BYTE(density.b[2]);
					WRITE_BYTE(density.b[3]);
				MESSAGE_END();
			}

			g_pGameRules->InitHUD(this);
			m_fGameHUDInitialized = TRUE;

			if (g_pGameRules->IsMultiplayer())
			{
				FireTargets("game_playerjoin", this, this, USE_TOGGLE, 0);
			}

			m_iObserverLastMode = OBS_ROAMING;
			m_iObserverC4State = 0;
			m_bObserverHasDefuser = false;
			SetObserverAutoDirector(false);
		}

		FireTargets("game_playerspawn", this, this, USE_TOGGLE, 0);

		MESSAGE_BEGIN(MSG_ONE, gmsgMoney, NULL, pev);
			WRITE_LONG(m_iAccount);
			WRITE_BYTE(0);
		MESSAGE_END();

		if (m_bHasDefuser)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, pev);
				WRITE_BYTE(STATUSICON_SHOW);
				WRITE_STRING("defuser");
				WRITE_BYTE(0);
				WRITE_BYTE(160);
				WRITE_BYTE(0);
			MESSAGE_END();
		}

		SetBombIcon(FALSE);
		SyncRoundTimer();
		SendHostagePos();
		SendWeatherInfo();

		if (g_pGameRules->IsMultiplayer())
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgTeamScore, NULL, pev);
				WRITE_STRING(GetTeam(CT));
				WRITE_SHORT(g_pGameRules->m_iNumCTWins);
			MESSAGE_END();

			MESSAGE_BEGIN(MSG_ONE, gmsgTeamScore, NULL, pev);
				WRITE_STRING(GetTeam(TERRORIST));
				WRITE_SHORT(g_pGameRules->m_iNumTerroristWins);
			MESSAGE_END();
		}
	}

	if (m_iHideHUD != m_iClientHideHUD)
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgHideWeapon, NULL, pev);
			WRITE_BYTE(m_iHideHUD);
		MESSAGE_END();

		m_iClientHideHUD = m_iHideHUD;
	}

	if (m_iFOV != m_iClientFOV)
	{
		// cache FOV change at end of function, so weapon updates can see that FOV has changed

		pev->fov = m_iFOV;

		MESSAGE_BEGIN(MSG_ONE, gmsgSetFOV, NULL, pev);
			WRITE_BYTE(m_iFOV);
		MESSAGE_END();

		MESSAGE_BEGIN(MSG_SPEC, gmsgHLTV);
			WRITE_BYTE(ENTINDEX(edict()));
			WRITE_BYTE(m_iFOV);
		MESSAGE_END();
	}

	// HACKHACK -- send the message to display the game title
	if (gDisplayTitle)
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgShowGameTitle, NULL, pev);
			WRITE_BYTE(0);
		MESSAGE_END();

		gDisplayTitle = FALSE;
	}

	if ((int)pev->health != m_iClientHealth)
	{
		int iHealth = clamp(pev->health, 0, 255);

		if (pev->health > 0.0f && pev->health <= 1.0f)
			iHealth = 1;

		// send "health" update message
		MESSAGE_BEGIN(MSG_ONE, gmsgHealth, NULL, pev);
			WRITE_BYTE(iHealth);
		MESSAGE_END();

		m_iClientHealth = (int)pev->health;
	}

	if ((int)pev->armorvalue != m_iClientBattery)
	{
		m_iClientBattery = (int)pev->armorvalue;

		assert(gmsgBattery > 0);

		// send "armor" update message
		MESSAGE_BEGIN(MSG_ONE, gmsgBattery, NULL, pev);
			WRITE_SHORT((int)pev->armorvalue);
		MESSAGE_END();
	}

	if (pev->dmg_take != 0.0f || pev->dmg_save != 0.0f || m_bitsHUDDamage != m_bitsDamageType)
	{
		// Comes from inside me if not set
		Vector damageOrigin = pev->origin;

		// send "damage" message
		// causes screen to flash, and pain compass to show direction of damage
		edict_t *other = pev->dmg_inflictor;

		if (other)
		{
			CBaseEntity *pEntity = CBaseEntity::Instance(other);

			if (pEntity)
			{
				damageOrigin = pEntity->Center();
			}
		}

		// only send down damage type that have hud art
		int visibleDamageBits = m_bitsDamageType & DMG_SHOWNHUD;

		MESSAGE_BEGIN(MSG_ONE, gmsgDamage, NULL, pev);
			WRITE_BYTE((int)pev->dmg_save);
			WRITE_BYTE((int)pev->dmg_take);
			WRITE_LONG(visibleDamageBits);
			WRITE_COORD(damageOrigin.x);
			WRITE_COORD(damageOrigin.y);
			WRITE_COORD(damageOrigin.z);
		MESSAGE_END();

		pev->dmg_take = 0;
		pev->dmg_save = 0;
		m_bitsHUDDamage = m_bitsDamageType;

		// Clear off non-time-based damage indicators
		m_bitsDamageType &= DMG_TIMEBASED;
	}

	// Update Flashlight
	if (m_flFlashLightTime && m_flFlashLightTime <= gpGlobals->time)
	{
		if (FlashlightIsOn())
		{
			if (m_iFlashBattery)
			{
				m_flFlashLightTime = gpGlobals->time + FLASH_DRAIN_TIME;
				m_iFlashBattery--;

				if (!m_iFlashBattery)
				{
					FlashlightTurnOff();
				}
			}
		}
		else
		{
			if (m_iFlashBattery < 100)
			{
				m_flFlashLightTime = gpGlobals->time + FLASH_CHARGE_TIME;
				m_iFlashBattery++;
			}
			else
				m_flFlashLightTime = 0;
		}

		MESSAGE_BEGIN(MSG_ONE, gmsgFlashBattery, NULL, pev);
			WRITE_BYTE(m_iFlashBattery);
		MESSAGE_END();
	}

	if (m_iTrain & TRAIN_NEW)
	{
		assert(gmsgTrain > 0);

		// send "train hud" update message
		MESSAGE_BEGIN(MSG_ONE, gmsgTrain, NULL, pev);
			WRITE_BYTE(m_iTrain & 0xF);
		MESSAGE_END();
		
		m_iTrain &= ~TRAIN_NEW;
	}

	SendAmmoUpdate();

	// Update all the items
	for (int i = 0; i < MAX_ITEM_TYPES; i++)
	{
		if (m_rgpPlayerItems[i])
		{
			// each item updates it's successors
			m_rgpPlayerItems[i]->UpdateClientData(this);
		}
	}

	// Cache and client weapon change
	m_pClientActiveItem = m_pActiveItem;
	m_iClientFOV = m_iFOV;

	// Update Status Bar
	if (m_flNextSBarUpdateTime < gpGlobals->time)
	{
		UpdateStatusBar();
		m_flNextSBarUpdateTime = gpGlobals->time + 0.2;
	}
	
	if (!(m_flDisplayHistory & DHF_AMMO_EXHAUSTED))
	{
		if (m_pActiveItem && m_pActiveItem->IsWeapon())
		{
			CBasePlayerWeapon *w = (CBasePlayerWeapon *)m_pActiveItem;

			if (!(w->iFlags() & ITEM_FLAG_EXHAUSTIBLE))
			{
				if (AmmoInventory( w->m_iPrimaryAmmoType ) < 1 && w->m_iClip == 0)
				{
					m_flDisplayHistory |= DHF_AMMO_EXHAUSTED;
					HintMessage("#Hint_out_of_ammo");
				}
			}
		}
	}

	if (gpGlobals->time > m_tmHandleSignals)
	{
		m_tmHandleSignals = gpGlobals->time + 0.5f;
		HandleSignals();
	}

	if (pev->deadflag == DEAD_NO && gpGlobals->time > m_tmNextRadarUpdate)
	{
		m_tmNextRadarUpdate = gpGlobals->time + 1.0f;

		if ((pev->origin - m_vLastOrigin).Length() >= 64)
		{
			for (int i = 1; i <= gpGlobals->maxClients; i++)
			{
				CBaseEntity *pEntity = UTIL_PlayerByIndex(i);

				if (!pEntity || i == entindex())
					continue;

				CBasePlayer *pPlayer = GetClassPtr((CBasePlayer *)pEntity->pev);

				if (pPlayer->pev->flags == FL_DORMANT)
					continue;

				if (pPlayer->pev->deadflag != DEAD_NO)
					continue;

				if (pPlayer->m_iTeam == m_iTeam)
				{
					MESSAGE_BEGIN(MSG_ONE, gmsgRadar, NULL, pPlayer->pev);
						WRITE_BYTE(entindex());
						WRITE_COORD(pev->origin.x);
						WRITE_COORD(pev->origin.y);
						WRITE_COORD(pev->origin.z);
					MESSAGE_END();
				}
			}
		}

		m_vLastOrigin = pev->origin;
	}
}

/* <1510bc> ../cstrike/dlls/player.cpp:8330 */
BOOL CBasePlayer::__MAKE_VHOOK(FBecomeProne)(void)
{
	m_afPhysicsFlags |= PFLAG_ONBARNACLE;
	return TRUE;
}

/* <158e8a> ../cstrike/dlls/player.cpp:8341 */
NOXREF void CBasePlayer::BarnacleVictimBitten(entvars_t *pevBarnacle)
{
	TakeDamage(pevBarnacle, pevBarnacle, pev->armorvalue + pev->health, DMG_SLASH | DMG_ALWAYSGIB);
}

/* <158ec3> ../cstrike/dlls/player.cpp:8350 */
NOXREF void CBasePlayer::BarnacleVictimReleased(void)
{
	m_afPhysicsFlags &= ~PFLAG_ONBARNACLE;
}

// return player light level plus virtual muzzle flash

/* <1510e4> ../cstrike/dlls/player.cpp:8360 */
int CBasePlayer::__MAKE_VHOOK(Illumination)(void)
{
	int iIllum = CBaseEntity::Illumination();

	iIllum += m_iWeaponFlash;

	if (iIllum > 255)
		return 255;

	return iIllum;
}

/* <158eeb> ../cstrike/dlls/player.cpp:8371 */
void CBasePlayer::EnableControl(BOOL fControl)
{
	if (!fControl)
		pev->flags |= FL_FROZEN;
	else
		pev->flags &= ~FL_FROZEN;
}

/* <151142> ../cstrike/dlls/player.cpp:8387 */
void CBasePlayer::__MAKE_VHOOK(ResetMaxSpeed)(void)
{
	float speed = 240.0f;

	if (IsObserver())
		speed = 900.0f;

	else if (g_pGameRules->IsMultiplayer() && g_pGameRules->IsFreezePeriod())
		speed = 1.0f;

	else if (m_bIsVIP)
		speed = 227.0f;

	else if (m_pActiveItem)
		speed = m_pActiveItem->GetMaxSpeed();

	pev->maxspeed = speed;
}

/* <158f23> ../cstrike/dlls/player.cpp:8436 */
bool CBasePlayer::HintMessage(const char *pMessage, BOOL bDisplayIfPlayerDead, BOOL bOverride)
{
	if (!bDisplayIfPlayerDead && !IsAlive())
		return false;

	if (bOverride || m_bShowHints)
		return m_hintMessageQueue.AddMessage(pMessage, 6.0, true, NULL);

	return true;
}

/* <1513f7> ../cstrike/dlls/player.cpp:8473 */
Vector CBasePlayer::__MAKE_VHOOK(GetAutoaimVector)(float flDelta)
{
	Vector vecSrc;
	BOOL m_fOldTargeting;
	Vector angles;

	if (g_iSkillLevel == SKILL_HARD)
	{
		UTIL_MakeVectors(pev->v_angle + pev->punchangle);
		return gpGlobals->v_forward;
	}

	vecSrc = GetGunPosition();
	m_fOldTargeting = m_fOnTarget;
	m_vecAutoAim = Vector(0, 0, 0);
	angles = AutoaimDeflection(vecSrc, 8192, flDelta);

	if (g_pGameRules->AllowAutoTargetCrosshair())
	{
		if (m_fOldTargeting != m_fOnTarget)
			m_pActiveItem->UpdateItemInfo();
	}
	else
		m_fOnTarget = FALSE;

	if (angles.x > 180.0f)
		angles.x -= 360.0f;
	if (angles.x < -180.0f)
		angles.x += 360.0f;

	if (angles.y > 180.0f)
		angles.y -= 360.0f;
	if (angles.y < -180.0f)
		angles.y += 360.0f;

	if (angles.x > 25.0f)
		angles.x = 25.0f;
	if (angles.x < -25.0f)
		angles.x = -25.0f;

	if (angles.y > 12.0f)
		angles.y = 12.0f;
	if (angles.y < -12.0f)
		angles.y = -12.0f;

	if (g_iSkillLevel == SKILL_EASY)
		m_vecAutoAim = m_vecAutoAim * 0.67f + angles * 0.33f;
	else
		m_vecAutoAim = angles * 0.9f;

	if (sv_aim && sv_aim->value > 0.0f)
	{
		if (m_vecAutoAim.x != m_lastx || m_vecAutoAim.y != m_lasty)
		{
			SET_CROSSHAIRANGLE(ENT(pev), -m_vecAutoAim.x, m_vecAutoAim.y);

			m_lastx = m_vecAutoAim.x;
			m_lasty = m_vecAutoAim.y;
		}
	}
	UTIL_MakeVectors(pev->v_angle + pev->punchangle + m_vecAutoAim);
	return gpGlobals->v_forward;
}

/* <158f62> ../cstrike/dlls/player.cpp:8553 */
Vector CBasePlayer::AutoaimDeflection(Vector &vecSrc, float flDist, float flDelta)
{
	m_fOnTarget = FALSE;
	return g_vecZero;
}

/* <158fc1> ../cstrike/dlls/player.cpp:8686 */
void CBasePlayer::ResetAutoaim(void)
{
	if (m_vecAutoAim.x != 0.0f || m_vecAutoAim.y != 0.0f)
	{
		m_vecAutoAim = Vector(0, 0, 0);
		SET_CROSSHAIRANGLE(ENT(pev), 0, 0);
	}
	m_fOnTarget = FALSE;
}

// UNDONE: Determine real frame limit, 8 is a placeholder.
// Note: -1 means no custom frames present.

/* <158ff6> ../cstrike/dlls/player.cpp:8704 */
void CBasePlayer::SetCustomDecalFrames(int nFrames)
{
	if (nFrames > 0 && nFrames < 8)
		m_nCustomSprayFrames = nFrames;
	else
		m_nCustomSprayFrames = -1;
}

// Returns the # of custom frames this player's custom clan logo contains.

/* <15902e> ../cstrike/dlls/player.cpp:8720 */
int CBasePlayer::GetCustomDecalFrames(void)
{
	return m_nCustomSprayFrames;
}

/* <151183> ../cstrike/dlls/player.cpp:8731 */
void CBasePlayer::__MAKE_VHOOK(Blind)(float duration, float holdTime, float fadeTime, int alpha)
{
	m_blindUntilTime = gpGlobals->time + duration;
	m_blindStartTime = gpGlobals->time;

	m_blindHoldTime = holdTime;
	m_blindFadeTime = fadeTime;
	m_blindAlpha = alpha;
}

/* <159051> ../cstrike/dlls/player.cpp:8741 */
void CBasePlayer::InitStatusBar(void)
{
	m_flStatusBarDisappearDelay = 0.0f;
	m_SbarString0[0] = '\0';
}

/* <159079> ../cstrike/dlls/player.cpp:8749 */
void CBasePlayer::UpdateStatusBar(void)
{
	int newSBarState[ SBAR_END ];
	char sbuf0[ SBAR_STRING_SIZE ];

	Q_memset(newSBarState, 0, sizeof(newSBarState));
	Q_strcpy(sbuf0, m_SbarString0);

	// Find an ID Target
	TraceResult tr;
	UTIL_MakeVectors(pev->v_angle + pev->punchangle);

	Vector vecSrc = EyePosition();
	Vector vecEnd = vecSrc + (gpGlobals->v_forward * ((pev->flags & FL_SPECTATOR) != 0 ? MAX_SPECTATOR_ID_RANGE : MAX_ID_RANGE));

	UTIL_TraceLine(vecSrc, vecEnd, dont_ignore_monsters, edict(), &tr);

	if (tr.flFraction != 1.0f)
	{
		if (!FNullEnt(tr.pHit))
		{
			CBaseEntity *pEntity = CBaseEntity::Instance(tr.pHit);
			bool isVisiblePlayer = (!TheBots->IsLineBlockedBySmoke(&pev->origin, &pEntity->pev->origin) && pEntity->Classify() == CLASS_PLAYER);

			if (gpGlobals->time >= m_blindUntilTime && isVisiblePlayer)
			{
				CBasePlayer *pTarget = (CBasePlayer *)pEntity;

				newSBarState[ SBAR_ID_TARGETNAME ] = ENTINDEX( pTarget->edict() );
				newSBarState[ SBAR_ID_TARGETTYPE ] = (pTarget->m_iTeam == m_iTeam) ? SBAR_TARGETTYPE_TEAMMATE : SBAR_TARGETTYPE_ENEMY;

				if (pTarget->m_iTeam == m_iTeam || IsObserver())
				{
					if (playerid.value != PLAYERID_MODE_OFF || IsObserver())
						Q_strcpy(sbuf0, "1 %c1: %p2\n2  %h: %i3%%");
					else
						Q_strcpy(sbuf0, " ");

					newSBarState[ SBAR_ID_TARGETHEALTH ] = (int)((pEntity->pev->health / pEntity->pev->max_health) * 100);

					if (!(m_flDisplayHistory & DHF_FRIEND_SEEN) && !(pev->flags & FL_SPECTATOR))
					{
						m_flDisplayHistory |= DHF_FRIEND_SEEN;
						HintMessage("#Hint_spotted_a_friend");
					}
				}
				else if (!IsObserver())
				{
					if (playerid.value != PLAYERID_MODE_TEAMONLY && playerid.value != PLAYERID_MODE_OFF)
						Q_strcpy(sbuf0, "1 %c1: %p2");
					else
						Q_strcpy(sbuf0, " ");

					if (!(m_flDisplayHistory & DHF_ENEMY_SEEN))
					{
						m_flDisplayHistory |= DHF_ENEMY_SEEN;
						HintMessage("#Hint_spotted_an_enemy");
					}
				}

				m_flStatusBarDisappearDelay = gpGlobals->time + 2.0f;
			}
			else if (pEntity->Classify() == CLASS_HUMAN_PASSIVE)
			{
				if (playerid.value != PLAYERID_MODE_OFF || IsObserver())
					Q_strcpy(sbuf0, "1 %c1  %h: %i3%%");
				else
					Q_strcpy(sbuf0, " ");

				newSBarState[ SBAR_ID_TARGETTYPE ] = SBAR_TARGETTYPE_HOSTAGE;
				newSBarState[ SBAR_ID_TARGETHEALTH ] = (int)((pEntity->pev->health / pEntity->pev->max_health) * 100);

				if (!(m_flDisplayHistory & DHF_HOSTAGE_SEEN_FAR) && tr.flFraction > 0.1f)
				{
					m_flDisplayHistory |= DHF_HOSTAGE_SEEN_FAR;

					if (m_iTeam == TERRORIST)
						HintMessage("#Hint_prevent_hostage_rescue", TRUE);

					else if (m_iTeam == CT)
						HintMessage("#Hint_rescue_the_hostages", TRUE);
				}
				else if (m_iTeam == CT && !(m_flDisplayHistory & DHF_HOSTAGE_SEEN_NEAR) && tr.flFraction <= 0.1f)
				{
					m_flDisplayHistory |= (DHF_HOSTAGE_SEEN_NEAR | DHF_HOSTAGE_SEEN_FAR);
					HintMessage("#Hint_press_use_so_hostage_will_follow");
				}

				m_flStatusBarDisappearDelay = gpGlobals->time + 2.0f;
			}
		}
	}
	else if (m_flStatusBarDisappearDelay > gpGlobals->time)
	{
		// hold the values for a short amount of time after viewing the object

		newSBarState[ SBAR_ID_TARGETTYPE ] = m_izSBarState[ SBAR_ID_TARGETTYPE ];
		newSBarState[ SBAR_ID_TARGETNAME ] = m_izSBarState[ SBAR_ID_TARGETNAME ];
		newSBarState[ SBAR_ID_TARGETHEALTH ] = m_izSBarState[ SBAR_ID_TARGETHEALTH ];
	}

	BOOL bForceResend = FALSE;

	if (Q_strcmp(sbuf0, m_SbarString0))
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgStatusText, NULL, pev);
			WRITE_BYTE(0);
			WRITE_STRING(sbuf0);
		MESSAGE_END();

		Q_strcpy(m_SbarString0, sbuf0);

		// make sure everything's resent
		bForceResend = TRUE;
	}

	// Check values and send if they don't match
	for (int i = 1; i < SBAR_END; i++)
	{
		if (newSBarState[ i ] != m_izSBarState[ i ] || bForceResend)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgStatusValue, NULL, pev);
				WRITE_BYTE(i);
				WRITE_SHORT(newSBarState[ i ]);
			MESSAGE_END();

			m_izSBarState[ i ] = newSBarState[ i ];
		}
	}
}

/* <1603f0> ../cstrike/dlls/player.cpp:8926 */
void CBasePlayer::DropPlayerItem(const char *pszItemName)
{
	if (!Q_strlen(pszItemName))
	{
		// if this string has no length, the client didn't type a name!
		// assume player wants to drop the active item.
		// make the string null to make future operations in this function easier
		pszItemName = NULL;
	}

	if (m_bIsVIP)
	{
		ClientPrint(pev, HUD_PRINTCENTER, "#Weapon_Cannot_Be_Dropped");
		return;
	}
	else if (!pszItemName && HasShield())
	{
		DropShield();
		return;
	}

	for (int i = 0; i < MAX_ITEM_TYPES; i++)
	{
		CBasePlayerItem *pWeapon = m_rgpPlayerItems[i];

		while (pWeapon != NULL)
		{
			if (pszItemName)
			{
				if (!Q_strcmp(pszItemName, STRING(pWeapon->pev->classname)))
					break;
			}
			else
			{
				if (pWeapon == m_pActiveItem)
					break;
			}

			pWeapon = pWeapon->m_pNext;
		}

		if (pWeapon)
		{
			if (!pWeapon->CanDrop())
			{
				ClientPrint(pev, HUD_PRINTCENTER, "#Weapon_Cannot_Be_Dropped");
				continue;
			}

			// take item off hud
			pev->weapons &= ~(1 << pWeapon->m_iId);
			g_pGameRules->GetNextBestWeapon(this, pWeapon);
			UTIL_MakeVectors(pev->angles);

			if (pWeapon->iItemSlot() == PRIMARY_WEAPON_SLOT)
				m_bHasPrimary = false;

			if (!Q_strcmp(STRING(pWeapon->pev->classname), "weapon_c4"))
			{
				m_bHasC4 = false;
				pev->body = 0;
				SetBombIcon(FALSE);
				pWeapon->m_pPlayer->SetProgressBarTime(0);

				if (!g_pGameRules->m_fTeamCount)
				{
					UTIL_LogPrintf("\"%s<%i><%s><TERRORIST>\" triggered \"Dropped_The_Bomb\"\n",
						STRING(pev->netname),
						GETPLAYERUSERID(edict()),
						GETPLAYERAUTHID(edict()));

					g_pGameRules->m_bBombDropped = TRUE;

					CBaseEntity *pEntity = NULL;

					while ((pEntity = UTIL_FindEntityByClassname(pEntity, "player")) != NULL)
					{
						if (FNullEnt(pEntity->edict()))
							break;

						if (!pEntity->IsPlayer())
							continue;

						if (pEntity->pev->flags != FL_DORMANT)
						{
							CBasePlayer *pOther = GetClassPtr((CBasePlayer *)pEntity->pev);

							if (pOther->pev->deadflag == DEAD_NO && pOther->m_iTeam == TERRORIST)
							{
								ClientPrint(pOther->pev, HUD_PRINTCENTER, "#Game_bomb_drop", STRING(pev->netname));

								MESSAGE_BEGIN(MSG_ONE, gmsgBombDrop, NULL, pOther->pev);
									WRITE_COORD(pev->origin.x);
									WRITE_COORD(pev->origin.y);
									WRITE_COORD(pev->origin.z);
									WRITE_BYTE(0);
								MESSAGE_END();
							}
						}
					}
				}
			}

			CWeaponBox *pWeaponBox = (CWeaponBox *)Create("weaponbox", pev->origin + gpGlobals->v_forward * 10, pev->angles, edict());
			pWeaponBox->pev->angles.x = 0;
			pWeaponBox->pev->angles.z = 0;
			pWeaponBox->SetThink(&CWeaponBox::Kill);
			pWeaponBox->pev->nextthink = gpGlobals->time + 300;
			pWeaponBox->PackWeapon(pWeapon);
			pWeaponBox->pev->velocity = gpGlobals->v_forward * 300 + gpGlobals->v_forward * 100;

			if (!Q_strcmp(STRING(pWeapon->pev->classname), "weapon_c4"))
			{
				pWeaponBox->m_bIsBomb = true;
				pWeaponBox->SetThink(&CWeaponBox::BombThink);
				pWeaponBox->pev->nextthink = gpGlobals->time + 1;

				TheCSBots()->SetLooseBomb(pWeaponBox);
				TheCSBots()->OnEvent(EVENT_BOMB_DROPPED);
			}

			if (pWeapon->iFlags() & ITEM_FLAG_EXHAUSTIBLE)
			{
				int iAmmoIndex = GetAmmoIndex(pWeapon->pszAmmo1());

				if (iAmmoIndex != -1)
				{
					pWeaponBox->PackAmmo(MAKE_STRING(pWeapon->pszAmmo1()), m_rgAmmo[iAmmoIndex] > 0);
					m_rgAmmo[iAmmoIndex] = 0;
				}
			}

			const char *modelname = GetCSModelName(pWeapon->m_iId);

			if (modelname)
				SET_MODEL(ENT(pWeaponBox->pev), modelname);

			return;
		}
	}
}

/* <1594a2> ../cstrike/dlls/player.cpp:9094 */
BOOL CBasePlayer::HasPlayerItem(CBasePlayerItem *pCheckItem)
{
	CBasePlayerItem *pItem = m_rgpPlayerItems[ pCheckItem->iItemSlot() ];
	while (pItem != NULL)
	{
		if (FClassnameIs(pItem->pev, STRING(pCheckItem->pev->classname)))
			return TRUE;

		pItem = pItem->m_pNext;
	}
	return FALSE;
}

/* <159534> ../cstrike/dlls/player.cpp:9113 */
BOOL CBasePlayer::HasNamedPlayerItem(const char *pszItemName)
{
	CBasePlayerItem *pItem;
	int i;

	for (i = 0; i < MAX_ITEM_TYPES ; i++)
	{
		pItem = m_rgpPlayerItems[ i ];

		while (pItem != NULL)
		{
			if (!Q_strcmp(pszItemName, STRING(pItem->pev->classname)))
				return TRUE;

			pItem = pItem->m_pNext;
		}
	}

	return FALSE;
}

/* <1619fd> ../cstrike/dlls/player.cpp:9137 */
void CBasePlayer::SwitchTeam(void)
{
	int oldTeam;
	char *szOldTeam;
	char *szNewTeam;
	const char *szName;

	oldTeam = m_iTeam;

	if (m_iTeam == CT)
	{
		m_iTeam = TERRORIST;

		switch (m_iModelName)
		{
		case MODEL_URBAN:
			m_iModelName = MODEL_LEET;
			SET_CLIENT_KEY_VALUE(entindex(), GET_INFO_BUFFER(edict()), "model", "leet");
			break;
		case MODEL_GIGN:
			m_iModelName = MODEL_GUERILLA;
			SET_CLIENT_KEY_VALUE(entindex(), GET_INFO_BUFFER(edict()), "model", "guerilla");
			break;
		case MODEL_SAS:
			m_iModelName = MODEL_ARCTIC;
			SET_CLIENT_KEY_VALUE(entindex(), GET_INFO_BUFFER(edict()), "model", "arctic");
			break;
		case MODEL_SPETSNAZ:
			if (UTIL_IsGame("czero"))
			{
				m_iModelName = MODEL_MILITIA;
				SET_CLIENT_KEY_VALUE(entindex(), GET_INFO_BUFFER(edict()), "model", "militia");
				break;
			}
		default:
			if (m_iModelName == MODEL_GSG9 || !IsBot() || !TheBotProfiles->GetCustomSkinModelname(m_iModelName))
			{
				m_iModelName = MODEL_TERROR;
				SET_CLIENT_KEY_VALUE(entindex(), GET_INFO_BUFFER(edict()), "model", "terror");
			}
			break;
		}
	}
	else if (m_iTeam == TERRORIST)
	{
		m_iTeam = CT;

		switch (m_iModelName)
		{
		case MODEL_TERROR:
			m_iModelName = MODEL_GSG9;
			SET_CLIENT_KEY_VALUE(entindex(), GET_INFO_BUFFER(edict()), "model", "gsg9");
			break;

		case MODEL_ARCTIC:
			m_iModelName = MODEL_SAS;
			SET_CLIENT_KEY_VALUE(entindex(), GET_INFO_BUFFER(edict()), "model", "sas");
			break;

		case MODEL_GUERILLA:
			m_iModelName = MODEL_GIGN;
			SET_CLIENT_KEY_VALUE(entindex(), GET_INFO_BUFFER(edict()), "model", "gign");
			break;

		case MODEL_MILITIA:
			if (UTIL_IsGame("czero"))
			{
				m_iModelName = MODEL_SPETSNAZ;
				SET_CLIENT_KEY_VALUE(entindex(), GET_INFO_BUFFER(edict()), "model", "spetsnaz");
				break;
			}
		default:
			if (m_iModelName == MODEL_LEET || !IsBot() || !TheBotProfiles->GetCustomSkinModelname(m_iModelName))
			{
				m_iModelName = MODEL_URBAN;
				SET_CLIENT_KEY_VALUE(entindex(), GET_INFO_BUFFER(edict()), "model", "urban");
			}
			break;
		}
	}

	MESSAGE_BEGIN(MSG_ALL, gmsgTeamInfo);
	WRITE_BYTE(entindex());
	switch (m_iTeam)
	{
	case CT:
		WRITE_STRING("CT");
		break;
	case TERRORIST:
		WRITE_STRING("TERRORIST");
		break;
	case SPECTATOR:
		WRITE_STRING("SPECTATOR");
		break;
	default:
		WRITE_STRING("UNASSIGNED");
		break;
	}
	MESSAGE_END();

	TheBots->OnEvent(EVENT_PLAYER_CHANGED_TEAM, this);

	UpdateLocation(true);

	if (m_iTeam)
	{
		SetScoreboardAttributes();
	}

	if (pev->netname)
	{
		szName = STRING(pev->netname);

		if (!szName[0])
			szName = "<unconnected>";
	}
	else
		szName = "<unconnected>";

	UTIL_ClientPrintAll(HUD_PRINTNOTIFY, (m_iTeam == TERRORIST) ? "#Game_join_terrorist_auto" : "#Game_join_ct_auto", szName);

	if (m_bHasDefuser)
	{
		m_bHasDefuser = false;
		pev->body = 0;

		MESSAGE_BEGIN(MSG_ONE, gmsgStatusIcon, NULL, pev);
			WRITE_BYTE(STATUSICON_HIDE);
			WRITE_STRING("defuser");
		MESSAGE_END();

		SendItemStatus(this);
		SetProgressBarTime(0);

		for (int i = 0; i < MAX_ITEM_TYPES; i++)
		{
			m_pActiveItem = m_rgpPlayerItems[ i ];

			if (m_pActiveItem && FClassnameIs(m_pActiveItem->pev, "item_thighpack"))
			{
				m_pActiveItem->Drop();
				m_rgpPlayerItems[i] = NULL;
			}
		}
	}

	szOldTeam = GetTeam(oldTeam);
	szNewTeam = GetTeam(m_iTeam);

	UTIL_LogPrintf
	(
		"\"%s<%i><%s><%s>\" joined team \"%s\" (auto)\n",
		STRING(pev->netname),
		GETPLAYERUSERID(edict()),
		GETPLAYERAUTHID(edict()),
		szOldTeam,
		szNewTeam
	);

	CCSBot *pBot = reinterpret_cast<CCSBot *>(this);

	if (pBot->IsBot())
	{
		const BotProfile *pProfile = pBot->GetProfile();

		if (pProfile != NULL)
		{
			bool kick = false;

			if (m_iTeam == CT && !pProfile->IsValidForTeam( BOT_TEAM_CT ))
				kick = true;

			else if (m_iTeam == TERRORIST && !pProfile->IsValidForTeam( BOT_TEAM_T ))
				kick = true;

			if (kick)
			{
				SERVER_COMMAND( UTIL_VarArgs("kick \"%s\"\n", STRING(pev->netname)) );
			}
		}
	}
}

/* <159594> ../cstrike/dlls/player.cpp:9302 */
void CBasePlayer::UpdateShieldCrosshair(bool draw)
{
	if (draw)
		m_iHideHUD &= ~HIDEHUD_CROSSHAIR;
	else
		m_iHideHUD |= HIDEHUD_CROSSHAIR;
}

/* <152fbc> ../cstrike/dlls/player.cpp:9313 */
BOOL CBasePlayer::SwitchWeapon(CBasePlayerItem *pWeapon)
{
	if (!pWeapon->CanDeploy())
	{
		return FALSE;
	}

	ResetAutoaim();

	if (m_pActiveItem)
	{
		m_pActiveItem->Holster();
	}

	CBasePlayerItem *pTemp = m_pActiveItem;
	m_pActiveItem = pWeapon;
	m_pLastItem = pTemp;
	pWeapon->Deploy();

	if (pWeapon->m_pPlayer)
	{
		pWeapon->m_pPlayer->ResetMaxSpeed();
	}

	if (HasShield())
	{
		UpdateShieldCrosshair(true);
	}

	return TRUE;
}

/* <1595ed> ../cstrike/dlls/player.cpp:9342 */
void CBasePlayer::TabulateAmmo(void)
{
	ammo_buckshot = AmmoInventory(GetAmmoIndex("buckshot"));
	ammo_9mm = AmmoInventory(GetAmmoIndex("9mm"));
	ammo_556nato = AmmoInventory(GetAmmoIndex("556Nato"));
	ammo_556natobox = AmmoInventory(GetAmmoIndex("556NatoBox"));
	ammo_762nato = AmmoInventory(GetAmmoIndex("762Nato"));
	ammo_45acp = AmmoInventory(GetAmmoIndex("45acp"));
	ammo_50ae = AmmoInventory(GetAmmoIndex("50AE"));
	ammo_338mag = AmmoInventory(GetAmmoIndex("338Magnum"));
	ammo_57mm = AmmoInventory(GetAmmoIndex("57mm"));
	ammo_357sig = AmmoInventory(GetAmmoIndex("357SIG"));
}

/* <1511eb> ../cstrike/dlls/player.cpp:9365 */
int CDeadHEV::__MAKE_VHOOK(Classify)(void)
{
	return CLASS_HUMAN_MILITARY;
}

/* <152451> ../cstrike/dlls/player.cpp:9375 */
void CDeadHEV::__MAKE_VHOOK(KeyValue)(KeyValueData *pkvd)
{
	if (FStrEq(pkvd->szKeyName, "pose"))
	{
		m_iPose = Q_atoi(pkvd->szValue);
		pkvd->fHandled = TRUE;
	}
	else
		CBaseMonster::KeyValue(pkvd);
}

/* <159a88> ../cstrike/dlls/player.cpp:9386 */
LINK_ENTITY_TO_CLASS(monster_hevsuit_dead, CDeadHEV);

/* <1513ce> ../cstrike/dlls/player.cpp:9391 */
void CDeadHEV::__MAKE_VHOOK(Spawn)(void)
{
	PRECACHE_MODEL("models/player.mdl");
	SET_MODEL(ENT(pev), "models/player.mdl");

	pev->effects = 0;
	pev->yaw_speed = 8.0f;

	pev->sequence = 0;
	pev->body = 1;

	m_bloodColor = BLOOD_COLOR_RED;
	pev->sequence = LookupSequence(m_szPoses[ m_iPose ]);

	if (pev->sequence == -1)
	{
		ALERT(at_console, "Dead hevsuit with bad pose\n");
		pev->sequence = 0;
		pev->effects = EF_BRIGHTFIELD;
	}

	pev->health = 8;
	MonsterInitDead();
}

/* <159b64> ../cstrike/dlls/player.cpp:9426 */
LINK_ENTITY_TO_CLASS(player_weaponstrip, CStripWeapons);

/* <15f62f> ../cstrike/dlls/player.cpp:9428 */
void CStripWeapons::__MAKE_VHOOK(Use)(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value)
{
	CBasePlayer *pPlayer = NULL;

	if (pActivator && pActivator->IsPlayer())
	{
		pPlayer = (CBasePlayer *)pActivator;
	}
	else if (!g_pGameRules->IsDeathmatch())
	{
		pPlayer = (CBasePlayer *)Instance(INDEXENT(1));
	}

	if (pPlayer)
	{
		pPlayer->RemoveAllItems(FALSE);
	}
}

/* <159c40> ../cstrike/dlls/player.cpp:9473 */
LINK_ENTITY_TO_CLASS(player_loadsaved, CRevertSaved);

/* <151a24> ../cstrike/dlls/player.cpp:9481 */
IMPLEMENT_SAVERESTORE(CRevertSaved, CPointEntity);

/* <152540> ../cstrike/dlls/player.cpp:9483 */
void CRevertSaved::__MAKE_VHOOK(KeyValue)(KeyValueData *pkvd)
{
	if (FStrEq(pkvd->szKeyName, "duration"))
	{
		SetDuration(Q_atof(pkvd->szValue));
		pkvd->fHandled = TRUE;
	}
	else if (FStrEq(pkvd->szKeyName, "holdtime"))
	{
		SetHoldTime(Q_atof(pkvd->szValue));
		pkvd->fHandled = TRUE;
	}
	else if (FStrEq(pkvd->szKeyName, "messagetime"))
	{
		SetMessageTime(Q_atof(pkvd->szValue));
		pkvd->fHandled = TRUE;
	}
	else if (FStrEq(pkvd->szKeyName, "loadtime"))
	{
		SetLoadTime(Q_atof(pkvd->szValue));
		pkvd->fHandled = TRUE;
	}
	else
		CPointEntity::KeyValue(pkvd);
}

/* <151365> ../cstrike/dlls/player.cpp:9509 */
void CRevertSaved::__MAKE_VHOOK(Use)(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value)
{
	UTIL_ScreenFadeAll(pev->rendercolor, Duration(), HoldTime(), (int)pev->renderamt, FFADE_OUT);
	pev->nextthink = gpGlobals->time + MessageTime();
	SetThink(&CRevertSaved::MessageThink);
}

/* <152a96> ../cstrike/dlls/player.cpp:9517 */
void CRevertSaved::MessageThink(void)
{
	float nextThink = LoadTime() - MessageTime();
	UTIL_ShowMessageAll(STRING(pev->message));

	if (nextThink > 0)
	{
		pev->nextthink = gpGlobals->time + nextThink;
		SetThink(&CRevertSaved::LoadThink);
	}
	else
		LoadThink();
}

/* <15198b> ../cstrike/dlls/player.cpp:9531 */
void CRevertSaved::LoadThink(void)
{
	if (!gpGlobals->deathmatch)
		SERVER_COMMAND("reload\n");
}

/* <15133c> ../cstrike/dlls/player.cpp:9549 */
void CInfoIntermission::__MAKE_VHOOK(Spawn)(void)
{
	UTIL_SetOrigin(pev, pev->origin);

	pev->solid = SOLID_NOT;
	pev->effects = EF_NODRAW;
	pev->v_angle = g_vecZero;
	pev->nextthink = gpGlobals->time + 2;
}

/* <1530e6> ../cstrike/dlls/player.cpp:9560 */
void CInfoIntermission::__MAKE_VHOOK(Think)(void)
{
	edict_t *pTarget = FIND_ENTITY_BY_TARGETNAME(NULL, STRING(pev->target));

	if (!FNullEnt(pTarget))
	{
		pev->v_angle = UTIL_VecToAngles((pTarget->v.origin - pev->origin).Normalize());
		pev->v_angle.x = -pev->v_angle.x;
	}
}

/* <159d1c> ../cstrike/dlls/player.cpp:9574 */
LINK_ENTITY_TO_CLASS(info_intermission, CInfoIntermission);

/* <159df8> ../cstrike/dlls/player.cpp:9586 */
void CBasePlayer::StudioEstimateGait(void)
{
	float_precision dt;
	Vector est_velocity;

	dt = gpGlobals->frametime;

	if (dt < 0)
		dt = 0;

	else if (dt > 1.0)
		dt = 1;

	if (dt == 0)
	{
		m_flGaitMovement = 0;
		return;
	}

	est_velocity = pev->origin - m_prevgaitorigin;
	m_prevgaitorigin = pev->origin;

	m_flGaitMovement = est_velocity.Length();
	
	if (dt <= 0 || m_flGaitMovement / dt < 5)
	{
		m_flGaitMovement = 0;

		est_velocity.x = 0;
		est_velocity.y = 0;
	}

	if (!est_velocity.x && !est_velocity.y)
	{
		float_precision flYawDiff = pev->angles.y - m_flGaityaw;
		float_precision flYaw = fmod(flYawDiff, 360);

		flYawDiff = flYawDiff - (int64_t)(flYawDiff / 360) * 360;

		if (flYawDiff > 180)
			flYawDiff -= 360;

		if (flYawDiff < -180)
			flYawDiff += 360;

		if (flYaw < -180)
			flYaw += 360;

		else if (flYaw > 180)
			flYaw -= 360;

		if (flYaw > -5 && flYaw < 5)
			m_flYawModifier = 0.05;

		if (flYaw < -90 || flYaw > 90)
			m_flYawModifier = 3.5;

		if (dt < 0.25)
			flYawDiff *= dt * m_flYawModifier;
		else
			flYawDiff *= dt;

		if ((float_precision)abs((int64_t)flYawDiff) < 0.1)
			flYawDiff = 0;

		m_flGaityaw += flYawDiff;
		m_flGaityaw -= (int64_t)(m_flGaityaw / 360) * 360;

		m_flGaitMovement = 0;
	}
	else
	{
		m_flGaityaw = (atan2((float_precision)est_velocity.y, (float_precision)est_velocity.x) * 180 / M_PI);

		if (m_flGaityaw > 180)
			m_flGaityaw = 180;

		if (m_flGaityaw < -180)
			m_flGaityaw = -180;
	}
}

/* <159f01> ../cstrike/dlls/player.cpp:9685 */
void CBasePlayer::StudioPlayerBlend(int *pBlend, float *pPitch)
{
	// calc up/down pointing
	float range = (float)(int64_t)(*pPitch * 3.0f);
	
	*pBlend = range;

	if (range <= -45.0f)
	{
		*pBlend = 255;
		*pPitch = 0;
	}
	else if (range >= 45.0f)
	{
		*pBlend = 0;
		*pPitch = 0;
	}
	else
	{
		*pBlend = (int64_t)((45.0f - range) * (255.0f / 90.0f));
		*pPitch = 0;
	}
}

/* <159f81> ../cstrike/dlls/player.cpp:9709 */
void CBasePlayer::CalculatePitchBlend(void)
{
	int iBlend;
	float temp = pev->angles.x;

	StudioPlayerBlend(&iBlend, &temp);

	pev->blending[1] = iBlend;
	m_flPitch = iBlend;
}

/* <15a007> ../cstrike/dlls/player.cpp:9720 */
void CBasePlayer::CalculateYawBlend(void)
{
	float dt;
	float maxyaw = 255.0f;

	float_precision flYaw;
	float_precision blend_yaw;

	dt = gpGlobals->frametime;

	if (dt < 0.0)
		dt = 0;

	else if (dt > 1.0)
		dt = 1;

	StudioEstimateGait();

	flYaw = fmod((float_precision)(pev->angles.y - m_flGaityaw), 360);

	if (flYaw < -180)
		flYaw += 360;

	else if (flYaw > 180)
		flYaw -= 360;

	if (m_flGaitMovement != 0.0)
	{
		if (flYaw > 120)
		{
			m_flGaityaw -= 180;
			m_flGaitMovement = -m_flGaitMovement;
			flYaw -= 180;
		}
		else if (flYaw < -120)
		{
			m_flGaityaw += 180;
			m_flGaitMovement = -m_flGaitMovement;
			flYaw += 180;
		}
	}

	flYaw = (flYaw / 90) * 128 + 127;

	if (flYaw > 255)
		flYaw = 255;

	else if (flYaw < 0)
		flYaw = 0;

	blend_yaw = maxyaw - flYaw;

	pev->blending[0] = (int64_t)blend_yaw;
	m_flYaw = blend_yaw;
}

/* <15a07b> ../cstrike/dlls/player.cpp:9776 */
void CBasePlayer::StudioProcessGait(void)
{
	mstudioseqdesc_t *pseqdesc;
	float_precision dt = gpGlobals->frametime;

	if (dt < 0.0)
		dt = 0;

	else if (dt > 1.0)
		dt = 1;

	CalculateYawBlend();
	CalculatePitchBlend();

	model_t *model = (model_t *)GET_MODEL_PTR(edict());

	if (!model)
		return;

	studiohdr_t *pstudiohdr = (studiohdr_t *)model;

	pseqdesc = (mstudioseqdesc_t *)((byte *)pstudiohdr + pstudiohdr->seqindex) + pev->gaitsequence;

	if (pseqdesc->linearmovement.x > 0.0f)
		m_flGaitframe += (m_flGaitMovement / pseqdesc->linearmovement.x) * pseqdesc->numframes;
	else
		m_flGaitframe += pev->framerate * pseqdesc->fps * dt;

	m_flGaitframe -= (int)(m_flGaitframe / pseqdesc->numframes) * pseqdesc->numframes;

	if (m_flGaitframe < 0)
		m_flGaitframe += pseqdesc->numframes;
}

/* <15a444> ../cstrike/dlls/player.cpp:9821 */
void CBasePlayer::ResetStamina(void)
{
	pev->fuser1 = 0;
	pev->fuser3 = 0;
	pev->fuser2 = 0;
}

/* <15a467> ../cstrike/dlls/player.cpp:9829 */
float GetPlayerPitch(const edict_t *pEdict)
{
	entvars_t *pev = VARS((edict_t *)pEdict);
	CBasePlayer *pPlayer = reinterpret_cast<CBasePlayer *>(CBasePlayer::Instance(pev));

	if (!pPlayer)
		return 0.0f;

	return pPlayer->m_flPitch;
}

/* <15a530> ../cstrike/dlls/player.cpp:9846 */
float GetPlayerYaw(const edict_t *pEdict)
{
	entvars_t *pev = VARS((edict_t *)pEdict);
	CBasePlayer *pPlayer = reinterpret_cast<CBasePlayer *>(CBasePlayer::Instance(pev));

	if (!pPlayer)
		return 0.0f;

	return pPlayer->m_flYaw;
}

/* <15a5f9> ../cstrike/dlls/player.cpp:9863 */
int GetPlayerGaitsequence(const edict_t *pEdict)
{
	entvars_t *pev = VARS((edict_t *)pEdict);
	CBasePlayer *pPlayer = reinterpret_cast<CBasePlayer *>(CBasePlayer::Instance(pev));

	if (!pPlayer)
		return 1;

	return pPlayer->m_iGaitsequence;
}

/* <15a6c2> ../cstrike/dlls/player.cpp:9880 */
void CBasePlayer::SpawnClientSideCorpse(void)
{
	char *infobuffer = GET_INFO_BUFFER(edict());
	char *pModel = GET_KEY_VALUE(infobuffer, "model");

	MESSAGE_BEGIN(MSG_ALL, gmsgSendCorpse);
		WRITE_STRING(pModel);
		WRITE_LONG(pev->origin.x * 128);
		WRITE_LONG(pev->origin.y * 128);
		WRITE_LONG(pev->origin.z * 128);
		WRITE_COORD(pev->angles.x);
		WRITE_COORD(pev->angles.y);
		WRITE_COORD(pev->angles.z);
		WRITE_LONG((pev->animtime - gpGlobals->time) * 100);
		WRITE_BYTE(pev->sequence);
		WRITE_BYTE(pev->body);
		WRITE_BYTE(m_iTeam);
		WRITE_BYTE(entindex());
	MESSAGE_END();

	m_canSwitchObserverModes = true;

	if (TheTutor != NULL)
	{
		TheTutor->OnEvent(EVENT_CLIENT_CORPSE_SPAWNED, this);
	}
}

/* <15a7a2> ../cstrike/dlls/player.cpp:9909 */
BOOL CBasePlayer::IsArmored(int nHitGroup)
{
	BOOL fApplyArmor = FALSE;

	if (m_iKevlar == ARMOR_TYPE_EMPTY)
		return FALSE;

	switch (nHitGroup)
	{
	case HITGROUP_HEAD:
	{
		fApplyArmor = (m_iKevlar == ARMOR_TYPE_HELMET);
		break;
	}
	case HITGROUP_GENERIC:
	case HITGROUP_CHEST:
	case HITGROUP_STOMACH:
	case HITGROUP_LEFTARM:
	case HITGROUP_RIGHTARM:
		fApplyArmor = TRUE;
		break;
	}

	return fApplyArmor;
}

/* <15a847> ../cstrike/dlls/player.cpp:9939 */
BOOL CBasePlayer::ShouldDoLargeFlinch(int nHitGroup, int nGunType)
{
	if (pev->flags & FL_DUCKING)
		return FALSE;

	if (nHitGroup != HITGROUP_LEFTLEG && nHitGroup != HITGROUP_RIGHTLEG)
	{
		switch (nGunType)
		{
		case WEAPON_SCOUT:
		case WEAPON_AUG:
		case WEAPON_SG550:
		case WEAPON_GALIL:
		case WEAPON_FAMAS:
		case WEAPON_AWP:
		case WEAPON_M3:
		case WEAPON_M4A1:
		case WEAPON_G3SG1:
		case WEAPON_DEAGLE:
		case WEAPON_SG552:
		case WEAPON_AK47:
			return TRUE;
		}
	}

	return FALSE;
}

/* <15a87d> ../cstrike/dlls/player.cpp:9971 */
void CBasePlayer::SetPrefsFromUserinfo(char *infobuffer)
{
	const char *pszKeyVal;
	
	pszKeyVal = GET_KEY_VALUE(infobuffer, "_cl_autowepswitch");

	if (Q_strcmp(pszKeyVal, ""))
		m_iAutoWepSwitch = Q_atoi(pszKeyVal);
	else
		m_iAutoWepSwitch = 1;

	pszKeyVal = GET_KEY_VALUE(infobuffer, "_vgui_menus");

	if (Q_strcmp(pszKeyVal, ""))
		m_bVGUIMenus = Q_atoi(pszKeyVal) != 0;
	else
		m_bVGUIMenus = true;

	pszKeyVal = GET_KEY_VALUE(infobuffer, "_ah");

	if (Q_strcmp(pszKeyVal, ""))
		m_bShowHints = Q_atoi(pszKeyVal) != 0;
	else
		m_bShowHints = true;
}

/* <15a92a> ../cstrike/dlls/player.cpp:10013 */
bool CBasePlayer::IsLookingAtPosition(Vector *pos, float angleTolerance)
{
	Vector to = *pos - EyePosition();
	Vector idealAngle = UTIL_VecToAngles( to );

	idealAngle.x = 360.0 - idealAngle.x;

	float deltaYaw = NormalizeAngle(idealAngle.y - pev->v_angle.y);
	float deltaPitch = NormalizeAngle(idealAngle.x - pev->v_angle.x);

	return (abs(deltaYaw) < angleTolerance
		&& abs(deltaPitch) < angleTolerance);
}

/* <15aa7b> ../cstrike/dlls/player.cpp:10083 */
bool CBasePlayer::CanAffordPrimary(void)
{
	int account = m_iAccount;

	if (m_iTeam == CT)
	{
		WeaponStruct *temp;
		for (int i = 0; i < MAX_WEAPONS; i++)
		{
			temp = &g_weaponStruct[ i ];

			if ((temp->m_side & TERRORIST) && temp->m_slot == PRIMARY_WEAPON_SLOT && account >= temp->m_price)
				return true;
		}
	}
	else if (m_iTeam == TERRORIST)
	{
		WeaponStruct *temp;
		for (int i = 0; i < MAX_WEAPONS; i++)
		{
			temp = &g_weaponStruct[ i ];

			if ((temp->m_side & CT) && temp->m_slot == PRIMARY_WEAPON_SLOT && account >= temp->m_price)
				return true;
		}
	}

	return false;
}

/* <15ab2c> ../cstrike/dlls/player.cpp:10139 */
bool CBasePlayer::CanAffordPrimaryAmmo(void)
{
	CBasePlayerWeapon *primary = (CBasePlayerWeapon *)&m_rgpPlayerItems[ PRIMARY_WEAPON_SLOT ];

	for (int i = 0; i < MAX_WEAPONS; i++)
	{
		WeaponStruct *temp = &g_weaponStruct[ i ];

		if (temp->m_type == primary->m_iId && m_iAccount >= temp->m_ammoPrice)
			return true;
	}

	return false;
}

/* <15aba0> ../cstrike/dlls/player.cpp:10169 */
bool CBasePlayer::CanAffordSecondaryAmmo(void)
{
	CBasePlayerWeapon *secondary = (CBasePlayerWeapon *)&m_rgpPlayerItems[ PISTOL_SLOT ];

	for (int i = 0; i < MAX_WEAPONS; i++)
	{
		WeaponStruct *temp = &g_weaponStruct[ i ];

		if (temp->m_type == secondary->m_iId && m_iAccount >= temp->m_ammoPrice)
			return true;
	}

	return false;
}

/* <15ac14> ../cstrike/dlls/player.cpp:10199 */
bool CBasePlayer::CanAffordArmor(void)
{
	if (m_iKevlar == ARMOR_TYPE_KEVLAR && pev->armorvalue == 100.0f && m_iAccount >= HELMET_PRICE)
		return true;

	return (m_iAccount >= KEVLAR_PRICE);
}

/* <15ac3c> ../cstrike/dlls/player.cpp:10217 */
bool CBasePlayer::CanAffordDefuseKit(void)
{
	return (m_iAccount >= DEFUSEKIT_PRICE);
}

/* <15ac64> ../cstrike/dlls/player.cpp:10227 */
bool CBasePlayer::CanAffordGrenade(void)
{
	return (m_iAccount >= FLASHBANG_PRICE);
}

/* <15ac8c> ../cstrike/dlls/player.cpp:10247 */
bool CBasePlayer::NeedsPrimaryAmmo(void)
{
	CBasePlayerWeapon *primary = (CBasePlayerWeapon *)&m_rgpPlayerItems[ PRIMARY_WEAPON_SLOT ];

	if (!primary || primary->m_iId == WEAPON_SHIELDGUN)
		return false;

	return (m_rgAmmo[ primary->m_iPrimaryAmmoType ] < primary->iMaxAmmo1());
}

/* <15ace1> ../cstrike/dlls/player.cpp:10268 */
bool CBasePlayer::NeedsSecondaryAmmo(void)
{
	CBasePlayerWeapon *secondary = (CBasePlayerWeapon *)&m_rgpPlayerItems[ PISTOL_SLOT ];

	if (!secondary)
		return false;

	return (m_rgAmmo[ secondary->m_iPrimaryAmmoType ] < secondary->iMaxAmmo1());
}

/* <15ad36> ../cstrike/dlls/player.cpp:10285 */
bool CBasePlayer::NeedsArmor(void)
{
	if (m_iKevlar == ARMOR_TYPE_EMPTY)
		return true;

	return (pev->armorvalue < 50.0f);
}

/* <15ad5e> ../cstrike/dlls/player.cpp:10300 */
bool CBasePlayer::NeedsDefuseKit(void)
{
	CHalfLifeMultiplay *mpRules = g_pGameRules;

	if (m_bHasDefuser || m_iTeam != CT)
		return false;

	return (mpRules->m_bMapHasBombTarget);
}

/* <15ad9a> ../cstrike/dlls/player.cpp:10325 */
bool CBasePlayer::NeedsGrenade(void)
{
	int iAmmoIndex = GetAmmoIndex("HEGrenade");

	if (iAmmoIndex > 0 && m_rgAmmo[ iAmmoIndex ])
		return false;

	iAmmoIndex = GetAmmoIndex("Flashbang");

	if (iAmmoIndex > 0 && m_rgAmmo[ iAmmoIndex ])
		return false;

	iAmmoIndex = GetAmmoIndex("SmokeGrenade");

	if (iAmmoIndex > 0 && m_rgAmmo[ iAmmoIndex ])
		return false;

	return true;
}

/* <15aeab> ../cstrike/dlls/player.cpp:10381 */
void CBasePlayer::ClientCommand(const char *cmd, const char *arg1, const char *arg2, const char *arg3)
{
	BotArgs[0] = cmd;
	BotArgs[1] = arg1;
	BotArgs[2] = arg2;
	BotArgs[3] = arg3;

	UseBotArgs = true;
	::ClientCommand(ENT(pev));
	UseBotArgs = false;
}

/* <15aea9> ../cstrike/dlls/player.cpp:10401 */
const char *GetBuyStringForWeaponClass(int weaponClass)
{
	switch (weaponClass)
	{
	case WEAPONCLASS_PISTOL:
		return "deagle elites fn57 usp glock p228 shield";
	case WEAPONCLASS_SNIPERRIFLE:
		return "awp sg550 g3sg1 scout";
	case WEAPONCLASS_GRENADE:
		return "hegren";
	case WEAPONCLASS_SHOTGUN:
		return "xm1014 m3";
	case WEAPONCLASS_SUBMACHINEGUN:
		return "p90 ump45 mp5 tmp mac10";
	case WEAPONCLASS_MACHINEGUN:
		return "m249";
	case WEAPONCLASS_RIFLE:
		return "sg552 aug ak47 m4a1 galil famas";
	}

	return NULL;
}

/* <15aee9> ../cstrike/dlls/player.cpp:10454 */
void CBasePlayer::ClearAutoBuyData(void)
{
	m_autoBuyString[0] = '\0';
}

/* <15af11> ../cstrike/dlls/player.cpp:10459 */
void CBasePlayer::AddAutoBuyData(const char *str)
{
	int len = Q_strlen(m_autoBuyString);

	if (len < MAX_AUTOBUY_LENGTH - 1)
	{
		if (len > 0)
			m_autoBuyString[ len ] = ' ';

		Q_strncat(m_autoBuyString, str, MAX_AUTOBUY_LENGTH - len);
	}
}

/* <15af66> ../cstrike/dlls/player.cpp:10478 */
void CBasePlayer::InitRebuyData(const char *str)
{
	if (!str || Q_strlen(str) > MAX_REBUY_LENGTH)
	{
		return;
	}

	if (m_rebuyString != NULL)
	{
		delete m_rebuyString;
		m_rebuyString = NULL;
	}

	m_rebuyString = new char[ Q_strlen(str) + 1 ];
	Q_strcpy(m_rebuyString, str);
	m_rebuyString[ Q_strlen(str) ] = '\0';
}

/* <15be4f> ../cstrike/dlls/player.cpp:10500 */
void CBasePlayer::AutoBuy(void)
{
	const char *c = NULL;
	bool boughtPrimary = false;
	bool boughtSecondary = false;
	char prioritizedString[ MAX_AUTOBUY_LENGTH ];

	c = PickFlashKillWeaponString();

	if (c != NULL)
	{
		ParseAutoBuyString(c, boughtPrimary, boughtSecondary);
	}

	c = PickGrenadeKillWeaponString();

	if (c != NULL)
	{
		ParseAutoBuyString(c, boughtPrimary, boughtSecondary);
	}

	// TODO: Reverse me
	c = PickPrimaryCareerTaskWeapon();

	if (c != NULL)
	{
		Q_strcpy(prioritizedString, c);

		PrioritizeAutoBuyString(prioritizedString, m_autoBuyString);
		ParseAutoBuyString(prioritizedString, boughtPrimary, boughtSecondary);
	}

	// TODO: Reverse me
	c = PickSecondaryCareerTaskWeapon();

	if (c != NULL)
	{
		Q_strcpy(prioritizedString, c);

		PrioritizeAutoBuyString(prioritizedString, m_autoBuyString);
		ParseAutoBuyString(prioritizedString, boughtPrimary, boughtSecondary);
	}

	ParseAutoBuyString(m_autoBuyString, boughtPrimary, boughtSecondary);

	c = PickFlashKillWeaponString();

	if (c != NULL)
	{
		ParseAutoBuyString(c, boughtPrimary, boughtSecondary);
	}

	if (TheTutor)
		TheTutor->OnEvent( EVENT_PLAYER_LEFT_BUY_ZONE );
}

/* <14ea4e> ../cstrike/dlls/player.cpp:10556 */
bool IsPrimaryWeaponClass(int classId)
{
	return (classId >= WEAPONCLASS_SUBMACHINEGUN && classId <= WEAPONCLASS_SNIPERRIFLE);
}

/* <15afbe> ../cstrike/dlls/player.cpp:10571 */
bool IsPrimaryWeaponId(int id)
{
	int classId = WEAPONCLASS_NONE;
	const char *alias = WeaponIDToAlias( id );

	if (alias)
	{
		classId = AliasToWeaponClass(alias);
	}

	return IsPrimaryWeaponClass(classId);
}

/* <14ea6f> ../cstrike/dlls/player.cpp:10583 */
bool IsSecondaryWeaponClass(int classId)
{
	return (classId == WEAPONCLASS_PISTOL);
}

/* <15b059> ../cstrike/dlls/player.cpp:10588 */
bool IsSecondaryWeaponId(int id)
{
	int classId = WEAPONCLASS_NONE;
	const char *alias = WeaponIDToAlias( id );

	if (alias)
	{
		classId = AliasToWeaponClass(alias);
	}

	return IsSecondaryWeaponClass(classId);
}

/* <15b0f1> ../cstrike/dlls/player.cpp:10600 */
const char *GetWeaponAliasFromName(const char *weaponName)
{
	if (!Q_strncmp(weaponName, "weapon_", 7))
	{
		weaponName += 7;
	}

	return weaponName;
}

/* <15b133> ../cstrike/dlls/player.cpp:10607 */
bool CurrentWeaponSatisfies(CBasePlayerWeapon *pWeapon, int id, int classId)
{
	if (pWeapon == NULL)
		return false;

	const char *weaponName = GetWeaponAliasFromName(pWeapon->pszName());

	if (id && AliasToWeaponID(weaponName) == id)
		return true;

	if (classId && AliasToWeaponClass(weaponName) == classId)
		return true;

	return false;
}

void (*pCBasePlayer__PickPrimaryCareerTaskWeapon)(void);

/* <15b1eb> ../cstrike/dlls/player.cpp:10623 */
NOBODY const char __declspec(naked) *CBasePlayer::PickPrimaryCareerTaskWeapon(void)
{
	__asm
	{
		jmp pCBasePlayer__PickPrimaryCareerTaskWeapon
	}
//	{
//		intconst BufLen;                                      // 10625
//		char buf;                                             // 10626
//		class CBasePlayerWeapon *primary;                    // 10632
//		class vector<CCareerTask*, std::allocator<CCareerTask*> > taskVector;               // 10634
//		CareerTaskListIt it;                                  // 10635
//		vector(vector<CCareerTask*, std::allocator<CCareerTask*> > *const this);  // 10634
//		{
//			class CCareerTask *pTask;                    // 10638
//			push_back(vector<CCareerTask*, std::allocator<CCareerTask*> > *const this,
//					const value_type  &__x);  // 10656
//			IsPrimaryWeaponId(int id);  // 10644
//			CurrentWeaponSatisfies(CBasePlayerWeapon *pWeapon,
//						int id,
//						int classId);  // 10647
//			IsPrimaryWeaponId(int id);  // 10649
//			GetBuyStringForWeaponClass(int weaponClass);  // 10652
//		}
//		operator++(_List_iterator<CCareerTask*> *const this);  // 10636
//		{
//			int taskNum;                                  // 10664
//			class CCareerTask *temp;                     // 10666
//			operator[](vector<CCareerTask*, std::allocator<CCareerTask*> > *const this,
//					size_type __n);  // 10667
//		}
//		{
//			int i;                                        // 10673
//			{
//				class CCareerTask *pTask;            // 10675
//				IsPrimaryWeaponId(int id);  // 10676
//				GetBuyStringForWeaponClass(int weaponClass);  // 10682
//			}
//			size(const class vector<CCareerTask*, std::allocator<CCareerTask*> > *const this);  // 10673
//		}
//		~vector(vector<CCareerTask*, std::allocator<CCareerTask*> > *const this,
//			intconst __in_chrg);  // 10634
//	}
}

void (*pCBasePlayer__PickSecondaryCareerTaskWeapon)(void);

/* <15b5d7> ../cstrike/dlls/player.cpp:10690 */
NOBODY const char __declspec(naked) *CBasePlayer::PickSecondaryCareerTaskWeapon(void)
{
	__asm
	{
		jmp pCBasePlayer__PickSecondaryCareerTaskWeapon
	}
//	{
//		intconst BufLen;                                      // 10692
//		char buf;                                             // 10693
//		class CBasePlayerWeapon *secondary;                  // 10699
//		class vector<CCareerTask*, std::allocator<CCareerTask*> > taskVector;               // 10701
//		CareerTaskListIt it;                                  // 10702
//		vector(vector<CCareerTask*, std::allocator<CCareerTask*> > *const this);  // 10701
//		{
//			class CCareerTask *pTask;                    // 10705
//			IsSecondaryWeaponId(int id);  // 10711
//			CurrentWeaponSatisfies(CBasePlayerWeapon *pWeapon,
//						int id,
//						int classId);  // 10714
//			push_back(vector<CCareerTask*, std::allocator<CCareerTask*> > *const this,
//					const value_type  &__x);  // 10723
//			IsSecondaryWeaponId(int id);  // 10716
//			GetBuyStringForWeaponClass(int weaponClass);  // 10719
//		}
//		operator++(_List_iterator<CCareerTask*> *const this);  // 10703
//		{
//			int taskNum;                                  // 10731
//			class CCareerTask *temp;                     // 10733
//			operator[](vector<CCareerTask*, std::allocator<CCareerTask*> > *const this,
//					size_type __n);  // 10734
//		}
//		{
//			int i;                                        // 10740
//			{
//				class CCareerTask *pTask;            // 10742
//				IsSecondaryWeaponId(int id);  // 10743
//			}
//			size(const class vector<CCareerTask*, std::allocator<CCareerTask*> > *const this);  // 10740
//		}
//		~vector(vector<CCareerTask*, std::allocator<CCareerTask*> > *const this,
//			intconst __in_chrg);  // 10701
//	}
}

/* <15b9ea> ../cstrike/dlls/player.cpp:10759 */
const char *CBasePlayer::PickFlashKillWeaponString(void)
{
	bool foundOne = false;

	for (CareerTaskListIt it = TheCareerTasks->GetTasks()->begin(); it != TheCareerTasks->GetTasks()->end(); ++it)
	{
		CCareerTask *pTask = (*it);

		if (!pTask->IsComplete() && !Q_strcmp(pTask->GetTaskName(), "killblind"))
		{
			foundOne = true;
			break;
		}
	}

	if (foundOne)
		return "flash flash";
	
	return NULL;
}

/* <15baa1> ../cstrike/dlls/player.cpp:10787 */
const char *CBasePlayer::PickGrenadeKillWeaponString(void)
{
	bool foundOne = false;

	for (CareerTaskListIt it = TheCareerTasks->GetTasks()->begin(); it != TheCareerTasks->GetTasks()->end(); ++it)
	{
		CCareerTask *pTask = (*it);

		if (!pTask->IsComplete() && pTask->GetWeaponId() == WEAPON_HEGRENADE)
		{
			foundOne = true;
			break;
		}
	}

	if (foundOne)
		return "hegren";
	
	return NULL;
}

/* <15bb0c> ../cstrike/dlls/player.cpp:10816 */
void CBasePlayer::PrioritizeAutoBuyString(char *autobuyString, const char *priorityString)
{
	char newString[ MAX_AUTOBUY_LENGTH ];
	int newStringPos = 0;
	char priorityToken[32];

	if (!priorityString || !autobuyString)
		return;

	const char *priorityChar = priorityString;

	while (*priorityChar != '\0')
	{
		int i = 0;

		while (*priorityChar != '\0' && *priorityChar != ' ')
		{
			priorityToken[ i++ ] = *priorityChar;
			priorityChar++;
		}

		priorityToken[i] = 0;

		while (*priorityChar == ' ')
			priorityChar++;

		if (!Q_strlen(priorityToken))
			continue;

		char *autoBuyPosition = Q_strstr(autobuyString, priorityToken);

		if (autoBuyPosition != NULL)
		{
			while (*autoBuyPosition != '\0' && *autoBuyPosition != ' ')
			{
				newString[ newStringPos ] = *autoBuyPosition;
				*autoBuyPosition = ' ';

				++newStringPos;
				++autoBuyPosition;
			}

			newString[ newStringPos++ ] = ' ';
		}
	}

	char *autobuyPosition = autobuyString;

	while (*autobuyPosition != '\0')
	{
		while (*autobuyPosition == ' ')
			autobuyPosition++;

		while (*autobuyPosition != '\0' && *autobuyPosition != ' ')
		{
			newString[ newStringPos++ ] = *autobuyPosition;
			autobuyPosition++;
		}

		newString[ newStringPos++ ] = ' ';
	}

	newString[ newStringPos ] = 0;
	Q_sprintf(autobuyString, "%s", newString);
}

/* <15bcd5> ../cstrike/dlls/player.cpp:10899 */
void CBasePlayer::ParseAutoBuyString(const char *string, bool &boughtPrimary, bool &boughtSecondary)
{
	char command[32];
	const char *c = string;

	if (!string || !string[0])
		return;

	while (*c)
	{
		int i = 0;

		while (*c && (*c != ' ') && i < sizeof(command))
		{
			command[i] = *c;
			++c;
			++i;
		}

		if (*c == ' ')
			++c;

		command[i] = 0;
		i = 0;

		while (command[i] != 0)
		{
			if (command[i] == ' ')
			{
				command[i] = 0;
				break;
			}

			++i;
		}

		if (!Q_strlen(command))
			continue;

		AutoBuyInfoStruct *commandInfo = GetAutoBuyCommandInfo(command);
		if (ShouldExecuteAutoBuyCommand(commandInfo, boughtPrimary, boughtSecondary))
		{
			ClientCommand(commandInfo->m_command);
			PostAutoBuyCommandProcessing(commandInfo, boughtPrimary, boughtSecondary);
		}
	}
}

/* <15bb6b> ../cstrike/dlls/player.cpp:10957 */
bool CBasePlayer::ShouldExecuteAutoBuyCommand(AutoBuyInfoStruct *commandInfo, bool boughtPrimary, bool boughtSecondary)
{
	if (!commandInfo)
		return false;

	if (boughtPrimary && (commandInfo->m_class & AUTOBUYCLASS_PRIMARY) != 0 && !(commandInfo->m_class & AUTOBUYCLASS_AMMO))
		return false;

	if (boughtSecondary && (commandInfo->m_class & AUTOBUYCLASS_SECONDARY) != 0 && !(commandInfo->m_class & AUTOBUYCLASS_AMMO))
		return false;

	return true;
}

/* <15bbfa> ../cstrike/dlls/player.cpp:10978 */
AutoBuyInfoStruct *CBasePlayer::GetAutoBuyCommandInfo(const char *command)
{
	int i = 0;
	AutoBuyInfoStruct *ret = NULL;
	AutoBuyInfoStruct *temp = NULL;

	while (ret == NULL)
	{
		temp = &(g_autoBuyInfo[ i ]);

		if (!temp->m_class)
			break;

		if (Q_stricmp(temp->m_command, command) == 0)
			ret = temp;

		i++;
	}

	return ret;
}

/* <15bc49> ../cstrike/dlls/player.cpp:11000 */
void CBasePlayer::PostAutoBuyCommandProcessing(AutoBuyInfoStruct *commandInfo, bool &boughtPrimary, bool &boughtSecondary)
{
	CBasePlayerWeapon *primary = (CBasePlayerWeapon *)m_rgpPlayerItems[ PRIMARY_WEAPON_SLOT ];
	CBasePlayerWeapon *secondary = (CBasePlayerWeapon *)m_rgpPlayerItems[ PISTOL_SLOT ];

	if (!commandInfo)
		return;

	if (primary != NULL && !Q_stricmp(STRING(primary->pev->classname), commandInfo->m_classname))
		boughtPrimary = true;

	else if (commandInfo->m_class & AUTOBUYCLASS_SHIELD && HasShield())
		boughtPrimary = true;

	else if (secondary != NULL && !Q_stricmp(STRING(secondary->pev->classname), commandInfo->m_classname))
		boughtSecondary = true;
}

/* <15c0b4> ../cstrike/dlls/player.cpp:11027 */
void CBasePlayer::BuildRebuyStruct(void)
{
	int iAmmoIndex;

	if (m_bIsInRebuy)
		return;

	CBasePlayerWeapon *primary = (CBasePlayerWeapon *)m_rgpPlayerItems[ PRIMARY_WEAPON_SLOT ];
	CBasePlayerWeapon *secondary = (CBasePlayerWeapon *)m_rgpPlayerItems[ PISTOL_SLOT ];

	if (primary != NULL)
	{
		m_rebuyStruct.m_primaryWeapon = primary->m_iId;
		m_rebuyStruct.m_primaryAmmo = m_rgAmmo[ primary->m_iPrimaryAmmoType ];
	}
	else
	{
		m_rebuyStruct.m_primaryAmmo = 0;

		if (HasShield())
			m_rebuyStruct.m_primaryWeapon = WEAPON_SHIELDGUN;
		else
			m_rebuyStruct.m_primaryWeapon = 0;
	}

	if (secondary != NULL)
	{
		m_rebuyStruct.m_secondaryWeapon = secondary->m_iId;
		m_rebuyStruct.m_secondaryAmmo = m_rgAmmo[ secondary->m_iPrimaryAmmoType ];
	}
	else
	{
		m_rebuyStruct.m_secondaryWeapon = 0;
		m_rebuyStruct.m_secondaryAmmo = 0;
	}

	iAmmoIndex = GetAmmoIndex("HEGrenade");

	if (iAmmoIndex != -1)
		m_rebuyStruct.m_heGrenade = m_rgAmmo[ iAmmoIndex ];
	else
		m_rebuyStruct.m_heGrenade = 0;

	iAmmoIndex = GetAmmoIndex("Flashbang");

	if (iAmmoIndex != -1)
		m_rebuyStruct.m_flashbang = m_rgAmmo[ iAmmoIndex ];
	else
		m_rebuyStruct.m_flashbang = 0;

	iAmmoIndex = GetAmmoIndex("SmokeGrenade");

	if (iAmmoIndex != -1)
		m_rebuyStruct.m_smokeGrenade = m_rgAmmo[ iAmmoIndex ];
	else
		m_rebuyStruct.m_smokeGrenade = 0;

	m_rebuyStruct.m_defuser = m_bHasDefuser;
	m_rebuyStruct.m_nightVision = m_bHasNightVision;
	m_rebuyStruct.m_armor = m_iKevlar;
}

/* <15c37d> ../cstrike/dlls/player.cpp:11134 */
void CBasePlayer::Rebuy(void)
{
	char *fileData = m_rebuyString;
	char *token;

	m_bIsInRebuy = true;

	while (true)
	{
		fileData = MP_COM_Parse(fileData);
		token = MP_COM_GetToken();

		if (!fileData)
			break;

		if (!Q_stricmp(token, "primaryWeapon"))
			RebuyPrimaryWeapon();
		else if (!Q_stricmp(token, "primaryAmmo"))
			RebuyPrimaryAmmo();
		else if (!Q_stricmp(token, "secondaryWeapon"))
			RebuySecondaryWeapon();
		else if (!Q_stricmp(token, "secondaryAmmo"))
			RebuySecondaryAmmo();
		else if (!Q_stricmp(token, "hegrenade"))
			RebuyHEGrenade();
		else if (!Q_stricmp(token, "flashbang"))
			RebuyFlashbang();
		else if (!Q_stricmp(token, "smokegrenade"))
			RebuySmokeGrenade();
		else if (!Q_stricmp(token, "defuser"))
			RebuyDefuser();
		else if (!Q_stricmp(token, "nightvision"))
			RebuyNightVision();
		else if (!Q_stricmp(token, "armor"))
			RebuyArmor();
	}

	m_bIsInRebuy = false;

	if (TheTutor)
		TheTutor->OnEvent(EVENT_PLAYER_LEFT_BUY_ZONE);
}

/* <15c96a> ../cstrike/dlls/player.cpp:11200 */
NOXREF void CBasePlayer::RebuyPrimaryWeapon(void)
{
	if (!m_rgpPlayerItems[ PRIMARY_WEAPON_SLOT ])
	{
		if (m_rebuyStruct.m_primaryWeapon)
		{
			const char *alias = WeaponIDToAlias(m_rebuyStruct.m_primaryWeapon);

			if (alias != NULL)
				ClientCommand(alias);
		}
	}
}

/* <15c9e4> ../cstrike/dlls/player.cpp:11217 */
NOXREF void CBasePlayer::RebuyPrimaryAmmo(void)
{
	CBasePlayerWeapon *primary = (CBasePlayerWeapon *)m_rgpPlayerItems[ PRIMARY_WEAPON_SLOT ];

	if (primary != NULL)
	{
		if (m_rebuyStruct.m_primaryAmmo > m_rgAmmo[ primary->m_iPrimaryAmmoType ])
			ClientCommand("primammo");
	}
}

/* <15ca68> ../cstrike/dlls/player.cpp:11233 */
NOXREF void CBasePlayer::RebuySecondaryWeapon(void)
{
	if (m_rebuyStruct.m_secondaryWeapon)
	{
		const char *alias = WeaponIDToAlias(m_rebuyStruct.m_secondaryWeapon);

		if (alias != NULL)
			ClientCommand(alias);
	}
}

/* <15cae2> ../cstrike/dlls/player.cpp:11245 */
NOXREF void CBasePlayer::RebuySecondaryAmmo(void)
{
	CBasePlayerWeapon *secondary = (CBasePlayerWeapon *)m_rgpPlayerItems[ PISTOL_SLOT ];

	if (secondary)
	{
		if (m_rebuyStruct.m_secondaryAmmo > m_rgAmmo[ secondary->m_iPrimaryAmmoType ])
			ClientCommand("secammo");
	}
}

/* <15cb66> ../cstrike/dlls/player.cpp:11259 */
NOXREF void CBasePlayer::RebuyHEGrenade(void)
{
	int iAmmoIndex = GetAmmoIndex("HEGrenade");

	if (iAmmoIndex == -1)
		return;

	int numToBuy = m_rebuyStruct.m_heGrenade - m_rgAmmo[ iAmmoIndex ];

	for (int i = 0; i < numToBuy; i++)
		ClientCommand("hegren");
}

/* <15cc3f> ../cstrike/dlls/player.cpp:11279 */
NOXREF void CBasePlayer::RebuyFlashbang(void)
{
	int iAmmoIndex = GetAmmoIndex("Flashbang");

	if (iAmmoIndex == -1)
		return;

	int numToBuy = m_rebuyStruct.m_flashbang - m_rgAmmo[ iAmmoIndex ];

	for (int i = 0; i < numToBuy; i++)
		ClientCommand("flash");
}

/* <15cd18> ../cstrike/dlls/player.cpp:11299 */
NOXREF void CBasePlayer::RebuySmokeGrenade(void)
{
	int iAmmoIndex = GetAmmoIndex("SmokeGrenade");

	if (iAmmoIndex == -1)
		return;

	int numToBuy = m_rebuyStruct.m_smokeGrenade - m_rgAmmo[ iAmmoIndex ];

	for (int i = 0; i < numToBuy; i++)
		ClientCommand("sgren");
}

/* <15cdf1> ../cstrike/dlls/player.cpp:11319 */
void CBasePlayer::RebuyDefuser(void)
{
	if (m_rebuyStruct.m_defuser)
	{
		if (!m_bHasDefuser)
			ClientCommand("defuser");
	}
}

/* <15ce59> ../cstrike/dlls/player.cpp:11330 */
void CBasePlayer::RebuyNightVision(void)
{
	if (m_rebuyStruct.m_nightVision)
	{
		if (!m_bHasNightVision)
			ClientCommand("nvgs");
	}
}

/* <15cec1> ../cstrike/dlls/player.cpp:11341 */
void CBasePlayer::RebuyArmor(void)
{
	if (m_rebuyStruct.m_armor)
	{
		if (m_rebuyStruct.m_armor > m_iKevlar)
		{
			if (m_rebuyStruct.m_armor == ARMOR_TYPE_KEVLAR)
				ClientCommand("vest");
			else
				ClientCommand("vesthelm");
		}
	}
}

/* <15cf7c> ../cstrike/dlls/player.cpp:11366 */
bool CBasePlayer::IsObservingPlayer(CBasePlayer *pPlayer)
{
	if (!pPlayer || pev->flags == FL_DORMANT)
		return false;

	if (FNullEnt(pPlayer))
		return false;

	return (IsObserver() == OBS_IN_EYE && pev->iuser2 == pPlayer->entindex()) != 0;
}

/* <15d049> ../cstrike/dlls/player.cpp:11380 */
void CBasePlayer::UpdateLocation(bool forceUpdate)
{
	if (!forceUpdate && m_flLastUpdateTime >= gpGlobals->time + 2)
		return;

	const char *placeName = "";

	if (pev->deadflag == DEAD_NO && UTIL_IsGame("czero"))
	{
		// search the place name where is located the player
		Place playerPlace = TheNavAreaGrid.GetPlace( &pev->origin );
		const BotPhraseList *placeList = TheBotPhrases->GetPlaceList();

		for (BotPhraseList::const_iterator iter = placeList->begin(); iter != placeList->end(); ++iter)
		{
			if ((*iter)->GetID() == playerPlace)
			{
				placeName = (*iter)->GetName();
				break;
			}
		}
	}

	if (!placeName[0] || (m_lastLocation[0] && !Q_strcmp(placeName, &m_lastLocation[1])))
	{
		return;
	}

	m_flLastUpdateTime = gpGlobals->time;
	Q_snprintf(m_lastLocation, sizeof(m_lastLocation), "#%s", placeName);

	for (int i = 1; i <= gpGlobals->maxClients; i++)
	{
		CBasePlayer *player = (CBasePlayer *)UTIL_PlayerByIndex( i );

		if (!player)
			continue;

		if (player->m_iTeam == m_iTeam || player->m_iTeam == SPECTATOR)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgLocation, NULL, player->edict());
				WRITE_BYTE(entindex());
				WRITE_STRING(m_lastLocation);
			MESSAGE_END();
		}
		else if (forceUpdate)
		{
			MESSAGE_BEGIN(MSG_ONE, gmsgLocation, NULL, player->edict());
				WRITE_BYTE(entindex());
				WRITE_STRING("");
			MESSAGE_END();
		}
	}
}

#ifdef HOOK_GAMEDLL

void CBasePlayer::Spawn(void)
{
	Spawn_();
}

void CBasePlayer::Precache(void)
{
	Precache_();
}

int CBasePlayer::Save(CSave &save)
{
	return Save_(save);
}

int CBasePlayer::Restore(CRestore &restore)
{
	return Restore_(restore);
}

int CBasePlayer::Classify(void)
{
	return Classify_();
}

void CBasePlayer::TraceAttack(entvars_t *pevAttacker,float flDamage,Vector vecDir,TraceResult *ptr,int bitsDamageType)
{
	TraceAttack_(pevAttacker,flDamage,vecDir,ptr,bitsDamageType);
}

int CBasePlayer::TakeDamage(entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,int bitsDamageType)
{
	return TakeDamage_(pevInflictor,pevAttacker,flDamage,bitsDamageType);
}

int CBasePlayer::TakeHealth(float flHealth,int bitsDamageType)
{
	return TakeHealth_(flHealth,bitsDamageType);
}

void CBasePlayer::Killed(entvars_t *pevAttacker,int iGib)
{
	Killed_(pevAttacker,iGib);
}

void CBasePlayer::AddPoints(int score,BOOL bAllowNegativeScore)
{
	AddPoints_(score,bAllowNegativeScore);
}

void CBasePlayer::AddPointsToTeam(int score,BOOL bAllowNegativeScore)
{
	AddPointsToTeam_(score,bAllowNegativeScore);
}

BOOL CBasePlayer::AddPlayerItem(CBasePlayerItem *pItem)
{
	return AddPlayerItem_(pItem);
}

BOOL CBasePlayer::RemovePlayerItem(CBasePlayerItem *pItem)
{
	return RemovePlayerItem_(pItem);
}

int CBasePlayer::GiveAmmo(int iAmount,char *szName,int iMax)
{
	return GiveAmmo_(iAmount,szName,iMax);
}

const char *CBasePlayer::TeamID(void)
{
	return TeamID_();
}

BOOL CBasePlayer::FBecomeProne(void)
{
	return FBecomeProne_();
}

int CBasePlayer::Illumination(void)
{
	return Illumination_();
}

void CBasePlayer::ResetMaxSpeed(void)
{
	ResetMaxSpeed_();
}

void CBasePlayer::Jump(void)
{
	Jump_();
}

void CBasePlayer::Duck(void)
{
	Duck_();
}

void CBasePlayer::PreThink(void)
{
	PreThink_();
}

void CBasePlayer::PostThink(void)
{
	PostThink_();
}

Vector CBasePlayer::GetGunPosition(void)
{
	return GetGunPosition_();
}

void CBasePlayer::UpdateClientData(void)
{
	UpdateClientData_();
}

void CBasePlayer::ImpulseCommands(void)
{
	ImpulseCommands_();
}

void CBasePlayer::RoundRespawn(void)
{
	RoundRespawn_();
}

Vector CBasePlayer::GetAutoaimVector(float flDelta)
{
	return GetAutoaimVector_(flDelta);
}

void CBasePlayer::Blind(float flUntilTime,float flHoldTime,float flFadeTime,int iAlpha)
{
	Blind_(flUntilTime,flHoldTime,flFadeTime,iAlpha);
}

void CStripWeapons::Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value)
{
	Use_(pActivator, pCaller, useType, value);
}

void CRevertSaved::KeyValue(KeyValueData *pkvd)
{
	KeyValue_(pkvd);
}

int CRevertSaved::Save(CSave &save)
{
	return Save_(save);
}

int CRevertSaved::Restore(CRestore &restore)
{
	return Restore_(restore);
}

void CRevertSaved::Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value)
{
	Use_(pActivator, pCaller, useType, value);
}

void CDeadHEV::Spawn(void)
{
	Spawn_();
}

void CDeadHEV::KeyValue(KeyValueData *pkvd)
{
	KeyValue_(pkvd);
}

int CDeadHEV::Classify(void)
{
	return Classify_();
}

void CSprayCan::Think(void)
{
	Think_();
}

void CInfoIntermission::Spawn(void)
{
	Spawn_();
}

void CInfoIntermission::Think(void)
{
	Think_();
}

void CWShield::Spawn(void)
{
	Spawn_();
}

void CWShield::Touch(CBaseEntity *pOther)
{
	Touch_(pOther);

}

#endif // HOOK_GAMEDLL
