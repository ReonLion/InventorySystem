#pragma once

#include "../../Items/WeaponBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class MagicSword : public WeaponBase
{
public:
	MagicSword();
	~MagicSword();

	// ʰ�����
	void Pickup(Backpack* p_backpack, int quantity);

	// ���ߵ�����
	void Function() override;
};
