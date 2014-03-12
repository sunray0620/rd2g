#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

void swapElement(int *array, int i, int j) {
	int swap = array[i];
	array[i] = array[j];
	array[j] = swap;
}

void insertSort(int *array, int sz) {
	for (int i=1; i<sz; ++i) {
		int tbi = array[i];
		int j = i-1;
		for (; j>=0 && array[j]>tbi; --j) {
			array[j+1] = array[j];
		}
		array[j+1] = tbi;
	}
}

void bubbleSort(int *array, int sz) {
	for (int i=sz-1; i>=0; --i) {
		for (int j=0; j<i; ++j) {
			if (array[j] > array[j+1]) {
				swapElement(array, j, j+1);
			}
		}
	}
}

void printArray(int *array, int sz) {
	for(int i=0; i<sz; ++i) {
		printf("[%d] ", array[i]);
	}
	cout << endl;
}

bool validateSortedArray(int *array, int sz) {
	if (sz <= 0) return false;
	if (sz == 1) return true;
	for (int i=1; i<sz; ++i) {
		if (array[i] < array[i-1]) {
			return false;
		}
	}
	return true;
}

int main() {
	srand(time(0));
	int testDataSize = 100;
	int testData[testDataSize];

	for(int i=0; i<testDataSize; ++i) {
		testData[i] = rand() % (testDataSize * 100);
	}

	printArray(testData, testDataSize);
	cout << validateSortedArray(testData, testDataSize) << endl;

	bubbleSort(testData, testDataSize);
	printArray(testData, testDataSize);
	cout << validateSortedArray(testData, testDataSize) << endl;

	return 0;
}
