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
      for(int num : nums){
        maxor |= num;
      }

      dfs(nums,0,0);

      return count;
        
    }
};