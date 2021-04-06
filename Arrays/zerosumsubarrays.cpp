/*
Zero Sum Subarrays 
https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#
*/

class Solution
{
public:
    //Function to count subarrays with sum equal to 0.
    /*the basic idea is to use the hashmap and store the count
    of 0 sum and traverse the array and add each element and check
    every time whether it is present in the map or not, if yes then
    add to the count and return else go through the loop.
    Time: O(N), Space: O(N)*/
    ll findSubarray(vector<ll> arr, int n)
    {
        //code here
        ll count = 0;
        unordered_map<ll, ll> mp;
        mp[0] = 1;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (mp.find(sum) != mp.end())
            {
                count += mp[sum];
                mp[sum]++;
            }
            else
            {
                //creating the new pair
                mp[sum]++;
            }
        }
        return count;
    }
};
