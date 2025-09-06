
class Solution
{
    int solve(int n, int m, string text1, string text2, vector<vector<int>> &dp)
    {
        if (n == 0 || m == 0)
            return 0;
        int take = 0;
        if (dp[n][m] != -1)
            return dp[n][m];

        if (text1[n - 1] == text2[m - 1])
        {
            take = 1 + solve(n - 1, m - 1, text1, text2, dp);
        }
        int not_take1 = solve(n - 1, m, text1, text2, dp);
        int not_take2 = solve(n, m - 1, text1, text2, dp);

        return dp[n][m] = max(take, max(not_take1, not_take2));
    }

public:
    int longestPalindromeSubseq(string text1)
    {
        int n = text1.size();
        string text2 = text1;
        reverse(text2.begin(), text2.end());
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(n, m, text1, text2, dp);
    }
};

//optimzed..

class Solution
{
public:
    int longestPalindromeSubseq(string text1)
    {
        int n = text1.size();
        string text2 = text1;
        reverse(text2.begin(), text2.end());
        int m = text2.size();
        // dp[i][j] = LCS of text1[0..i-1] and text2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};