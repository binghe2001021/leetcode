#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

class Solution {
public:
	int minDistance(string word1, string word2) {
		int f[666][666];
		int l1 = word1.size();
		int l2 = word2.size();
		for (int i = 0; i <= l2; i++)
			f[0][i] = i;
		for (int i = 1; i <= l1; i++)
		{
			f[i][0] = i;
			for (int j = 1; j <= l2; j++)
			{
				f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
				f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1 - (word1[i - 1] == word2[j - 1]));
			}
		}
		return f[l1][l2];
	}
};

int main()
{
	Solution a;
	string word1 = "abcde";
	string word2 = "bcd";
	printf("%d\n", a.minDistance(word1, word2));
	system("pause");
}
