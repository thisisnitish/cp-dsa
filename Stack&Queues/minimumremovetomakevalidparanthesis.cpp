/*
Leetcode 1249. Minimum Remove to Make Valid Parentheses
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/

// Solution 1
class Solution {
public:
    //Time: O(N), Space: O(N)
    string minRemoveToMakeValid(string s) {
        //base case
        if(s == "") return s;
        
        //here stack is storing the indexes
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            //if we encounter '(' then store it
            if(s[i] == '(') st.push(i);
            //if we encounter ')' then there will be two cases
            else if(s[i] == ')'){
                if(st.size() > 0) st.pop();
                else s[i] = '#';
            }
        }
        
        //all the elements in the stack will be invalid so put '#' in place of them
        //in the string
        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }
        
        //build a new string
        string temp;
        for(auto c : s){
            if(c != '#') temp.push_back(c);
        }
        return temp;
    }
};

//Solution 2
/*
The idea of this approach is,
1. Go from left to right, count '(' and when you encounter ')' there can be two cases
either the open brackets > 0 or open brackets == 0. If first cases happens, then
decrease the count of open brackets else put '#' in string in place of ')'

Similary, go from right to left, count ')' and when you encounter '(' there can be
two cases either the close brackets > 0 or close brackets == 0. If first caes happens
then decrease the count of close brackets else put '#' in string in place of '('
*/
class Solution {
public:
    //Time: O(N), Space: O(1)
    string minRemoveToMakeValid(string s) {
        //base case
        if(s == "") return s;
        
        int open = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') open++;
            else if(s[i] == ')'){
                if(open > 0) open--;
                else s[i] = '#';
            }
        }
        
        int close = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == ')') close++;
            else if(s[i] == '('){
                if(close > 0) close--;
                else s[i] = '#';
            }
        }
        
        string temp;
        for(auto c : s){
            if(c != '#') temp.push_back(c);
        }
        return temp;
    }
};
