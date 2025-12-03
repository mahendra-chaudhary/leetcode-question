class Solution {
public:
    int countPartitions(vector<int> &nums, long long maxSum) {
        int n = nums.size();
        int partitions = 1;          // at least 1 partition
        long long subarraySum = 0;   // current subarray sum

        for (int i = 0; i < n; i++) {
            if (subarraySum + nums[i] <= maxSum) {
                subarraySum += nums[i];
            } else {
                partitions++;
                subarraySum = nums[i];
            }
        }
        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());   // at least max element
        long long high = accumulate(nums.begin(), nums.end(), 0LL); // at most total sum

        while (low < high) {
            long long mid = low + (high - low) / 2;

            // How many partitions are needed if max subarray sum <= mid?
            int parts = countPartitions(nums, mid);

            if (parts > k) {
                // mid too small → we are forced to create more than k partitions
                low = mid + 1;
            } else {
                // mid works (<= k partitions), try smaller maxSum
                high = mid;
            }
        }

        return (int)low;  // or (int)high, both same now
    }
};
