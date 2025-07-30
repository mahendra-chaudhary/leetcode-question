class Solution {
public:
    int longestSubarray(vector<int>& nums) {

       int maxval = *max_element(nums.begin(),nums.end());
       int streak =0;
       int maxstreak = 0;

       for(int num : nums){
        if(num == maxval){
            streak++;
            if(streak > maxstreak)
            maxstreak = streak;
            

        }
        else{
            streak = 0;
        }

       }

       return maxstreak;
    }
};