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
class Solution {
public:
	vector<int> ans;
	int now;
	bool hash[111111];
	void dfs(int depth, int n){
		for (int i = 0; i < n; i++){
			if (!hash[now ^ (1 << i)]){
				now ^= (1 << i);
				ans.push_back(now);
				hash[now] = true;
				dfs(depth + 1, n);
				hash[now] = false;
				now ^= (1 << i);
				break;
			}
		}
	}
	vector<int> grayCode(int n) {
		ans.resize(0);
		memset(hash, 0, sizeof(hash));
		now = 0;
		ans.push_back(0);
		hash[0] = true;
		dfs(0, n);
		return ans;
	}
};
int main(){
	Solution sol; 
	system("pause");
}