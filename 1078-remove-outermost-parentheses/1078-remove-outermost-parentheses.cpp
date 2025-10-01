class Solution {
public:
    string removeOuterParentheses(string s) {
        // int n = s.size();

        string result = "";
        int level = 0;

        for(char ch : s){
            if(ch == '(' ){
                if(level > 0) result = result + ch;
                level++;


            }
            else if(ch == ')' ){
                level--;
                if(level > 0) result = result + ch;
            }
        }
        return result;
    }
};
