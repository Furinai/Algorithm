/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
class Solution
{
public:
    int expandCenter(string s, int left, int right)
    {
        int l = left, r = right;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r - l - 1;
    }
    string longestPalindrome(string s)
    {
        if (s.empty())
        {
            return "";
        }
        int start = 0, end = 0;
        int len1 = 0, len2 = 0, len3 = 0;
        for (int i = 0; i < s.length(); i++)
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
        return s.substr(start, end - start + 1);
    }
};
