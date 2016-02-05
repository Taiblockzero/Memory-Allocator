#pragma once
#include "createHeap.h"


//My implementation of malloc() will find free memory blocks using "Implicit List" with "Boundary Tags", and will use
//"Best Fit" to decide which free block to allocate
//I chose: 
//Implicit list because it's good at using data locality, easy to implement; 
//Best fit because it will help keep external fragmentation low
//Boundary tags because it's the most convenient choice and we can spare some internal fragmentation
//Boundary tags will be int-sized so that we can allocate a lot of blocks at once with myMalloc()
char* myMalloc(size_t size);