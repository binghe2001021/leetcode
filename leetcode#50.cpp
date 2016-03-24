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
	double myPow(double x, int n) {
		double ans = 1, cnt = 1;
		bool p = true;
		long long t;
		if (n < 0) { p = false; t = -(long long)n; }
		else t = n;
		for (long long i = 1; i <= t; i <<= 1){
			if (i == 1) cnt = x;
			else cnt *= cnt;
			if (!p && 1.0 / cnt<0.00001 && 1.0 / cnt>-0.00001)
				return 0;
			if ((t&i) > 0) ans *= cnt;
			if ((i << 1ll) > INT_MAX) break;
		}
		if (!p) ans = 1 / ans;
		return ans;
	}
};

int main()
{
	Solution sol;
	cout << sol.myPow(2,-2147483647-1) << endl;
	system("pause");
}