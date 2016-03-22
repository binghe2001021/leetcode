#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#define maxn 222222
#define Mint 111111111
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* lst = NULL;
		for (ListNode* i = head; i!=NULL && i->next != NULL; i = i->next){
			ListNode* j = i->next;
			ListNode* temp = j->next;
			j->next = i;
			i->next = temp;
			if (i == head)
				head = j;
			else
				lst->next = j;
			lst = i;
		}
		return head;
	}
};
int main()
{
	Solution sol;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	sol.swapPairs(head);
	system("pause");
}