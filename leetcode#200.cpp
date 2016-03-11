class Solution {
public:
	int ans = 0;
	vector<int> ufs;

	int getfather(int i)
	{
		if (ufs[i] == i) return i;
		else return ufs[i] = getfather(ufs[i]);
	}

	void merge(int a, int b)
	{
		int f1 = getfather(a);
		int f2 = getfather(b);
		if (f1 != f2) ans--;
		ufs[f2] = f1;
	}

	int numIslands(vector<vector<char> >& grid) {
	    if (grid.empty()) return 0;
		int n = grid.size(), m = grid[0].size();
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				ufs.push_back(i*m + j);
				if (grid[i][j] == '1')
				{
					ans++;
					if (i>0 && grid[i - 1][j] == '1') merge(i*m + j, (i - 1)*m + j);
					if (j>0 && grid[i][j - 1] == '1') merge(i*m + j, i*m + j - 1);
				}
			}
		}
		return ans;
	}
};