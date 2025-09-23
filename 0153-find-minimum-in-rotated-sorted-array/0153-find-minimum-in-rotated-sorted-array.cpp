class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mini = 0;

        sort(nums.begin(),nums.end());

        mini = nums[0];
        return mini;

        // for(int i = 0;i<n;i++){

        // }
    }
};