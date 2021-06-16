/*
Leetcode Question 1859. Sorting the Sentence
https://leetcode.com/problems/sorting-the-sentence/
*/

/*
As the hints is given in the question that convert the sentence into array of strings.
So, first try do that don't look at the solution. First, convert the sentence to vector of
string and if you are done with that then think of how you can use the numbers to order the 
strings.

So, if you will see carefully you can use those numbers as index for that word. Now, you have
two things in your hand, index of the word and the word which we want
example: abcd5 => before putting into the array take the number and use it as a index and
rest of the string as you desired result.

Now you will have to use a data structure that can provide you one to one mapping, you can 
map, but i'm using vector of pairs. Now push two data to the vector, the string and the idx
along with that string.

At the end, sort the vector according to the index in ascending order and return string.
*/
class Solution
{
public:
    //Time: O(nlogn), Space: O(n)
    string sortSentence(string s)
    {
        vector<pair<int, string> > v;

        string word = "";
        for (auto x : s)
        {
            if (x == ' ')
            {
                int len = word.length();
                int idx = word[len - 1] - '0';
                string residue = word.substr(0, len - 1);
                v.push_back({idx, residue});
                word = "";
            }
            else
            {
                word += x;
            }
        }

        int idx = word[word.length() - 1] - '0';
        string residue = word.substr(0, word.length() - 1);
        v.push_back({idx, residue});

        sort(v.begin(), v.end());

        string result = "";
        for (int i = 0; i < v.size(); i++)
        {
            result += v[i].second;
            if (i != v.size() - 1)
                result += " ";
        }

        return result;
    }
};
