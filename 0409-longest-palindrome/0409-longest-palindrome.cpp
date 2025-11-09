class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        int count  = 0;
        unordered_map<char,int> ans;

        for(char ch : s){
            ans[ch]++;
            if(ans[ch] % 2 == 1)
            count++;
            else count--;

        }
        if(count>1)
           return n-count+1;
           return n;
    }
};