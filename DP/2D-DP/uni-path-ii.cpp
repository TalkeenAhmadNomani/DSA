class Solution
{
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0)
            return 0;
        if (grid[i][j] == 1)
            return 0; // obstacle
        if (i == 0 && j == 0)
            return 1; // start point

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = 0, left = 0;
        // if (i - 1 >= 0 && grid[i - 1][j] != 1)
        up = solve(i - 1, j, dp, grid);
        // if (j - 1 >= 0 && grid[i][j - 1] != 1)
        left = solve(i, j - 1, dp, grid);

        return dp[i][j] = up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp, grid);
    }
};
