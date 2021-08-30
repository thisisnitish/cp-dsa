/*
Maximum of all subarrays of size k
https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#
*/

class Solution
{
public:
    //Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *nums, int n, int k)
    {
        vector<int> ans;
        deque<int> q;
        int i = 0, j = 0;

        while (j < n)
        {
            //calculation 1
            while (q.size() > 0 && q.back() < nums[j])
                q.pop_back();
            q.push_back(nums[j]);

            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                //store the maximum element of that window
                //maximum element will always be in front
                ans.push_back(q.front());
                //before sliding the window if the nums[i] and q.front()
                //are equal then remove the element, if not don't remove it
                if (q.front() == nums[i])
                    q.pop_front();

                i++;
                j++;
            }
        }
        return ans;
    }
};
