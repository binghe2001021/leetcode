#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ans;
		ListNode* head;
		int k=0;
		ans = new ListNode(0);
		head = ans;
		while (l1!= NULL || l2!= NULL){
			int n1, n2;
			if (l1 != NULL)
				n1 = l1->val;
			else
				n1 = 0;
			if (l2 != NULL)
				n2 = l2->val;
			else
				n2 = 0;
			ans->val = n1 + n2 + k;
			k = ans->val / 10;
			ans->val %= 10;
			if (l1!=NULL)
				l1 = l1->next;
			if (l2!=NULL)
				l2 = l2->next;
			if (l1 == NULL && l2 == NULL)
				break;
			ans->next = new ListNode(0);
			ans = ans->next;
		}
		if (k != 0){
			ans->next = new ListNode(0);
			ans = ans->next;
			ans->val = k;
			k = 0;
		}
		return head;
	}
};

int main()
{
	Solution s;
	system("pause");
}