/*
Leetcode Question 1346. Check If N and Its Double Exist
https://leetcode.com/problems/check-if-n-and-its-double-exist/
*/

class Solution
{
public:
    //Time: O(nlogn + nlogn), Space: O(n)
    bool checkIfExist(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            if (helper(arr, 2 * arr[i], i))
                return true;
        }
        return false;
    }

    int helper(vector<int> &arr, int target, int idx)
    {
        int low = 0, high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target && idx != mid)
                return true;
            else if (target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};

class Solution
{
public:
    //Time: O(n), Space: O(n)
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> s;
        for (auto x : arr)
        {
            if (s.find(2 * x) != s.end() || x % 2 == 0 && s.find(x / 2) != s.end())
                return true;
            s.insert(x);
        }
        return false;
    }
};
