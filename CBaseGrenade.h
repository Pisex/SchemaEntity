#pragma once
#include "CBaseModelEntity.h"
#include "CBasePlayerPawn.h"
#include "globaltypes.h"

class CBaseGrenade : public CBaseModelEntity
{
public:
	DECLARE_SCHEMA_CLASS(CBaseGrenade);
	SCHEMA_FIELD(CHandle<CCSPlayerPawn>, m_hThrower);
};

class CBaseCSGrenadeProjectile : public CBaseGrenade
{
public:
	DECLARE_SCHEMA_CLASS(CBaseCSGrenadeProjectile);
};

class CSmokeGrenadeProjectile : public CBaseCSGrenadeProjectile
{
public:
	DECLARE_SCHEMA_CLASS(CSmokeGrenadeProjectile);
	SCHEMA_FIELD(Vector, m_vSmokeColor);
};