/*
Leetcode Question 871. Minimum Number of Refueling Stops
https://leetcode.com/problems/minimum-number-of-refueling-stops/
*/

/*
-- We need to keep track of the all the stations where car can react with currentFuel
-- We need to stop at those stations which can fill the car with maximum fuel

We have two choices:
1. Either the car don't have enough fuel to reach the station
2. Either car covered all the stations and unable to reach the destination
In both the cases we need to return -1 as car can't reach target

As we know that we need to keep track of all the stations that car can cover and among them car can stop at the station which has maximum fuel

Hence, we need to keep track of all the stations which has a maximum fuel, And it can be achieved by maxHeap
*/
class Solution
{
public:
    //Time: O(nlogn), Space: O(n)
    int minRefuelStops(int target, int startFuel, vector<vector<int> > &stations)
    {
        priority_queue<int> maxHeap;

        int n = stations.size();
        int currentPosition = 0, minStops = 0;

        while (startFuel < target)
        {
            while (currentPosition < n and startFuel >= stations[currentPosition][0])
            {
                maxHeap.push(stations[currentPosition][1]); //filling the gas
                currentPosition++;
            }

            if (maxHeap.empty())
                return -1;

            startFuel += maxHeap.top();
            maxHeap.pop();
            minStops++;
        }
        return minStops;
    }
};
