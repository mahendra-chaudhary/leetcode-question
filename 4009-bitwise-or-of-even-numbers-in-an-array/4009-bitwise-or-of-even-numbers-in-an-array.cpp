class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int n =  nums.size();
        int result =  0;

        for(int i  =  0;i<n;i++){
            if(nums[i]%2 == 0 ){
                result |= nums[i];
            }
        }
        
        // for(int num : nums){
        //     if(num % 2 == 0){
        //         result |= num;

        //     }

        // }

        return result;
        


        
    }
};