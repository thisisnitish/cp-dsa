/*
Leetcode Question 24. Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/
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
    //Time: O(N)
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *prev;
        ListNode *temp;
        prev = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
            swap(prev->val, temp->val);
            temp = temp->next;
            if (temp == NULL)
                break;
        }
        return (head);
    }
};

// Solution 2
class Solution
{
public:
    //Time: O(N)
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = head;
        head = head->next;
        temp->next = head->next;
        head->next = temp;

        temp->next = swapPairs(temp->next);
        return head;
    }
};
