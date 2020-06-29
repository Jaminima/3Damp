#include "List.h"

void List::Add(void* Obj) {
	Item* N = new Item();

	N->Next = Head;
	N->Obj = Obj;

	Head = N;
	if (N->Next!=0x0) N->Next->Prev = Head;
	Len++;
}

void List::Remove(Item* Itm) {
	Len--;
	if (Head == Itm) {
		Head = Itm->Next;
		if (Head) Head->Prev = 0x0;
	}
	else Itm->Remove();
}

void Item::Remove() {
	if (Next) Next->Prev = Prev;
	if (Prev) Prev->Next = Next;
}

void* List::ToArray() {
	void** Data = new void*[Len];

	unsigned int i = 0;
	Item* t = Head;
	while (t != 0x0) {
		Data[i] = t->Obj;
		t = t->Next;
		i++;
	}

	return Data;
}