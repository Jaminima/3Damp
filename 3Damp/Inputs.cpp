#include "Events.h"

int mX = WIDTH/2;
int mY = HEIGHT/2;

List ActiveKeys;

void Events::MouseMovedInWindow(int x, int y) {
	if (Events::OnMouseMove) Events::OnMouseMove(x - mX, y - mY);

	if (LockMouse) glutWarpPointer(WIDTH / 2, HEIGHT / 2);
	else {
		mX = x;
		mY = y;
	}
}

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
			ActiveKeys.Remove(I);
		}
		I = I->Next;
	}

	if (OnKeyUp) OnKeyUp(C);
}