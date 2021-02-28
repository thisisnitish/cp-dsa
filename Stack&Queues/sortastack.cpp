/*
Sort a stack 
https://practice.geeksforgeeks.org/problems/sort-a-stack/1#
*/

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

/*the basic idea constantly pop the element from stack and 
then call insert function to insert it. For insertion check if the
stack is empty or not of if the top element in smaller than the element
which is going to insert. Time: O(N*N), Space: O(N)
I've used recursion just to explore the concept of recursion,
otherwise we can use any method*/

void stackInsert(stack<int> &s, int ele)
{
    if (s.empty() || ele > s.top())
    {
        s.push(ele);
    }
    else
    {
        int temp = s.top();
        s.pop();
        stackInsert(s, ele);
        s.push(temp);
    }
}

void SortedStack ::sort()
{
    //Your code here
    if (!s.empty())
    {
        int temp = s.top();
        s.pop();
        SortedStack::sort();
        stackInsert(s, temp);
    }
}