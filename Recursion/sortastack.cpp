/*
Sort a stack
https://practice.geeksforgeeks.org/problems/sort-a-stack/1
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
//We can sort the stack in ascending order as well with the
//help of same code
//Time: O(N*N), Space: O(N)
void insert(stack<int> &s, int temp)
{
    if (s.size() == 0 || s.top() <= temp)
    {
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void sortStack(stack<int> &s)
{
    if (s.size() == 1)
        return;
    int val = s.top();
    s.pop();
    sortStack(s);
    insert(s, val);
}

void SortedStack ::sort()
{
    sortStack(s);
}
