





class Solution{
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
