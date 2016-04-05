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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		int cnt = 0;
		ListNode* a = new ListNode(1);
		a->next = head;
		head = a;
		ListNode* tar, *lst, *nxt, *i;
		for (i = head; i != NULL && cnt<n; i = nxt){
			cnt++;
			cout << cnt << endl;
			nxt = i->next;
			if (cnt == m){
				tar = i;
			}
			if (cnt > m + 1){
				i->next = lst;
			}
			lst = i;
		}
		if (tar->next != i){
			tar->next->next = i->next;
			i->next = lst;
			tar->next = i;
		}
		return head->next;
	}
};
int main(){
	Solution sol; 
	system("pause");
}