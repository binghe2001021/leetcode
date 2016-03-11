#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans = 0;
		int Maxans = 0;
		for (int i = 0; i < s.length(); i++){
			int p = -1;
			for (int j = i-1; j >= i - ans;j--)
				if (s[i] == s[j]){
					p = j;
					break;
				}
			if (p!=-1){
				if (ans > Maxans)
					Maxans = ans;
				ans = i-p;
			}
			else
				ans++;
		}
		if (ans > Maxans)
			Maxans = ans;
		return Maxans;
	}
};

int main()
{
	string t = "abcbcbcabcc";
	Solution s;
	printf("%d\n", s.lengthOfLongestSubstring(t));
	system("pause");
}