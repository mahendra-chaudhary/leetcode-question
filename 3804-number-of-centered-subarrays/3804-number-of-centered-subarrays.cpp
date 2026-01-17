class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n  = nums.size();
        int count = 0;

        count += n;

      
        for(int i = 0;i<n;i++){
        unordered_set<int>st;
            int sum = nums[i];
            st.insert(nums[i]);

            for(int j = i+1;j<n;j++){
                sum +=nums[j];
                st.insert(nums[j]);

               if(st.count(sum)){
                count++;
            }
            }   
        }
        return count  ;
        
    }
};