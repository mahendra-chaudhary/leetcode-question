class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) return true;

            // Handle duplicates
            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
                lo++;
                hi--;
            }
            else if (nums[lo] <= nums[mid]) { // left half sorted
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else { // right half sorted
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }

        return false;
    }
};
