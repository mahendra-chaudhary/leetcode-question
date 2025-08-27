class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n =  nums.size();


        // int j = 0;

        // for(int i = 0;i<n;i++){

        //     if(nums[i] == NULL) return false;

        //     if(nums[i] == j) return true;

        //     j++;
            
            
        //   }

        //   return false;
        sort(nums.begin(),nums.end());

        for(int i =1;i<n;i++){
            if(nums[i] == nums[i-1]) return true;
              
        }

        return false;
    }
};