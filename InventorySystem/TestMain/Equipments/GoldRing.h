#pragma once

#include "../../Items/EquipmentBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class GoldRing : public EquipmentBase
{
public:
	GoldRing();
	~GoldRing();

	// ʰ�����
	void Pickup(Backpack* p_backpack, int quantity);

	// ���ߵ�����
	void Function() override;
};
