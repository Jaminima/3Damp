#include "List.h"

void List::Add(void* Obj) {
	Item* N = new Item();

	N->Next = Head;
	N->Obj = Obj;

	Head = N;
}