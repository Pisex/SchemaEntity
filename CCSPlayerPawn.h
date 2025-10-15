#pragma once
#include "ehandle.h"
#include "CCSPlayerController.h"
#include "CBasePlayerPawn.h"
#include "services.h"
#include "CCSWeaponBase.h"

enum CSPlayerState
{
	STATE_ACTIVE = 0x0,
	STATE_WELCOME = 0x1,
	STATE_PICKINGTEAM = 0x2,
	STATE_PICKINGCLASS = 0x3,
	STATE_DEATH_ANIM = 0x4,
	STATE_DEATH_WAIT_FOR_KEY = 0x5,
	STATE_OBSERVER_MODE = 0x6,
	STATE_GUNGAME_RESPAWN = 0x7,
	STATE_DORMANT = 0x8,
	NUM_PLAYER_STATES = 0x9,
};

class CCSPlayerController;

struct EntitySpottedState_t
{
private:
    [[maybe_unused]] std::uint8_t __pad0000[ 0x8 ]; // 0x0
public:
    // MNetworkEnable
    // MNetworkChangeCallback "OnIsSpottedChanged"
    bool m_bSpotted; // 0x8	
private:
    [[maybe_unused]] std::uint8_t __pad0009[ 0x3 ]; // 0x9
public:
    // MNetworkEnable
    // MNetworkChangeCallback "OnIsSpottedChanged"
    std::uint32_t m_bSpottedByMask[2]; // 0xc	
};

class CCSPlayerPawnBase : public CBasePlayerPawn
{
public:
	DECLARE_SCHEMA_CLASS(CCSPlayerPawnBase);
	
	SCHEMA_FIELD(CSPlayerState, m_iPlayerState)
	SCHEMA_FIELD(CHandle<CCSPlayerController>, m_hOriginalController)
	SCHEMA_FIELD(int32_t, m_iProgressBarDuration);
	SCHEMA_FIELD(CPlayer_ViewModelServices*, m_pViewModelServices)
	SCHEMA_FIELD(float, m_flFlashDuration)
	SCHEMA_FIELD(float, m_flFlashMaxAlpha)
	SCHEMA_FIELD(GameTime_t, m_blindUntilTime)
	SCHEMA_FIELD(GameTime_t, m_blindStartTime)
	SCHEMA_FIELD(GameTime_t, m_fImmuneToGunGameDamageTime)
	SCHEMA_FIELD(bool, m_bGunGameImmunity)
	
	CCSPlayerController *GetOriginalController()
	{
		return m_hOriginalController().Get();
	}

	bool IsBot()
	{
		return m_fFlags() & FL_PAWN_FAKECLIENT;
	}
};

class CCSPlayerPawn : public CCSPlayerPawnBase
{
public:
	DECLARE_SCHEMA_CLASS(CCSPlayerPawn);

	SCHEMA_FIELD(QAngle, m_angEyeAngles);
	SCHEMA_FIELD(CEconItemView, m_EconGloves);
	SCHEMA_FIELD(uint8, m_nEconGlovesChanged);
	SCHEMA_FIELD(uint16, m_nCharacterDefIndex);
	SCHEMA_FIELD(CUtlString, m_strVOPrefix);
	SCHEMA_FIELD(float, m_flVelocityModifier);
	SCHEMA_FIELD(CCSPlayer_ActionTrackingServices*, m_pActionTrackingServices);
	SCHEMA_FIELD(GameTime_t, m_flHealthShotBoostExpirationTime);
	SCHEMA_FIELD(int32, m_ArmorValue);
	SCHEMA_FIELD(bool, m_bInBuyZone);
	SCHEMA_FIELD(EntitySpottedState_t, m_entitySpottedState)
	SCHEMA_FIELD(int, m_aimPunchTickBase)
	SCHEMA_FIELD(float, m_aimPunchTickFraction)
	SCHEMA_FIELD(QAngle, m_aimPunchAngle)
	SCHEMA_FIELD(QAngle, m_aimPunchAngleVel)
};

class CCSGO_TeamPreviewCharacterPosition: public CBaseEntity
{
public:
	DECLARE_SCHEMA_CLASS(CCSGO_TeamPreviewCharacterPosition);
	
	SCHEMA_FIELD(int32, m_nVariant);
	SCHEMA_FIELD(int32, m_nRandom);
	SCHEMA_FIELD(int32, m_nOrdinal);
	SCHEMA_FIELD(CUtlString, m_sWeaponName);
	SCHEMA_FIELD(uint64, m_xuid);
	SCHEMA_FIELD_POINTER(CEconItemView, m_agentItem);
	SCHEMA_FIELD_POINTER(CEconItemView, m_glovesItem);
	SCHEMA_FIELD_POINTER(CEconItemView, m_weaponItem);
};