#pragma once

#include "../../Items/ClothBase.h"
#include "../../Backpack/Backpack.h"
#include <string.h>

class OldRobe : public ClothBase
{
public:
	OldRobe();
	~OldRobe();

	// ʰ�����
	void Pickup(Backpack* p_backpack, int quantity);

	// ���ߵ�����
	void Function() override;
};
