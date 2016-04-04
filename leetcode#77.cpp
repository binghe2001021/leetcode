#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#define maxn 1111
using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> now;
	void dfs(int depth, int cnt, int n, int k){
		if (cnt >= k){
			ans.push_back(now);
			return;
		}
		if (depth > n){
			return;
		}
		now.push_back(depth);
		dfs(depth + 1, cnt + 1, n, k);
		now.resize(now.size() - 1);
		dfs(depth + 1, cnt, n, k);
	}
	vector<vector<int>> combine(int n, int k) {
		now.resize(0);
		dfs(1, 0, n, k);
		return ans;
	}
};

int main(){
	Solution sol;
}