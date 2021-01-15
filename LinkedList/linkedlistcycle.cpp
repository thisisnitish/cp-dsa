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
//Hashing
class Solution {
public:
    /*the basic idea is check the node is 
    present in the set or not if node is present
    then return true else put the node in set
    Time: O(N), Space: O(N)*/
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        
        while(head){
            if(s.find(head) != s.end()){
                return true;
            }
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};

//Floyd's Tortoise and Hare Algorithm
class Solution
{
public:
    /*the basic idea is take two pointers
    first move one position & second move two position
    but at a time both will point to the same node then 
    return true else return false
    Time: O(N), Space: O(1)*/
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;

        ListNode *hare, *tortoise;
        tortoise = head;
        hare = head->next;

        while (hare != tortoise)
        {
            if (hare == NULL || hare->next == NULL)
                return false;

            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return true;
    }
};
