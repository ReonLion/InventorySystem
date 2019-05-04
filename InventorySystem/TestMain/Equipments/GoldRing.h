#pragma once

#include "../../Items/EquipmentBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class GoldRing : public EquipmentBase
{
public:
	GoldRing();
	~GoldRing();

	// 拾起道具
	void Pickup(Backpack* p_backpack, int quantity);

	// 道具的作用
	void Function() override;
};
