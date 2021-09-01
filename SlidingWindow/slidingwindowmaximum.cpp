/*
Leetcode Question 239. Sliding Window Maximum
https://leetcode.com/problems/sliding-window-maximum/
*/

class Solution
{
public:
    //Time: O(N), Space: O(M)
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        //Base case
        if (k >= nums.size())
        {
            return {*max_element(nums.begin(), nums.end())};
        }

        int i = 0, j = 0;
        vector<int> result;
        deque<int> dq;

        while (j < nums.size())
        {
            //Calculation I
            /*
            we are removing those elements from the deque which are smaller than the
            upcoming element
            */
            while (dq.size() > 0 && dq.back() < nums[j])
            {
                dq.pop_back();
            }
            dq.push_back(nums[j]);

            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                //Calculation II
                /*
                our maximum element for any window of size k will be in front of the deque
                */
                result.push_back(dq.front());
                if (dq.front() == nums[i])
                {
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return result;
    }
};
