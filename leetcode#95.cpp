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
	vector<TreeNode*> dfs(int l, int r){
		vector<TreeNode*> ans;
		if (l > r){
			ans.push_back(NULL);
			return ans;
		}
		if (l == r){
			ans.push_back(new TreeNode(l));
			return ans;
		}
		for (int i = l; i <= r; i++){
			vector<TreeNode*> a1 = dfs(l, i - 1);
			vector<TreeNode*> a2 = dfs(i + 1, r);
			int l1 = a1.size();
			int l2 = a2.size();
			for (int j = 0; j < l1; j++)
				for (int k = 0; k < l2; k++){
					TreeNode* root = new TreeNode(i);
					root->left = a1[j];
					root->right = a2[k];
					ans.push_back(root);
				}
		}
		return ans;
	}
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> ans(0);
		if (n == 0) return ans;
		return dfs(1, n);
	}
};
int main(){
	Solution sol; 
	sol.generateTrees(3);
	system("pause");
}