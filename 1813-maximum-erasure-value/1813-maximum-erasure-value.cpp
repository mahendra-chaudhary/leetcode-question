class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        unordered_set<int>seen;

        int right = 0;
        int left = 0;
        int maxsum = 0;
        int currsum = 0;


        while(right<nums.size()){
            while(seen.count(nums[right])){
                    seen.erase(nums[left]);

                    currsum -= nums[left];

                    left++;

            

            }

            seen.insert(nums[right]);
            currsum += nums[right];

            maxsum = max(maxsum,currsum);

            right++;

        }

        return maxsum ;




        // for(int i=0;i<n ;i++){
        //      if(nums[i] == nums[n]){
        //         nums[i].pop();

        //      }
        //             }

        // for(int i = 0;i<right ;i++){
        //     for(int j = 1;j<left;i++){
        //         int sum = 0;

        //         if(right == left){
                     
        //         }

        //     }
        // }






        
    }
};