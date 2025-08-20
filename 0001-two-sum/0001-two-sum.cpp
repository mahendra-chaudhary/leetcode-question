class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> result;

        int n =  nums.size();
        int j = 0;



        for(int i = 0;i<n;i++){

            int num  = nums[i];

            // if( nums[i] <= target){

                if(result.find(target-nums[i]) != result.end()){

                    return {i,result[target-nums[i]]};
                    
                // }



            }
            result[nums[i]] =i;
            
            


        }
        return  {};

        
    }
};