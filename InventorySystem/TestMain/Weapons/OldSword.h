#pragma once

#include "../../Items/WeaponBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class OldSword : public WeaponBase
{
public:
	OldSword();
	~OldSword();

	// ʰ�����
	void Pickup(Backpack* p_backpack, int quantity);

	// ���ߵ�����
	void Function() override;
};
