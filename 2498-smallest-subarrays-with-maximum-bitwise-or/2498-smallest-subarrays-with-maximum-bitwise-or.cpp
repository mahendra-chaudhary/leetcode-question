class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int>result(n);
        vector<int>setIndex(32,-1);

        for(int i = n-1;i>=0;i--){
            int endidx = i ;
            for(int j = 0;j<32;j++){
                if(!(nums[i]  & (1<<j))){
                    if(setIndex[j] != -1){
                        endidx = max(endidx,setIndex[j]);

                    }
                }
                    else{
                        setIndex[j] = i;
                    }
            }
                    result[i] = endidx - i + 1;
 
        }
        return result;



        
    }
};