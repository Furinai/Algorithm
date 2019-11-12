#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#
class Solution:
    def longestPalindrome(self, s: str) -> str:
        start, end, n = 0, 0, len(s)
        if (not s) or (n < 1):
            return ""
        for i in range(n):
            len1 = self.expandCenter(s, i, i)
            len2 = self.expandCenter(s, i, i + 1)
            len3 = max(len1, len2)
            if len3 > (end - start):
                start = i - (len3 - 1) // 2
                end = i + len3 // 2
        return s[start : end + 1]

    def expandCenter(self, s: str, left: int, right: int):
        l, r, n = left, right, len(s)
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return r - l - 1
