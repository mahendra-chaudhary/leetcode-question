class Solution {
public:
    int getReversed(int n) {
        int reversed = 0;
        while (n > 0) {
            reversed = (reversed << 1) | (n & 1); // Shift result left and add the last bit of n
            n >>= 1; // Shift n right to process the next bit
        }
        return reversed;
    }
   
    vector<int> sortByReflection(vector<int>& nums) {
            sort(nums.begin(), nums.end(), [&](int a, int b) {
            int revA = getReversed(a);
            int revB = getReversed(b);
            
            // Primary Sort: Compare based on reversed values
            if (revA != revB) {
                return revA < revB;
            }
            
            // Secondary Sort (Tie-breaker): Compare based on original values
            // This ensures stability for numbers like 3 and 6 which both reverse to 3
            return a < b;
        });
        
        return nums;
    }
};
