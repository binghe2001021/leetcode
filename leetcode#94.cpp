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
	vector<int> ans;
	void dfs(TreeNode* root){
		if (root == NULL) return;
		dfs(root->left);
		ans.push_back(root->val);
		dfs(root->right);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		ans.resize(0);
		dfs(root);
		return ans;
	}
};
int main(){
	Solution sol; 
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	a->right = b;
	b->left = c;
	vector<int> res = sol.inorderTraversal(a);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	system("pause");
}