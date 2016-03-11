#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval& a, const Interval& b){
	return a.start < b.start;
}

class Solution {
public:

	int Max(int a, int b){
		if (a>b) return a; else return b;
	}

	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ans;
		sort(intervals.begin(), intervals.end(), cmp);
		Interval now = intervals[0];
		for (int i = 1; i < intervals.size(); i++){
			if (intervals[i].start <= now.end){
				now.end = Max(intervals[i].end, now.end);
			}
			else{
				ans.push_back(now);
				now = intervals[i];
			}
		}
		ans.push_back(now);
		return ans;
	}
};

int main()
{

}