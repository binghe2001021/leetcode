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
	int len;
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int k, int l, int r){
		if (k >= preorder.size() || l > r) return NULL;
		TreeNode* root = new TreeNode(preorder[k]);
		if (l == r) return root;
		for (int i = l; i <= r; i++)
			if (inorder[i] == preorder[k]){
				if (i > l)
					root->left = build(preorder, inorder, k + 1, l, i - 1);
				if (i < r)
					root->right = build(preorder, inorder, k + i - l + 1, i + 1, r);
			}
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		len = inorder.size();
		TreeNode* root = build(preorder, inorder, 0, 0, len - 1);
	}
};
int main(){
	Solution sol; 
	system("pause");
}