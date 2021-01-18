/*
Leetcode Question 160. Intersection of Two Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    /*the basic idea is to traverse the list and find
    the length and diff and that diff will decide the 
    index of the longer list and then start comparing 
    elements one by one. Time: O(N)*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lengthA = 0, lengthB = 0;
        ListNode *tempA, *tempB;
        tempA = headA;
        tempB = headB;

        while (tempA != NULL)
        {
            lengthA++;
            tempA = tempA->next;
        }

        while (tempB != NULL)
        {
            lengthB++;
            tempB = tempB->next;
        }

        int difference = 0;
        /*re-initialize the tempA and tempB*/
        tempA = headA;
        tempB = headB;

        if (lengthA > lengthB)
        {
            difference = lengthA - lengthB;
            for (int i = 0; i < difference; i++)
                tempA = tempA->next;
        }
        else
        {
            difference = lengthB - lengthA;
            for (int i = 0; i < difference; i++)
                tempB = tempB->next;
        }

        while (tempA && tempB)
        {
            if (tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};