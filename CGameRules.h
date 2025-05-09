#pragma once
#include <platform.h>
#include "globaltypes.h"
#include "CBaseEntity.h"

class CGameRules
{
public:
	DECLARE_SCHEMA_CLASS(CGameRules)
};

class CCSGameModeRules_Deathmatch : public CGameRules
{
public:
	DECLARE_SCHEMA_CLASS(CCSGameModeRules_Deathmatch)

	SCHEMA_FIELD(GameTime_t, m_flDMBonusStartTime);
	SCHEMA_FIELD(float32, m_flDMBonusTimeLength);
	SCHEMA_FIELD(CUtlString, m_sDMBonusWeapon);
};

class CCSGameRules : public CGameRules
{
public:
	DECLARE_SCHEMA_CLASS(CCSGameRules)

	SCHEMA_FIELD(float, m_fMatchStartTime);
	SCHEMA_FIELD(float, m_flGameStartTime);
	SCHEMA_FIELD(int, m_totalRoundsPlayed);
	SCHEMA_FIELD(GameTime_t, m_fRoundStartTime);
	SCHEMA_FIELD(GameTime_t, m_flRestartRoundTime);
	SCHEMA_FIELD_POINTER(int, m_nEndMatchMapGroupVoteOptions)
	SCHEMA_FIELD(int, m_nEndMatchMapVoteWinner);
	SCHEMA_FIELD(int, m_iRoundTime);
	SCHEMA_FIELD(bool, m_bWarmupPeriod);
	SCHEMA_FIELD(GamePhase, m_gamePhase);
	SCHEMA_FIELD(bool, m_bGameRestart);
	SCHEMA_FIELD(bool, m_bBombPlanted);
	SCHEMA_FIELD(int32_t, m_totaArenaoundsPlayed);
	SCHEMA_FIELD(int32_t, m_nOvertimePlaying);
	SCHEMA_FIELD(bool, m_bBuyTimeEnded);
	SCHEMA_FIELD(bool, m_bTCantBuy);
	SCHEMA_FIELD(bool, m_bCTCantBuy);
	SCHEMA_FIELD(bool, m_bSwitchingTeamsAtRoundReset);
	SCHEMA_FIELD(int, m_iRoundEndWinnerTeam);
	SCHEMA_FIELD(CUtlString, m_sRoundEndMessage);
	SCHEMA_FIELD(CUtlString, m_sRoundEndFunFactToken);
	SCHEMA_FIELD_POINTER(CUtlVector<SpawnPoint*>, m_CTSpawnPoints);
	SCHEMA_FIELD_POINTER(CUtlVector<SpawnPoint*>, m_TerroristSpawnPoints);
};

class CCSGameRulesProxy : public CBaseEntity
{
public:
	DECLARE_SCHEMA_CLASS(CCSGameRulesProxy)

	SCHEMA_FIELD(CCSGameRules *, m_pGameRules);
};