/*
Leetcode Question 19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    //Time: O(length of LL), Space: O(1)
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (head == NULL)
            return head;

        int count = 0;
        ListNode *r = head;
        //counting the length of the list
        while (r != NULL)
        {
            count++;
            r = r->next;
        }
        int accessLessthan_n = count - n;
        if (accessLessthan_n == 0)
            return head->next;

        //removing the element from the desired position
        r = head;
        while (--accessLessthan_n)
        {
            r = r->next;
        }
        ListNode *temp;
        temp = r->next;
        r->next = temp->next;
        return head;
    }
};