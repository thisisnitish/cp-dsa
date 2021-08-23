/*
InterviewBit Question Allocate Books
https://www.interviewbit.com/problems/allocate-books/
*/

bool isValid(vector<int> &A, int B, int max)
{
    int students = 1;
    int pages = 0; //Number of pages assigned to students
    for (auto page : A)
    {
        pages += page; //page is number of page for any book

        /*if the number of paegs assigned to a single student is more than the max
        then increase the number of students and also assign page to pages which
        caused increase in number of pages for previous student*/
        if (pages > max)
        {
            students++;
            pages = page;
        }
        //if number of students is more than the number of students given in question
        if (students > B)
            return false;
    }
    //if everything goes alright
    return true;
}

int Solution::books(vector<int> &A, int B)
{
    if (A.size() < B)
        return -1;

    int low = INT_MIN, high = 0;
    for (auto x : A)
    {
        low = max(low, x);
        high += x;
    }

    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValid(A, B, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return result;
}
