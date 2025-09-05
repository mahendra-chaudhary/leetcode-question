class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {

         for (int k = 1; k <= 60; k++) {
            long long x = 1LL * num1 - 1LL * k * num2; // remaining after k operations
            if (x < k) continue;  // can't distribute into k powers of two
            // Check if x can be expressed as sum of k powers of two
            if (__builtin_popcountll(x) <= k && k <= x) {
                return k;
            }
        }
        return -1;        
    }
};