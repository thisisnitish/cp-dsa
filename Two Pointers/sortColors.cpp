/*
Leetcode Question 75. Sort Colors
https://leetcode.com/problems/sort-colors/
*/

//Soultion 1
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        
        int count_zero = 0;
        int count_one = 0;
        int count_two = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                count_zero++;
            else if(nums[i] == 1)
                count_one++;
            else if(nums[i] == 2)
                count_two++;
        }
        
        nums.clear();
        
        for(int i=0; i<count_zero; i++)
            nums.push_back(0);
        
        for(int i=0; i<count_one; i++)
            nums.push_back(1);
        
        for(int i=0; i<count_two; i++)
            nums.push_back(2);
    }
};

//Solution 2
//Dutch National Flag Algorithm
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1, mid = 0;

        while (mid <= high){
            if (nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1){
                mid++;
            }
            else if (nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};