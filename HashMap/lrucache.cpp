/*
Leetcode Question 146. LRU Cache
https://leetcode.com/problems/lru-cache/
*/

class LRUCache
{
    int size;
    list<pair<int, int> > keys; // storing the keys with value which are least recently used
    unordered_map<int, list<pair<int, int> >::iterator> mp;

public:
    LRUCache(int capacity)
    {
        // initializing the capacity of the cache
        size = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            /*
            if the key is present then move that element in the front of the list or keys
            and return the element
            */
            keys.splice(keys.begin(), keys, mp[key]);
            return mp[key]->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        /*
        if the key is already present in the cache then just update the value of that
        element and move that element in the front in keys
        */
        if (mp.find(key) != mp.end())
        {
            keys.splice(keys.begin(), keys, mp[key]);
            mp[key]->second = value;
            return;
        }
        else
        {
            if (keys.size() == size)
            {
                int _key = keys.back().first;
                keys.pop_back();
                mp.erase(_key);
            }
            keys.push_front({key, value});
            mp[key] = keys.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */