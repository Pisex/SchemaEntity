#pragma once

#include "CBaseEntity.h"
#include "virtual.h"

enum gear_slot_t : uint32_t
{
	GEAR_SLOT_INVALID = 0xffffffff,
	GEAR_SLOT_RIFLE = 0x0,
	GEAR_SLOT_PISTOL = 0x1,
	GEAR_SLOT_KNIFE = 0x2,
	GEAR_SLOT_GRENADES = 0x3,
	GEAR_SLOT_C4 = 0x4,
	GEAR_SLOT_RESERVED_SLOT6 = 0x5,
	GEAR_SLOT_RESERVED_SLOT7 = 0x6,
	GEAR_SLOT_RESERVED_SLOT8 = 0x7,
	GEAR_SLOT_RESERVED_SLOT9 = 0x8,
	GEAR_SLOT_RESERVED_SLOT10 = 0x9,
	GEAR_SLOT_RESERVED_SLOT11 = 0xa,
	GEAR_SLOT_BOOSTS = 0xb,
	GEAR_SLOT_UTILITY = 0xc,
	GEAR_SLOT_COUNT = 0xd,
	GEAR_SLOT_FIRST = 0x0,
	GEAR_SLOT_LAST = 0xc,
};

class CAttributeManager
{
public:
	DECLARE_SCHEMA_CLASS_INLINE(CAttributeManager);
	SCHEMA_FIELD_POINTER(CUtlVector<CAttributeManager>, m_CachedResults);
};

class CEconItemAttribute
{
public:
    DECLARE_SCHEMA_CLASS_INLINE(CEconItemAttribute);
    SCHEMA_FIELD(uint16_t, m_iAttributeDefinitionIndex);
    SCHEMA_FIELD(int, m_flValue);
    SCHEMA_FIELD(int, m_flInitialValue);
    SCHEMA_FIELD(int32_t, m_nRefundableCurrency);
    SCHEMA_FIELD(bool, m_bSetBonus);
};

class CAttributeList
{
public:
    DECLARE_SCHEMA_CLASS_INLINE(CAttributeList);
    SCHEMA_FIELD_POINTER(CUtlVector<CEconItemAttribute>, m_Attributes);
    SCHEMA_FIELD(CAttributeManager*, m_pManager);
};

class CEconItemView
{
public:
	DECLARE_SCHEMA_CLASS_INLINE(CEconItemView);

	SCHEMA_FIELD(uint16, m_iItemDefinitionIndex)
	SCHEMA_FIELD(int32, m_iEntityQuality)
	SCHEMA_FIELD(uint32, m_iEntityLevel)
	SCHEMA_FIELD(uint64, m_iItemID)
	SCHEMA_FIELD(uint32, m_iItemIDHigh)
	SCHEMA_FIELD(uint32, m_iItemIDLow)
	SCHEMA_FIELD(uint32, m_iAccountID)
	SCHEMA_FIELD(uint32, m_iInventoryPosition)
	SCHEMA_FIELD(bool, m_bInitialized)
	SCHEMA_FIELD(CAttributeList, m_AttributeList)
	SCHEMA_FIELD(CAttributeList, m_NetworkedDynamicAttributes)
	SCHEMA_FIELD_POINTER(char, m_szCustomName)
	SCHEMA_FIELD_POINTER(char, m_szCustomNameOverride)
};

class CAttributeContainer
{
public:
	DECLARE_SCHEMA_CLASS_INLINE(CAttributeContainer);

	SCHEMA_FIELD(CEconItemView, m_Item)
};

class CEconEntity : public CBaseEntity
{
public:
	DECLARE_SCHEMA_CLASS(CEconEntity)

	SCHEMA_FIELD(CAttributeContainer, m_AttributeManager)
	SCHEMA_FIELD(uint32, m_OriginalOwnerXuidLow)
	SCHEMA_FIELD(uint32, m_OriginalOwnerXuidHigh)
	SCHEMA_FIELD(int32, m_nFallbackPaintKit)
	SCHEMA_FIELD(int32, m_nFallbackSeed)
	SCHEMA_FIELD(float, m_flFallbackWear)
	SCHEMA_FIELD(int32, m_nFallbackStatTrak)
};

class CBasePlayerWeaponVData : public CEntitySubclassVDataBase
{
public:
	DECLARE_SCHEMA_CLASS(CBasePlayerWeaponVData)
	SCHEMA_FIELD(int, m_iMaxClip1)
	SCHEMA_FIELD(int, m_iDefaultClip1)
};

class CCSWeaponBaseVData : public CBasePlayerWeaponVData
{
public:
	DECLARE_SCHEMA_CLASS(CCSWeaponBaseVData)

	SCHEMA_FIELD(gear_slot_t, m_GearSlot)
	SCHEMA_FIELD(int, m_nPrice)
	SCHEMA_FIELD(CUtlString, m_szName)
	SCHEMA_FIELD(int, m_nPrimaryReserveAmmoMax);
};

class CBasePlayerWeapon : public CEconEntity
{
public:
	DECLARE_SCHEMA_CLASS(CBasePlayerWeapon)
	
	SCHEMA_FIELD(GameTick_t, m_nNextPrimaryAttackTick);
	SCHEMA_FIELD(float, m_flNextPrimaryAttackTickRatio);
	SCHEMA_FIELD(GameTick_t, m_nNextSecondaryAttackTick);
	SCHEMA_FIELD(float, m_flNextSecondaryAttackTickRatio);

    SCHEMA_FIELD(int32_t, m_iClip1);
    SCHEMA_FIELD_POINTER(int32_t, m_pReserveAmmo);

	CCSWeaponBaseVData* GetWeaponVData() { return (CCSWeaponBaseVData*)GetVData(); }
};

class CCSWeaponBase : public CBasePlayerWeapon
{
public:
	DECLARE_SCHEMA_CLASS(CCSWeaponBase)
};


class CWeaponBaseItem : public CCSWeaponBase
{
public:
	DECLARE_SCHEMA_CLASS(CWeaponBaseItem)
};

class CCSWeaponBaseGun : public CCSWeaponBase
{
public:
	DECLARE_SCHEMA_CLASS(CCSWeaponBaseGun)
};