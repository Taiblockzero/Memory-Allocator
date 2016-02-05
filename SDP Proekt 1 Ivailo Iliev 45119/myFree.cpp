#include "myFree.h"
#include "constants.h"
#include "coalescePrevBlock.h"
#include "coalesceNextBlock.h"
#include <iostream>


void myFree(char* pBlock)
{
	//if myFree is used on NULL adress, then it does nothing
	if (pBlock == NULL)
		return;

	char* bHeader = pBlock - INT_SIZE;
	int bSize = *((int*)bHeader);
	if (false == (bSize & 1))
	{
		std::cout << "ERROR: Invalid block was passed to myFree(). It's invalid because it was either not allocated with myAlloc(), "
				  << "myFree() was already used on it, or something else made the memory block invalid.\n";
		return;
	}

	//clear lowest bit so that block is free
	bSize = (bSize & -2);
	*((int*)bHeader) = bSize;

	char* bFooter = bHeader + bSize - INT_SIZE;
	*((int*)bFooter) = bSize;
	
	//coalesce the newly-freed block with previous and/or next blocks if any of them are free
	coalesceNextBlock(bHeader);
	coalescePrevBlock(bHeader);
}