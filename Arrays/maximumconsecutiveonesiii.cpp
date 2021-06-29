/*
Leetcode Question 1004. Max Consecutive Ones III
https://leetcode.com/problems/max-consecutive-ones-iii/
*/

/*
The idea is simple, use two pointer approach, when you encounter one increase the pointer by 1 
and when you encounter 0 decrease k and increase the pointer untill it becomes 0, then take 
the length and store it. Again if k = 0, then move the left pointer till k = 1, inorder to 
create a new window.
*/
class Solution
{
public:
    //Time: O(N), Space: O(1)
    int longestOnes(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        int n = nums.size();
        int len = 0;
        while (j < n)
        {
            //if nums[j] = 1
            if (nums[j])
                j++;
            else
            {
                //if nums[j] = 0, there could be two possible situation, k=0 or k!=0
                if (k == 0)
                {
                    len = max(len, j - i);

                    //to create a new window shift the left pointer till k = 1
                    while (k == 0)
                    {
                        if (nums[i])
                            i++;
                        else
                            k++, i++;
                    }
                }
                else //decrease the k value and increase the pointer
                    k--, j++;
            }
        }
        //return the maximum length
        len = max(len, (j - i));
        return len;
    }
};
