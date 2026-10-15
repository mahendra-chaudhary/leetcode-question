
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int next = -1;

            for (int j = 0; j < m; j++) {

                // Find nums1[i] in nums2
                if (nums1[i] == nums2[j]) {

                    // Search to the right
                    for (int k = j + 1; k < m; k++) {
                        if (nums2[k] > nums1[i]) {
                            next = nums2[k];
                            break;
                        }
                    }

                    break;
                }
            }

            ans.push_back(next);
        }

        return ans;
    }
};
