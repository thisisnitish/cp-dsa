/*
Leetcode Question 23. Merge k Sorted Lists
https://leetcode.com/problems/merge-k-sorted-lists/
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

//Solution 1
class Solution
{
public:
    /*the basic idea is to implement the merge part
    of merge sort, but the we will take sublists one 
    by one. Time: O(N), Space: O(1)*/
    ListNode *merge2Lists(ListNode *l1, ListNode *l2)
    {

        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *result1 = new ListNode();
        ListNode *result = result1;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                result->next = l1;
                l1 = l1->next;
            }
            else
            {
                result->next = l2;
                l2 = l2->next;
            }
            result = result->next;
        }

        if (l1)
            result->next = l1;

        if (l2)
            result->next = l2;

        result = result1->next;
        delete result1;
        return result;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        ListNode *head = new ListNode(0);
        head->next = merge2Lists(lists[0], lists[1]);

        int length = lists.size();
        for (int i = 2; i < length; i++)
        {
            head->next = merge2Lists(lists[i], head->next);
        }
        return head->next;
    }
};

//Solution 2
class Solution
{
public:
    /*the basic idea is to implement the merge part
    of merge sort. Time: O(Nlogk), Space: O(1)*/
    ListNode *merge2Lists(ListNode *l1, ListNode *l2)
    {

        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *result1 = new ListNode();
        ListNode *result = result1;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                result->next = l1;
                l1 = l1->next;
            }
            else
            {
                result->next = l2;
                l2 = l2->next;
            }
            result = result->next;
        }

        if (l1)
            result->next = l1;

        if (l2)
            result->next = l2;

        result = result1->next;
        delete result1;
        return result;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
            return NULL;

        int length = lists.size();

        while (length > 1)
        {
            for (int i = 0; i < length / 2; i++)
            {
                lists[i] = merge2Lists(lists[i], lists[length - i - 1]);
            }
            //we will be moving 2 times
            //e.g. length = 2*length
            length = (length + 1) / 2;
        }

        return lists[0];
    }
};
