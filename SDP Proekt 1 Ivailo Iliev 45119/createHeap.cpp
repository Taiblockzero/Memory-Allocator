#include "createHeap.h"
#include "constants.h"

char* heap;
int heapSize;
void createHeap()
{
	heapSize = 1000000000; //heapSize should be a product of the ALIGNMENT constant (in our case 8)	
	heap = new char[heapSize];
	*((int*)heap) = heapSize;
	char* footer = heap + heapSize - INT_SIZE;
	*((int*)footer) = heapSize;
}