class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int> &nums)
    {
        /*Solution 1
        the idea is every digit in the list will 
        occur equal number of times in the 
        begin so try all the possibilites, just remove 
        one digit from the list put it in the 
        begining and fix it and then we will left with k-1 
        digs and recurusively call it and 
        the n append at the end*/
        if (nums.size() <= 1)
            return {nums};

        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> v(nums.begin(), nums.end());
            v.erase(v.begin() + i);
            auto res = permute(v);

            for (int j = 0; j < res.size(); j++)
            {
                vector<int> _v = res[j];
                _v.insert(_v.begin(), nums[i]);
                result.push_back(_v);
            }
        }
        return result;

        //Solution 2
        /*here the basic idea is to swap the values one by one
        and store it*/
        permutations(nums, 0);
        return ans;
    }

    void permutations(vector<int> &nums, int idx)
    {
        if (idx == nums.size())
            ans.push_back(nums);

        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            permutations(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
};