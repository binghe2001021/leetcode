#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
	vector<int> cnt;
public:
	void dfs(vector<int> & a, int n)
	{
		bool p = false;
		if (cnt[n] != -1) return;
		if (n > 0 && a[n - 1] < a[n])
		{
			dfs(a, n - 1);
			cnt[n] = cnt[n - 1]+1;
			p = true;
		}
		if (n+1 < a.size() && a[n + 1] < a[n])
		{
			dfs(a, n + 1);
			if (cnt[n+1]+1 > cnt[n]) cnt[n] = cnt[n + 1]+1;
			p = true;
		}
		if (!p)
			cnt[n] = 1;
	}

	int candy(vector<int>& ratings) {
		int len = ratings.size();
		cnt.resize(len);
		for (int i = 0; i < len; i++)
			cnt[i] = -1;
		int ans = 0;
		for (int i = 0; i < len; i++)
			dfs(ratings,i);
		for (int i = 0; i < len; i++)
			ans += cnt[i];
		return ans;
	}
};

int main()
{
	Solution a;
	vector<int> b;
	/*for (int i = 0; i < 20000; i++)
	{
		b.push_back(i);
	}*/
	b.push_back(1);
	b.push_back(3);
	b.push_back(4);
	b.push_back(3);
	b.push_back(2);
	b.push_back(1);
	printf("%d\n", a.candy(b));
	system("pause");
}
