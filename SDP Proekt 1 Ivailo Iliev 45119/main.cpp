#include <iostream>
#include "createHeap.h"
#include "myMalloc.h"
#include "myFree.h"

int main()
{
	createHeap();

	//Dadenite testove v zadanieto na proekta
	int* pArr1 = (int*)myMalloc(100 * sizeof(int));
	int* pArr2 = (int*)myMalloc(100 * sizeof(int));
	pArr1[0] = pArr2[0] = 10;
	myFree((char*)pArr1);
	myFree((char*)pArr2);

	
	//Allocate 10 times and free 10 times
	char* a = myMalloc(2);
	char* b = myMalloc(34);
	char* c = myMalloc(1);
	char* d = myMalloc(809);
	char* e = myMalloc(90);
	char* f = myMalloc(66);
	char* g = myMalloc(101);
	char* h = myMalloc(10000);
	char* i = myMalloc(13247);
	char* j = myMalloc(100001);

	myFree(a);
	myFree(b);
	myFree(c);
	myFree(d);
	myFree(e);
	myFree(f);
	myFree(g);
	myFree(h);
	myFree(i);
	myFree(j);



	//Allocate and then free twice
	char* a1 = myMalloc(14098);
	myFree(a1);
	myFree(a1);


	//Fill up heap and then allocate, THIS DOESN'T WORK BECAUSE OLD POINTERS (a2 in this case) WILL NOT BE UPDATED TO 
	//POINT TO NEW LOCATION
	char* a2 = myMalloc(1000000000);
	char* a3 = myMalloc(5000000);
	//myFree(a2);
	myFree(a3);

	//Extending heap still has uses, for example to allocate a GIANT piece of memory
	char* a4 = myMalloc(1500000000); //This doesn't succeed because extending heap fails and myMalloc returns NULL
	myFree(a4);

	return 0;
}