class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int maxi  = INT_MAX;

        sort(nums.begin(),nums.end());

        for(int n : nums)

            maxi = min(maxi,n);
        int count = 0;
        for(int n : nums) 
           
           count += n-maxi;

            

            
           
        return count;

        
    }
};