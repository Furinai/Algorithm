/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length(), len = 0;
        unordered_map<int, int> map;
        for (int i = 0, j = 0; j < n; j++)
        {
            if (map.find(s[j]) != map.end())
            {
                i = max(map[s[j]], i);
            }
            len = max(len, j - i + 1);
            map[s[j]] = j + 1;
        }
        return len;
    }
};
