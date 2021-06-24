/*
Leetcode Question 92. Reverse Linked List II
https://leetcode.com/problems/reverse-linked-list-ii/
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
    //Time: O(N), Space: O(1)
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (head == NULL)
            return NULL;

        ListNode *curr = head, *prev = NULL;
        while (m > 1)
        {
            prev = curr;
            curr = curr->next;
            m--;
            n--;
        }

        ListNode *con = prev, *tail = curr;
        ListNode *third = NULL;
        while (n > 0)
        {
            third = curr->next;
            curr->next = prev;
            prev = curr;
            curr = third;
            n--;
        }

        if (con != NULL)
        {
            con->next = prev;
        }
        else
        {
            head = prev;
        }
        tail->next = curr;
        return head;
    }
};
