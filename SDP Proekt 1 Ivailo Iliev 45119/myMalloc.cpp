#include "myMalloc.h"
#include "bestFit.h"
#include "extendHeap.h"
#include "constants.h"

char* myMalloc(size_t size)
{

	int bfResult = bestFit(size); //result of bestFit() function
	while (-1 == bfResult)
	{
		//In my current implementation, if you use extendHeap twice in a row, the heapsize will be too big for int and it will fuck up
		//I could change it to long, but it would take a lot of time to change all the code linked to heapSize and also boundary tags
		//would have to become of size long(or whatever size i choose for heapSize)
		if (false == extendHeap())
			return 0;
		bfResult = bestFit(size);
	}

	char* bfbHeader = heap + bfResult; //pointer to bestFit block
	int bfbSize = *((int*)bfbHeader);

	//set bfb's boundary tags as not-free
	*((int*)bfbHeader) = (bfbSize | 1);
	char* bfbFooter = bfbHeader + bfbSize - INT_SIZE;
	*((int*)bfbFooter) = (bfbSize | 1);

	char* result = bfbHeader + INT_SIZE;
	return result;
	
}