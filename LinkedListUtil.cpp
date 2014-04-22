#include <cstdio>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
	Node(int _data, Node* _next, Node* _prev): data(_data), next(_next), prev(_prev) {}
};

void printLinkedList(Node* head, bool withIndex) {
	if (head == 0) {
		printf("Empty List!\n");
		return;
	}
	int index = 0;
	for (Node *itr = head; itr != 0; itr = itr->next) {
		if (withIndex) {
			printf(" [%d:%d] ", index, itr->data);
		} else {
			printf(" [%d] ", itr->data);
		}
		++index;
		if (index % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

Node* insertFromHead(Node* head, int dv) {
	head = new Node(dv, head, 0);
	return head;
}

Node* insertFromTail(Node* head, int dv) {
	Node** pItr = &head;
	for ( ; *pItr != 0; pItr = &((*pItr)->next));
	*pItr = new Node(dv, 0, 0);
	return head;
}

