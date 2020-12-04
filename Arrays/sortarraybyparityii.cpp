/*
Leetcode Question 922. Sort Array By Parity II
https://leetcode.com/problems/sort-array-by-parity-ii/
*/

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        vector<int> odd;
        vector<int> even;
        int n = A.size();
        // vector<int> result;   //can use one extra array also

        for (int i = 0; i < n; i++){
            if (A[i] % 2 == 0){
                even.push_back(A[i]);
            }
            else
                odd.push_back(A[i]);
        }
        A.clear();
        for (int i = 0; i < n / 2; i++){
            A.push_back(even[i]);
            A.push_back(odd[i]);
        }
        return A;
    }
};