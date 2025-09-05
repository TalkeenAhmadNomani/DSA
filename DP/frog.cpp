class Solution
{
    int solve(vector<int> &arr, int n, vector<int> &dp)
    {

        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int one_step = solve(arr, n - 1, dp) + abs(arr[n] - arr[n - 1]);

        int two_step = INT_MAX;

        if (n - 2 >= 0)
            two_step = solve(arr, n - 2, dp) + abs(arr[n] - arr[n - 2]);

        return dp[n] = min(one_step, two_step);
    }

public:
    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n + 1, -1);
        return solve(height, n - 1, dp);
    }
};

//optimized

class Solution
{
public:
    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        if (n > 1)
            dp[1] = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++)
        {
            int one_step = dp[i - 1] + abs(height[i] - height[i - 1]);

            int two_step = dp[i - 2] + abs(height[i] - height[i - 2]);

            dp[i] = min(one_step, two_step);
        }

        return dp[n - 1];
    }
};
