#pragma once

#include "CBaseEntity.h"
#include"schemasystem.h"

#define SF_TRIG_PUSH_ONCE 0x80

class CEnvEntityMaker : public CBaseEntity
{
public:
	DECLARE_SCHEMA_CLASS(CEnvEntityMaker);

	SCHEMA_FIELD(CUtlSymbolLarge, m_iszTemplate)
};