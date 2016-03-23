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

string operator *(const string &s1, const string &s2){
	string s3;
	int temp, k = 0;
	int l1 = s1.size(), l2 = s2.size();
	s3.resize(l1 + l2, '0');
	for (int i = 0; i < l1; i++){
		k = 0;
		for (int j = 0; j < l2; j++){
			temp = s3[i + j] - 48 + (s1[l1-1-i] - 48) * (s2[l2-1-j] - 48) + k;
			s3[i + j] = temp % 10 + 48;
			k = temp / 10;
		}
		if (k>0) s3[i + l2] = s3[i + l2] + k;
	}
	int l = 0, r = s3.size() - 1;
	while (l < r){
		temp = s3[l];
		s3[l] = s3[r];
		s3[r] = temp;
		l++; r--;
	}
	while (s3[0] == '0' && s3.size()>1)
		s3.erase(s3.begin());
	return s3;
}

class Solution {
public:
	string multiply(string num1, string num2) {
		string num3;
		num3 = num1*num2;
		return num3;
	}
};

int main()
{
	Solution sol;
	cout << sol.multiply("123", "23");
	system("pause");
}