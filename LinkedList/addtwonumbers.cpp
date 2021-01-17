/*
Leetcode Question 2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/
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
    /*the basic idea is to apply simple math, take every
    node and add them and manage carries
    Time: O(max(m,n)), Space: O(max(m,n))*/
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode();
        ListNode *temp = result;
        int carry = 0;

        while (l1 || l2)
        {
            int x = l1 != NULL ? l1->val : 0;
            int y = l2 != NULL ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10; //getting the carry

            //putting the actual value in the node
            temp->next = new ListNode(sum % 10);
            temp = temp->next;

            /*move to the next node*/
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (carry > 0)
        {
            temp->next = new ListNode(carry);
        }
        return result->next;
    }
};
