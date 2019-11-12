#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for index, value in enumerate(nums):
            complement = target - value
            if complement in hashmap:
                return {hashmap[complement],index}
            hashmap[value] = index
