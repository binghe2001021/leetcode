#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		int ans = 1;
		string rec;
		rec.push_back(s[0]);
		for (int i = 1; i < len-1; i++){
			int l = i - 1, r = i + 1;
			while (l >= 0 && r <= len - 1){
				if (s[l] != s[r])
					break;
				l--; r++;
			}
			l++; r--;
			if (2 * (i - l) + 1 > ans){
				ans = 2 * (i - l) + 1;
				rec.clear();
				rec = s.substr(l, ans);
			}
		}
		for (int i = 0; i < len - 1; i++){
			int l = i, r = i + 1;
			while (l >= 0 && r <= len - 1){
				if (s[l] != s[r])
					break;
				l--; r++;
			}
			l++; r--;
			if (2 * (i - l + 1) > ans){
				ans = 2 * (i - l + 1);
				rec.clear();
				rec = s.substr(l, ans);
			}
		}
		return rec;
	}
};

int main()
{
	string t = "acbbca";
	Solution s;
	string ans = s.longestPalindrome(t);
	cout << ans;
	system("pause");
}