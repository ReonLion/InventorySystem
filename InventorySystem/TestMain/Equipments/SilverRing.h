#pragma once

#include "../../Items/EquipmentBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class SilverRing : public EquipmentBase
{
public:
	SilverRing();
	~SilverRing();

	// ʰ�����
	void Pickup(Backpack* p_backpack, int quantity);

	// ���ߵ�����
	void Function() override;
};
