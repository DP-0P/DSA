class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, 0, 0, "", n);
        return result;
    }
    void generate(vector<string> &result, int open, int close, string current, int n){
        if(open == n && close == n){
            result.push_back(current);
            return;
        }

        if(open < n)
            generate(result, open+1, close, current + '(', n);
        
        if(close < open)
            generate(result, open, close+1, current + ')', n);
    }
};
