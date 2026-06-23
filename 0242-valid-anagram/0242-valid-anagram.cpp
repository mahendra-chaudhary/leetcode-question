class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m ) {
         return false;
        }

        vector<int> freq(26,0);

        for(char ch : s){
            freq[ch - 'a']++;
        } 
        for(char ch : t){
            freq[ch - 'a']--;
        }

        for(int count : freq){
            if(count != 0){
                return false;
            }
        }
        return true;

        // return true;

        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());


        // if(s==t) {
        //     return true;
        // }

        // return false;

        
    }
};