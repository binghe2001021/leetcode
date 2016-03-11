#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool operator < (ListNode a, ListNode b){
	return a.val > b.val;
}

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return NULL;
		priority_queue<ListNode> heap;
		for (int i = 0; i < lists.size(); i++)
			if (lists[i]!=NULL) heap.push(*lists[i]);
		if (heap.empty()) return NULL;
		ListNode *ans = new ListNode(heap.top().val);
		ListNode *tail = ans;
		while (!heap.empty()){
			ListNode temp = heap.top();
			heap.pop();
			if (temp.next!=NULL) heap.push(*(temp.next));
			if(!heap.empty()) tail->next = new ListNode(heap.top().val);
			tail = tail->next;
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	
	system("pause");
}
