/*
Leetcode Question 735. Asteroid Collision
https://leetcode.com/problems/asteroid-collision/
*/

class Solution
{
public:
    /*the basic idea is put the first value into the stack and after that
    for the next values check the top values for all the three possibilities.
    Time: O(N)*/
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;
        int i = 0;
        while (i < asteroids.size())
        {
            if (s.empty())
            {
                s.push(asteroids[i++]);
            }
            else
            {
                if (s.top() > 0 && asteroids[i] < 0)
                {
                    if (s.top() > abs(asteroids[i]))
                        i++;
                    else if (s.top() < abs(asteroids[i]))
                        s.pop();
                    else
                    {
                        i++;
                        s.pop();
                    }
                }
                else
                {
                    s.push(asteroids[i++]);
                }
            }
        }

        vector<int> result(s.size(), 0);
        for (int i = s.size() - 1; i >= 0; i--)
        {
            result[i] = s.top();
            s.pop();
        }
        return result;
    }
};