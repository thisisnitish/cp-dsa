/*
Leetcode Question 141. Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
The basic idea is check the node is present in the set or not if node is present
then return true else put the node in set and if head becomes null or moves to the
end then return false
*/

// Solution 1
class Solution
{
public:
    // Time: O(N), Space: O(1)
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> s;

        while (head)
        {
            if (s.count(head))
            {
                return true;
            }
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};

/*
We can also use, tortoise and hare algorithm where tortoise takes 1 jump and hare
takes 2 jumps and at some point of time both of them will point to a same node
*/

// Solution 2
class Solution
{
public:
    // Time: O(N), Space: O(N)
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;

        ListNode *hare, *tortoise;
        tortoise = head;
        hare = head;

        while (hare && hare->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;

            if (hare == tortoise)
                return true;
        }
        return false;
    }
};
