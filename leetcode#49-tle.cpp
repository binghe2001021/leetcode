#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#define maxn 222222
#define Mint 111111111
using namespace std;

class Solution {
public:
	int ufs[1111];
	bool inclu(string s1, string s2){
		int n = s1.size();
		for (int i = 0; i < n; i++){
			if (s2.find(s1[i]) == -1)
				return false;
		}
		return true;
	}
	int getfather(int n){
		if (ufs[n] == n) return n;
		else return getfather(ufs[n]);
	}
	void merge(int a, int b){
		int f1, f2;
		f1 = getfather(a);
		f2 = getfather(b);
		ufs[f2] = f1;
	}
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int n = strs.size();
		vector<vector<string>> ans;
		sort(strs.begin(), strs.end());
		for (int i = 0; i < n; i++)
			ufs[i] = i;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < i; j++){
				if (inclu(strs[i], strs[j]) && inclu(strs[j], strs[i])){
					merge(j,i);
					break;
				}
			}
		bool p[1111];
		vector<string> now;
		memset(p, 0, sizeof(p));
		for (int i = 0; i < n; i++){
			if (!p[i]){
				now.clear();
				for (int j = i; j < n; j++)
					if (ufs[j] == ufs[i]){
						now.push_back(strs[j]);
						p[j] = true;
					}
				ans.push_back(now);
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<string> a = { "eat", "tea", "pan" };
	vector<string> b;
	vector<vector<string>> res;
	res = sol.groupAnagrams(a);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size()-1; j++){
			cout << res[i][j] << ' ';
		}
		cout << res[i][res[i].size() - 1] << endl;
	}
	system("pause");
}