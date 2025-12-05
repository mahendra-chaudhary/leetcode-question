class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> result ;
        int next = 1;

        for(int  t : target){

            while(next < t){
                result.push_back("Push");
                result.push_back("Pop");
                next ++;

            }
            //next == t: push it to keep
            result.push_back("Push");
            next++;

        }
        return result;
        
    }
};