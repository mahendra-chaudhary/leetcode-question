class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        // int result = -1;

        //  int first = 0 ;
        //  int last = n-1;

        //  while(last >= first){
        //     int mid  = (first + last) / 2;

        //     if(nums[first] > target ){
        //          result = mid;
        //          last = mid-1;


        //     }
        //     else{
        //         first = mid + 1;

        //     }
        //  }

        //  return result;

        int first = -1;
        int last = -1;

        for(int i = 0;i<n;i++){
            if(nums[i] == target) {
                if(first == -1)first = i ;
                last = i;

            }
        }

        return {first,last};
    }
};