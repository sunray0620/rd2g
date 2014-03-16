#include <iostream>
#include "ArrayUtil.cpp"

using namespace std;

int maxBetween(int a, int b) {
	return a >= b? a : b;
}

int minBetween(int a, int b) {
	return a <= b? a : b;
}

int maxSumSubArray(int *array, int sz) {
	int maxByHere = -1000000;
	int globalMax = maxByHere;
	int globalMaxStart = -1;
	int globalMaxEnd = -1;
	for (int i=0; i<sz; ++i) {
		if (maxByHere + array[i] >= array[i]) {
			maxByHere += array[i];
		} else {
			maxByHere = array[i];
			globalMaxStart = i;
		}
		if (maxByHere > globalMax) {
			globalMax = maxByHere;
			globalMaxEnd = i;
		}
	}
	cout << "Global Max Sum is " << globalMax << endl;
	cout << "From " << globalMaxStart << " to " << globalMaxEnd << endl;
}


int main() {
	int testDataSize = 10;
	int testData[testDataSize];
	generateRandomArray(testData, testDataSize, -testDataSize * 1, testDataSize * 1);

	printArray(testData, testDataSize);
	maxSumSubArray(testData, testDataSize);

}
