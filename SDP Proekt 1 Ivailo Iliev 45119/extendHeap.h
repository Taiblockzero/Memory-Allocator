#pragma once

//Makes new twice as big heap and copies over values from old heap
//Returns true if succeeds, false if bad_alloc exception
//In my current implementation, if you use this twice in a row, the heapsize will be too big for int and it will fuck up
bool extendHeap();