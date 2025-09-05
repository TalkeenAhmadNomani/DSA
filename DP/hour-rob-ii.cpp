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
