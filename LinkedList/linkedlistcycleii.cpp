/*
Leetcode Question 142. Linked List Cycle II
https://leetcode.com/problems/linked-list-cycle-ii/
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
    /*the basic idea is follow the procedure of
    detecting the cycle in LL and then when the
    hare and tortoise meet reset the tortoise to 
    head and then move forward tortoise and hare 
    one by one, again they will meet then that 
    will be the answer Time: O(N)*/
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *hare, *tortoise;
        hare = head;
        tortoise = head;

        while (hare && hare->next)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;

            if (hare == tortoise)
            {
                tortoise = head;

                while (hare != tortoise)
                {
                    hare = hare->next;
                    tortoise = tortoise->next;
                }
                /*can return tortoise also*/
                return hare;
            }
        }
        return NULL;
    }
};