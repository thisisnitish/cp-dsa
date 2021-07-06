/*
Leetcode Question 1338. Reduce Array Size to The Half
https://leetcode.com/problems/reduce-array-size-to-the-half/
*/
/*
We need to choose the smallest set of numbers such that deleting all their occurrences will
reduce the array size by atleast half. To accomplish this, we need to delete the numbers
having higher frequencies so that the size is minimized.
*/
class Solution
{
public:
    //Time: O(N + N + NlogN), Space: O(N)
    int minSetSize(vector<int> &arr)
    {

        //calculate the frequency of the numbers
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]]++;

        //store the frequencies in vector
        vector<int> v;
        for (auto x : mp)
            v.push_back(x.second);

        //sort the frequencies in descending order
        sort(v.begin(), v.end(), greater<int>());

        //numbers having maximum frequency should be deleted so that we will get the set with
        //atleast size >= half of the array size
        int deleteNumbers = 0;
        int result = 0;
        for (auto y : v)
        {
            deleteNumbers += y;
            result++;
            if (deleteNumbers >= arr.size() / 2)
                return result;
        }
        return -1;
    }
};
