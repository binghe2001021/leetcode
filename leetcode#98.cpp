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
	stack<int> q;
	bool dfs(TreeNode* root){
		if (root == NULL) return true;
		if (!dfs(root->left)) return false;
		if (!q.empty() && root->val <= q.top()) return false;
		else q.push(root->val);
		if (!dfs(root->right)) return false;
		return true;
	}
	bool isValidBST(TreeNode* root) {
		return dfs(root);
	}
};
int main(){
	Solution sol; 
	system("pause");
}