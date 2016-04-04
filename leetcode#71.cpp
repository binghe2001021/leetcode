#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#define maxn 1111
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		size_t found = path.find('/');
		string ans;
		stack<int> q;
		path.push_back('/');
		while (found != string::npos){
			if (path[found + 1] != '/'){
				if (path[found + 1] == '.' && (path[found + 2] == '/' || path[found + 2] == '.' && path[found + 3] == '/')){
					if (path[found + 2] == '.' && path[found + 3] == '/' && !q.empty()){
						ans.resize(ans.size() - q.top());
						q.pop();
					}
				}
				else{
					int cnt = 0;
					for (int i = found; path[i] != 0 && (path[i] != '/' || i == found); i++){
						ans.push_back(path[i]);
						cnt++;
					}
					q.push(cnt);
				}
			}
			found = path.find('/', found + 1);
		}
		while (ans.size()>1 && ans[ans.size() - 1] == '/')
			ans.resize(ans.size() - 1);
		if (ans.size() == 0)
			ans.push_back('/');
		return ans;
	}
};

int main(){
	Solution sol;
	cout << sol.simplifyPath("/..//");
}