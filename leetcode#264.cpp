#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> ugly;
		ugly.push_back(2);
		ugly.push_back(3);
		ugly.push_back(4);
		ugly.push_back(5);
		int min2 = 1;
		int min3 = 0;
		int min5 = 0;
		if (n == 1)
			return 1;
		if (n <= 5)
			return ugly[n - 2];
		for (int i = 4; i < n - 1 ;)
		{
			if (i == 20)
				i = i;
			if (ugly[min2] * 2 <= ugly[min3] * 3 && ugly[min2] * 2 <= ugly[min5] * 5)
			{
				if (ugly[min2] * 2 != ugly[i - 1])
				{
					ugly.push_back(ugly[min2] * 2);
					i++;
				}
				min2++;
			}
			else if (ugly[min3] * 3 <= ugly[min2] * 2 && ugly[min3] * 3 <= ugly[min5] * 5)
			{
				if (ugly[min3] * 3 != ugly[i - 1])
				{
					ugly.push_back(ugly[min3] * 3);
					i++;
				}
				min3++;
			}
			else if (ugly[min5] * 5 <= ugly[min3] * 3 && ugly[min5] * 5 <= ugly[min2] * 2)
			{
				if (ugly[min5] * 5 != ugly[i - 1])
				{
					ugly.push_back(ugly[min5] * 5);
					i++;
				}
				min5++;
			}
		}
		return ugly[n-2];
	}
};

int main()
{
	Solution a;
	for (int i = 22; i < 23; i++)
		printf("%d ", a.nthUglyNumber(i));
	system("pause");
}
