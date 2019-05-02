#pragma once

//----------------------------------------------------------------------------------------
// Abstract Class TreeData implements an abstract data type held by BinarySearchTree's
// nodes. Needs to implement these function:
// Compare two TreeData objects with <, ==, >, !=
//----------------------------------------------------------------------------------------

class TreeData
{
public:
	// Do nothing
	TreeData();
	// Do nothing
	~TreeData();

	// Return true if this TreeData object is smaller than the other one
	// Two TreeData object must can be compared
	virtual bool operator<(const TreeData &) const = 0;

	// Return true if this TreeData object is bigger than the other one
	virtual bool operator>(const TreeData &) const = 0;

	// Return true if Two TreeData objects are equal
	virtual bool operator==(const TreeData &) const = 0;

	// Return true if Two TreeData objects are not equal
	virtual bool operator!=(const TreeData &) const = 0;
};

