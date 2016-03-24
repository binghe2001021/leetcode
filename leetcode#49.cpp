#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#define maxn 222222
#define Mint 111111111
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> hash;
		int n = strs.size();
		sort(strs.begin(), strs.end());
		for (int i = 0; i < n; i++){
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			hash[temp].push_back(strs[i]);
		}
		vector<vector<string>> ans;
		for (map<string, vector<string>>::iterator it= hash.begin(); it != hash.end(); it++)
			ans.push_back(it->second);
		return ans;
	}
};

int main()
{
	Solution sol;
	
	system("pause");
}