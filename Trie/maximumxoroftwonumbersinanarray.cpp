/*
Leetcode Question 421. Maximum XOR of Two Numbers in an Array
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
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
    int findMaximumXOR(vector<int> &nums)
    {
        Trie trie;

        for (auto n : nums)
            trie.insert(n);

        int maxNum = 0;
        for (auto n : nums)
        {
            maxNum = max(maxNum, trie.getMax(n));
        }
        return maxNum;
    }
};
