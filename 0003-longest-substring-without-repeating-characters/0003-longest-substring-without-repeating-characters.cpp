class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    // i can use stoi because strring to array convert
    int maxlength  =  0;
    int left = 0;
    int n = s.length();
     
     vector<int> lastIdx(256,-1);

     for(int i = 0;i<n;i++){
        if(lastIdx[s[i]] >= left){
            left = lastIdx[s[i]] +1;

        }
        lastIdx[s[i]] = i;
        maxlength = max(maxlength,i - left + 1);
     }
     return maxlength;





    }
};