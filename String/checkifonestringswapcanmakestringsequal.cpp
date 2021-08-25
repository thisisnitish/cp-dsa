/*
Leetcode Question 1790. Check if One String Swap Can Make Strings Equal
https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
*/

//Solution 1
class Solution {
public:
    //Time: O(N), Space: O(1)
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        
        int count = 0;
        int idx1 = -1, idx2 = -1;
        
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                if(count == 0) count++, idx1 = i;
                if(count == 1) count++, idx2 = i;
                count--;
            }
        }
        
        swap(s1[idx1], s1[idx2]);
        if(s1 == s2) return true;
        return false;
    }
};

//Solution 2
class Solution {
public:
    //Time: O(N), Space: O(N)
    bool areAlmostEqual(string s1, string s2) {
        
        vector<int> indices;
        
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i])
                indices.push_back(i);
        }
        
        //string will be equal
        if(indices.size() == 0) return true;
        
        if(indices.size() == 2)
            swap(s1[indices[0]], s1[indices[1]]);
        
        return s1 == s2;
    }
};
