#pragma once

#include "CBaseModelEntity.h"
#include "schemasystem.h"

#define SF_TRIG_PUSH_ONCE 0x80

class CBaseTrigger : public CBaseModelEntity
{
public:
	DECLARE_SCHEMA_CLASS(CBaseTrigger);

	SCHEMA_FIELD(CUtlSymbolLarge, m_iFilterName)
	SCHEMA_FIELD(CEntityHandle, m_hFilter)
	SCHEMA_FIELD_POINTER(CUtlVector<CHandle<CBaseEntity>>, m_hTouchingEntities)
	SCHEMA_FIELD(bool, m_bClientSidePredicted)
};