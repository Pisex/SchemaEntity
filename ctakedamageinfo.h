#pragma once
#include <platform.h>
#include "ehandle.h"

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

class CTakeDamageInfo
{
private:
	[[maybe_unused]] uint8_t __pad0000[0x8];
public:
	Vector m_vecDamageForce;
	Vector m_vecDamagePosition;
	Vector m_vecReportedPosition;
	Vector m_vecDamageDirection;
	CHandle<CBaseEntity> m_hInflictor;
	CHandle<CBaseEntity> m_hAttacker;
	CHandle<CBaseEntity> m_hAbility;
	float m_flDamage;
	float m_flTotalledDamage;
	float m_flTotalledDamageAbsorbed;
	DamageTypes_t m_bitsDamageType;
	int32_t m_iDamageCustom;
	uint8_t m_iAmmoType;

private:
	[[maybe_unused]] uint8_t __pad0059[0xf];

public:
	float m_flOriginalDamage;
	bool m_bShouldBleed;
	bool m_bShouldSpark;

private:
	[[maybe_unused]] uint8_t __pad006e[0x2];

public:
	float m_flDamageAbsorbed;

private:
	[[maybe_unused]] uint8_t __pad0074[0x8];

public:
	TakeDamageFlags_t m_nDamageFlags;

private:
	[[maybe_unused]] uint8_t __pad0084[0x4];

public:
	int32_t m_nNumObjectsPenetrated;
	float m_flFriendlyFireDamageReductionRatio;
	uint64_t m_hScriptInstance;
	AttackerInfo_t m_AttackerInfo;
	bool m_bInTakeDamageFlow;

private:
	[[maybe_unused]] uint8_t __pad00ad[0x4];
};

struct CTakeDamageInfoContainer
{
	CTakeDamageInfo* pInfo;
};