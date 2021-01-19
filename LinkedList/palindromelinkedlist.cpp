/*
Leetcode Question 234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list/
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
    //Time: O(N), Space: O(N)
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
            return true;

        vector<int> v;
        ListNode *temp = head;

        while (temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }

        for (int i = 0; i < v.size() / 2; i++)
        {
            if (v[i] != v[v.size() - i - 1])
                return false;
        }
        return true;
    }
};

//Solution 2
class Solution
{
public:
    //Time: O(N), Space: O(1)
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
            return true;

        ListNode *slow, *fast;
        slow = head;
        fast = head;

        //dividing the LL into two halves
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //fast = slow->next;
        //slow->next = NULL;

        /*reversing the first LL*/
        ListNode *curr, *prev, *next;
        curr = head;
        prev = next = NULL;

        while (curr != slow)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (fast)
        {
            slow = slow->next;
        }

        while (prev && slow)
        {
            if (prev->val != slow->val)
                return false;
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};
