/*
Leetcode Question 1337. The K Weakest Rows in a Matrix
https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
*/

class Solution
{
public:
    //Time: O(mlogn + mlogk), Space: O(k)
    vector<int> kWeakestRows(vector<vector<int> > &mat, int k)
    {
        priority_queue<pair<int, int> > maxHeap;

        for (int i = 0; i < mat.size(); i++)
        {
            int count = findOnes(mat[i]);

            maxHeap.push({count, i});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<int> result;
        while (maxHeap.size() > 0)
        {
            int x = maxHeap.top().second;
            maxHeap.pop();
            result.push_back(x);
        }

        reverse(result.begin(), result.end());
        return result;
    }

    int findOnes(vector<int> &v)
    {
        if (v[0] == 0)
            return 0;

        int low = 0, high = v.size() - 1;
        int result = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (v[mid] == 1)
            {
                result = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return result + 1;
    }
};
