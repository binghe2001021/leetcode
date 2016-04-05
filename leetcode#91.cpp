#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#define maxn 1111
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	int f[111111];
	int numDecodings(string s) {
		int len = s.size();
		if (len == 0) return 0;
		if (s[0] == '0') return 0;
		else f[0] = 1;
		if (s[1] == '0' && s[0] != '2' && s[0] != '1') return 0;
		if (s[0] < '2' || (s[0] == '2' && s[1] < '7')) f[1] = 2 - (s[1] == '0');
		else f[1] = 1;
		for (int i = 2; i < len; i++){
			if (s[i] == '0' && s[i - 1] != '1' && s[i - 1] != '2'){
				return 0;
			}
			if (s[i - 1] != '0' && (s[i - 1] < '2' || (s[i - 1] == '2' && s[i] < '7')))
				f[i] = f[i - 1] * (s[i] != '0') + f[i - 2];
			else f[i] = f[i - 1];
		}
		return f[len - 1];
	}
};
int main(){
	Solution sol; 
	system("pause");
}