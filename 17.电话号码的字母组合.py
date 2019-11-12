#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        map = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"],
        }

        def backtrace(combination: str, next_digits: str):
            if len(next_digits) != 0:
                for letter in map[next_digits[0]]:
                    backtrace(combination + letter, next_digits[1:])
            else:
                result.append(combination)

        result = []
        if len(digits) != 0:
            backtrace("", digits)
        return result
