class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;

        sort(nums.begin(), nums.end()); // start with smallest lexicographical
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end())); // generate next permutation

        return result;
    }
        
    
};