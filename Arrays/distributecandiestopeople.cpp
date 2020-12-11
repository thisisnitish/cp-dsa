/*
Leetcode Question 1103. Distribute Candies to People
https://leetcode.com/problems/distribute-candies-to-people/
*/

class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> result(num_people, 0);

        int i = 0, k = 1;

        while (candies > 0){
            if (candies - k >= 0)
                result[i % num_people] += k;
            else
                result[i % num_people] += candies;

            candies -= k;
            i++;
            k++;
        }
        return result;
    }
};