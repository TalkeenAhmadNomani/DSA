class Solution
{
    int solve(vector<int> &nums, int start, int end, vector<int> &dp)
    {
        if (start > end)
            return 0;
        if (dp[start] != -1)
            return dp[start];

        int take = nums[start] + solve(nums, start + 2, end, dp);
        int not_take = solve(nums, start + 1, end, dp);

        return dp[start] = max(take, not_take);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1); // for robbing from 0 to n-2
        vector<int> dp2(n, -1); // for robbing from 1 to n-1

        return max(
            solve(nums, 0, n - 2, dp1),
            solve(nums, 1, n - 1, dp2));
    }
};
//optimized

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp1(n, 0); // for robbing from 0 to n-2
        vector<int> dp2(n, 0); // for robbing from 1 to n-1
        // For dp1: Robbing from house 0 to n-2
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++i)
        {
            int take = nums[i] + dp1[i - 2];
            int not_take = dp1[i - 1];
            dp1[i] = max(take, not_take);
        }
        // For dp2: Robbing from house 1 to n-1
        dp2[1] = nums[1];
        if (n >= 3) // dp2[0] is unused
            dp2[2] = max(nums[1], nums[2]);
        for (int i = 3; i < n; ++i)
        {
            int take = nums[i] + dp2[i - 2];
            int not_take = dp2[i - 1];
            dp2[i] = max(take, not_take);
        }
        return max(dp1[n - 2], dp2[n - 1]);
    }
};
