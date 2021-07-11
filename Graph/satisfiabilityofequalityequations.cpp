/*
Leetcode Question 990. Satisfiability of Equality Equations
https://leetcode.com/problems/satisfiability-of-equality-equations/
*/

/*
The idea is simple if the variables are equal then they belong to same component and if not
then they don't. We will be using union-find algorithm for this. First if the variablse are 
equal then union them and make them as a single component. Now, check for those variables 
which are not equal, if they belong to same component then return false else return true.
*/
class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        //parent array
        vector<int> parent(26, 0);
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        //first union the variables
        for (auto eq : equations)
        {
            if (eq[1] == '=')
            {
                uni(eq[0], eq[3], parent);
            }
        }

        //now if the two variables are not same and they are in same component then return
        //false
        for (auto eq : equations)
        {
            if (eq[1] == '!')
            {
                int x = findParent(parent, eq[0] - 'a');
                int y = findParent(parent, eq[3] - 'a');

                if (x == y)
                    return false;
            }
        }
        return true;
    }

    //find the absolute parent of the variable
    int findParent(vector<int> &parent, int i)
    {
        if (i == parent[i])
            return i;
        return parent[i] = findParent(parent, parent[i]);
    }

    //union the two variables
    void uni(char a, char b, vector<int> &parent)
    {
        int aParent = findParent(parent, a - 'a');
        int bParent = findParent(parent, b - 'a');

        if (aParent != bParent)
        {
            parent[aParent] = bParent;
        }
    }
};
