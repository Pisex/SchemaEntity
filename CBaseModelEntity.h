#pragma once
#include "CBaseEntity.h"
#include "globaltypes.h"

class CBaseModelEntity : public CBaseEntity
{
public:
	DECLARE_SCHEMA_CLASS(CBaseModelEntity);

	SCHEMA_FIELD(CCollisionProperty , m_Collision)
	SCHEMA_FIELD(CGlowProperty, m_Glow)
	SCHEMA_FIELD(Color, m_clrRender)
	SCHEMA_FIELD(RenderMode_t, m_nRenderMode)
	SCHEMA_FIELD(float, m_flDissolveStartTime)
	SCHEMA_FIELD(Vector, m_vecViewOffset)
    
	CUtlSymbolLarge GetModelName()
	{
		if(m_CBodyComponent == nullptr) return CUtlSymbolLarge();
		if(m_CBodyComponent->m_pSceneNode == nullptr) return CUtlSymbolLarge();
		if(((CSkeletonInstance*)m_CBodyComponent->m_pSceneNode.Get()) == nullptr) return CUtlSymbolLarge();
		return ((CSkeletonInstance*)m_CBodyComponent->m_pSceneNode.Get())->m_modelState().m_ModelName.Get();
	}

	Vector GetEyePosition()
	{
		const auto x = m_vecViewOffset();
		return x + GetAbsOrigin();
	}
};

class CBaseProp : public CBaseModelEntity
{
public:
	DECLARE_SCHEMA_CLASS(CBaseProp);
};

class CBeam : public CBaseModelEntity
{
public:
	DECLARE_SCHEMA_CLASS(CBeam);
    SCHEMA_FIELD(Vector, m_vecEndPos);
    SCHEMA_FIELD(float, m_fWidth);
};