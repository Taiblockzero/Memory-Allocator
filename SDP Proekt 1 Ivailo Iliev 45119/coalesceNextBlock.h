#pragma once

//Checks if next block is free and if it is, coalesces (joins together) current block with the next one
//Argument cur points to first byte of the header of the current block
void coalesceNextBlock(char* cur);