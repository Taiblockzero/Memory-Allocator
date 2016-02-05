#include "extendHeap.h"
#include "createHeap.h"
#include "coalescePrevBlock.h"
#include "constants.h"
#include <exception>
#include <iostream>

bool extendHeap()
{
	int oldHeapSize = heapSize;
	int newHeapSize = heapSize * 2;

	char* tempHeapPointer;
	try
	{
		tempHeapPointer = new char[newHeapSize];
	}
	catch (std::bad_alloc& ba)
	{
		return false;
	}

	//copy values of blocks from old heap to new heap
	for (int i = 0; i < oldHeapSize; ++i)
	{
		*(tempHeapPointer + i) = *(heap + i);
	}

	delete[] heap; //free old heap memory

	heap = tempHeapPointer;
	heapSize = newHeapSize;

	//now to set the blocksize of the new unused memory
	char* middle = heap + oldHeapSize; //middle points to the first byte of the new unused memory
	*((int*)middle) = newHeapSize - oldHeapSize;
	char* endFooter = heap + newHeapSize - INT_SIZE;
	*((int*)endFooter) = newHeapSize - oldHeapSize;

	coalescePrevBlock(middle);
	return true;
}