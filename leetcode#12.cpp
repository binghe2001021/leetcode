#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#define maxn 222222
#define Mint 111111111
using namespace std;

const char ch[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
const int val[7] = { 1, 5, 10, 50, 100, 500, 1000 };
class Solution {
public:
	string intToRoman(int num) {
		int t = num;
		int k = 0;
		string ans = "";
		while (t > 0){
			int n = t % 10;
			if (n <= 3){
				for (int j = 0; j < n; j++)
					ans.push_back(ch[k]);
			}else
				if (n == 4){
					ans.push_back(ch[k + 1]);
					ans.push_back(ch[k]);
				}else
					if (n <= 8){
						for (int j = 6; j <= n; j++)
							ans.push_back(ch[k]);
						ans.push_back(ch[k + 1]);
					}
					else
					{
						ans.push_back(ch[k + 2]);
						for (int j = 9; j >= n; j--)
							ans.push_back(ch[k]);
					}
			t /= 10;
			k += 2;
		}
		string res;
		for (int i = ans.size() - 1; i >= 0;i--)
			res.push_back(ans[i]);
		return res;
	}
};

int main()
{
	Solution sol;
	cout<<sol.intToRoman(17);
	system("pause");
}