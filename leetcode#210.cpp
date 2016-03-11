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
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int> > mymap;
		vector<int> result;
		int cnt[11111];
		mymap.resize(numCourses);
		for (int i = 0; i < numCourses; i++)
		{
			cnt[i] = 0;
		}
		for (int i = 0; i < prerequisites.size(); i++)
		{
			mymap[prerequisites[i].second].push_back(prerequisites[i].first);
			cnt[prerequisites[i].first]++;
		}
		bool p;
		for (int i = 0; i < numCourses; i++)
		{
			p = false;
			for (int j = 0; j < numCourses; j++)
			{
				if (cnt[j] == 0)
				{
					p = true;
					result.push_back(j);
					for (int k = 0; k < mymap[j].size(); k++)
					{
						cnt[mymap[j][k]]--;
					}
					cnt[j]--;
					break;
				}
			}
			if (p == false)
			{
				result.resize(0);
				return result;
			}
		}
		return result;
	}
};

int main()
{
	vector<pair<int, int> > a;
	a.push_back(make_pair(1, 0));
	a.push_back(make_pair(2, 0));
	a.push_back(make_pair(3, 1));
	a.push_back(make_pair(3, 2));
	Solution sol;
	vector<int> result;
	result = sol.findOrder(4, a);
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", result[i]);
	}
	system("pause");
}
