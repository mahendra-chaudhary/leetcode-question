class Solution {
public:
    int count = 0,maxor = 0;

    void dfs(vector<int>& nums,int index,int current){
        if(index == nums.size()){
            if(current == maxor) count++;
            return ;
        }
        dfs(nums,index+1,current | nums[index]);

        dfs(nums,index+1,current);

    }

    int countMaxOrSubsets(vector<int>& nums) {
       vector<int> dp(1 << 17, 0);
        dp[0] = 1;
        int maxOr = 0;

        for (int num : nums) {
            for (int i = maxOr; i >= 0; --i) {
                dp[i | num] += dp[i];
            }
            maxOr |= num;
        }

        return dp[maxOr];
    }
};