class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i  = 0;
        long long res = 0;

        while(i<n){
            long long l = 0;

            if(nums[i] == 0){
                while(i < n && nums[i] == 0){
                    i++;
                    l++;
                }
                res += (l) * (l + 1) / 2;
            } else {
                i++;
            }
           
        }
        return res;

        // 2nd approach
        // int count = 0;
        // long long result = 0;



        // for(int i = 0;i<n;i++){
        //     if(nums[i] == 0){

        //         count++;

        //     }
        //     else{
        //         count = 0;

        //     }
        //     result = result + count;

        // }
        // return result;
        
    }
};