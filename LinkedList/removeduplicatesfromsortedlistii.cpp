/*
Leetcode Question 82. Remove Duplicates from Sorted List II
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        auto temp = new ListNode(-1);
        auto prev = temp;

        while (head != NULL)
        {
            if (head->next && head->val == head->next->val)
            {
                int duplicate = head->val;
                while (head && head->val == duplicate)
                {
                    head = head->next;
                }
            }
            else
            {
                prev->next = head;
                prev = prev->next;
                head = head->next;
            }
        }
        prev->next = NULL;
        return temp->next;
    }
};