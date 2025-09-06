class Solution
{
    int solve(int n, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (j > grid.size() - 1 || j < 0 || n < 0)
            return 1e9;
        if (n == 0)
            return grid[n][j];
        if (dp[n][j] != -1)
            return dp[n][j];

        int up = grid[n][j] + solve(n - 1, j, grid, dp);

        int left = grid[n][j] + solve(n - 1, j - 1, grid, dp);

        int right = grid[n][j] + solve(n - 1, j + 1, grid, dp);

        return dp[n][j] = min(up, min(left, right));
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int maxi = INT_MAX;

        for (int j = 0; j < n; j++)
        {
            int curr = solve(n - 1, j, matrix, dp);
            maxi = min(curr, maxi);
        }
        return maxi;
    }
};
