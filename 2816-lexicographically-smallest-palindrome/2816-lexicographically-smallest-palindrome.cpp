class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;

        while(i<j){
            s[j--] = s[i++] = min(s[i],s[j]);

        }
        return s;
        
    }
};