/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */
bool isMatch(char *s, char *p)
{
    bool dp[strlen(s) + 1][strlen(p) + 1];
    dp[strlen(s)][strlen(p)] = true;
    for (int i = strlen(s); i >= 0; i--)
    {
        for (int j = strlen(p) - 1; j >= 0; j--)
        {
            bool match = i < strlen(s) && s[i] == p[j] || p[j] == '.';
            if (j + 1 < strlen(p) && p[j + 1] == '*')
            {
                dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
            }
            else
            {
                dp[i][j] = match && dp[i + 1][j + 1];
            }
        }
    }
    return dp[0][0];
}
