class Solution {
public:
    
         int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            int d = x % 10;
            rev = rev * 10 + d;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {

            unordered_map<int, int> lastIndex; // value -> latest index i where reverse(nums[i]) == value
        int ans = INT_MAX;

        for (int i = 0; i < (int)nums.size(); i++) {
            int val = nums[i];

            // Step 1: treat i as right side j
            if (lastIndex.count(val)) {
                ans = min(ans, i - lastIndex[val]);
            }

            // Step 2: now treat i as left side, prepare for future
            int rev = reverseNum(val);
            lastIndex[rev] = i;  // keep closest i from left for this 'rev'
        }

        return ans == INT_MAX ? -1 : ans;
    }
};