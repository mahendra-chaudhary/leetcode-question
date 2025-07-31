class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int maxlen = 0;
        int bit = 0;

        for(int i = 0;i<n;i++){
            while((bit & nums[i] ) != 0){
                bit ^= nums[left];
                left++;

            }

            bit |=  nums[i];
            maxlen = max(maxlen, i-left+1);

        }
        return maxlen;

        
    }
};