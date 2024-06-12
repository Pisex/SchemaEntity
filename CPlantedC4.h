#pragma once
#include "CBaseModelEntity.h"
#include "globaltypes.h"

class CPlantedC4 : public CBaseModelEntity
{
public:
	DECLARE_SCHEMA_CLASS(CPlantedC4)

	SCHEMA_FIELD(GameTime_t, m_flC4Blow);
	SCHEMA_FIELD(GameTime_t, m_flDefuseCountDown);
};