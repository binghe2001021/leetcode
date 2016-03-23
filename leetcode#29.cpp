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
	int divide(int dividend, int divisor) {
		long long cnt = 0;
		int k;
		if (divisor == 0)
			return INT_MAX;
		if (divisor == INT_MIN)
			return dividend == INT_MIN;
		if ((dividend>0 && divisor>0) || (dividend<0 && divisor<0)) k = 1;
		else k = -1;
		long long lldiv;
		if (dividend < 0) lldiv = -(long long)dividend;
		else lldiv = dividend;
		divisor = abs(divisor);
		int tot = 0;
		bool inrange = true;
		for (int i = 0; i < 1000; i++){
			if ((long long)tot + divisor > INT_MAX){
				inrange = false;
				break;
			}
			tot += divisor;
		}
		if (inrange){
			while (lldiv >= 0){
				lldiv -= tot;
				cnt += 1000;
			}
			lldiv += tot;
			cnt -= 1000;
		}
		while (lldiv >= 0){
			lldiv -= divisor;
			cnt++;
		}
		if (k > 0)
			if (cnt - 1 > 2147483647) return INT_MAX;
			else return cnt - 1;
		else
			if (1 - cnt > 2147483647) return INT_MAX;
			else return 1 - cnt;
	}
};

int main()
{
	Solution sol;
	int a = -2147483647 - 1;
	cout << sol.divide(a, -1) << endl;
	system("pause");
}