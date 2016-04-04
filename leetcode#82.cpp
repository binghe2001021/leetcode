#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#define maxn 1111
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* lst = NULL;
		for (ListNode* i = head; i != NULL;){
			ListNode* j = i->next;
			bool p = true;
			while (j != NULL && j->val == i->val) {
				p = false; j = j->next;
			}
			if (!p){
				if (lst == NULL)
					head = j;
				else
					lst->next = j;
			}
			else{
				lst = i;
			}
			i = j;
		}
		return head;
	}
};

int main(){
	Solution sol; 
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(3);
	ListNode *e = new ListNode(4);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	sol.deleteDuplicates(a);
	system("pause");
}