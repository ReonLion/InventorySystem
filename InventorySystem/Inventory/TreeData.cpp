#include "TreeData.h"

TreeData::TreeData()
{
}


TreeData::~TreeData()
{
}

ostream & operator<<(ostream &output, const TreeData &t)
{
	t.print(output);
	return output;
}
