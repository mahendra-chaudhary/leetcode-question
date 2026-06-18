class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // int s = "";

        // here i decleare first prefix already and start to index 1 to n 
        // then to find 
        // pop_back'
        //empty the given ans 

        string prefix = strs[0];

        int n = strs.size();

        for(int i = 1;i<n;i++){

            while(strs[i].find(prefix)  != 0){
                prefix.pop_back();

            if(prefix.empty())
             return "";
            }

        }

        return prefix;

        
    }
};