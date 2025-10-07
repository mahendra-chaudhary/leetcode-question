class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        // string str = "";
        int ans = 0;

        int n = s.size();
           for(int i = 0;i<n;i++){

            if(i + 1 < n && value[s[i]] < value[s[i+1]]){

                ans -= value[s[i]];
            }
            else{

                ans += value[s[i]];
            }
           }
            
            return ans;
        
    }
};