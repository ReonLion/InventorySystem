#include "Item.h"

Item::Item()
{
}


Item::~Item()
{
}

Item::Item(ItemType type)
{
	this->type = type;
}

void Item::SetType(ItemType type)
{
	this->type = type;
}

void Item::SetId(int id)
{
	this->id = id;
}

void Item::SetConsumable(bool bConsumable)
{
	this->bConsumable = bConsumable;
}

void Item::SetName(string name)
{
	this->name = name;
}

ItemType Item::GetType() const
{
	return this->type;
}

int Item::GetId() const
{
	return this->id;
}

bool Item::IsConsumable() const
{
	return this->bConsumable;
}

string Item::GetName() const
{
	return this->name;
}

bool Item::operator<(const TreeData & otherTreeData) const
{
	const Item & item = static_cast<const Item &>(otherTreeData);
	// 两个item类别不一样，抛出异常
	if (this->type != item.type)
		throw "Compare Two Different Item Type!\n";
	return this->id < item.id;
}

bool Item::operator>(const TreeData & otherTreeData) const
{
	const Item & item = static_cast<const Item &>(otherTreeData);
	return item < *this;
}

bool Item::operator==(const TreeData & otherTreeData) const
{
	const Item & item = static_cast<const Item &>(otherTreeData);
	// 两个item类别不一样，返回false
	if (this->type != item.type)
		return false;
	return this->id == item.id;
}

bool Item::operator!=(const TreeData & otherTreeData) const
{
	const Item & item = static_cast<const Item &>(otherTreeData);
	// 两个item类别不一样，返回false
	if (this->type != item.type)
		return false;
	return !(*this == item);
}

void Item::print(ostream & output) const
{
	std::cout << name;
}

Item * Item::Clone()
{
	return new Item(*this);
}

void Item::Function()
{
	std::cout << "You shouldn't see this!!!\n";
}

