#include "Events.h"

void (*Events::OnFrame)();
void (*Events::OnObjectUpdate)(GmeObject*);
void (*Events::OnKeyDown)(unsigned char);
void (*Events::OnKeyUp)(unsigned char);
void (*Events::OnKeyDepressed)(unsigned char);

List ActiveKeys;

void Events::DoKeys() {
	Item* I = ActiveKeys.Head;
	unsigned char _C;

	while (I != 0x0) {
		_C = *(unsigned char*)I->Obj;
		OnKeyDepressed(_C);
		I = I->Next;
	}
}

void Events::KeyPressedDown(unsigned char C, int x, int y) {
	Item* I = ActiveKeys.Head;
	unsigned char _C;

	while (I != 0x0) {
		_C = *(unsigned char*)I->Obj;
		if (_C == C) { return; }
		I = I->Next;
	}

	if (OnKeyDown) OnKeyDown(C);
	ActiveKeys.Add(new unsigned char(C));
}

void Events::KeyReleased(unsigned char C, int x, int y) {
	Item* I = ActiveKeys.Head;

	while (I != 0x0) {
		if (*(unsigned char*)I->Obj == C) { 
			ActiveKeys.Remove(I); }
		I = I->Next;
	}

	if (OnKeyUp) OnKeyUp(C);
}