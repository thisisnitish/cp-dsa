/*
Leetcode Question 328. Odd Even Linked List
https://leetcode.com/problems/odd-even-linked-list/
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
    /*basic idea is to create two temporary LL, and 
    find the length of the original LL, then according 
    to index, insert the node into the temporary LL.
    Time: O(N), Space: O(1)*/
    ListNode *oddEvenList(ListNode *head)
    {

        if (head == NULL)
            return NULL;
        //for even list
        ListNode *list1 = new ListNode();
        ListNode *l1 = list1;

        //for odd list
        ListNode *list2 = new ListNode();
        ListNode *l2 = list2;

        int length = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        //cout<<length<<endl;
        for (int i = 1; i <= length; i++)
        {
            if (i % 2 == 0)
            {
                ListNode *temp1 = new ListNode(head->val);
                l1->next = temp1;
                l1 = l1->next;
                head = head->next;
            }
            else
            {
                ListNode *temp2 = new ListNode(head->val);
                l2->next = temp2;
                l2 = l2->next;
                head = head->next;
            }
        }
        l2->next = list1->next;
        return list2->next;
    }
};

//Solution 2
class Solution
{
public:
    /*besic idea is to change the links, but be careful
    while implementing this logic. Time: O(N), O(1)*/
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        ListNode *odd = head, *even = head->next, *evenHead = even;

        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};