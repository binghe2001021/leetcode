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
	ListNode* partition(ListNode* head, int x) {
		ListNode* newhead1 = NULL;
		ListNode* newhead2 = NULL;
		ListNode* tail1 = NULL;
		ListNode* tail2 = NULL;
		for (ListNode* i = head; i != NULL; i = i->next){
			if (i->val < x){
				if (newhead1 == NULL){
					newhead1 = new ListNode(i->val);
					tail1 = newhead1;
				}
				else
				{
					tail1->next = new ListNode(i->val);
					tail1 = tail1->next;
				}
			}
			else
			{
				if (newhead2 == NULL){
					newhead2 = new ListNode(i->val);
					tail2 = newhead2;
				}
				else
				{
					tail2->next = new ListNode(i->val);
					tail2 = tail2->next;
				}
			}
		}
		if (newhead1 == NULL) return newhead2;
		tail1->next = newhead2;
		return newhead1;
	}
};
int main(){
	Solution sol; 
	system("pause");
}