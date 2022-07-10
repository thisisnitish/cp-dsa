/*
Leetcode Question 211. Design Add and Search Words Data Structure
https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/

/*
No need to write the generic functions in the data structure that we do usually. It
will give TLE, so to simulate the functionality (insert, get, setEnd) we will be
using the links[] array itself.
*/
struct Node
{
    Node *links[26];
    bool isEnd = false;
};

class WordDictionary
{
private:
    Node *root;

public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->links[word[i] - 'a'] == NULL)
            {
                node->links[word[i] - 'a'] = new Node();
            }

            node = node->links[word[i] - 'a'];
        }

        node->isEnd = true;
    }

    bool searchHelper(string word, Node *node)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (node->links[c - 'a'])
                    {
                        if (searchHelper(word.substr(i + 1), node->links[c - 'a']))
                            return true;
                    }
                }
                return false;
            }
            else
            {
                if (node->links[word[i] - 'a'] == NULL)
                    return false;
                node = node->links[word[i] - 'a'];
            }
        }

        if (node->isEnd)
            return true;
        return false;
    }

    bool search(string word)
    {
        Node *node = root;
        return searchHelper(word, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
