#include "GridItem.h"
GridItem::GridItem(const char& s)
{
	symbol = s;
}

const char GridItem::get_symbol() 
{
	return symbol;
};