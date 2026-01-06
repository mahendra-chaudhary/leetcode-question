class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if(nums.size() <= 2) return nums.size();

        int j = 2;

        for(int i = 2;i<n;i++){
            if(nums[i] != nums[j-2]){
                nums[j] = nums[i];
                j++;


            }
        }
        return j;



        
    }
};