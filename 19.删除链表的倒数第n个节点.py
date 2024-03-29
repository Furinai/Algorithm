#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第N个节点
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        p = dummy
        q = dummy
        for _ in range(n):
            p = p.next
        while p.next:
            p = p.next
            q = q.next
        q.next = q.next.next
        return dummy.next

