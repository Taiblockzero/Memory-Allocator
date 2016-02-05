#include "coalescePrevBlock.h"
#include "constants.h"
#include <iostream>
#include "createHeap.h"

void coalescePrevBlock(char* cur)
{

	//if previous block is before start of heap, don't touch it!
	char* prevFooter = cur - INT_SIZE;
	if (prevFooter < heap)
		return;


	int prevSize = *((int*)prevFooter);
	
	if (true == (prevSize & 1)) //check if prev is not free
		return;

	char* prevHeader = cur - prevSize;
	
	int curSize = *((int*)cur);
	if (true == (curSize & 1))
	{
		std::cout << "Why would you even want to coalesce a not-free block???\n";
		return;
	}

	int newBlockSize = prevSize + curSize;
	char* newBlockHeader = prevHeader;
	char* newBlockFooter = newBlockHeader + newBlockSize - INT_SIZE;


	*((int*)newBlockHeader) = newBlockSize;
	*((int*)newBlockFooter) = newBlockSize;
}