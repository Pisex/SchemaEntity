#pragma once
#include <entity2/entityidentity.h>
#include "mathlib/vector.h"
#include "schemasystem.h"
#include "ccollisionproperty.h"
#include "globaltypes.h"
#include "ctakedamageinfo.h"
#include "virtual.h"

extern CEntitySystem* g_pEntitySystem;

inline CEntityInstance* UTIL_GetEntityByIndex(int index)
{
	if(!g_pEntitySystem) return nullptr;
	CEntityIdentity* pEntity = g_pEntitySystem->m_EntityList.m_pFirstActiveEntity;

	for (; pEntity; pEntity = pEntity->m_pNext)
	{
		if (pEntity->m_EHandle.GetEntryIndex() == index)
			return pEntity->m_pInstance;
	};

	return nullptr;
}

inline CEntityInstance* UTIL_FindEntityByClassname(const char* name)
{
	if(!g_pEntitySystem) return nullptr;
	CEntityIdentity* pEntity = g_pEntitySystem->m_EntityList.m_pFirstActiveEntity;

	for (; pEntity; pEntity = pEntity->m_pNext)
	{
		if (!strcmp(pEntity->m_designerName.String(), name))
			return pEntity->m_pInstance;
	};

	return nullptr;
}

inline CEntityInstance* UTIL_FindEntityByEHandle(CEntityInstance* pFind)
{
	if(!g_pEntitySystem) return nullptr;
	CEntityIdentity* pEntity = g_pEntitySystem->m_EntityList.m_pFirstActiveEntity;

	for (; pEntity; pEntity = pEntity->m_pNext)
	{
		if (pEntity->GetRefEHandle() == pFind)
			return pEntity->m_pInstance;
	};

	return nullptr;
}

inline std::vector<CEntityInstance*> UTIL_FindEntityByClassnameAll(const char* name)
{
	if(!g_pEntitySystem) return {};
	CEntityIdentity* pEntity = g_pEntitySystem->m_EntityList.m_pFirstActiveEntity;
	std::vector<CEntityInstance*> entities;
	for (; pEntity; pEntity = pEntity->m_pNext)
	{
		if (!strcmp(pEntity->m_designerName.String(), name))
			entities.push_back(pEntity->m_pInstance);
	};
	return entities;
}

inline std::vector<CEntityInstance*> UTIL_FindAllEntitiesByDesignerName(const char* name)
{
	if(!g_pEntitySystem) return {};
	CEntityIdentity* pEntity = g_pEntitySystem->m_EntityList.m_pFirstActiveEntity;
	std::vector<CEntityInstance*> entities;
	for (; pEntity; pEntity = pEntity->m_pNext)
	{
		if (!pEntity->m_designerName.IsValid() || !strstr(pEntity->m_designerName.String(), "weapon_")) continue;
		entities.push_back(pEntity->m_pInstance);
	}
	return entities;
}
class CGameSceneNode
{
public:
	DECLARE_SCHEMA_CLASS(CGameSceneNode)

	SCHEMA_FIELD(CEntityInstance*, m_pOwner);
	SCHEMA_FIELD(CGameSceneNode*, m_pParent);
	SCHEMA_FIELD(CGameSceneNode*, m_pChild);
	SCHEMA_FIELD(CNetworkOriginCellCoordQuantizedVector, m_vecOrigin);
	SCHEMA_FIELD(QAngle, m_angRotation);
	SCHEMA_FIELD(float, m_flScale);
	SCHEMA_FIELD(float, m_flAbsScale);
	SCHEMA_FIELD(Vector, m_vecAbsOrigin);
	SCHEMA_FIELD(QAngle, m_angAbsRotation);
	SCHEMA_FIELD(Vector, m_vRenderOrigin);

	matrix3x4_t EntityToWorldTransform()
	{
		matrix3x4_t mat;

		QAngle angles = this->m_angAbsRotation();
		float sr, sp, sy, cr, cp, cy;
		SinCos(DEG2RAD(angles[YAW]), &sy, &cy);
		SinCos(DEG2RAD(angles[PITCH]), &sp, &cp);
		SinCos(DEG2RAD(angles[ROLL]), &sr, &cr);
		mat[0][0] = cp * cy;
		mat[1][0] = cp * sy;
		mat[2][0] = -sp;

		float crcy = cr * cy;
		float crsy = cr * sy;
		float srcy = sr * cy;
		float srsy = sr * sy;
		mat[0][1] = sp * srcy - crsy;
		mat[1][1] = sp * srsy + crcy;
		mat[2][1] = sr * cp;

		mat[0][2] = (sp * crcy + srsy);
		mat[1][2] = (sp * crsy - srcy);
		mat[2][2] = cr * cp;

		Vector pos = this->m_vecAbsOrigin();
		mat[0][3] = pos.x;
		mat[1][3] = pos.y;
		mat[2][3] = pos.z;

		return mat;
	}
};

class CBodyComponent
{
public:
	DECLARE_SCHEMA_CLASS(CBodyComponent)

	SCHEMA_FIELD(CGameSceneNode *, m_pSceneNode);
};

class CModelState
{
public:
	DECLARE_SCHEMA_CLASS(CModelState)

	SCHEMA_FIELD(CUtlSymbolLarge, m_ModelName)
	SCHEMA_FIELD(uint64, m_MeshGroupMask)
};

class CSkeletonInstance : public CGameSceneNode
{
public:
	DECLARE_SCHEMA_CLASS(CSkeletonInstance)

	SCHEMA_FIELD(CModelState, m_modelState)
};

class CEntitySubclassVDataBase
{
public:
	DECLARE_SCHEMA_CLASS(CEntitySubclassVDataBase)
};

class CBaseEntity : public CEntityInstance
{
public:
	DECLARE_SCHEMA_CLASS(CBaseEntity)

	SCHEMA_FIELD(float32, m_flSimulationTime)
	SCHEMA_FIELD(CBodyComponent *, m_CBodyComponent)
	SCHEMA_FIELD(CBitVec<64>, m_isSteadyState)
	SCHEMA_FIELD(float, m_lastNetworkChange)
	SCHEMA_FIELD_POINTER(CNetworkTransmitComponent, m_NetworkTransmitComponent)
	SCHEMA_FIELD(int, m_iHealth)
	SCHEMA_FIELD(int, m_iMaxHealth)
	SCHEMA_FIELD(int, m_iTeamNum)
	SCHEMA_FIELD(bool, m_bLagCompensate)
	SCHEMA_FIELD(Vector, m_vecAbsVelocity)
	SCHEMA_FIELD(Vector, m_vecBaseVelocity)
	SCHEMA_FIELD(CCollisionProperty*, m_pCollision)
	SCHEMA_FIELD(MoveCollide_t, m_MoveCollide)
	SCHEMA_FIELD(MoveType_t, m_MoveType)
	SCHEMA_FIELD(MoveType_t, m_nActualMoveType)
	SCHEMA_FIELD(CHandle<CBaseEntity>, m_hEffectEntity)
	SCHEMA_FIELD(uint32, m_spawnflags)
	SCHEMA_FIELD(uint32, m_fFlags)
	SCHEMA_FIELD(LifeState_t, m_lifeState)
	SCHEMA_FIELD(float, m_flDamageAccumulator)
	SCHEMA_FIELD(bool, m_bTakesDamage)
	SCHEMA_FIELD(TakeDamageFlags_t, m_nTakeDamageFlags)
	SCHEMA_FIELD_POINTER(CUtlStringToken, m_nSubclassID)
	SCHEMA_FIELD(float, m_flFriction)
	SCHEMA_FIELD(float, m_flGravityScale)
	SCHEMA_FIELD(float, m_flActualGravityScale)
	SCHEMA_FIELD(float, m_flTimeScale)
	SCHEMA_FIELD(float, m_flSpeed)
	SCHEMA_FIELD(CUtlString, m_sUniqueHammerID)
	SCHEMA_FIELD(CUtlSymbolLarge, m_target)
	SCHEMA_FIELD(CUtlSymbolLarge, m_iGlobalname)
	SCHEMA_FIELD(CHandle<CBaseEntity>, m_hOwnerEntity)
	SCHEMA_FIELD(uint32, m_fEffects)
	SCHEMA_FIELD(QAngle, m_vecAngVelocity)

	int entindex() { return m_pEntity->m_EHandle.GetEntryIndex(); }

	Vector GetAbsOrigin() { return m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin; }
	QAngle GetAngRotation() { return m_CBodyComponent->m_pSceneNode->m_angRotation; }
	QAngle GetAbsRotation() { return m_CBodyComponent->m_pSceneNode->m_angAbsRotation; }
	Vector GetAbsVelocity() { return m_vecAbsVelocity; }
	void SetAbsOrigin(Vector vecOrigin) { m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin(vecOrigin); }
	void SetAbsRotation(QAngle angAbsRotation) { m_CBodyComponent->m_pSceneNode->m_angAbsRotation(angAbsRotation); }
	void SetAngRotation(QAngle angRotation) { m_CBodyComponent->m_pSceneNode->m_angRotation(angRotation); }
	CEntitySubclassVDataBase* GetVData() { return *(CEntitySubclassVDataBase**)((uint8*)(m_nSubclassID()) + 4); }

	void SetAbsVelocity(Vector vecVelocity) { m_vecAbsVelocity = vecVelocity; }
	void SetBaseVelocity(Vector vecVelocity) { m_vecBaseVelocity = vecVelocity; }

	void Teleport(const Vector *position, const QAngle *angles, const Vector *velocity)
	{
		CALL_VIRTUAL(void, 167, this, position, angles, velocity);
	}
	
	void SetMoveType(MoveType_t nMoveType)
	{
		m_MoveType() = nMoveType;
		m_nActualMoveType() = nMoveType;
	}

	void TakeDamage(int iDamage)
	{
		m_iHealth(m_iHealth() - iDamage);
	}

	uint8 GetCollisionGroup()
	{
		if (!m_pCollision())
			return 0;

		return m_pCollision->m_collisionAttribute().m_nCollisionGroup;
	}

	void SetCollisionGroup(uint8 nCollisionGroup = COLLISION_GROUP_DEBRIS)
	{
		if (!m_pCollision())
			return;

		m_pCollision->m_collisionAttribute().m_nCollisionGroup = nCollisionGroup;
		m_pCollision->m_CollisionGroup = nCollisionGroup;
		CollisionRulesChanged();
	}

	void CollisionRulesChanged()
	{
		CALL_VIRTUAL(void, 190, this);
	}

	int GetTeam() { return m_iTeamNum(); }

	bool IsAlive() { return m_lifeState() == LifeState_t::LIFE_ALIVE; }

	CHandle<CBaseEntity> GetHandle() { return m_pEntity->m_EHandle; }

	// A double pointer to entity VData is available 4 bytes past m_nSubclassID, if applicable
	// CEntitySubclassVDataBase* GetVData() { return *(CEntitySubclassVDataBase**)((uint8*)(m_nSubclassID()) + 4); }

	const char* GetName() const { return m_pEntity->m_name.String(); }
};

class CBodyComponentSkeletonInstance : public CBodyComponent
{
public:	
	DECLARE_SCHEMA_CLASS(CBodyComponentSkeletonInstance);
};

class CBaseAnimGraphController
{
public:
	DECLARE_SCHEMA_CLASS_INLINE(CBaseAnimGraphController);

	SCHEMA_FIELD(float, m_flPlaybackRate);
};

class CBodyComponentBaseAnimGraph : public CBodyComponentSkeletonInstance
{
public:
	DECLARE_SCHEMA_CLASS(CBodyComponentBaseAnimGraph);

	SCHEMA_FIELD(CBaseAnimGraphController, m_animationController);
};

class SpawnPoint : public CBaseEntity
{
public:
	DECLARE_SCHEMA_CLASS(SpawnPoint);

	SCHEMA_FIELD(bool, m_bEnabled);
};