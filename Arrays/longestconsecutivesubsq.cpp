/*
Leetcode Question 128. Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence/
*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        //Solution 1
        //Time: O(nlogn) Space: O(1) or O(n)
        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int longsubs = 1;
        int currsubs = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1]+1){
                    currsubs += 1;
                }
                else{
                    longsubs = max(longsubs, currsubs);
                    currsubs = 1;
                }
            }
        }
        //this last max statement is for the end case
        return max(longsubs, currsubs);
    
        //Solution 2
        //Time: O(n), Space: O(n)
        // we can use set also in place of unordered_set, I've tried and it worked
        unordered_set<int> arr;

        for (auto x : nums)
            arr.emplace(x);

        int maxsubs = 0;

        for (auto item : arr){
            if (!arr.count(item - 1)){
                int currentnum = item;
                int currsubs = 1;

                while (arr.count(currentnum + 1)){
                    currentnum += 1;
                    currsubs += 1;
                }

                maxsubs = max(maxsubs, currsubs);
            }
        }
        return maxsubs;
    }
};

//Solution 2
//Time: O(n), Space: O(n)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // we can use set also in place of unordered_set, I've tried and it worked
        unordered_set<int> arr;

        for (auto x : nums)
            arr.emplace(x);

        int maxsubs = 0;

        for (auto item : arr){
            if (!arr.count(item - 1)){
                int currentnum = item;
                int currsubs = 1;

                while (arr.count(currentnum + 1)){
                    currentnum += 1;
                    currsubs += 1;
                }

                maxsubs = max(maxsubs, currsubs);
            }
        }
        return maxsubs;
    }
};
