#pragma once
#include "CBaseEntity.h"
#include "globaltypes.h"

class CSkyCamera : public CBaseEntity
{
public:
	DECLARE_SCHEMA_CLASS(CSkyCamera)
	SCHEMA_FIELD(CUtlStringToken, m_skyboxSlotToken);
};