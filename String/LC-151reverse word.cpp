class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        string temp = "";
        string ans = "";

        s = " " + s; // prepend a space so the last word also gets flushed

        for (int i = n; i >= 0; i--)
        {
            if (s[i] == ' ' && temp.size() == 0)
                continue; // skip multiple spaces

            if (s[i] == ' ')
            {

                if (!temp.empty())
                {
                    reverse(temp.begin(), temp.end());
                    if (!ans.empty())
                        ans += " "; // add space between words
                    ans += temp;
                    temp = "";
                }
            }
            else
            {
                temp += s[i];
            }
        }

        return ans;
    }
};

// 2nd way // both are not otpmized becoze taking n space
class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        string temp = "";
        string ans = "";

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && temp.size() == 0)
                continue; // skip trailing spaces

            if (s[i] == ' ')
            {
                reverse(temp.begin(), temp.end()); // fix word order
                ans += temp + " ";
                temp = "";
            }
            else
            {
                temp += s[i];
            }
        }

        // add the last word
        if (!temp.empty())
        {
            reverse(temp.begin(), temp.end());
            ans += temp;
        }

        // remove trailing space if any
        if (!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};
//. optimized while lop space 0(1)

