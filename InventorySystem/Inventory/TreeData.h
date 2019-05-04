#pragma once
#include <iostream>

using namespace std;

//----------------------------------------------------------------------------------------
// Abstract Class TreeData implements an abstract data type held by BinarySearchTree's
// nodes. Needs to implement these function:
// Compare two TreeData objects with <, ==, >, !=
//----------------------------------------------------------------------------------------

class TreeData
{

friend ostream& operator<<(ostream&, const TreeData &);

public:
	// Do nothing
	TreeData();
	// Do nothing
	~TreeData();

	// Return true if this TreeData object is smaller than the other one
	// Two TreeData object must can be compared
	virtual bool operator<(const TreeData & otherTreeData) const = 0;

	// Return true if this TreeData object is bigger than the other one
	virtual bool operator>(const TreeData & otherTreeData) const = 0;

	// Return true if Two TreeData objects are equal
	virtual bool operator==(const TreeData & otherTreeData) const = 0;

	// Return true if Two TreeData objects are not equal
	virtual bool operator!=(const TreeData & otherTreeData) const = 0;

	virtual void print(ostream &output) const = 0;

	// 克隆对象，在Item中override
	virtual TreeData* Clone() = 0;
};

