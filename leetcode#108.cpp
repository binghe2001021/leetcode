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
	TreeNode* build(vector<int> nums, int l, int r){
		if (l > r) return NULL;
		TreeNode* root = new TreeNode(nums[(l + r) / 2]);
		if (l == r) return root;
		root->left = build(nums, l, (l + r) / 2 - 1);
		root->right = build(nums, (l + r) / 2 + 1, r);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		len = nums.size();
		TreeNode* root;
		root = build(nums, 0, len - 1);
		return root;
	}
};
int main(){
	Solution sol; 
	system("pause");
}