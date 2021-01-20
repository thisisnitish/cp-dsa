/*
Leetcode Question 1019. Next Greater Node In Linked List
https://leetcode.com/problems/next-greater-node-in-linked-list/
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
    /*basic idea is to traverse through the list
    and compare one by one. Time: O(N^2), Space: O(1)*/
    vector<int> nextLargerNodes(ListNode *head)
    {

        if (head == NULL)
            return {};

        vector<int> result;
        while (head != NULL)
        {
            int x = head->val;
            ListNode *temp = head->next;

            while (temp != NULL)
            {
                if (x < temp->val)
                {
                    result.push_back(temp->val);
                    break;
                }
                temp = temp->next;
            }

            if (temp == NULL)
            {
                result.push_back(0);
            }
            head = head->next;
        }
        return result;
    }
};
