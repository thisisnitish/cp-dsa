/*
Leetcode Question 139. Word Break
https://leetcode.com/problems/word-break/
*/

/*
The idea is to check every possible prefix of that string in the 
dictionary of words, if it is found in the dictionary, then the 
recursive function is called for the remaining portion of that string. 
And, if in some function call, it is found that the complete string is 
in dictionary, then it will return true.
*/


//Recursive
class Solution {
public:
    //Time: O(2^N), Space: O(N)
    bool wordBreak(string s, vector<string>& wordDict) {
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
            return true;
        
        for(int i=1; i<=s.length(); i++){
            string prefix = s.substr(0, i);
            
            //finding the prefix in the wordDict
            auto it = find(wordDict.begin(), wordDict.end(), prefix) != wordDict.end();
            
            //check for the remaining portion of string
            if(it && wordBreak(s.substr(i), wordDict))
                return true;
        }
        return false;
    }
};

//Recursive + Memoization
class Solution {
public:
    //Time: O(N^3), Space: O(N)
    unordered_map<string, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
            return true;
        
        //check before doing any further calculation
        if(memo.find(s) != memo.end()) return memo[s];
        
        for(int i=1; i<=s.length(); i++){
            string prefix = s.substr(0, i);
            
            //finding the prefix in the wordDict
            auto it = find(wordDict.begin(), wordDict.end(), prefix) != wordDict.end();
            
            //check for the remaining portion of string
            if(it && wordBreak(s.substr(i), wordDict)){
                return memo[s] = true;   
            }
        }
        return memo[s] = false;
    }
};
