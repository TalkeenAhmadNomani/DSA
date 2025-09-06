class Solution
{
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp, int &res)
    {
        if (i == s1.size() || j == s2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int take = 0;
        if (s1[i] == s2[j])
        {
            take = 1 + solve(s1, s2, i + 1, j + 1, dp, res);
            res = max(res, take);
        }
        else
        {
            take = 0;
        }
        return dp[i][j] = take;
    }

public:
    int longestCommonSubstr(string &text1, string &text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                solve(text1, text2, i, j, dp, res);
            }
        }
        return res;
    }
};
//optmized and easy ratt lo

class Solution
{
public:
    int longestCommonSubstring(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    res = max(res, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0; // reset since substring must be continuous
                }
            }
        }
        return res;
    }
};
