class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n = s.size();
        // unoredered_map<char> sp;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if( s == t) {
            return true;
        }
        return false;
        
    }
};