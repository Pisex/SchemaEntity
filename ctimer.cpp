#include "ctimer.h"

CUtlVector<CTimerBase*> g_timers;

void RemoveTimers()
{
	g_timers.PurgeAndDeleteElements();
}