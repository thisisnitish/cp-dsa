/*
Leetcode Question 78. Subsets
https://leetcode.com/problems/subsets/
*/

//Solution 1
//Backtracking Recursion
class Solution
{
public:
    //we can do with the iterative approach
    void subsets_rec(vector<int> &nums, int idx, vector<vector<int>> &result)
    {
        /*recursively calling the function 
        and at the end if only one element 
        will left push to the result*/
        if (idx == nums.size() - 1)
        {
            result.push_back({});
            result.push_back({nums[idx]});
        }
        else
        {
            //here we are calling for next index
            subsets_rec(nums, idx + 1, result);
            /*if you are trying recursion then you use 
            one loop for elements one by one and then 
            copy the entire below part in that loop and
            replace nums[idx] with nums element*/
            int n = result.size();
            for (int i = 0; i < n; i++)
            {
                vector<int> r = result[i];
                r.push_back(nums[idx]);
                result.push_back(r);
            }
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        //Time- O(N*2^N)
        if (nums.empty())
            return {{}};

        vector<vector<int>> result;
        subsets_rec(nums, 0, result);

        return result;
    }
};

//Solution 2
//Bit Manipulation

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> result;
        for (int i = 0; i < (1 << nums.size()); i++)
        { // 1<<nums.size() => 2^nums.size();
            vector<int> temp;
            for (int j = 0; j < nums.size(); j++)
            { //this loop for positions for a number
                if (i & (1 << j))
                { // check a bit is set or unset
                    temp.push_back(nums[j]);
                }
            }
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
}
