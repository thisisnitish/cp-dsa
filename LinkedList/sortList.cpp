/*
Leetcode Question 148. Sort List
https://leetcode.com/problems/sort-list/
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
    /*Actually this question combines Find Middle of LL, 
    Merge two Sorted LLbasic is idea is same as we 
    know about merge sort. divide the list in two halves 
    and then start sorting. Time: O(NlogN), Space: O(1)*/
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *fast = head->next, *slow = head;

        /*here we are dividing the list into two halves*/
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow->next;
        slow->next = NULL;

        return merge(sortList(head), sortList(fast));
    }

    /*Basic merge sort implementation*/
    ListNode *merge(ListNode *head, ListNode *fast)
    {
        ListNode *result1 = new ListNode();
        ListNode *result = result1;

        while (head && fast)
        {
            if (head->val <= fast->val)
            {
                result->next = head;
                result = result->next;
                head = head->next;
            }
            else
            {
                result->next = fast;
                result = result->next;
                fast = fast->next;
            }
        }

        if (head)
        {
            result->next = head;
        }
        if (fast)
        {
            result->next = fast;
        }

        result = result1->next;
        delete result1;
        return result;
    }
};