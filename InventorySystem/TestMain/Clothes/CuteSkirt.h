#pragma once

#include "../../Items/ClothBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class CuteSkirt : public ClothBase
{
public:
	CuteSkirt();
	~CuteSkirt();

	// ʰ�����
	void Pickup(Backpack* p_backpack, int quantity);

	// ���ߵ�����
	void Function() override;
};
