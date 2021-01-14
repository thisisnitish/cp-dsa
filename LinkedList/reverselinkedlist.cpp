/*
Leetcode Question 206. Reverse Linked List
https://leetcode.com/problems/reverse-linked-list/
*/

//Iterative
//Time O(N), Space O(1)
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prevptr, *nextptr, *curr;
        curr = head;
        prevptr = nextptr = NULL;
        while (curr)
        {
            nextptr = curr->next;
            curr->next = prevptr;
            prevptr = curr;
            curr = nextptr;
        }
        //curr = prevptr;
        return prevptr;
    }
};

//Recursive
//Time O(N), Space O(N)
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newhead;
    }
};