#pragma once
class Inventory
{
public:
	Inventory();
	~Inventory();
private:
	enum InvenorySubType
	{
		WEAPON,
		EQUIPMENT,
		CLOTH,
		POTION
	};
};

