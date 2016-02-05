#include "constants.h"
#include "bestFit.h"
#include "createHeap.h"

int bestFit(size_t size)
{
	char* pCur; //pointer to current location in heap
	//size needed for memory block to be returned + boundary tags + padding
	int req8ByteBlocks = (size + 2 * INT_SIZE + (ALIGNMENT - 1)) / ALIGNMENT;
	int reqBytes = 8 * req8ByteBlocks;
	int difference = -1;
	int bSize; //Block size
	int bestFitIndex;
	int minDifference = heapSize + 1; //so that it's bigger than any (bSize - size)

	for (int i = 0; i < heapSize; )
	{
		//pCur is used so that the pointer arithmetic increases adress with (sizeof(char*) * i) bytes instead of (sizeof(int*) * i)
		pCur = heap + i;
		bSize = ((*((int*)pCur)) & -2); //mask out lowest bit so we get true size


		if (false == ((*((int*)pCur)) & 1)) //if block is free
		{
			if (bSize >= reqBytes)
			{
				if (bSize == reqBytes)
				{
					return i;
				}
				else //bSize > reqBytes
				{
					difference = bSize - reqBytes;
					if (difference < minDifference)
					{
						minDifference = difference;
						bestFitIndex = i;
					}
				}
			}
		}

		i = i + ((*((int*)pCur)) & -2); //mask out lowest bit so we get true size
	}

	if (-1 == difference) //if this is true then there isn't a suitable block to return
		return -1;

	//If we have gotten to here, then bestFit-ting block is bigger than needed so we will split it into two blocks
	char* freeBlockHeader = heap + bestFitIndex;
	int freeBlockSize = *((int*)freeBlockHeader);
	int firstBlockSize = freeBlockSize - minDifference;
	int secondBlockSize = minDifference;

	char* firstBlockHeader = freeBlockHeader;
	*((int*)firstBlockHeader) = firstBlockSize;
	
	char* firstBlockFooter = firstBlockHeader + firstBlockSize - INT_SIZE;
	*((int*)firstBlockFooter) = firstBlockSize;

	//Memory is rounded up to 8 bytes and required bytes is always (something*8) so if there is a block we have to split, its second
	//part will always have atleast 8 bytes if there is a second block, so there will always be space for boundary tags on it
	char* secondBlockHeader = firstBlockHeader + firstBlockSize;
	*((int*)secondBlockHeader) = secondBlockSize;

	char* secondBlockFooter = secondBlockHeader + secondBlockSize - INT_SIZE;
	*((int*)secondBlockFooter) = secondBlockSize;


	return bestFitIndex;
}