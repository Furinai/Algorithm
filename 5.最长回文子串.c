/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */
int max(int a, int b)
{
    return a > b ? a : b;
}
char *substr(char *s, int begin, int end)
{
    char temp[end - begin + 1];
    char *string = NULL;
    if (strlen(s) < 2 || begin < 0 || begin >= end)
    {
        return s;
    }
    for (int i = begin; i < end; i++)
    {
        temp[i - begin] = s[i];
    }
    temp[end - begin] = '\0';
    string = temp;
    return string;
}
int expandCenter(char *s, int left, int right)
{
    int n = strlen(s);
    int l = left, r = right;
    while (l >= 0 && r < n && s[l] == s[r])
    {
        l--;
        r++;
    }
    return r - l - 1;
}
char *longestPalindrome(char *s)
{
    int n = strlen(s);
    if (n == 0)
    {
        char *a = "";
        return a;
    }
    int start = 0, end = 0;
    int len1 = 0, len2 = 0, len3 = 0;
    for (int i = 0; i < n; i++)
    {
        len1 = expandCenter(s, i, i);
        len2 = expandCenter(s, i, i + 1);
        len3 = max(len1, len2);
        if (len3 > end - start)
        {
            start = i - (len3 - 1) / 2;
            end = i + len3 / 2;
        }
    }
    return substr(s, start, end + 1);
}
