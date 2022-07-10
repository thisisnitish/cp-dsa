/*
Leetcode Question 208. Implement Trie (Prefix Tree)
https://leetcode.com/problems/implement-trie-prefix-tree/
*/

// Build your data structure first
struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        // if the ch is not NULL then ch exists
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
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

    // Time: O(length of the word), Space: O(length of the word)
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            // moves to the reference trie
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    // Time: O(length of the word), Space: O(length of the word)
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }

            node = node->get(word[i]);
        }

        // check for the end
        return node->isEnd();
    }

    // Time: O(length of the word), Space: O(length of the word)
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }

            node = node->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
