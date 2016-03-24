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
	string getPermutation(int n, int k) {
		char s[1111];
		bool hash[10];
		int perm[11];
		perm[1] = 1;
		memset(hash, 0, sizeof hash);
		for (int i = 2; i <= n; i++)
			perm[i] = perm[i - 1] * i;
		for (int i = 0; i < n - 1; i++){
			int j = 1;
			while (hash[j]) j++;
			while (k>perm[n - i - 1]){
				j++;
				if (hash[j]) continue;
				k -= perm[n - i - 1];
			}
			s[i] = j + 48;
			hash[j] = true;
		}
		int j = 1;
		int cnt = 0;
		while (cnt < k)
			cnt += 1 - hash[j++];
		s[n - 1] = j + 47;
		string ans = s;
		ans.resize(n);

		return ans;
	}
};
int main()
{
	Solution sol;
	cout << sol.getPermutation(5, 14);
	system("pause");
}