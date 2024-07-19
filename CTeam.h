#pragma once
#include "CBaseEntity.h"

class CTeam : public CBaseEntity
{
public:
	DECLARE_SCHEMA_CLASS(CTeam)

	SCHEMA_FIELD(int32_t, m_iScore);
};