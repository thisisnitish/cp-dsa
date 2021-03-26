/*
First negative integer in every window of size k
https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/0#
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    //code
    /*the basic idea is to use queue, take the first negative number from 
	the first k values from the subarrays and then start loop from k to n
	and delete all the previous values from the queue and find rest of the
	values Time: O(N)*/
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int k;
        cin >> k;

        queue<int> q;
        for (int i = 0; i < k; i++)
        {
            if (a[i] < 0)
            {
                q.push(i);
            }
        }

        if (!q.empty())
            cout << a[q.front()] << " ";
        else
            cout << "0"
                 << " ";

        for (int i = k; i < n; i++)
        {

            while (!q.empty() && q.front() <= (i - k))
                q.pop();

            if (a[i] < 0)
                q.push(i);

            if (q.empty())
                cout << "0"
                     << " ";
            else
                cout << a[q.front()] << " ";
        }
        cout << endl;
    }
    return 0;
}