#pragma once
#include <platform.h>
#include "ehandle.h"
#include "globaltypes.h"

class CBaseEntity;
class CCSPlayerPawn;

struct AttackerInfo_t
{
	bool m_bNeedInit;
	bool m_bIsPawn;
	bool m_bIsWorld;
	CHandle<CCSPlayerPawn> m_hAttackerPawn;
	uint16_t m_nAttackerPlayerSlot;
	int m_iTeamChecked;
	int m_nTeam;
};
static_assert(sizeof(AttackerInfo_t) == 20);

class CGameTrace;

class CTakeDamageInfo
{
public:
	DECLARE_SCHEMA_CLASS(CTakeDamageInfo)

	SCHEMA_FIELD(Vector, m_vecDamageForce);
	SCHEMA_FIELD(Vector, m_vecDamagePosition);
	SCHEMA_FIELD(Vector, m_vecReportedPosition);
	SCHEMA_FIELD(Vector, m_vecDamageDirection);
	SCHEMA_FIELD(CBaseHandle, m_hInflictor);
	SCHEMA_FIELD(CBaseHandle, m_hAttacker);
	SCHEMA_FIELD(CBaseHandle, m_hAbility);
	SCHEMA_FIELD(float, m_flDamage);
	SCHEMA_FIELD(float, m_flTotalledDamage);
	SCHEMA_FIELD(int32_t, m_bitsDamageType);
	SCHEMA_FIELD(int32_t, m_iDamageCustom);
	SCHEMA_FIELD(int8_t, m_iAmmoType);
	SCHEMA_FIELD(float, m_flOriginalDamage);
	SCHEMA_FIELD(bool, m_bShouldBleed);
	SCHEMA_FIELD(bool, m_bShouldSpark);
	SCHEMA_FIELD(float, m_flDamageAbsorbed);
	SCHEMA_FIELD(TakeDamageFlags_t, m_nDamageFlags);
	SCHEMA_FIELD(HitGroup_t, m_iHitGroupId);
	SCHEMA_FIELD(int32_t, m_nNumObjectsPenetrated);
	SCHEMA_FIELD(float, m_flFriendlyFireDamageReductionRatio);
	SCHEMA_FIELD(AttackerInfo_t, m_AttackerInfo);
	SCHEMA_FIELD(bool, m_bInTakeDamageFlow);
};

struct CTakeDamageInfoContainer
{
	DECLARE_SCHEMA_CLASS(CTakeDamageInfoContainer)

	SCHEMA_FIELD_POINTER(CTakeDamageInfo, m_DamageInfo);
};