/*
Interviewbit Question Painter's Partition Problem
https://www.interviewbit.com/problems/painters-partition-problem/
*/

bool isValid(vector<int> &C, int max, int A)
{
    int painters = 1;
    int boardLength = 0;

    for (auto c : C)
    {
        boardLength += c;
        if (boardLength > max)
        {
            boardLength = c;
            painters++;
        }
        if (painters > A)
            return false;
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C)
{
    int low = 0, high = 0;
    for (auto c : C)
    {
        low = max(low, c);
        high += c;
    }

    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValid(C, mid, A))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return (int)((res * (long)B) % 10000003);
}
