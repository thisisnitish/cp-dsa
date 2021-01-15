/*
Leetcode Question 25. Reverse Nodes in k-Group
https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    /*the basic idea is reverse the first k nodes in LL
    and then recursively call the function for rest of the 
    LL but this is not the standard reverse k node problem, 
    the change is if the nodes in LL is not the multiple of 
    k then remain those as it is
    Time Complexity: O(N)*/
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        int length = 0;
        /*here we are counting the length of LL
        and checking if length >= k then we have 
        enough nodes to reverse and else return head*/
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
            if (length >= k)
                break;
        }
        if (length < k)
            return head;

        ListNode *prevptr, *nextptr, *curr;
        prevptr = nextptr = NULL;
        curr = head;
        int count = 0;

        while (curr != NULL && count < k)
        {
            nextptr = curr->next;
            curr->next = prevptr;
            prevptr = curr;
            curr = nextptr;
            count++;
        }

        if (nextptr != NULL)
        {
            head->next = reverseKGroup(nextptr, k);
        }
        return prevptr;
    }
};