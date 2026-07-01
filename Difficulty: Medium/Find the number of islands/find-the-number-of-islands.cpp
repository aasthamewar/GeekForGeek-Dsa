class Solution {
	public:
	void dfs(int i, int j, vector<vector<bool>> & vis, vector<vector<char>> & grid, int n, int m) {
		// Boundary check
		if (i < 0 || j < 0 || i >= n || j >= m)
			return;
		
		// Water or already visited
		if (grid[i][j] == 'W' || vis[i][j])
			return;
		vis[i][j] = true;
		
		// Explore all 8 directions
		dfs(i - 1, j, vis, grid, n, m);
		dfs(i + 1, j, vis, grid, n, m);
		dfs(i, j - 1, vis, grid, n, m);
		dfs(i, j + 1, vis, grid, n, m);
		
		dfs(i - 1, j - 1, vis, grid, n, m);
		dfs(i - 1, j + 1, vis, grid, n, m);
		dfs(i + 1, j - 1, vis, grid, n, m);
		dfs(i + 1, j + 1, vis, grid, n, m);
	}
	int countIslands(vector<vector<char>> & grid) {
		// Code here
		int islands = 0;
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<bool>> vis(n, vector<bool>(m, false));
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (grid[i][j] == 'L' && !vis[i][j]) {
					dfs(i, j, vis, grid, n, m);
					islands++;
				}
			}
		}
		return islands;
	}
};
