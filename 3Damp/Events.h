#pragma once
#include "GmeObject.h"

namespace Events {
	extern void (*OnFrame)();
	extern void (*OnObjectUpdate)(GmeObject*);
}