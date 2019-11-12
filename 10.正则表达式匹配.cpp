/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        bool dp[s.length() + 1][p.length() + 1];
        dp[s.length()][p.length()] = true;
        for (int i = s.length(); i >= 0; i--)
        {
            for (int j = p.length() - 1; j >= 0; j--)
            {
                bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
                if (j + 1 < p.length() && p[j + 1] == '*')
                {
                    dp[i][j] = dp[i][j + 2] || match && dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};
