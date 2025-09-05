class Solution
{

public:
    int fib(int n)
    {
        vector<int> dp(n + 1);
        if (n < 2)
            return n;
        dp[1] = 1;
        dp[0] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
//optimized
class Solution
{

public:
    int fib(int n)
    {

        if (n < 2)
            return n;
        int prev1 = 1;
        int prev2 = 0;
        int curr = 0;
        int temp = 0;
        for (int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};