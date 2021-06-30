/*
Leetcode Question 171. Excel Sheet Column Number
https://leetcode.com/problems/excel-sheet-column-number/
*/

/*
The idea is, if there is a single character use number from 1 to 26 but when there are more 
than one charaters such as AA, AB, ABC etc. then we have to do some calculations
example: AB => A*26^1 + B*26^2, Now if you will calculate this you will get the exact column 
number. Similary we can do for all the strings.
*/
class Solution
{
public:
    //Time: O(N), Space: O(1)
    int titleToNumber(string columnTitle)
    {
        int result = 0;
        for (auto c : columnTitle)
        {
            int n = c - 'A' + 1;
            result = result * 26 + n;
        }
        return result;
    }
};
