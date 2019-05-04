#pragma once

#include "../../Items/EquipmentBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class SilverRing : public EquipmentBase
{
public:
	SilverRing();
	~SilverRing();

	// 拾起道具
	void Pickup(Backpack* p_backpack, int quantity);

	// 道具的作用
	void Function() override;
};
