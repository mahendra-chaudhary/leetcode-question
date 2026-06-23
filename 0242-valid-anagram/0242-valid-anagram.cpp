class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        // if(n != m ) {
        //  return false;
        // }

        // return true;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());


        if(s==t) {
            return true;
        }

        return false;

        
    }
};