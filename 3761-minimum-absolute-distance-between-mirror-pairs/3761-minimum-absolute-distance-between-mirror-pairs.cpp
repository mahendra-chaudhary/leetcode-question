class Solution {
public:
    int reverseNumLL(long long x ){
        long long rev = 0;
        x = llabs(x);
        while(x>0){
            int d = x % 10;
            rev = rev * 10 + d;
            x /= 10;

        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {

        unordered_map<long long, int> lastIndex; // map value -> latest index j where reverse(nums[j]) == key
        int ans = INT_MAX;

        for (int i = 0; i < (int)nums.size(); ++i) {
            long long val = nums[i];
            if (lastIndex.count(val)) {
                ans = min(ans, i - lastIndex[val]);
            }
            long long rev = reverseNumLL(val);
            lastIndex[rev] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};