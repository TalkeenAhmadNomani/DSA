
class Solution
{
    int solve(vector<int> &nums, int n, vector<int> &dp)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return nums[0];
        if (dp[n] != -1)
            return dp[n];

        int not_take = solve(nums, n - 1, dp);
        int take = nums[n] + solve(nums, n - 2, dp);

        return dp[n] = max(not_take, take);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);

        return solve(nums, n - 1, dp);
    }
};

//optimized

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = nums[0];
        if (n >= 2)
            dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            int take = nums[i] + dp[i - 2];
            int not_take = dp[i - 1];

            dp[i] = max(take, not_take);
        }

        return dp[n - 1];
    }
};