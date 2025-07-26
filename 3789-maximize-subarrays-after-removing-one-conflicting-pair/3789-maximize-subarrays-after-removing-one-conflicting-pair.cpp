class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {


        vector<vector<int>> conflict(n + 1);

        // Step 1: For each conflict [a, b], store a in conflict[b] (where a < b)
        for (auto& p : conflictingPairs) {
            int a = min(p[0], p[1]);
            int b = max(p[0], p[1]);
            conflict[b].push_back(a);
        }

        long long total = 0;
        vector<long long> gain(n + 2, 0); // potential gains if we remove constraint at left pointer
        int left = 0, secondLeft = 0;

        // Step 2: Iterate through array from 1 to n
        for (int right = 1; right <= n; ++right) {
            for (int a : conflict[right]) {
                if (a > left) {
                    secondLeft = left;
                    left = a;
                } else if (a > secondLeft) {
                    secondLeft = a;
                }
            }

            total += (right - left); // valid subarrays ending at 'right'
            gain[left] += (left - secondLeft); // track gain if we remove the restriction at 'left'
        }

        // Step 3: Final answer is total + max gain
        return total + *max_element(gain.begin(), gain.end());
        
    }
};