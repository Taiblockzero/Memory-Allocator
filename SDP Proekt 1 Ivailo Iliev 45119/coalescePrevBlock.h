#pragma once
#include "createHeap.h"

//Checks if previous block is free and if it is, coalesces (joins together) current block with the previous one
//Argument cur points to first byte of the header of the current block
void coalescePrevBlock(char* cur);