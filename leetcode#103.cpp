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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		queue<pair<TreeNode*, bool>> q;
		vector<vector<int>> ans(0);
		if (root == NULL) return ans;
		vector<int> a(0);
		vector<int> temp(0);
		bool pan = true;
		q.push(make_pair(root, true));
		while (!q.empty()){
			TreeNode* now = q.front().first;
			bool p = q.front().second;
			q.pop();
			if (p != pan){
				if (p){
					temp.clear();
					for (int i = a.size() - 1; i >= 0; i--)
						temp.push_back(a[i]);
					ans.push_back(temp);
				}
				else
					ans.push_back(a);
				pan = p;
				a.clear();
			}
			if (now->left != NULL) q.push(make_pair(now->left, !p));
			if (now->right != NULL) q.push(make_pair(now->right, !p));
			a.push_back(now->val);
		}
		if (!pan){
			temp.clear();
			for (int i = a.size() - 1; i >= 0; i--)
				temp.push_back(a[i]);
			ans.push_back(temp);
		}
		else
			ans.push_back(a);
		return ans;
	}
};
int main(){
	cout << a.front();
	Solution sol; 
	system("pause");
}