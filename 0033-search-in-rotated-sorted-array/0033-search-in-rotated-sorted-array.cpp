class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;

        while(lo<=hi){
            int mid = (hi+lo)/2;

            if(nums[mid] == target) return mid;

            if(nums[lo] <= nums[mid]){

                if(nums[mid] > target && nums[lo] <= target){
                      hi = mid-1;

                 }
                else{
                     lo = mid + 1;
                }
              
            }
            else{
                if(target  <= nums[hi] && nums[mid] < target){
                lo = mid + 1;

            }
            else{
                 hi = mid-1;
                }
            }
        }

        return -1;




        
    }
};