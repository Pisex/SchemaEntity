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
    
	const char* GetModelName()
	{
		return ((CSkeletonInstance*)m_CBodyComponent->m_pSceneNode.Get())->m_modelState().m_ModelName.Get().String();
	}
};

class CBaseProp : public CBaseModelEntity
{
public:
};