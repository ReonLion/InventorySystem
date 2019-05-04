#pragma once

#include "../../Items/WeaponBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class RusstyAxe : public WeaponBase
{
public:
	RusstyAxe();
	~RusstyAxe();

	// 拾起道具
	void Pickup(Backpack* p_backpack, int quantity);

	// 道具的作用
	void Function() override;
};
