class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int n = s.size();
        string temp;
        string ans;

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                cnt++;
                temp += s[i];
            }
            else
            {
                cnt--;
                temp += s[i];
            }
            if (cnt == 0)
            {
                for (int i = 1; i < temp.size() - 1; i++)
                {
                    ans += temp[i];
                }
                temp = "";
            }
        }
        return ans;
    }
};

// optimizedclass Solution {
public:{
string removeOuterParentheses(string s)
{
    string result;
    int balance = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {

            if (balance > 0)
            {
                result += s[i];
            }
            balance++;
        }
        else
        {
            balance--;
            if (balance > 0)
            {
                result += s[i];
            }
        }
    }

    return result;
}

};