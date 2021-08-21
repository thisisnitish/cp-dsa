/*
Leetcode Question 46. Permutations
https://leetcode.com/problems/permutations/
*/

//Solution 1
class Solution
{
public:
    //Time: O(N.N!), Space: O(N)
    vector<vector<int> > permutations;
    vector<vector<int> > permute(vector<int> &nums)
    {
        generatePermutations(nums, 0);
        return permutations;
    }

    void generatePermutations(vector<int> &nums, int idx)
    {
        //if we reach at the end
        if (idx == nums.size())
        {
            permutations.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            generatePermutations(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
};

/*
Solution 2
the idea is every digit in the list will 
occur equal number of times in the 
begin so try all the possibilites, just remove 
one digit from the list put it in the 
begining and fix it and then we will left with k-1 
digs and recurusively call it and 
the n append at the end
*/
class Solution
{
public:
    vector<vector<int> > ans;
    vector<vector<int> > permute(vector<int> &nums)
    {

        if (nums.size() <= 1)
            return {nums};

        vector<vector<int> > result;

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
    }
};
