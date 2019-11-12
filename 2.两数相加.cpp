/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        int sum = 0, carry = 0;
        while (l1 != NULL || l2 != NULL)
        {
            int x = (l1 == NULL) ? 0 : l1->val;
            int y = (l2 == NULL) ? 0 : l2->val;
            sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }
        if (carry == 1)
        {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        return head->next;
    }
};