#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0:
            return False
        map = {")": "(", "}": "{", "]": "["}
        stack = []
        for c in s:
            if c in map:
                topElement = stack.pop() if stack else "#"
                if topElement != map[c]:
                    return False
            else:
                stack.append(c)
        return not stack
