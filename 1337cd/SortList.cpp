/*
Sort Linked List with O(nlgn) time
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		return sort(head, 0);
	}

	ListNode *sort(ListNode *head, ListNode *end) {
		if (head == end || head->next == end) {
			return head;
		}
		//
		ListNode* pivot = head;
		ListNode** itr = &(head->next);
		while ((*itr) != end) {
			if((*itr)->val < pivot->val) {
				ListNode* tbr = *itr;
				*itr = (*itr)->next;
				tbr->next = head;
				head = tbr;
			} else if((*itr)->val == pivot->val) {
				ListNode* tbr = *itr;
				*itr = (*itr)->next;
				tbr->next = pivot->next;
				pivot->next = tbr;
			} else {
				itr = &((*itr)->next);
			}
		}
		//
		/*
		head = sort(head, pivot);

		ListNode** head2 = &(pivot->next);
		while(*head2 != end && (*head2)->val == pivot->val) {
			head2 = &((*head2)->next);
		}
		*head2 = sort(*head2, end);
		*/
		return head;
	}

private:

};

void printLL(ListNode* head) {
	for (ListNode* itr = head; itr != 0; itr = itr->next) {
		cout << " [" << itr->val << "] ";
	}
	cout << endl;
}

int main() {

	// Generate Test Data
	srand(time(0));
	int inputSize = 10;
	ListNode* head = 0;
	for(int i = 0; i < inputSize; ++i) {
		head = new ListNode(rand()%3, head);
	}

	// Print original data
	printLL(head);

	// Sort List
	head = (new Solution())->sortList(head);

	//Print result data
	printLL(head);

	return 0;
}
