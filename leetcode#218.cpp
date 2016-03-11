#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

bool operator <(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}
bool cmp(vector<int> a, vector<int> b){
	return a[0] < b[0] || (a[0] == b[0] && a[2] > b[2]);
}

class Solution {
public:
	vector<pair<int, int> > getSkyline(vector<vector<int>>& buildings) {
		int head = 0;
		priority_queue<pair<int, int> > q,h;
		vector<pair<int, int> > ans;
		int lb = buildings.size();
		if (lb == 0)
			return ans;
		sort(buildings.begin(), buildings.end(), cmp);
		int now = buildings[0][2];
		int nowb = 0;
		int nowx = buildings[0][0];
		q.push(make_pair(-buildings[0][1],0));
		h.push(make_pair(buildings[0][2],0));
		ans.push_back(make_pair(buildings[0][0],buildings[0][2]));
		while (1){
			if (q.empty() && head + 1 == lb)
				break;
			if (q.empty() || (head+1<lb && buildings[head + 1][0] <= -q.top().first)){
				nowx = buildings[head + 1][0];
				head++;
				h.push(make_pair(buildings[head][2],head));
				q.push(make_pair(-buildings[head][1], head));
				if (buildings[head][2] >= now){
					nowb = head;
					if (buildings[head][2] > now)
						ans.push_back(make_pair(buildings[head][0], now = buildings[head][2]));
				}
			}
			else{
				nowx = -q.top().first;
			//	printf("%d\n", q.top().second);
				if (q.top().second == nowb){
					h.pop();
					while (!h.empty() && buildings[h.top().second][1] <= nowx)
						h.pop();
					if (h.empty())
						ans.push_back(make_pair(-q.top().first,now = 0));
					else{
						nowb = h.top().second;
						ans.push_back(make_pair(-q.top().first, now = h.top().first));
					}
				}
				q.pop();
			}
			while (!h.empty() && buildings[h.top().second][1] < nowx)
				h.pop();
		}
		return ans;
	}
};

int main(){
	Solution a;
	vector<vector<int> > buildings;
	vector<pair<int, int> > ans;
/*	for (int i = 1; i <= 10000; i++){
		vector<int> temp;
		temp.push_back(i);
		temp.push_back(10001);
		temp.push_back(10001-i);
		buildings.push_back(temp);
	}*/
	buildings.push_back({ 1,2,1});
	buildings.push_back({ 1, 2, 2 });
	buildings.push_back({ 1, 2, 3 });
	ans = a.getSkyline(buildings);
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	system("pause");
}