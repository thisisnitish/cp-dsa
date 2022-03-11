/*
Leetcode Question 61. Rotate List
https://leetcode.com/problems/rotate-list/
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
    // Time: O(N)
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode *temp = head;
        int n = 1;
        while (temp->next)
        {
            n++;
            temp = temp->next;
        }

        k = k % n;
        // if k == 0 no rotation
        if (k == 0)
            return head;
        ListNode *newTail = head;

        // creating the new tail
        int stepsForNewTail = n - k - 1;
        while (stepsForNewTail--)
        {
            newTail = newTail->next;
        }

        // get the new head for the linked list
        ListNode *newHead = newTail->next;
        newTail->next = NULL;
        temp->next = head;

        return newHead;
    }
};
