#pragma once
class Item {
public:
	void* Obj;
	Item* Next=0x0;
};

class List {
public:
	Item* Head=0x0;

	void Add(void* Obj);
};