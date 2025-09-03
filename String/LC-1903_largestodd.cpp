class Solution
{
public:
    string largestOddNumber(string num)
    {
        // check from the end until we find an odd digit
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                return num.substr(0, i + 1); //(0, show starting and i+1, the lenth means how much we want, so 0 indexing so i+1);
            }
        }
        return "";
    }
};
