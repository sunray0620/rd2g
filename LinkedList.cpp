#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedListUtil.cpp"

using namespace std;

void playJosephCircle(const int numOfPlayers, const int stepSize) {
	// Construct the initial line
	Node* head = 0;
	for (int i = 0; i < numOfPlayers; ++i) {
		head = insertFromTail(head, i+1);
	}

	// Connect tail to head to make it a circular line
	Node* itr = 0;
	for (itr = head; itr->next != 0; itr = itr->next);
	itr->next = head;

	// Start playing from head
	while (itr->next->next != itr->next) {
		for (int i = 1; i < stepSize; ++i, itr = itr->next);

		// Delete this node
		Node* tbd = itr->next;
		itr->next = itr->next->next;

		// Print current status
		printf("Delete node [%d]; \n", tbd->data);
	}

	return;
}

int main() {
	playJosephCircle(10, 7);

	return 0;
}


