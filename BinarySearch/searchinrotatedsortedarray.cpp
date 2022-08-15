/*
Leetcode Question 33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

/*
See, if the array is rotated, we need to think that one side of the array will be 
sorted. So, everytime the bounds are changing, we are checking that which side is
sorted and based on that we are moving.
*/

class Solution {
public:
    // Time: O(logN), Space: O(1)
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            // if we get the element
            if(nums[mid] == target) return mid;
            
            // if left side is rotated
            if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target <= nums[mid]) high = mid-1;
                else low = mid+1;
            }
            // if the right side is rotated i.e. nums[mid] <= nums[high]
            else{
                if(target >= nums[mid] && target <= nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};
