/*
Leetcode Question 1823. Find the Winner of the Circular Game
https://leetcode.com/problems/find-the-winner-of-the-circular-game/
*/

/*
This is a classic josephus problem. It's very easy to implement but the main part of this
question is to understand that what it is saying. Let's solve this together.

So, the question says, there are n friends sitting in a circle and we have also one more
variable k. As the rule says, start from the 1st friend and count the next k friends in
clockwise direction including the friend you started at. Now, the last friend you counted
after k leaves the circle and loses the game. See figure below,

In the figure you can see that n=5, and k=2. If you will dry run this example you will endup
having 3 as a winner of the game.
So, now we have understood the problem so far.

Now, if we flatten the cirlce into an array, so it will be
1, 2, 3, 4, 5 for n = 5, k=2
Now, here we know that the players are leaving the game after the k count, or effectively we
can say that the elements are getting deleted. Also, let's design our hypothesis function
that how it will work.

We can see that we are at 5 now from the above figure but still we have to delete some ele
from the array but don't know how to move further because if we do so we will have index
overflow problem. So, to remove this we can do something like,
index = (index + k) % v.size()

Now, we have everything set, Let's talk about the base:
If the array size is 1 then just return the element because we have a winner.
Discuss:
https://leetcode.com/problems/find-the-winner-of-the-circular-game/discuss/1398924/Find-the-Winner-of-the-Circular-Game-oror-CPPC%2B%2B-oror-with-explanation
*/
class Solution
{
public:
    //Time: O(N), Space: O(N)
    int findTheWinner(int n, int k)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }

        k = k - 1;
        int index = 0;
        int result = -1;
        helper(v, k, index, result);
        return result;
    }

    void helper(vector<int> &v, int k, int index, int &result)
    {
        //Base condition
        if (v.size() == 1)
        {
            result = v[0];
            return;
        }

        //handles the index overflow
        index = (index + k) % v.size();
        //player will leave the circle
        v.erase(v.begin() + index);
        helper(v, k, index, result);
    }
};
