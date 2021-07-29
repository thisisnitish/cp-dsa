/*
Leetcode Question 78. Subsets
https://leetcode.com/problems/subsets/
*/

//Easy and Recommended
//Recursion
class Solution
{
public:
    vector<vector<int> > result;
    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<int> v;
        helper(nums, v);
        return result;
    }
    void helper(vector<int> nums, vector<int> v)
    {
        //when the nums get empty we will get the subset
        if (nums.size() == 0)
        {
            //push back to the result
            result.push_back(v);
            return;
        }

        auto v1 = v;
        auto v2 = v;
        v2.push_back(nums[0]);

        nums.erase(nums.begin() + 0);

        helper(nums, v1);
        helper(nums, v2);
        return;
    }
};

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
            /*if you are trying iteration then you use 
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

//BackTracking
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> subset;
        vector<int> current; //to save the small lists
        findSubset(subset, 0, nums, current);
        return subset;
    }

    void findSubset(vector<vector<int>> &subset, int index, vector<int> &nums, vector<int> &current)
    {
        //adding the empty list first of all
        subset.push_back(current);
        for (int i = index; i < nums.size(); i++)
        {
            current.push_back(nums[i]);
            findSubset(subset, i + 1, nums, current);
            current.pop_back();
        }
    }
};

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
