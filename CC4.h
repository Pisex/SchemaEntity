#pragma once
#include <entity2/entityidentity.h>
#include "schemasystem.h"

class CC4
{
public:
	DECLARE_SCHEMA_CLASS(CC4);

	SCHEMA_FIELD(GameTime_t, m_fArmedTime);
};