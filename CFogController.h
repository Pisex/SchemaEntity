#pragma once
#include "CBaseEntity.h"

struct fogparams_t
{
public:
    DECLARE_SCHEMA_CLASS_INLINE(fogparams_t)

    SCHEMA_FIELD(Vector, dirPrimary);
    SCHEMA_FIELD(Color, colorPrimary);
    SCHEMA_FIELD(Color, colorSecondary);
    SCHEMA_FIELD(Color, colorPrimaryLerpTo);
    SCHEMA_FIELD(Color, colorSecondaryLerpTo);
    SCHEMA_FIELD(float32, start);
    SCHEMA_FIELD(float32, end);
    SCHEMA_FIELD(float32, farz);
    SCHEMA_FIELD(float32, maxdensity);
    SCHEMA_FIELD(float32, exponent);
    SCHEMA_FIELD(float32, HDRColorScale);
    SCHEMA_FIELD(float32, skyboxFogFactor);
    SCHEMA_FIELD(float32, skyboxFogFactorLerpTo);
    SCHEMA_FIELD(float32, startLerpTo);
    SCHEMA_FIELD(float32, endLerpTo);
    SCHEMA_FIELD(float32, maxdensityLerpTo);
    SCHEMA_FIELD(GameTime_t, lerptime);
    SCHEMA_FIELD(float32, duration);
    SCHEMA_FIELD(float32, blendtobackground);
    SCHEMA_FIELD(float32, scattering);
    SCHEMA_FIELD(float32, locallightscale);
    SCHEMA_FIELD(bool, enable);
    SCHEMA_FIELD(bool, blend);
    SCHEMA_FIELD(bool, m_bPadding2);
    SCHEMA_FIELD(bool, m_bPadding);
};

class CFogController : public CBaseEntity
{
public:
	DECLARE_SCHEMA_CLASS(CFogController)

	SCHEMA_FIELD(fogparams_t, m_fog);
	SCHEMA_FIELD(bool, m_bUseAngles);
	SCHEMA_FIELD(int32, m_iChangedVariables);
};