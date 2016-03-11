#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	TreeNode *target1, *target2;
public:
	int lowerbound(TreeNode* root){
		if (root == NULL) return -2147483647;
		if (root->right != NULL) return lowerbound(root->right);
		else return root->val;
	}
	int upperbound(TreeNode* root){
		if (root == NULL) return 2147483647;
		if (root->left != NULL) return upperbound(root->left);
		else return root->val;
	}
	TreeNode* biggest(TreeNode* root){
		if (root == NULL) return root;
		TreeNode *l = root->left;
		TreeNode *r = root->right;
		if (root->left != NULL)
			l = biggest(root->left);
		if (root->right != NULL)
			r = biggest(root->right);
		TreeNode *ans = root;
		if (l!=NULL && l->val > ans->val) ans = l;
		if (r!=NULL && r->val > ans->val) ans = r;
		return ans;
	}
	TreeNode* smallest(TreeNode* root){
		if (root == NULL) return root;
		TreeNode *l = root->left;
		TreeNode *r = root->right;
		if (root->left != NULL)
			l = smallest(root->left);
		if (root->right != NULL)
			r = smallest(root->right);
		TreeNode *ans = root;
		if (l!=NULL && l->val < ans->val) ans = l;
		if (r!=NULL && r->val < ans->val) ans = r;
		return ans;
	}
	void recoverTree(TreeNode* root) {
		bool p = false;
		int low = lowerbound(root->left);
		int upp = upperbound(root->right);
		TreeNode *lmax = biggest(root->left);
		TreeNode *rmin = smallest(root->right);
		if (low > root->val){
			p = true;
			target1 = root;
			target2 = lmax;
			if (target2 == NULL) target2 = new TreeNode(0);
		}
		if (upp < root->val){
			p = true;
			target1 = root;
			target2 = rmin;
			if (target2 == NULL) target2 = new TreeNode(0);
		}
		if (lmax!=NULL && rmin!=NULL && lmax->val > rmin->val){
			p = true;
			target1 = lmax;
			target2 = rmin;
		}
		if (p){
			int temp = target1->val;
			target1->val = target2->val;
			target2->val = temp;
			return;
		}
		if (root->left != NULL) recoverTree(root->left);
		if (root->right != NULL) recoverTree(root->right);
	}
};

int main()
{
	Solution sol;
	TreeNode *root = new TreeNode(1);
	TreeNode *l = new TreeNode(2);
	TreeNode *r = new TreeNode(3);
	root->right = r;
	r->right = l;
	sol.recoverTree(root);
	printf("%d %d %d\n", root->val, l->val, r->val);
	system("pause");
}
