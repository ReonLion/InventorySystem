#pragma once

#include "../../Items/EquipmentBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class CopperRing : public EquipmentBase
{
public:
	CopperRing();
	~CopperRing();

	// ʰ�����
	void Pickup(Backpack* p_backpack, int quantity);

	// ���ߵ�����
	void Function() override;
};
