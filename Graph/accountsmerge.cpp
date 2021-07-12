/*
Leetcode Question 721. Accounts Merge
https://leetcode.com/problems/accounts-merge/
*/

class Solution {
public:
    //Time: O(nlogn), Space: O(n)
    vector<int> parent;
    int findParent(int i){
        if(parent[i] == i) return i;
        return parent[i] = findParent(parent[i]);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //base case
        if(accounts.size() == 1){
            sort(accounts[0].begin()+1, accounts[1].end());
            return accounts;
        }
        
        int n = accounts.size();
        
        //fill the parent initially
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        
        /*
        emailMap is for storing the emails according to the index. we know that in map
        key should be unique, so we can't have key as index but we can keep string because
        in an account every email is different so map those emails to the index
        */
        unordered_map<string, int> emailMap;
        
        /*It stores the names of the persons at their respective index*/
        vector<string> names(n, "");
        
        /*
        we are just looping through the accounts process on every account.
        For every account take the first name and push it to the names vector and for the
        rest of the vector, because these are only emails, we need to push all those emails
        in the emailMap. Now to fill emailMap, take the email check if it is present or not
        in the emailMap, if no then push it in the emailMap and map it to the suitable index 
        but if it is already present then find the parent of it and also find the parent of
        the index and then make parent[x] = y.
        */
        int idx = 0;
        for(auto account : accounts){
            names[idx] = account[0];
            for(int i=1; i<account.size(); i++){
                if(emailMap.find(account[i]) != emailMap.end()){
                    int x = findParent(idx);
                    int y = findParent(emailMap[account[i]]);
                    parent[x] = y;
                }
                else
                    emailMap[account[i]] = idx;
            }
            idx++;
        }
        
        /*
        here we are trying to aggregate everything that we have done so far
        we are looping through the emailMap and taking all the emails by finding the root
        parent for each of the map
        */
        unordered_map<int, vector<string>> resultMap;
        for(auto email : emailMap){
            int u = findParent(email.second);
            resultMap[u].push_back(email.first);
        }
        
        /*
        loop through the resultMap take all the aggregated strings and sort it.
        Also find the names according to the mapped value and insert it in the first position
        */
        vector<vector<string>> result;
        for(auto res : resultMap){
            auto v = res.second;
            sort(v.begin(), v.end());
            v.insert(v.begin(), names[res.first]);
            result.push_back(v);
        }
        
        return result;
    }
};





/*
Example
[
["John","johnsmith@mail.com","john_newyork@mail.com"],
["John","johnsmith@mail.com","john00@mail.com"],
["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]
]

a = findParent(i)
b = findParent(emailmap[x[y]])
parent[a] = b


parent[];
[1, 2, 3, 4, 5, 6]

emailMap - unordered_map
{email, idx}

name - vector
strings

resultMap

vector<<vector<string>> result;
*/

