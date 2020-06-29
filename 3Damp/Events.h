#pragma once
#include "GmeObject.h"
#include "List.h"

namespace Events {
	extern void (*OnFrame)();
	extern void (*OnObjectUpdate)(GmeObject*);
	extern void (*OnKeyDown)(unsigned char);
	extern void (*OnKeyUp)(unsigned char);
	extern void (*OnKeyDepressed)(unsigned char);

	void KeyPressedDown(unsigned char C, int x, int y);
	void KeyReleased(unsigned char C, int x, int y);
	void DoKeys();
}