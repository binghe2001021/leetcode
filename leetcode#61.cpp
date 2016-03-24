#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL)
			return head;
		if (k == 0)
			return head;
		int c1 = 1, c2 = 0;
		ListNode* t1 = head;
		ListNode* t2 = head;
		while (t1->next != NULL){
			t1 = t1->next;
			c1++;
		}
		k %= c1;
		if (k == 0) k = c1;
		ListNode* lst = new ListNode(1);
		while (c2 != c1 - k){
			lst = t2;
			t2 = t2->next;
			c2++;
		}
		ListNode* temp = head;
		lst->next = t1->next;
		head = t2;
		if (k != 0) t1->next = temp;
		return head;
	}
};
int main()
{
	Solution sol;
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	a->next = b;
	ListNode *c = sol.rotateRight(a,3);
	printf("%d %d\n", c->val, c->next->val);
	system("pause");
}