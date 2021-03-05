/*
Leetcode Question 146. LRU Cache
https://leetcode.com/problems/lru-cache/
*/

class LRUCache
{
    int _size;
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator> > mp;

public:
    LRUCache(int capacity)
    {
        _size = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            keys.erase(mp[key].second);
            keys.push_front(key);
            mp[key].second = keys.begin();
            return mp[key].first;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            keys.erase(mp[key].second);
            keys.push_front(key);
            mp[key] = {value, keys.begin()};
        }
        else
        {
            if (keys.size() == _size)
            {
                mp.erase(keys.back());
                keys.pop_back();
            }
            keys.push_front(key);
            mp[key] = {value, keys.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */