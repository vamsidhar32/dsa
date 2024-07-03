class Solution {
public:
    int cherrydp(int i, int j, int b, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int n, int m) {
        if (i == n - 1) {
            if (j == b)
                return grid[i][j];
            else
                return grid[i][j] + grid[i][b];
        }
        
        if (dp[i][j][b] != -1)
            return dp[i][j][b];
        
        int cherries = (j == b) ? grid[i][j] : grid[i][j] + grid[i][b];
        int ans = -1e9; 
        
        for (int k = -1; k <= 1; k++) {
            for (int h = -1; h <= 1; h++) {
                if (j + k >= 0 && j + k < m && b + h >= 0 && b + h < m && i + 1 < n) {
                    ans = max(ans, cherries + cherrydp(i + 1, j + k, b + h, grid, dp, n, m));
                }
            }
        }
        
        return dp[i][j][b] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1, -1)));
        
        return cherrydp(0, 0, m - 1, grid, dp, n, m);
    }
};
