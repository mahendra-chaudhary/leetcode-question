class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> result ;
        if(n == 1){
            vector<int> single;
            single.push_back(nums[0]);
            result.push_back(single);
            return result;
        }
        for(int i = 0;i<n;i++){
            int m = nums[i];
            vector<int> remain;
            for(int j = 0;j<n;j++){
                if(j != i ){
                    remain.push_back(nums[j]);

                }
            }
            vector<vector<int>> perms = permute(remain);
            for(vector<int>p:perms){
                p.insert(p.begin(),m);
                result.push_back(p);
            }
        }


     
            
        return result;
        
    }
};