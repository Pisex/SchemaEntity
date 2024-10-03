/**
 * =============================================================================
 * CS2Fixes
 * Copyright (C) 2023-2024 Source2ZE
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include <platform.h>
#include "ehandle.h"

enum DamageTypes_t : uint32_t
{
	DMG_GENERIC = 0x0,
	DMG_CRUSH = 0x1,
	DMG_BULLET = 0x2,
	DMG_SLASH = 0x4,
	DMG_BURN = 0x8,
	DMG_VEHICLE = 0x10,
	DMG_FALL = 0x20,
	DMG_BLAST = 0x40,
	DMG_CLUB = 0x80,
	DMG_SHOCK = 0x100,
	DMG_SONIC = 0x200,
	DMG_ENERGYBEAM = 0x400,
	DMG_DROWN = 0x4000,
	DMG_POISON = 0x8000,
	DMG_RADIATION = 0x10000,
	DMG_DROWNRECOVER = 0x20000,
	DMG_ACID = 0x40000,
	DMG_PHYSGUN = 0x100000,
	DMG_DISSOLVE = 0x200000,
	DMG_BLAST_SURFACE = 0x400000,
	DMG_BUCKSHOT = 0x1000000,
	DMG_LASTGENERICFLAG = 0x1000000,
	DMG_HEADSHOT = 0x2000000,
	DMG_DANGERZONE = 0x4000000,
};

enum TakeDamageFlags_t : uint32_t
{
	DFLAG_NONE = 0x0,
	DFLAG_SUPPRESS_HEALTH_CHANGES = 0x1,
	DFLAG_SUPPRESS_PHYSICS_FORCE = 0x2,
	DFLAG_SUPPRESS_EFFECTS = 0x4,
	DFLAG_PREVENT_DEATH = 0x8,
	DFLAG_FORCE_DEATH = 0x10,
	DFLAG_ALWAYS_GIB = 0x20,
	DFLAG_NEVER_GIB = 0x40,
	DFLAG_REMOVE_NO_RAGDOLL = 0x80,
	DFLAG_SUPPRESS_DAMAGE_MODIFICATION = 0x100,
	DFLAG_ALWAYS_FIRE_DAMAGE_EVENTS = 0x200,
	DFLAG_RADIUS_DMG = 0x400,
	DMG_LASTDFLAG = 0x400,
	DFLAG_IGNORE_ARMOR = 0x800,
};

struct AmmoIndex_t
{
public:
	int8_t m_Value;
};

class CTakeDamageInfo
{
private:
	[[maybe_unused]] uint8_t __pad0000[0x8]; // 0x0
public:
	Vector m_vecDamageForce; // 0x8	
	Vector m_vecDamagePosition; // 0x14	
	Vector m_vecReportedPosition; // 0x20	
	Vector m_vecDamageDirection; // 0x2c	
	CHandle< CBaseEntity > m_hInflictor; // 0x38	
	CHandle< CBaseEntity > m_hAttacker; // 0x3c	
	CHandle< CBaseEntity > m_hAbility; // 0x40	
	float m_flDamage; // 0x44	
	float m_flTotalledDamage; // 0x48	
	float m_flTotalledDamageAbsorbed; // 0x4c	
	DamageTypes_t m_bitsDamageType; // 0x50	
	int32_t m_iDamageCustom; // 0x54	
	AmmoIndex_t m_iAmmoType; // 0x58	
private:
	[[maybe_unused]] uint8_t __pad0059[0xf]; // 0x59
public:
	float m_flOriginalDamage; // 0x68	
	bool m_bShouldBleed; // 0x6c	
	bool m_bShouldSpark; // 0x6d	
private:
	[[maybe_unused]] uint8_t __pad006e[0x2]; // 0x6e
public:
	float m_flDamageAbsorbed; // 0x70	
private:
	[[maybe_unused]] uint8_t __pad0074[0xc]; // 0x74
public:
	TakeDamageFlags_t m_nDamageFlags; // 0x80	
	int32_t m_nNumObjectsPenetrated; // 0x88	
	float m_flFriendlyFireDamageReductionRatio; // 0x8c	
	HSCRIPT m_hScriptInstance; // 0x90	
private:
	[[maybe_unused]] uint8_t __pad0098[0x14]; // 0x98
public:
	bool m_bInTakeDamageFlow; // 0xac
};

struct CTakeDamageInfoContainer
{
	CTakeDamageInfo *pInfo;
};