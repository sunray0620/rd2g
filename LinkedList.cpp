#include <cstdlib>
#include <ctime>
#include "LinkedListUtil.cpp"

using namespace std;

int main() {
	srand(time(0));
	int testDataSize = 100;
	Node* head = 0;
	for (int i=0; i<testDataSize; ++i) {
		head = insertFromTail(head, rand()%(testDataSize*10));
	}
	printLinkedList(head, true);

	return 0;
}
