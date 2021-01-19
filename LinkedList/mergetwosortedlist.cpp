/*
Leetcode Question 21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/
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
    /*basic idea is to implement merge part of merge sort
    Time: O(N)*/
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        if (l1 == NULL && l2 == NULL)
            return {};

        if (l1 == NULL)
            return l2;

        if (l2 == NULL)
            return l1;

        ListNode *result1 = new ListNode();
        ListNode *result = result1;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                result->next = l1;
                l1 = l1->next;
                result = result->next;
            }
            else
            {
                result->next = l2;
                l2 = l2->next;
                result = result->next;
            }
        }

        if (l1)
        {
            result->next = l1;
        }

        if (l2)
        {
            result->next = l2;
        }

        result = result1->next;
        delete result1;
        return result;
    }
};