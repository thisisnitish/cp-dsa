/*
Leetcode Question 779. K-th Symbol in Grammar
https://leetcode.com/problems/k-th-symbol-in-grammar/
*/

/*
This is a pretty good problem. One thing I would say this question ask you for your
observation skills. Let get back to the question.

It says that, there are two inputs n and k. n define the rows and k defines the index of the
row that we want as a result. Now, let's explore some example
As the question says, the first row will be 1 and for subsequent rows, we look at the
previous row and replace each 0 => 01 and each 1 => 10
Examples:
n = 1 | 0
n = 2 | 0, 1
n = 3 | 0, 1, 1, 0

Let's make it more representable clear understanding
n | k 1 2 3 4 5 6 7 8
----------------------
1 |   0
----------------------
2 |   0 1
----------------------
3 |   0 1 1 0
----------------------
4 |   0 1 1 0 1 0 0 1

Now, you can explore the test cases of question from the table that we made.

I think we understood the problem.
Now, If we think again we found that this question is recursively define itself, like it says
that for current row, go to the previous row like that.
So, we can design the hypothesis for our function based on previous stuff we did, say our 
function is solve(n, k) take two params n and k.

Hypothesis:
1. solve(n, k) => output will be either 0 or 1
2. For smaller inputs, solve(n-1, ?), Here we see that we can go to the previous row as the
question says so we are decreasing n by 1. But what about k? we can't simply decrease it, as
you can see from the above table.

Now, it's time for observation. Look at the table, pause and think once.
1. If you look at the table you will find that, the length of row is increasing twice for 
every successive row.
2. n = 3, 0 1 1 0
   n = 4, 0 1 1 0 1 0 0 1
   Now, if you see this example and if you divide the row n=4 into two parts, you will find
   that the first half is same as the n=3. But for the second half, it is the complement of
   the n=3 for every element. Just think and draw on paper you will get.

In conlclusion,
1. length of the row = 2^(n-1)
2. Also, if k <= mid or if the k belongs to the first half then we can call the function like
    solve(n-1, k). But if k > mid or if the k belongs to the second half then we can call the
    function like !(solve(n-1, k-mid)) as we discussed earlier.

Also the base condition,
1. when n == 1 and k == 1 then return 0
*/
class Solution
{
public:
    //Time: O(N), Space: O(N)
    int kthGrammar(int n, int k)
    {
        //base condition
        if (n == 1 && k == 1)
            return 0;

        //length of the row
        int lengthOfRow = pow(2, n - 1);
        //calculating the mid
        int mid = lengthOfRow / 2;

        //if k belongs to the first half
        if (k <= mid)
        {
            return kthGrammar(n - 1, k);
        }
        //if k belongs to the second half
        else
        {
            return !(kthGrammar(n - 1, k - mid));
        }
    }
};
