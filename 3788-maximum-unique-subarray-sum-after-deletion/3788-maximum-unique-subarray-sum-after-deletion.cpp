class Solution {
public:
    int maxSum(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        if(mx <= 0) return mx;

        int n = nums.size();
        int sum = 0;

        // vector<int> sub;
        unordered_set<int> seen;

        for(int x : nums){
            if(x>0 && seen.insert(x).second){
                sum += x;
            }
        }

        return sum;
        
    }
};