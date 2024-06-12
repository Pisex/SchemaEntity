#pragma once
#include "CBaseEntity.h"

class CTeam : public CBaseEntity
{
public:
	DECLARE_SCHEMA_CLASS(CTeam)
	
	SCHEMA_FIELD(CUtlVector<CHandle<CBasePlayerController>>, m_aPlayerControllers);
	SCHEMA_FIELD(CUtlVector<CHandle<CBasePlayerPawn>>, m_aPlayers);

	SCHEMA_FIELD(int32_t, CTeam, m_iScore);
};