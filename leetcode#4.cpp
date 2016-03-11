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
	int findkbiggest(int k, int p1, int p2, vector<int>& nums1, vector<int>& nums2){
		int item1, item2;
		int k1, k2;
		if (p1 >= nums1.size()){
			return nums2[p2 + k - 1];
		}
		if (p2 >= nums2.size()){
			return nums1[p1 + k - 1];
		}
		if (k == 1){
			if (nums1[p1] < nums2[p2]) return nums1[p1];
			else return nums2[p2];
		}
		if (p1 + k / 2 - 1 >= nums1.size()){
			item1 = nums1[k1 = (nums1.size() - 1)];
		}
		else{
			item1 = nums1[k1 = (p1 + k / 2 - 1)];
		}
		if (p2 + k / 2 - 1 >= nums2.size()){
			item2 = nums2[k2 = (nums2.size() - 1)];
		}
		else{
			item2 = nums2[k2 = (p2 + k / 2 - 1)];
		}
		if (item1 < item2){
			return findkbiggest(k - k1 + p1 - 1, k1 + 1, p2, nums1, nums2);
		}
		else
			if (item1 > item2){
				return findkbiggest(k - k2 + p2 - 1, p1, k2 + 1, nums1, nums2);
			}
			else{
				if (k - k1 + p1 - 1 - k2 + p2 - 1 > 0)
					return findkbiggest(k - k1 + p1 - 1 - k2 + p2 - 1, k1 + 1, k2 + 1, nums1, nums2);
				else
					return item1;
			}
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		double ans = findkbiggest((len1 + len2) / 2 + 1, 0, 0, nums1, nums2);
		if ((len1 + len2) % 2 == 0) ans = (ans + findkbiggest((len1 + len2) / 2, 0, 0, nums1, nums2)) / 2.0;
		return ans;
	}
};

int main()
{
	Solution sol;
	int aa[] = { 1, 2 };
	int bb[] = { 1, 2 };
	vector <int> a(aa, aa + sizeof(aa) / sizeof(int));
	vector <int> b(bb, bb + sizeof(bb) / sizeof(int));
	printf("%.4f\n", sol.findMedianSortedArrays(a, b));
	system("pause");
}
