/*
Leetcode Question 90. Subsets II
https://leetcode.com/problems/subsets-ii/
*/

//Recursion
class Solution {
public:
    //Time: O(2^n + nlogn), Space: O(n)
    vector<vector<int>> result;
    set<vector<int>> s;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> op;
        //sorting to avoid the duplicates
        sort(nums.begin(), nums.end());
        helper(nums, op);
        return result;
    }
    
    void helper(vector<int> nums, vector<int> op){
        if(nums.size() == 0){
            
            //if the elements doesn't exits in set then insert it
            if(s.find(op) == s.end()){
                s.insert(op);
                result.push_back(op);
            }
            return;
        }
        
        //have two choices, either take the element or don't take it
        //for op1 we are not taking at all but for op2 we are taking
        auto op1 = op;
        auto op2 = op;
        op2.push_back(nums[0]);
        
        //remove the first element from the input
        nums.erase(nums.begin()+0);
        
        //recursively call the function
        helper(nums, op1);
        helper(nums, op2);
    }
};

//BackTracking
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
        vector<vector<int>> subset;
        
        if(nums.empty()) return subset;
        
        /*main reason for sorting the elements is 
        putting the same elements together
        so that we will remove the duplicacy*/
        sort(nums.begin(), nums.end());
        vector<int> current;
        findSubsets(subset, 0, nums, current);
        return subset;
    }
    
    void findSubsets(vector<vector<int>>& subset, int index, vector<int>& nums, vector<int>& current){
        subset.push_back(current);
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            
            current.push_back(nums[i]);
            findSubsets(subset, i+1, nums, current);
            current.pop_back();
        }
    }
};
