class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int totalsum = 0;

        for(int i =0;i<n;i++){
            totalsum += nums[i];

        }

        int leftsum = 0;
        int count = 0;

        for(int i = 0;i<n-1;i++){
            leftsum += nums[i];
            int rightsum =  totalsum + leftsum ;

            if((leftsum % 2) == (rightsum % 2)){
                count++;
            }
        }
        return count;
        
    }
};