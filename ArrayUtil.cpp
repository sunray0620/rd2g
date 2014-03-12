#include <iostream>
#include <cstdio>

using namespace std;

void swapElement(int *array, int i, int j) {
	int swap = array[i];
	array[i] = array[j];
	array[j] = swap;
}

void printArray(int *array, int sz, int numPerRow = 10) {
	for (int i=0; i<sz; ++i) {
		printf("[%d] ", array[i]);
		if ( (i+1) % numPerRow == 0 ) {
			cout << endl;
		}
	}
	if ( sz % numPerRow != 0 ) {
		cout << endl;	
	}
}
