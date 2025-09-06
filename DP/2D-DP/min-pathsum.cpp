class Solution
{
    int solve(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
    {
        if (row == 0 && col == 0)
            return grid[row][col];
        if (row < 0 || col < 0)
            return 1e9;
        int up = grid[row][col] + solve(grid, row - 1, col, dp);
        int left = grid[row][col] + solve(grid, row, col - 1, dp);
        return dp[row][col] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return solve(grid, m - 1, n - 1, dp);
    }
};
// optimized
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                int up = 1e9, left = 1e9;

                if (i > 0)
                    up = grid[i][j] + dp[i - 1][j];
                if (j > 0)
                    left = grid[i][j] + dp[i][j - 1];
                dp[i][j] = min(up, left);
            }
        }
        return dp[m - 1][n - 1];
    }
};
