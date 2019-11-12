#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n, i = len(s), 0
        result = 0
        map = {}
        for j in range(n):
            if s[j] in map:
                i = max(map[s[j]] , i)
            result = max(result, j - i + 1)
            map[s[j]] = j + 1
        return result
