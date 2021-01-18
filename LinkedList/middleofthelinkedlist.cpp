/*
Leetcode Question 876. Middle of the Linked List
https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode *middleNode(ListNode *head)
    {

        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};