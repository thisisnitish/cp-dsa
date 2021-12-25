/*
Leetcode Question 143. Reorder List
https://leetcode.com/problems/reorder-list/
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
/*
This is a 3 step solution:
1. Find the Length of the LL and and break into two pieces
2. Reverse the second part of Linked List
3. Merge both the Linked List
*/
class Solution
{
public:
    // Time: O(N)
    int countLengthOfLL(ListNode *temp)
    {
        int len = 0;
        while (temp)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode *reverseLL(ListNode *temp2)
    {
        ListNode *prevptr, *nextptr, *curr;
        curr = temp2;
        prevptr = nextptr = NULL;
        while (curr)
        {
            nextptr = curr->next;
            curr->next = prevptr;
            prevptr = curr;
            curr = nextptr;
        }
        return prevptr;
    }

    ListNode *mergeList(ListNode *temp1, ListNode *rrLL)
    {
        ListNode *result1 = new ListNode();
        ListNode *result = result1;

        while (temp1 && rrLL)
        {
            result->next = temp1;
            temp1 = temp1->next;
            result = result->next;
            result->next = rrLL;
            rrLL = rrLL->next;
            result = result->next;
        }

        if (temp1)
            result->next = temp1;
        if (rrLL)
            result->next = rrLL;

        result = result1->next;
        delete result1;
        return result;
    }

    void reorderList(ListNode *head)
    {
        if (!head)
            return;

        int length = countLengthOfLL(head);
        int breakLL = length / 2;

        ListNode *temp1 = head;
        int i = 0;
        while (i < breakLL - 1)
        {
            temp1 = temp1->next;
            i++;
        }
        ListNode *temp2;
        temp2 = temp1->next;
        temp1->next = NULL;
        temp1 = head;
        ListNode *rrLL = reverseLL(temp2);
        head = NULL;
        head = mergeList(temp1, rrLL);
    }
};
