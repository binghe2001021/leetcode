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
	int len;
	string now;
	vector<string> ans;
	bool isvalid(string t){
		if (t.size() > 3) return false;
		if (t[0] == '0' && t.size() != 1) return false;
		if (t.size() < 3) return true;
		return t < "256";
	}
	void dfs(int depth, int k, string s){
		if (depth == 3){
			if (k == len) return;
			string temp = s.substr(k, len - k);
			if (isvalid(temp)){
				now = now + temp;
				ans.push_back(now);
				now.resize(now.size() - temp.size());
			}
			return;
		}
		for (int i = 1; i < 4 && k + i <= len; i++){
			string temp = s.substr(k, i);
			if (!isvalid(temp)) continue;
			now += temp + '.';
			dfs(depth + 1, k + i, s);
			now.resize(now.size() - temp.size() - 1);
		}
	}
	vector<string> restoreIpAddresses(string s) {
		len = s.size();
		now.resize(0);
		ans.resize(0);
		dfs(0, 0, s);
		return ans;
	}
};
int main(){
	Solution sol; 
	system("pause");
}