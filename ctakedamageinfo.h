#pragma once
#include <platform.h>
#include "ehandle.h"

class CTakeDamageInfo
{
	DECLARE_SCHEMA_CLASS_INLINE(CTakeDamageInfo)

	SCHEMA_FIELD(Vector, m_vecDamageForce);	
	SCHEMA_FIELD(Vector, m_vecDamagePosition);	
	SCHEMA_FIELD(Vector, m_vecReportedPosition);	
	SCHEMA_FIELD(Vector, m_vecDamageDirection);	
	SCHEMA_FIELD(CHandle<CBaseEntity>, m_hInflictor);	
	SCHEMA_FIELD(CHandle<CBaseEntity>, m_hAttacker);	
	SCHEMA_FIELD(CHandle<CBaseEntity>, m_hAbility);	
	SCHEMA_FIELD(float, m_flDamage);	
	SCHEMA_FIELD(float, m_flTotalledDamage);	
	SCHEMA_FIELD(float, m_flTotalledDamageAbsorbed);	
	SCHEMA_FIELD(DamageTypes_t, m_bitsDamageType);	
	SCHEMA_FIELD(int32_t, m_iDamageCustom);	
	SCHEMA_FIELD(AmmoIndex_t, m_iAmmoType);	
	SCHEMA_FIELD(float, m_flOriginalDamage);
	SCHEMA_FIELD(bool, m_bShouldBleed);
	SCHEMA_FIELD(bool, m_bShouldSpark);
	SCHEMA_FIELD(float, m_flDamageAbsorbed);
	SCHEMA_FIELD(TakeDamageFlags_t, m_nDamageFlags);
	SCHEMA_FIELD(int32_t, m_nNumObjectsPenetrated);
	SCHEMA_FIELD(float, m_flFriendlyFireDamageReductionRatio);
	SCHEMA_FIELD(bool, m_bInTakeDamageFlow);
};

struct CTakeDamageInfoContainer
{
	CTakeDamageInfo* pInfo;
};