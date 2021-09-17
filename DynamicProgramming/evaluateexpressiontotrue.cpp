/*
Interviewbit Evaluate Expression To True
https://www.interviewbit.com/problems/evaluate-expression-to-true/
*/


unordered_map<string, int> mp;

int evaluateExpression(string s, int i, int j, bool isTrue){
    //base case
    if(i > j) return 0;
    
    //when the there is one char will be either True or False
    if(i == j){
        if(isTrue == true){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }

    //creating the key
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    //checking if the value is present or not
    if(mp.find(temp) != mp.end())
        return mp[temp];

    int ans = 0;
    for(int k=i+1; k<=j-1; k = k+2){
        //all 4 possible combinations
        int leftTrue = evaluateExpression(s, i, k-1, true);
        int leftFalse = evaluateExpression(s, i, k-1, false);
        int rightTrue = evaluateExpression(s, k+1, j, true);
        int rightFalse = evaluateExpression(s, k+1, j, false);

        if(s[k] == '&'){
            if(isTrue == true){
                ans = (ans + leftTrue*rightTrue)%1003;
            }
            else{
                ans = (ans + leftTrue*rightFalse + leftFalse*rightTrue + leftFalse*rightFalse)%1003;
            }
        }
        else if(s[k] == '|'){
            if(isTrue == true){
                ans = (ans + leftFalse*rightTrue + rightFalse*leftTrue + leftTrue*rightTrue)%1003;
            }
            else{
                ans = (ans + leftFalse*rightFalse)%1003;
            }
        }
        else if(s[k] == '^'){
            if(isTrue == true){
                ans = (ans + leftTrue*rightFalse + leftFalse*rightTrue)%1003;
            }
            else{
                ans = (ans + leftFalse*rightFalse + leftTrue*rightTrue)%1003;
            }
        }
    }
    return mp[temp] = ans % 1003;
}

int Solution::cnttrue(string s) {
    mp.clear();
    return evaluateExpression(s, 0, s.size()-1, 1);
}
