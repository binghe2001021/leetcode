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
	int f[111];
	int numTrees(int n) {
		if (f[n] != 0) return f[n];
		if (n <= 1) return 1;
		for (int i = 1; i <= n; i++)
			f[n] += numTrees(i - 1)*numTrees(n - i);
		return f[n];
	}
};
int main(){
	Solution sol; 
	system("pause");
}