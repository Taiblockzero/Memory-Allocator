#include "coalesceNextBlock.h"
#include <iostream>
#include "constants.h"
#include "createHeap.h"

void coalesceNextBlock(char* cur)
{
	int curSize = *((int*)cur);
	if (true == (curSize & 1))
	{
		std::cout << "Why would you even want to coalesce a not-free block???\n";
		return;
	}

	//if next block is beyond end of heap, don't touch it!
	char* nextHeader = cur + curSize;
	if (nextHeader > (heap + heapSize))
		return;
	

	int nextSize = *((int*)nextHeader);
	
	if (true == (nextSize & 1)) //check if next is not-free
		return;


	int newBlockSize = curSize + nextSize;
	char* newBlockHeader = cur;
	char* newBlockFooter = nextHeader + nextSize - INT_SIZE;


	*((int*)newBlockHeader) = newBlockSize;
	*((int*)newBlockFooter) = newBlockSize;
}