/*
Leetcode Question 42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        //Todo: Do with stack approach, dynamic programming also
        //Solution 1
        //Time: O(n2), Space: O(1)
        int collectwater = 0;
        for(int i=1; i<height.size(); i++){
            int left_max = 0, right_max = 0;
            
            for(int j=i; j>=0; j--){
                left_max = max(left_max, height[j]);
            }
            
            for(int k=i; k<height.size(); k++){
                right_max = max(right_max, height[k]);
            }
            
            collectwater += min(left_max, right_max) - height[i];
        }
        return collectwater;

        //Solution 2
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int result = 0;

        while (left < right){
            if (height[left] < height[right]){
                height[left] >= left_max ? left_max = height[left] : result += (left_max - height[left]);
                left++;
            }
            else{
                height[right] >= right_max ? right_max = height[right] : result += (right_max - height[right]);
                right--;
            }
        }
        return result;
    }
};