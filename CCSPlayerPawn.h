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
public:
	DECLARE_SCHEMA_CLASS_INLINE(EntitySpottedState_t);

	SCHEMA_FIELD(bool, m_bSpotted)
	SCHEMA_FIELD_POINTER(uint32_t, m_bSpottedByMask)
};

class CCSPlayerPawnBase : public CBasePlayerPawn
{
public:
	DECLARE_SCHEMA_CLASS(CCSPlayerPawnBase);
	
	SCHEMA_FIELD(QAngle, m_angEyeAngles)
	SCHEMA_FIELD(CSPlayerState, m_iPlayerState)
	SCHEMA_FIELD(CHandle<CCSPlayerController>, m_hOriginalController)
	SCHEMA_FIELD(int32_t, m_iProgressBarDuration);
	SCHEMA_FIELD(CPlayer_ViewModelServices*, m_pViewModelServices)
	SCHEMA_FIELD(EntitySpottedState_t, m_entitySpottedState)
	SCHEMA_FIELD(float, m_flFlashDuration)
	SCHEMA_FIELD(float, m_flFlashMaxAlpha)
	SCHEMA_FIELD(GameTime_t, m_blindUntilTime)
	SCHEMA_FIELD(GameTime_t, m_blindStartTime)
	
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

	SCHEMA_FIELD(CEconItemView, m_EconGloves);
	SCHEMA_FIELD(float, m_flVelocityModifier);
	SCHEMA_FIELD(CCSPlayer_ActionTrackingServices*, m_pActionTrackingServices);
	SCHEMA_FIELD(GameTime_t, m_flHealthShotBoostExpirationTime);
	SCHEMA_FIELD(int32_t, m_ArmorValue);
	SCHEMA_FIELD(bool, m_bInBuyZone);
};