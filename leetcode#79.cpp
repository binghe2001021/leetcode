#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#define maxn 1111
using namespace std;

const int dx[4] = { -1, 0, 0, 1 };
const int dy[4] = { 0, -1, 1, 0 };
class Solution {
public:
	int m, n;
	bool hash[111][111];
	string sav;
	bool f(vector<vector<char>>& board,string word, int x, int y){
		if (hash[x][y]) return false;
		if (word.size() == 1) return true;
		word.resize(word.size() - 1);
		hash[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i], ty = y + dy[i];
			if (tx>=0 && tx<m && ty>=0 && ty<n && board[tx][ty] == word[word.size()-1]) 
				if (f(board,word,tx,ty)) return true;
		}
		word.push_back(sav[word.size()]);
		hash[x][y] = false;
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		reverse(word.begin(), word.end());
		int len = word.size();
		m = board.size();
		n = board[0].size();
		memset(hash, 0, sizeof(hash));
		sav = word.substr(0, word.size());
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == word[len - 1])
					if (f(board,word, i, j)) return true;
		return false;
	}
};

int main(){
	Solution sol;
	vector<vector<char>> a = { { 'a', 'a', 'a' }, { 'a', 'a', 'a' }, {'a','a','b'} };
	string word = "aaaaaaaab";
	if (sol.exist(a, word)) cout << 111 << endl;
	system("pause");
}