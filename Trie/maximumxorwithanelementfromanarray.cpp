/*
Leetcode Question 1707. Maximum XOR With an Element From Array
https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
*/

// Build the Trie data structure
struct Node
{
    Node *links[2]; // contains 0 or 1

    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            // check if its 0 or 1 and it exists or not
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1; // get the bit

            // if node contains the opposite
            if (node->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {

        // sort the array
        sort(nums.begin(), nums.end());

        // <mi, xi, i>
        vector<pair<int, pair<int, int>>> offlineQueries;
        int q = queries.size();
        for (int i = 0; i < q; i++)
        {
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }

        // sort the queries
        sort(offlineQueries.begin(), offlineQueries.end());

        vector<int> answer(q, 0);
        int n = nums.size();
        int j = 0;
        Trie trie;

        for (int i = 0; i < q; i++)
        {

            int mi = offlineQueries[i].first;
            int xi = offlineQueries[i].second.first;
            int queryIdx = offlineQueries[i].second.second;

            while (j < n && nums[j] <= mi)
            {
                trie.insert(nums[j]);
                j++;
            }

            if (j == 0)
                answer[queryIdx] = -1;
            else
                answer[queryIdx] = trie.getMax(xi);
        }
        return answer;
    }
};
