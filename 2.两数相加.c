/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    struct ListNode *curr = head;
    int sum = 0, carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
        int x = (l1 == NULL) ? 0 : l1->val;
        int y = (l2 == NULL) ? 0 : l2->val;
        sum = carry + x + y;
        carry = sum / 10;
        curr->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = sum % 10;
        curr->next = NULL;
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }
    if (carry == 1)
    {
        curr->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = carry;
        curr->next = NULL;
    }
    return head->next;
}