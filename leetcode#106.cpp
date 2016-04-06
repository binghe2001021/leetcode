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
	TreeNode* build(vector<int>& postorder, vector<int>& inorder, int k, int l, int r){
		if (k < 0 || l > r) return NULL;
		TreeNode* root = new TreeNode(postorder[k]);
		if (l == r) return root;
		for (int i = l; i <= r; i++)
			if (inorder[i] == postorder[k]){
				if (i > l)
					root->left = build(postorder, inorder, k - (r - i) - 1, l, i - 1);
				if (i < r)
					root->right = build(postorder, inorder, k - 1, i + 1, r);
			}
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		len = postorder.size();
		TreeNode* root = build(postorder, inorder, len - 1, 0, len - 1);
	}
};
int main(){
	Solution sol; 
	system("pause");
}