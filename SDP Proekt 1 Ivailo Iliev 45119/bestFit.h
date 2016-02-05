#pragma once

//Returns heap index of bestFit-ting block's first byte and also splits the block if block size is bigger than needed block
//Returns -1 if there isn't a suitable block
int bestFit(size_t size);