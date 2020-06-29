#pragma once
class Item {
public:
	void* Obj;
	Item* Prev = 0x0;
	Item* Next = 0x0;

	void Remove();
};

class List {
public:
	Item* Head=0x0;

	void Add(void* Obj);

	void Remove(Item* Itm);
};