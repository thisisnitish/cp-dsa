/*
Leetcode Question 134. Gas Station
https://leetcode.com/problems/gas-station/
*/

//Solution 1
class Solution
{
public:
    //Time: O(n), Space: O(1)
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int totalFuel = 0;
        int currentFuel = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            totalFuel += gas[i] - cost[i];
            currentFuel += gas[i] - cost[i];

            /*if the current fuel is < 0 then Obviously, we have to change the start point
            so the start point will be more than from the current position*/
            if (currentFuel < 0)
            {
                currentFuel = 0;
                start = i + 1;
            }
        }

        //checking if the total fuel is < 0 then return -1 else return starting point
        if (totalFuel < 0)
            return -1;
        return start;
    }
};

//Solution 2
class Solution
{
public:
    //Time: O(n), Space: O(1)
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int g = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            g += gas[i];
            c += cost[i];
        }

        if (g < c)
            return -1;
        int start = 0;
        int fuel = 0;
        for (int i = 0; i < n; i++)
        {
            fuel += (gas[i] - cost[i]);
            if (fuel < 0)
            {
                fuel = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
