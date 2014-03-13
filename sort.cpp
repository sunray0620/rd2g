#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include "ArrayUtil.cpp"

using namespace std;

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

void _mergeSort(int* array, int start, int end) {
	if (end == start) {
		return;
	}
	int mid = (start + end) / 2;
	_mergeSort(array, start, mid);
	_mergeSort(array, mid+1, end);

	int buf[end-start+1];
	// Merge
	int ai = start;
	int bi = mid+1;
	while (ai <= mid && bi <= end) {
		if (array[ai] <= array[bi]) {
			buf[ai+bi-start-mid-1] = array[ai];
			++ai;
		} else {
			buf[ai+bi-start-mid-1] = array[bi];
			++bi;
		}
	}
	for (; ai <= mid; ++ai) {
		buf[ai+bi-start-mid-1] = array[ai];
	}
	for (; bi <= end; ++bi) {
		buf[ai+bi-start-mid-1] = array[bi];
	}

	// Copy to buffer first
	for (int i=start; i<=end; ++i) {
		array[i] = buf[i-start];	
	}
}

int getDigit(int input, int i) {
	if (i < 0 || i > 8) {
		return -1;
	}
	int a = pow(10, i);
	int b = pow(10, i-1);
	return input % a / b;
}

void radixSort(int *array, int sz) {
	bool finished = false;
	for(int dp=1; !finished; ++dp) {
		vector<int> temp[10];
		//
		for(int i=0; i<sz; ++i) {
			int digit = getDigit(array[i], dp);
			temp[digit].push_back(array[i]);
		}
		// Determine if it is finished
		finished = (temp[0].size() == sz);
		// Copy Back
		int pos = 0;
		for(int i=0; i<10; ++i) {
			for(int j=0; j<temp[i].size(); ++j) {
				array[pos++] = temp[i][j];
			}
		}
	}
}

int getParent(int child) {
	return (child-1) / 2;
}

int getLeftChild(int parent) {
	return parent * 2 + 1;
}

int getRightChild(int parent) {
	return parent * 2 + 2;
}

int siftUp(int *array, int sz, int pos) {
	int cur = pos;
	for (int p = getParent(cur); p >= 0 && array[p] < array[cur]; ) {
		swapElement(array, p, cur);
		cur = p;
		p = getParent(cur);
	}
}

int siftDown(int *array, int sz, int pos) {
	int cur = pos;
	for (int swapChild=cur; cur < sz;) {
		int leftChild = getLeftChild(cur);
		if (leftChild < sz && array[leftChild] > array[swapChild]) {
			swapChild = leftChild;
		}
		int rightChild = getRightChild(cur);
		if (rightChild < sz && array[rightChild] > array[swapChild]) {
			swapChild = rightChild;
		}
		if (swapChild == cur) {
			break;
		}
		swapElement(array, cur, swapChild);
		cur = swapChild;
	}
}

void heapSort(int *array, int sz) {
	// Make Sort
	for (int i=0; i<sz; ++i) {
		siftUp(array, sz, i);
	}
	// Sort
	for (int i=sz-1; i>=0; --i) {
		swapElement(array, 0, i);
		siftDown(array, i, 0);
	}
}

int main() {
	srand(time(0));
	int testDataSize = 100;
	int testData[testDataSize];
	generateRandomArray(testData, testDataSize, testDataSize * 100);

	printArray(testData, testDataSize);
	cout << validateSortedArray(testData, testDataSize) << endl;

	heapSort(testData, testDataSize);
	printArray(testData, testDataSize);
	cout << validateSortedArray(testData, testDataSize) << endl;
	return 0;
}
