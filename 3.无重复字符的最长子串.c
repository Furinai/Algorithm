/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */
int max(int a, int b)
{
    return a > b ? a : b;
}
int lengthOfLongestSubstring(char *s)
{
    int n = strlen(s);
    int l[256] = {0};
    int r = 0;
    for (int i = 0, j = 0; j < n; j++)
    {
        i = max(l[s[j]], i);
        r = max(j - i + 1, r);
        l[s[j]] = j + 1;
    }
    return r;
}
